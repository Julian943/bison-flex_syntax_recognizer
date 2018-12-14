%{
#include <stdio.h>
#include <math.h>
#include "Tree.h"

extern int yylex();
extern char * yytext;
extern int errorFlag;

int yyerror(const char *);

void * table;
void * tree;

%}

%union {
  int num;
  double decNum;
  char * str;
  void * node;
};

%type<node> stmt
%type<node> opt_stmts
%type<node> stmt_lst
%type<node> expr
%type<node> term
%type<node> factor
%type<node> expression
%type<str> id
%type<num> tipo
%type<node> dec
%type<node> decls
%type<node> opt_decls


%token PROGRAM ID BEG END INT FLOAT ASSIGN IF ENDIF ELSE REPEAT WHILE ENDW READ PRINT SEMICOLON COLON PLUS MINUS MULTIPLY DIVIDE OPEN_PAR CLOSE_PAR NUMINT NUMFLOAT LESS_THAN MORE_THAN EQUALS UNTIL 

%start prog

%% 

prog : PROGRAM ID opt_decls BEG opt_stmts END {table = $3; tree = $5;   printf("Compiled\n");}
;

opt_decls : decls {$$ = createOptDecls($1);}
            | {$$ = createOptDecls(NULL);}
; 

decls : dec SEMICOLON decls {$$ = createDecls($1,$3);}
      | dec {$$ = createDecls($1,NULL);}
;

dec : id COLON tipo { $$ = createDec($1,$3);}
;

tipo : INT { $$ = 1}
     | FLOAT { $$ = 2}
;

stmt : id ASSIGN expr  { $$ =  createStmtNode(createAssignNode($1,$3),1);}
      | IF OPEN_PAR expression CLOSE_PAR opt_stmts ENDIF   {$$ =  createStmtNode(createIfNode($3,$5),2);}
      | IF OPEN_PAR expression CLOSE_PAR opt_stmts ELSE opt_stmts ENDIF   {$$ =  createStmtNode(createIfElseNode($3,$5,$7),3);}
      | REPEAT opt_stmts UNTIL OPEN_PAR expression CLOSE_PAR  {$$ =  createStmtNode(createRepeatNode($2,$5),4);}
      | WHILE OPEN_PAR expression CLOSE_PAR opt_stmts ENDW {$$ =  createStmtNode(createWhileNode($3,$5),5);} 
      | READ ID  {$$ = createStmtNode(createReadNode(yylval.str),6);}
      | PRINT expr  {$$ =  createStmtNode(createPrintNode($2),7);}
;

id : ID { $$ = strdup(yylval.str); }

opt_stmts : stmt_lst {$$ = createOptStmtsNode($1);}
          | {$$ = createOptStmtsNode(NULL);}
;

stmt_lst : stmt SEMICOLON stmt_lst {$$ = createStmtLstNode($1,$3);}
         | stmt {$$ = createStmtLstNode($1,NULL);}
;

expr : expr PLUS term {$$ = createExprNode(createPlusNode($1,$3),1);}
     | expr MINUS term {$$ = createExprNode(createMinusNode($1,$3),2);}
     | term {$$ = createExprNode(createTermExprNode($1),3);}
;

term : term MULTIPLY factor {$$ = createTermNode(createMultiplyNode($1,$3),1);}
     | term DIVIDE factor {$$ = createTermNode(createDivideNode($1,$3),2);}
     | factor {$$ = createTermNode(createFactorTermNode($1),3);}
;

factor : OPEN_PAR expr CLOSE_PAR {$$ = createFactorNode(createExprFactorNode($2),1);}
       | ID {  $$ = createFactorNode(createIdNode(yylval.str),2);}
       | NUMINT {$$ = createFactorNode(createNumIntNode(yylval.num),3);}
       | NUMFLOAT {$$ = createFactorNode(createNumFloatNode(yylval.decNum),4);}
;

expression : expr LESS_THAN expr {$$ = createExpressionNode(createLessThanNode($1,$3),1);}
          | expr MORE_THAN expr {$$ = createExpressionNode(createMoreThanNode($1,$3),2);}
          | expr EQUALS expr {$$ = createExpressionNode(createEqualsNode($1,$3),3);}
;

%% 
int err = 0;
int yyerror(char const * s) {
  fprintf(stderr, "%s\n", s);
  err = 1;
  return 1;
}

int main(int argc, char**argv){
  extern FILE* yyin;
  char *sourceFile = argv[1];
  yyin = fopen(sourceFile, "r");
  if(yyin == NULL){
    printf("File not found\n");
    return 0;
  }
  yyparse();
  fclose(yyin);
  
  if(err == 1) return 0;
  //printOptDecls(table);
  //printOptStmtsNode(tree);
  executeOptStmts(tree,table);
  //printf("AFTER\n");
  //printOptDecls(table);
 /*
  struct dec * res = (struct dec *)lookUpTable(table,"sum");
  int * data = (int *)malloc(sizeof(int));
  *data = 10;
  res->value = (void *)data;
  if(res->value != NULL){
      if(res->type == 1){
          printf("INT: %d\n", (*(int *)res->value));
      }
      else{
        printf("Float: %lf\n", (*(double *)res->value));
      }
    }
    else{
      printf("Value is empty\n");
    }
*/
  return 0;
}

