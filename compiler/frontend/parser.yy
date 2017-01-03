/* $Id$ -*- mode: c++ -*- */
/** \file parser.yy Contains the impalajit Bison parser source */

%{ /*** C/C++ Declarations ***/

#include <stdio.h>
#include <string>
#include <vector>

#include <expression.h>
#include <basic_expression.h>
#include <comparison_expression.h>
#include <complex_expression.h>

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

 /*** BEGIN EXAMPLE - Change the example grammar's tokens below ***/

%union {
	int			integerVal;
    double 			doubleVal;
    std::string*		stringVal;
    class Node*		node;
    class Node**	nodeArray;
}

%token			END	     0				"end of file"
%token			EOL						"end of line"
%token <integerVal> 	INTEGER				"integer"
%token <doubleVal> 	DOUBLE				"double"
%token <stringVal> 	STRING				"string"
%token <stringVal>	FUNCTION    		"function"
%token <stringVal>  IF 					"if block"
%token <stringVal>  ELSE 				"else block"
%token <integerVal>  OR               	"or operator"
%token <integerVal>  AND               	"and operator"
%token <integerVal> CMPOP				"compare operator"


%type <node>	constant variable
%type <node>	atomexpr powexpr unaryexpr mulexpr addexpr expr atomcondition booleanand booleanor ifstmt

%destructor { delete $$; } constant variable 
%destructor { delete $$; } atomexpr powexpr unaryexpr mulexpr addexpr expr atomcondition booleanand booleanor ifstmt

 /*** END EXAMPLE - Change the example grammar's tokens above ***/

%{

#include <driver.h>
#include <scanner.h>

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex

%}

%% /*** Grammar Rules ***/

 /*** BEGIN EXAMPLE - Change the example grammar rules below ***/

constant :  DOUBLE
			{
	           double* v = (double*) malloc(sizeof(double));
	           *v = $1;
		       $$ = new ENConstant(v, driver.expressionContext.assembly);
	   		}


variable : STRING
           	{
		       	if (!driver.expressionContext.existsVariable(*$1)) 
		       	{
					error(yyla.location, std::string("Unknown variable \"") + *$1 + "\"");
					delete $1;
			   		YYERROR;
	       		}
	       		else 
	       		{
				   $$ = new ENConstant( driver.expressionContext.getVariable(*$1), driver.expressionContext.assembly );
				   delete $1;
	       		}
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
		       	$$ = new ENSQRT($3, driver.expressionContext.assembly);
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
	      		$$ = new ENPower($1, $3, driver.expressionContext.assembly);
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
				$$ = new ENNegate($2, driver.expressionContext.assembly);
			}

mulexpr : unaryexpr
          	{
	      		$$ = $1;
		  	}
	        
	        | mulexpr '*' unaryexpr
	        {
		      	$$ = new ENMultiply($1, $3, driver.expressionContext.assembly);
		  	}
	        
	        | mulexpr '/' unaryexpr
	        {
		  	    $$ = new ENDivide($1, $3, driver.expressionContext.assembly);
		  	}


addexpr : mulexpr
          	{
	      		$$ = $1;
		  	}
	      
	      	| addexpr '+' mulexpr
	      	{
		      	$$ = new ENAdd($1, $3, driver.expressionContext.assembly);
		  	}
	      	
	      	| addexpr '-' mulexpr
	      	{
		      	$$ = new ENSubtract($1, $3, driver.expressionContext.assembly);
		  	}


expr	: addexpr
          	{
	      		$$ = $1;
	  		}


assignment : STRING '=' expr
            {
            	driver.expressionContext.addVariable(*$1, $3);
		 		delete $1;
		 		delete $3;
	     	}

 
atomcondition : expr CMPOP expr 
			{
				$$ = new CNComparison($1, $3, $2, driver.expressionContext.assembly);
			}

			| '(' booleanor ')'
			{
				$$ = $2;
			}


booleanand : booleanand AND atomcondition
			{
				$$ = new BooleanJunctionNode($1, $3, $2, driver.expressionContext.assembly);
			}
			
			| atomcondition AND atomcondition 
			{
				$$ = new BooleanJunctionNode($1, $3, $2, driver.expressionContext.assembly);
			}
			
			


booleanor : atomcondition 
			{
				$$ = new BooleanJunctionNode($1, driver.expressionContext.assembly);
			}
			
			| booleanand 
			{
				$$ = $1;
			}

			| booleanor OR atomcondition 
			{
				$$ = new BooleanJunctionNode($1, $3, $2, driver.expressionContext.assembly);
			}

			| booleanor OR booleanand
			{
				$$ = new BooleanJunctionNode($1, $3, $2, driver.expressionContext.assembly);
			}

			

ifstmt	:	IF '(' booleanor ')' '{' expr '}'
			{
				$$ = new CxNIfStmt($3, $6, driver.expressionContext.assembly);
			}
			
			| IF '(' booleanor ')' '{' expr '}' ELSE '{' expr '}'
			{
				$$ = new CxNIfElseStmt($3, $6, $10, driver.expressionContext.assembly);
			}


start	: /* empty */
	        | start ';'
	        
	        | start EOL
			
			| start assignment ';'
			
			| start assignment END
	        
	        | start expr ';'
	        {
		      	driver.expressionContext.expressions.push_back($2);
		  	}
	        
	        | start expr EOL
	        {
		      	driver.expressionContext.expressions.push_back($2);
		  	}
	        
	        | start expr END
	        {
		      	driver.expressionContext.expressions.push_back($2);
		  	}
			
			| start ifstmt EOL
			{
				driver.expressionContext.expressions.push_back($2);
			}
			
			| start ifstmt END
			{
				driver.expressionContext.expressions.push_back($2);
			}

 /*** END EXAMPLE - Change the example grammar rules above ***/

%% /*** Additional Code ***/

void impalajit::Parser::error(const Parser::location_type& l,
							  const std::string& m)
{
	driver.error(l, m);
}
