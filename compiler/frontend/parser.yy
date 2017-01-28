/* $Id$ -*- mode: c++ -*- */
/** \file parser.yy Contains the impalajit Bison parser source */

%{ /*** C/C++ Declarations ***/

#include <stdio.h>
#include <string>

#include <expression_nodes.h>
#include <compare_nodes.h>
#include <conditional_nodes.h>
#include <assignment_nodes.h>
#include <boolean_nodes.h>
#include <return_nodes.h>

#include <driver.h>
#include <scanner.h>
%}

/*** yacc/bison Declarations ***/

/* Require bison 2.3 or later */
%require "3.0"

/* add debug output code to generated parser. disable this for release
 * versions. */
%debug

/* start symbol is named "start" */
%start start

/* write out a header file containing the token defines */
%defines

/* use newer C++ skeleton file */
%skeleton "lalr1.cc"

/* namespace to enclose parser in */
%define api.namespace{impalajit}

/* set the parser's class identifier */
%define parser_class_name{Parser}

/* keep track of the current position within the input */
%locations
%initial-action
{
    // initialize the initial location object
    @$.begin.filename = @$.end.filename = &driver.streamname;
};

/* The driver is passed by reference to the parser and to the scanner. This
 * provides a simple but effective pure interface, not relying on global
 * variables. */
%parse-param { class Driver& driver }

/* verbose error messages */
%error-verbose

%code requires {
  #include <set>
}

%union {
	int			integerVal;
    double 			doubleVal;
    std::string*		stringVal;
    class Node*		node;
    std::set<std::string>* stringSet;
    class FunctionContext* functionContext;
}

%token			END	     0				"end of file"
%token			EOL						"end of line"
%token <integerVal> 	INTEGER				"integer"
%token <doubleVal> 	DOUBLE				"double"
%token <stringVal> 	STRING				"string"
%token <stringVal>	FUNCTION    		"function"
%token <stringVal>  IF 					"if block"
%token <stringVal>  ELSE 				"else block"
%token <integerVal>  OR               	"|| operator"
%token <integerVal>  AND               	"&& operator"
%token <integerVal> CMPOP				"compare operator"
%token <stringVal> COMMA				","
%token <stringVal> SEMICOLON			";"
%token <stringVal> RETURN				"return value"


%type <node>	constant variable
%type <node>	atomexpr powexpr unaryexpr mulexpr addexpr expr atomcondition booleanand booleanor ifstmt assignment if_body else_body function_body return_stmt
%type <stringSet> parameter_list
%type <functionContext> function

%destructor { delete $$; } constant variable 
%destructor { delete $$; } atomexpr powexpr unaryexpr mulexpr addexpr expr atomcondition booleanand booleanor ifstmt assignment if_body else_body function_body return_stmt

%{


/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex

%}


%% /*** Grammar Rules ***/

function : STRING '(' parameter_list ')' '{' function_body '}'
			{
				$$ = new FunctionContext(*$1, *$3, $6);
			}

parameter_list : %empty 
			{
				std::set<std::string>* parameters = new std::set<std::string>();
				$$ = parameters;
			}

			| parameter_list STRING
			{
				$$ = $1;
				(*$$).insert(*$2);
			}

			|
			parameter_list COMMA STRING 
			{
				$$ = $1;
				(*$$).insert(*$3);
			}

function_body : %empty 
			{
				$$ = new RootNode();
			} 
			
			|
			function_body expr SEMICOLON
			{
				$$ = $1;
				($$->nodes).push_back($2);
			}

			| function_body ifstmt 
			{
				$$ = $1;
				($$->nodes).push_back($2);
			}

			| function_body assignment SEMICOLON
			{
				$$ = $1;
				($$->nodes).push_back($2);
			}

			| function_body return_stmt SEMICOLON
			{
				$$ = $1;
				($$->nodes).push_back($2);
			}


return_stmt : RETURN expr 
			{
				$$ = new ReturnNode($2);
			}

constant :  DOUBLE
			{
		        $$ = new ConstantNode($1);
	   		}


variable : STRING
           	{
	       		$$ = new VariableNode(*$1);
	   		}


atomexpr : constant
           	{
	       		$$ = $1;
		   	}
	       	
	       	| variable
	       	{
		       	$$ = $1;
		   	}
		   	
		   	| FUNCTION '(' expr ')'
		   	{
		       	$$ = new SQRTNode($3);
		   	}
	        
	        | '(' expr ')'
	        {
		       	$$ = $2;
		   	}
	     


powexpr	: atomexpr
          	{
	      		$$ = $1;
	  		}
        	
        	| atomexpr '^' powexpr
          	{
	      		$$ = new PowerNode($1, $3);
	  		}

unaryexpr : powexpr
            {
				$$ = $1;
			}
		    
		    | '+' powexpr
	        {
				$$ = $2;
			}
		    
		    | '-' powexpr
		    {
				$$ = new NegationNode($2);
			}

mulexpr : unaryexpr
          	{
	      		$$ = $1;
		  	}
	        
	        | mulexpr '*' unaryexpr
	        {
		      	$$ = new MultiplicationNode($1, $3);
		  	}
	        
	        | mulexpr '/' unaryexpr
	        {
		  	    $$ = new DivisionNode($1, $3);
		  	}


addexpr : mulexpr
          	{
	      		$$ = $1;
		  	}
	      
	      	| addexpr '+' mulexpr
	      	{
		      	$$ = new AdditionNode($1, $3);
		  	}
	      	
	      	| addexpr '-' mulexpr
	      	{
		      	$$ = new SubtractionNode($1, $3);
		  	}


expr	: addexpr
          	{
	      		$$ = $1;
	  		}


assignment : STRING '=' expr
            {
		 		$$ = new AssignmentNode(*$1, $3);
	     	}

 
atomcondition : expr CMPOP expr
			{
				$$ = new CompareNode($1, $3, static_cast<CompareOperatorType>($2));
			}

			| '(' booleanor ')'
			{
				$$ = $2;
			}


booleanand : atomcondition 
			{
				$$ = new BooleanAndNode();
				($$->nodes).push_back($1);
			}

			| booleanand AND atomcondition
			{
				$$ = $1;
				($$->nodes).push_back($3);
			}

booleanor : booleanand 
			{
				$$ = new BooleanOrNode();
				($$->nodes).push_back($1);
			}

			| booleanor OR booleanand
			{
				$$ = $1;
				($$->nodes).push_back($3);
			}
		

if_body : %empty 
			{
				$$ = new IfBodyNode();
			} 
			
			|
			if_body expr SEMICOLON
			{
				$$ = $1;
				($$->nodes).push_back($2);
			}

			| if_body ifstmt 
			{
				$$ = $1;
				($$->nodes).push_back($2);
			}

			| if_body assignment SEMICOLON
			{
				$$ = $1;
				($$->nodes).push_back($2);
			}

			| if_body return_stmt SEMICOLON
			{
				$$ = $1;
				($$->nodes).push_back($2);
			}

else_body : %empty 
			{
				$$ = new ElseBodyNode();
			} 
			
			|
			else_body expr SEMICOLON
			{
				$$ = $1;
				($$->nodes).push_back($2);
			}

			| else_body ifstmt 
			{
				$$ = $1;
				($$->nodes).push_back($2);
			}

			| else_body assignment SEMICOLON
			{
				$$ = $1;
				($$->nodes).push_back($2);
			}

			| else_body return_stmt SEMICOLON
			{
				$$ = $1;
				($$->nodes).push_back($2);
			}



ifstmt	:	IF '(' booleanor ')' '{' if_body '}'
			{
				$$ = new IfStmtNode($3, $6);
			}
			
			| IF '(' booleanor ')' '{' if_body '}' ELSE '{' else_body '}'
			{
				$$ = new IfElseStmtNode($3, $6, $10);
			}
		

start	:   function END
			{
				driver.setFunctionContext($1);
		  	}

%% /*** Additional Code ***/


void impalajit::Parser::error(const Parser::location_type& l,
							  const std::string& m)
{
	driver.error(l, m);
}
