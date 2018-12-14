%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "ExFinal.tab.h"

%}

ID_EXPR [a-zA-Z]([0-9]|[a-zA-Z])*
INTEGER_EXPR 0|[1-9][0-9]*
FLOAT_EXPR ((0|[1-9][0-9]*).(([0-9][1-9]*)|0))

%%


"program"	{return PROGRAM;}
"begin"		{return BEG;}
"end"		{return END;}
";"			{return SEMICOLON;}
":"			{return COLON;}
"int"		{return INT;}
"float"		{return FLOAT;}
":="		{return ASSIGN;}
"if"		{return IF;}
"("			{return OPEN_PAR;}
")"			{return CLOSE_PAR;}
"endif"		{return ENDIF;}
"else"		{return ELSE;}
"repeat"	{return REPEAT;}
"until"		{return UNTIL;}
"while"		{return WHILE;}
"endw"		{return ENDW;}
"read"		{return READ;}
"print"		{return PRINT;}
"+"			{return PLUS;}
"-"			{return MINUS;}
"*"			{return MULTIPLY;}
"/"			{return DIVIDE;}
"<"			{return LESS_THAN;}
">"			{return MORE_THAN;}
"="			{return EQUALS;}
{ID_EXPR} {   yylval.str = yytext;  return ID;}
{INTEGER_EXPR} { yylval.num = atoi(yytext); return NUMINT;}
{FLOAT_EXPR} { yylval.decNum = atof(yytext);  return NUMFLOAT;}


%%