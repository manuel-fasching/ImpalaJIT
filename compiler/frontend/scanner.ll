/**
 * Copyright 2017 Manuel Fasching <manuel.fasching@tum.de>
 * Distributed under the MIT License
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is furnished
 * to do so, subject to the following conditions:
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
 * PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
 * FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

/* $Id$ -*- mode: c++ -*- */
/** \file scanner.ll Define the impalajit Flex lexical scanner */

%{ /*** C/C++ Declarations ***/

#include <string>

#include <scanner.h>
#include <internal_types.hh>

/* import the parser's token type into a local typedef */
typedef impalajit::Parser::token token;
typedef impalajit::Parser::token_type token_type;

/* By default yylex returns int, we use token_type. Unfortunately yyterminate
 * by default returns 0, which is not of token_type. */
#define yyterminate() return token::END

/* This disables inclusion of unistd.h, which is not available under Visual C++
 * on Win32. The C++ scanner uses STL streams instead. */
#define YY_NO_UNISTD_H

%}

/*** Flex Declarations and Options ***/

/* enable c++ scanner class generation */
%option c++

/* change the name of the scanner class. results in "ImpalaJITFlexLexer" */
%option prefix="ImpalaJIT"

/* the manual says "somewhat more optimized" */
%option batch

/* enable scanner to generate debug output. disable this for release
 * versions. */
%option debug

/* no support for include files is planned */
%option yywrap nounput 

/* enables the use of start condition stacks */
%option stack

/* The following paragraph suffices to track locations accurately. Each time
 * yylex is invoked, the begin position is moved onto the end position. */
%{
#define YY_USER_ACTION  yylloc->columns(yyleng);
%}

%% /*** Regular Expressions Part ***/

 /* code to place at the beginning of yylex() */
%{
    // reset location
    yylloc->step();
%}

 /*** Numbers ***/
[-]?[0-9]+["."[0-9]*]? {
    yylval->doubleVal = atof(yytext);
    std::cout << "Double val: " << yylval->doubleVal << std::endl;
    return token::DOUBLE;
}


 /*** COMPARE OPERATORS ***/
(<=) {
    yylval->integerVal = LTE;
    return token::CMPOP;
}
(>=) {
    yylval->integerVal = GTE;
    return token::CMPOP;
}
(==) {
    yylval->integerVal = EQ;
    return token::CMPOP;
}
(!=) {
    yylval->integerVal = NE;
    return token::CMPOP;
}
(<) {
    yylval->integerVal = LT;
    return token::CMPOP;
}
(>) {
    yylval->integerVal = GT;
    return token::CMPOP;
}



 /*** BOOL OPERATORS ***/
(&&) {
    yylval->integerVal = AND;
    return token::AND;
}
(\|\|) {
    yylval->integerVal = OR;
    return token::OR;
}

 /*** Conditionals ***/
if {
    yylval->stringVal = new std::string(yytext, yyleng);
    return token::IF;
}
else {
    yylval->stringVal = new std::string(yytext, yyleng);
    return token::ELSE;
}


 /*** return ***/
return {
    yylval->stringVal = new std::string(yytext, yyleng);
    return token::RETURN;
}


 /*** Special strings ***/
(,) {
    yylval->stringVal = new std::string(yytext, yyleng);
    return token::COMMA;
}
(;) {
    yylval->stringVal = new std::string(yytext, yyleng);
    return token::SEMICOLON;
}


[A-Za-z][A-Za-z0-9_]* {
    yylval->stringVal = new std::string(yytext, yyleng);
    return token::STRING;
}


 /* gobble up white-spaces */
[ \t\r]+ {
    yylloc->step();
}

 /* gobble up end-of-lines */
\n {
    yylloc->lines(yyleng); yylloc->step();
   // return token::EOL;
}

 /* pass all other characters up to bison */
. {
    return static_cast<token_type>(*yytext);
}

 /*** END EXAMPLE - Change the impalajit lexer rules above ***/

%% /*** Additional Code ***/

namespace impalajit {

Scanner::Scanner(std::istream* in,
		 std::ostream* out)
    : ImpalaJITFlexLexer(in, out)
{
}

Scanner::~Scanner()
{
}

void Scanner::set_debug(bool b)
{
    yy_flex_debug = b;
}

}

/* This implementation of ImpalaJITFlexLexer::yylex() is required to fill the
 * vtable of the class ImpalaJITFlexLexer. We define the scanner's main yylex
 * function via YY_DECL to reside in the Scanner class instead. */

#ifdef yylex
#undef yylex
#endif

int ImpalaJITFlexLexer::yylex()
{
    std::cerr << "in ImpalaJITFlexLexer::yylex() !" << std::endl;
    return 0;
}

/* When the scanner receives an end-of-file indication from YY_INPUT, it then
 * checks the yywrap() function. If yywrap() returns false (zero), then it is
 * assumed that the function has gone ahead and set up `yyin' to point to
 * another input file, and scanning continues. If it returns true (non-zero),
 * then the scanner terminates, returning 0 to its caller. */

int ImpalaJITFlexLexer::yywrap()
{
    return 1;
}
