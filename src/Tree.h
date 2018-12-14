
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "SymbolsTable.h"

int errorFlag = 0;

//decls

void printAssignNode(void *);
void printIfNode(void *);
void printIfElseNode(void *);
void printRepeatNode(void *);
void printWhileNode(void *);
void printReadNode(void *);
void printPrintNode(void *);
void printStmtListNode(void *);
void printExprNode(void *);
void printPlusNode(void *);
void printMinusNode(void *);
void printEqualsNode(void *);
void printTermNode(void *);
void printExprFactorNode (void *);
void printIdNode (void *);
void printNumIntNode (void *);
void printNumFloatNode (void *);
void printTermExprNode(void *);
void printMultiplyNode(void *);
void printDivideNode(void *);
void printFactorTermNode(void *);
void printFactorNode(void *);
void printLessThanNode(void *);
void printMoreThanNode(void *);
void printEqualsNode(void *);
void printExpressionNode(void *);
void printOptStmtsNode(void *);

//stmt:
	struct stmt{
		int identifier;
		void * stmt_node;
	};
    //methods
    void * createStmtNode(void * stmt_node, int identifier){
        void * newNode;
        newNode = malloc(sizeof(struct stmt));
        ((struct stmt *)newNode)->identifier = identifier;
        ((struct stmt *)newNode)->stmt_node = stmt_node;

        return newNode;
    }

    void printStmtNode(void * data){
        if(data == NULL){
            printf("Empty stmt node\n");
        }
        else{
            struct stmt * stmt = (struct stmt *)data;
            switch(stmt->identifier){
                case 1:
                    printAssignNode(stmt->stmt_node);
                break;
                case 2:
                    printIfNode(stmt->stmt_node);
                break;
                case 3:
                    printIfElseNode(stmt->stmt_node);
                break;
                case 4:
                    printRepeatNode(stmt->stmt_node);
                break;
                case 5:
                    printWhileNode(stmt->stmt_node);
                break;
                case 6:
                    printReadNode(stmt->stmt_node);
                break;
                case 7:
                    printPrintNode(stmt->stmt_node);
                break;
            }
        }
    }
    //sons:
		struct assignNode{
			char * id;
			void * expr;
		};
        //methods
            void * createAssignNode(char * id, void * expr){
                void * newNode;
                newNode = malloc(sizeof(struct assignNode));
                ((struct assignNode *)newNode)->id = (char *)malloc(sizeof(strlen(id)));
                strcpy(((struct assignNode *)newNode)->id,id);
                ((struct assignNode *)newNode)->expr = expr;
                return newNode;
            }
            void printAssignNode(void * data){
                if(data == NULL){
                    printf("Assign node is empty\n");
                }
                else{
                    struct assignNode * node = (struct assignNode *)data;
                    printf("%s := ",node->id);
                    printExprNode(node->expr);
                }
            }
		struct ifNode{
			void * expression;
			void * opt_stms;
		};
         //methods
            void * createIfNode(void * expression, void * opt_stms){
                void * newNode;
                newNode = malloc(sizeof(struct ifNode));
                ((struct ifNode *)newNode)->expression = expression;
                ((struct ifNode *)newNode)->opt_stms = opt_stms;
                return newNode;
            }
            void printIfNode(void * data){
                if(data == NULL){
                    printf("If node is empty\n");
                }
                else{
                    struct ifNode * node = (struct ifNode *)data;
                    printf("if ( ");
                    printExpressionNode(node->expression);
                    printf(" ) \n");
                    printOptStmtsNode(node->opt_stms);
                    printf("endif");
                }
            }
		struct ifElseNode{
			void * expression;
			void * opt_stms1;
			void * opt_stms2;	
		};
        //methods
            void * createIfElseNode(void * expression, void * opt_stms1, void * opt_stms2){
                void * newNode;
                newNode = malloc(sizeof(struct ifElseNode));
                ((struct ifElseNode *)newNode)->expression = expression;
                ((struct ifElseNode *)newNode)->opt_stms1 = opt_stms1;
                ((struct ifElseNode *)newNode)->opt_stms2 = opt_stms2;
                return newNode;
            }
            void printIfElseNode(void * data){
                if(data == NULL){
                    printf("ifElse node is empty\n");
                }
                else{
                    struct ifElseNode * node = (struct ifElseNode *)data;
                    printf("if ( ");
                    printExpressionNode(node->expression);
                    printf(" ) ");
                    printOptStmtsNode(node->opt_stms1);
                    printf(" else ");
                    printOptStmtsNode(node->opt_stms2);
                    printf(" endif");
                }
            }
		struct repeatNode{
			void * opt_stms;
			void * expression;
		};
        //methods
            void * createRepeatNode(void * opt_stms, void * expression){
                void * newNode;
                newNode = malloc(sizeof(struct repeatNode));
                ((struct repeatNode *)newNode)->opt_stms = opt_stms;
                ((struct repeatNode *)newNode)->expression = expression;
                return newNode;
            }
            void printRepeatNode(void * data){
                if(data == NULL){
                    printf("Repeat node is empty\n");
                }
                else{
                    struct repeatNode * node = (struct repeatNode *)data;
                    printf("repeat ");
                    printOptStmtsNode(node->opt_stms);
                    printf(" until (");
                    printExpressionNode(node->expression);
                    printf(")");
                }
            }
		struct whileNode{
			void * expression;
			void * opt_stms;
		};
        //methods
            void * createWhileNode(void * expression, void * opt_stms){
                void * newNode;
                newNode = malloc(sizeof(struct whileNode));
                ((struct whileNode *)newNode)->expression = expression;
                ((struct whileNode *)newNode)->opt_stms = opt_stms;
                return newNode;
            }
            void printWhileNode(void * data){
                if(data == NULL){
                    printf("While node is empty\n");
                }
                else{
                    struct whileNode * node = (struct whileNode *)data;
                    printf("while (");
                    printExpressionNode(node->expression);
                    printf(") ");
                    printOptStmtsNode(node->opt_stms);
                    printf(" endw");
                }
            }
		struct readNode{
			char * id;
		};
         //methods
            void * createReadNode(char * id){
                void * newNode;
                newNode = malloc(sizeof(struct readNode));
                ((struct readNode *)newNode)->id = (char *)malloc(strlen(id));
                strcpy(((struct readNode *)newNode)->id,id);
                return newNode;
            }
            void printReadNode(void * data){
                struct readNode * node = (struct readNode *)data;
                if(node != NULL && node->id != NULL){
                    printf("Read %s",node->id);
                }
            }
		struct printNode{
			void * expr;
		};
        //methods
            void * createPrintNode(void * expr){
                void * newNode;
                newNode = malloc(sizeof(struct printNode));
                ((struct printNode *)newNode)->expr = expr;
                return newNode;
            }
            void printPrintNode(void * data){
                if(data == NULL){
                    printf("Print node is empty\n");
                }
                else{
                    struct printNode * node = (struct printNode *)data;
                    printf("Print ");
                    printExprNode(node->expr);
                }
            }
//opt_stms:
	struct opt_stms{
		void * stmt_lst; // can be null or stmt_lst node
	};
    //methods
        void * createOptStmtsNode(void * stmt_lst){
            void * newData = malloc(sizeof(struct opt_stms));
            ((struct opt_stms *)newData)->stmt_lst = stmt_lst;
            return newData;
        }
        void printOptStmtsNode(void * data){
            if(data == NULL){
                printf("Opt Stmts is empty\n");
            }
            else{
                struct opt_stms * opt_stms = (struct opt_stms *)data; 
                printStmtListNode(opt_stms->stmt_lst);
            }
        }

//stmt_lst:
	struct stmt_lst{
		void * stmt;
		void * stmt_lst; //can be null
	};
    //methods
        void * createStmtLstNode(void * stmt, void * stmt_lst){
            void * newData = malloc(sizeof(struct stmt_lst));
            ((struct stmt_lst *)newData)->stmt = stmt;
            ((struct stmt_lst *)newData)->stmt_lst = stmt_lst;
            return newData;
        }
        void printStmtListNode(void * data){
            if(data == NULL){
                //printf("Stmt List is empty\n");
            }
            else{
                struct stmt_lst * node = ((struct stmt_lst *)data);
                printStmtNode(node->stmt);
                if(node->stmt_lst != NULL) printf(";");
                printf("\n");
                printStmtListNode(node->stmt_lst);
            }
        }
//expression:
	struct expression{
		int identifier;
		void * expression_node;
	};
    //methods:
        void * createExpressionNode(void * expression_node, int identifier){
            void * newData = malloc(sizeof(struct expression));
            ((struct expression *)newData)->expression_node = expression_node;
            ((struct expression *)newData)->identifier = identifier;

            return newData;
        }
        void printExpressionNode(void * data){
            if(data == NULL){
                printf("Expression is empty\n");
            }
            else{
                struct expression * node = (struct expression *)data;
                switch(node->identifier){
                    case 1:
                        printLessThanNode(node->expression_node);
                    break;
                    case 2:
                        printMoreThanNode(node->expression_node);
                    break;
                    case 3:
                        printEqualsNode(node->expression_node);
                    break;
                }
            }
        }
	//sons
		struct lessThanNode{
			void * expr1;
			void * expr2;
		};
        //methods
            void * createLessThanNode(void * expr1, void * expr2){
                void * newNode = malloc(sizeof(struct lessThanNode));
                ((struct lessThanNode *)newNode)->expr1 = expr1;
                ((struct lessThanNode *)newNode)->expr2 = expr2;

                return newNode;
            }
            void printLessThanNode(void * data){
                if(data == NULL){
                    printf("Less Than Node is empty\n");
                }
                else{
                    struct lessThanNode * node = (struct lessThanNode *)data;
                    printExprNode(node->expr1);
                    printf(" < ");
                    printExprNode(node->expr2);
                }
            }
		struct moreThanNode{
			void * expr1;
			void * expr2;
		};
       //methods
            void * createMoreThanNode(void * expr1, void * expr2){
                void * newNode = malloc(sizeof(struct moreThanNode));
                ((struct moreThanNode *)newNode)->expr1 = expr1;
                ((struct moreThanNode *)newNode)->expr2 = expr2;

                return newNode;
            }
            void printMoreThanNode(void * data){
                if(data == NULL){
                    printf("More Than Node is empty\n");
                }
                else{
                    struct moreThanNode * node = (struct moreThanNode *)data;
                    printExprNode(node->expr1);
                    printf(" > ");
                    printExprNode(node->expr2);
                }
            }
		struct equalsNode{
			void * expr1;
			void * expr2;
		};
         //methods
            void * createEqualsNode(void * expr1, void * expr2){
                void * newNode = malloc(sizeof(struct equalsNode));
                ((struct equalsNode *)newNode)->expr1 = expr1;
                ((struct equalsNode *)newNode)->expr2 = expr2;

                return newNode;
            }
            void printEqualsNode(void * data){
                if(data == NULL){
                    printf("Equals Node is empty\n");
                }
                else{
                    struct equalsNode * node = (struct equalsNode *)data;
                    printExprNode(node->expr1);
                    printf(" = ");
                    printExprNode(node->expr2);
                }
            }
//expr:
	struct expr{
		int identifier;
		void * expr_node;
	};
    //methods:
        void * createExprNode(void * expr_node, int identifier){
            void * newData = malloc(sizeof(struct expr));
            ((struct expr *)newData)->expr_node = expr_node;
            ((struct expr *)newData)->identifier = identifier;

            return newData;
        }
        void printExprNode(void * data){
            if(data == NULL){
                printf("Expr is empty\n");
            }
            else{
                struct expr * node = (struct expr *)data;
                switch(node->identifier){
                    case 1:
                        printPlusNode(node->expr_node);
                    break;
                    case 2:
                        printMinusNode(node->expr_node);
                    break;
                    case 3:
                        printTermExprNode(node->expr_node);
                    break;
                }
            }
        }
	//sons
		struct plusNode{
			void * expr;
			void * term;
		};
        //methods
            void * createPlusNode(void * expr, void * term){
                void * newNode = malloc(sizeof(struct plusNode));
                ((struct plusNode *)newNode)->expr = expr;
                ((struct plusNode *)newNode)->term = term;

                return newNode;
            }
            void printPlusNode(void * data){
                if(data == NULL){
                    printf("Plus Node is empty\n");
                }
                else{
                    struct plusNode * node = (struct plusNode *)data;
                    printExprNode(node->expr);
                    printf(" + ");
                    printTermNode(node->term);
                }
            }
		struct minusNode{
			void * expr;
			void * term;
		};
         //methods
            void * createMinusNode(void * expr, void * term){
                void * newNode = malloc(sizeof(struct minusNode));
                ((struct minusNode *)newNode)->expr = expr;
                ((struct minusNode *)newNode)->term = term;

                return newNode;
            }
            void printMinusNode(void * data){
                if(data == NULL){
                    printf("Minus Node is empty\n");
                }
                else{
                    struct minusNode * node = (struct minusNode *)data;
                    printExprNode(node->expr);
                    printf(" - ");
                    printTermNode(node->term);
                }
            }
		struct termExprNode{
			void * term;
		};
        //methods
            void * createTermExprNode(void * term){
                void * newNode = malloc(sizeof(struct termExprNode));
                ((struct termExprNode *)newNode)->term = term;

                return newNode;
            }
            void printTermExprNode(void * data){
                if(data == NULL){
                    printf("TermExpr Node is empty\n");
                }
                else{
                    struct termExprNode * node = (struct termExprNode *)data;
                    printTermNode(node->term);
                }
            }
//term 
	struct term{
		int identifier;
		void * term_node;
	};
    //methods:
        void * createTermNode(void * term_node, int identifier){
            void * newData = malloc(sizeof(struct term));
            ((struct term *)newData)->term_node = term_node;
            ((struct term *)newData)->identifier = identifier;

            return newData;
        }
        void printTermNode(void * data){
            if(data == NULL){
                printf("Expr is empty\n");
            }
            else{
                struct term * node = (struct term *)data;
                switch(node->identifier){
                    case 1:
                        printMultiplyNode(node->term_node);
                    break;
                    case 2:
                        printDivideNode(node->term_node);
                    break;
                    case 3:
                        printFactorTermNode(node->term_node);
                    break;
                }
            }
        }
	//sons
		struct multiplyNode{
			void * term;
			void * factor;
		};
        //methods 
            void * createMultiplyNode(void * term, void * factor){
                void * newNode = malloc(sizeof(struct multiplyNode));
                ((struct multiplyNode *)newNode)->term = term; 
                ((struct multiplyNode *)newNode)->factor = factor; 

                return newNode; 
            }
            void printMultiplyNode(void * data){
                if(data == NULL){
                    printf("Multiply Node is empty\n");
                }
                else{
                    struct multiplyNode * node = (struct multiplyNode *)data;
                    printTermNode(node->term);
                    printf(" * ");
                    printFactorNode(node->factor);
                }
            }
		struct divideNode{
			void * term;
			void * factor;
		};
        //methods 
            void * createDivideNode(void * term, void * factor){
                void * newNode = malloc(sizeof(struct divideNode));
                ((struct divideNode *)newNode)->term = term; 
                ((struct divideNode *)newNode)->factor = factor; 

                return newNode; 
            }
            void printDivideNode(void * data){
                if(data == NULL){
                    printf("Divide Node is empty\n");
                }
                else{
                    struct divideNode * node = (struct divideNode *)data;
                    printTermNode(node->term);
                    printf(" / ");
                    printFactorNode(node->factor);
                }
            }
		struct factorTermNode{
			void * factor;
		};
        //methods 
            void * createFactorTermNode(void * factor){
                void * newNode = malloc(sizeof(struct factorTermNode));
                ((struct factorTermNode *)newNode)->factor = factor; 

                return newNode; 
            }
            void printFactorTermNode(void * data){
                if(data == NULL){
                    printf("FactorTerm Node is empty\n");
                }
                else{
                    struct factorTermNode * node = (struct factorTermNode *)data;
                    printFactorNode(node->factor);
                }
            }
//factor 
		struct factor{
			int identifier;
			void * factor_node;
		};
        //methods
            void * createFactorNode(void * factor_node, int identifier){
                void * newNode = malloc(sizeof(struct factor));
                ((struct factor *)newNode)->factor_node = factor_node;
                ((struct factor *)newNode)->identifier = identifier;

                return newNode;  
            }
            void printFactorNode(void * data){
                if(data == NULL){
                    printf("Factor Node is empty\n");
                }
                else{
                    struct factor * node = (struct factor *)data;
                    switch(node->identifier){
                        case 1:
                            printExprFactorNode(node->factor_node);
                        break;
                        case 2:
                            printIdNode(node->factor_node);
                        break;
                        case 3:
                            printNumIntNode(node->factor_node);
                        break;
                        case 4:
                            printNumFloatNode(node->factor_node);
                        break;
                        
                    }
                }
            }
		//sons
			struct exprFactorNode{
				void * expr;
			};
            //methods 
                void * createExprFactorNode(void * expr){
                    void * newNode = malloc(sizeof(struct exprFactorNode));
                    ((struct exprFactorNode *)newNode)->expr = expr; 

                    return newNode; 
                }
                void printExprFactorNode(void * data){
                    if(data == NULL){
                        printf("Expr Node is empty\n");
                    }
                    else{
                        struct exprFactorNode * node = (struct exprFactorNode *)data;
                        printf("(");
                        printExprNode(node->expr);
                        printf(")");
                    }
                }
			struct idNode{
				char * id;
			};
            //methods  
                void * createIdNode(char * id){
                    void * newNode = malloc(sizeof(struct idNode));
                    ((struct idNode *)newNode)->id = (char *)malloc(strlen(id));
                    strcpy(((struct idNode *)newNode)->id,id);

                    return newNode; 
                }
                void printIdNode(void * data){
                    if(data == NULL){
                        printf("Id Node is empty\n");
                    }
                    else{
                        struct idNode * node = (struct idNode *)data;
                        printf("%s",node->id);
                    }
                }
			struct numIntNode{
				int numInt;
			};
            //methods  
                void * createNumIntNode(int numInt){
                    void * newNode = malloc(sizeof(struct numIntNode));
                    ((struct numIntNode *)newNode)->numInt = numInt;
                    return newNode; 
                }
                void printNumIntNode(void * data){
                    if(data == NULL){
                        printf("NumInt Node is empty\n");
                    }
                    else{
                        struct numIntNode * node = (struct numIntNode *)data;
                        printf("%d",node->numInt);
                    }
                }
			struct numFloatNode{
				double numFloat;
			};
            //methods  
                void * createNumFloatNode(double numFloat){
                    void * newNode = malloc(sizeof(struct numFloatNode));
                    ((struct numFloatNode *)newNode)->numFloat = numFloat;
                    return newNode; 
                }
                void printNumFloatNode(void * data){
                    if(data == NULL){
                        printf("NumFloat Node is empty\n");
                    }
                    else{
                        struct numFloatNode * node = (struct numFloatNode *)data;
                        printf("%lf",node->numFloat);
                    }
                }


//execute section 
struct value{
    int type;
    void * data;
};

void * createValue(int type, void * data){
    void * newVal = malloc(sizeof(struct value));
    ((struct value *)newVal)->type = type;
    ((struct value *)newVal)->data = data;

    return newVal;
}

int getType(void * value){
    return ((struct value *)value)->type;
}

int getInt(void * value){
    return *((int *)((struct value *)value)->data);
}

double getFloat(void * value){
    return *((double *)((struct value *)value)->data);
}

/*int setInt(void * value, int newVal){
    if( ((struct value *)value)->type != 1 ){
        printf("Error: Trying to assign a value that is not int at line %d",__LINE__);
        return 1;
    }
    else{
        *((int *)((struct value *)value)->data) = newVal;
        return 0;
    }
}*/

void executeOptStmts(void *, void *);
void executeStmtLst(void *, void *);
void executeStmt(void *, void *);
void executeAssign(void *, void *);
void executeIf(void *, void *);
void executeIfElse(void *, void *);
void executeRepeat(void *, void *);
void executeWhile(void *, void *);
void executeRead(void *, void *);
void executePrint(void *, void *);

void * executeExpr(void *, void *);
void * executeTerm(void *, void *);
void * executeFactor(void *, void *);
int executeExpression(void *, void *);

void executeOptStmts(void * opt_stms,void * table){
    if(errorFlag != 0) return;
    if(opt_stms == NULL){

    }
    else{
        struct opt_stms * node = (struct opt_stms *)opt_stms;
        executeStmtLst(node->stmt_lst, table);
    }
}

void executeStmtLst(void * stmt_lst,void * table){
    if(errorFlag != 0) return;
    if(stmt_lst == NULL){

    }
    else{
        struct stmt_lst * node = (struct stmt_lst *)stmt_lst;
        executeStmt(node->stmt,table);
        executeStmtLst(node->stmt_lst, table);
    }
}

void executeStmt(void * stmt,void * table){
    if(errorFlag != 0) return;
    if(stmt == NULL){

    }
    else{
        struct stmt * node = (struct stmt *)stmt;
        switch(node->identifier){
            case 1:
                executeAssign(node->stmt_node, table);
            break;
            case 2:
                executeIf(node->stmt_node, table);
            break;
            case 3:
                executeIfElse(node->stmt_node, table);
            break;
            case 4:
                executeRepeat(node->stmt_node, table);
            break;
            case 5:
                executeWhile(node->stmt_node, table);
            break;
            case 6:
                executeRead(node->stmt_node, table);
            break;
            case 7:
                executePrint(node->stmt_node, table);
            break;
        }
    }
}

void executeAssign(void * stmt, void * table){
    if(errorFlag != 0) return;
    struct assignNode * assign = (struct assignNode *)stmt;
    
    //look up the id in the symbols table 
    struct dec * searchRes = (struct dec *)lookUpTable(table,assign->id);

    if(searchRes == NULL){
        errorFlag = 1;
        printf("Error: Symbol \"%s\" not found at line %d\n",assign->id,__LINE__);
        return;
    }
    else{
        //here we have a value struct with the things we need
        struct value * expr =  (struct value *)executeExpr(assign->expr,table);
        if(expr == NULL) return;

        //so we set searchRes->values to the things expr has 
        if(searchRes->type != expr->type){
            errorFlag = 1;
            printf("Error: Data types does not match at line %d\n",__LINE__);
            return;
        }
        searchRes->value = expr->data;

    }
    //busca assign->id en tabla de simbolos
    //si no está, return y dile que valiio madre 
    //si si está, saca lo que retorna expr y ponselo al simbolito
    //falta elaborar expr que necesita term que necesita factor

}

void executeIf(void * stmt, void * table){
    if(errorFlag != 0) return;
    struct ifNode * ifNode = (struct ifNode *)stmt;

    int expression_result = executeExpression(ifNode->expression, table);

    if(expression_result == -1) return;
    else if(expression_result == 0){
        executeOptStmts(ifNode->opt_stms, table);
    }
    else{

    }
}

void executeIfElse(void * stmt, void * table){
    if(errorFlag != 0) return;
    struct ifElseNode * ifElseNode = (struct ifElseNode *)stmt;

    int expression_result = executeExpression(ifElseNode->expression, table);

    if(expression_result == -1) return;
    else if(expression_result == 0){
        executeOptStmts(ifElseNode->opt_stms1, table);
    }
    else{
        executeOptStmts(ifElseNode->opt_stms2, table);
    }
}

void executeWhile(void * stmt, void * table){
    if(errorFlag != 0) return;
    struct whileNode * whileNode = (struct whileNode *)stmt;

    int expression_result = executeExpression(whileNode->expression, table);
    if(expression_result == -1) return;
    while(expression_result == 0){
        executeOptStmts(whileNode->opt_stms, table);
        expression_result = executeExpression(whileNode->expression, table);
        if(expression_result == -1) return;
    }

    if(expression_result == -1) return;

}

void executeRepeat(void * stmt, void * table){
    if(errorFlag != 0) return;
    struct repeatNode * repeatNode = (struct repeatNode *)stmt;
    int expression_result = 0;
    do{
        executeOptStmts(repeatNode->opt_stms, table);
        expression_result = executeExpression(repeatNode->expression, table);
    }while(!(expression_result == 0));

    if(expression_result == -1) return;
}

void executeRead(void * stmt, void * table){
    if(errorFlag != 0) return;
    struct readNode * readNode = (struct readNode *)stmt;

    struct dec * searchRes = (struct dec *)lookUpTable(table,readNode->id);

    if(searchRes == NULL){
        errorFlag = 1;
        printf("Error: Symbol \"%s\" not found at line %d\n",readNode->id,__LINE__);
        return;
    }

    char * input = (char *)malloc(15);

    scanf("%s",input);
    if( strstr(input,".") == NULL ){
        int intVal = atoi(input);
        if(intVal == 0){
            if(strstr(input,"0") == NULL){
                errorFlag = 1;
                printf("Error: Scanned value is not an integer at line %d\n",__LINE__);
                return;
            }
            else{
                //assign that value 
                int * intPtr = (int *)malloc(sizeof(int));
                *intPtr = intVal;
                if(searchRes->type == 1){
                    searchRes->value = (void *)intPtr;
                }
                else{
                    errorFlag = 1;
                    printf("Error: Scanned value does not match symbol type at line %d\n",__LINE__);
                    return;
                }
            }
        }
        else{
            //assign that value 
            int * intPtr = (int *)malloc(sizeof(int));
            *intPtr = intVal;
            if(searchRes->type == 1){
                searchRes->value = (void *)intPtr;
            }
            else{
                errorFlag = 1;
                printf("Error: Scanned value does not match symbol type at line %d\n",__LINE__);
                return;
            }

        }
    }
    else{
        double floatVal = atof(input);
        if(floatVal == 0.0){
            if(strstr(input,"0.0") == NULL){
                errorFlag = 1;
                printf("Error: Scanned value is not an integer at line %d\n",__LINE__);
                return;
            }
            else{
                double * floatPtr = (double *)malloc(sizeof(double));
                *floatPtr = floatVal;
                if(searchRes->type == 2){
                    searchRes->value = (void *)floatPtr;
                }
                else{
                    errorFlag = 1;
                    printf("Error: Scanned value does not match symbol type at line %d\n",__LINE__);
                    return;
                }

            }
        }
        else{
            double * floatPtr = (double *)malloc(sizeof(double));
            *floatPtr = floatVal;
            if(searchRes->type == 2){
                searchRes->value = (void *)floatPtr;
            }
            else{
                errorFlag = 1;
                printf("Error: Scanned value does not match symbol type at line %d\n",__LINE__);
                return;
            }
        }
    }

}

void executePrint(void * stmt, void  * table){
    if(errorFlag != 0) return;
    struct printNode * printNode = (struct printNode *)stmt;

    struct value * result = (struct value *)executeExpr(printNode->expr,table);
    if(result == NULL){

    }
    else{
        if(result->type == 1){
            int intVal = *((int *)result->data);
            printf("%d\n",intVal  );
        }
        else{
            double floatVal = *((double *)result->data);
            printf("%lf\n",floatVal  );
        }
    }
}

void * executeExpr(void * expr, void * table){
    if(errorFlag != 0) return NULL;
    struct expr * cast = (struct expr *)expr;
    
    void * result; 
    if(cast->identifier == 1){ //expr and term
        struct plusNode * data = (struct plusNode *)cast->expr_node;
        void * res1 = executeExpr(data->expr,table);
        void * res2 = executeTerm(data->term,table);
        if(res1 == NULL || res2 == NULL) return NULL;
        if(getType(res1) != getType(res2)){
            errorFlag = 1;
            printf("Error: Data types does not match at line %d\n",__LINE__);
            return NULL;
        }

        if(getType(res1) == 1){
            int * intVal = (int *)malloc(sizeof(int));
            *intVal = (getInt(res1) + getInt(res2));
            result = createValue(1,(void *)intVal);
        }
        else{
            double * floatVal = (double *)malloc(sizeof(double));
            *floatVal = (getFloat(res1) + getFloat(res2));
            result = createValue(2,(void *)floatVal);
        }
        
        
    }
    else if(cast->identifier == 2){
        struct minusNode * data = (struct minusNode *)cast->expr_node;
        void * res1 = executeExpr(data->expr,table);
        void * res2 = executeTerm(data->term,table);
        if(res1 == NULL || res2 == NULL) return NULL;

        if(getType(res1) != getType(res2)){
            errorFlag = 1;
            printf("Error: Data types does not match at line %d\n",__LINE__);
            return NULL;
        }

        if(getType(res1) == 1){
            int * intVal = (int *)malloc(sizeof(int));
            *intVal = (getInt(res1) - getInt(res2));
            result = createValue(1,(void *)intVal);
        }
        else{
            double * floatVal = (double *)malloc(sizeof(double));
            *floatVal = (getFloat(res1) - getFloat(res2));
            result = createValue(2,(void *)floatVal);
        }
    }
    else{
        struct termExprNode * data = (struct termExprNode *)cast->expr_node;
        result = executeTerm(data->term,table);

    }

    return result;
}

void * executeTerm(void * term, void * table){
    if(errorFlag != 0) return NULL;
    struct term * cast = (struct term *)term;
    
    void * result; 
    if(cast->identifier == 1){ //expr and term
        struct multiplyNode * data = (struct multiplyNode *)cast->term_node;
        void * res1 = executeTerm(data->term,table);
        void * res2 = executeFactor(data->factor,table);
        if(res1 == NULL || res2 == NULL) return NULL;
        if(getType(res1) != getType(res2)){
            errorFlag = 1;
            printf("Error: Data types does not match at line %d\n",__LINE__);
            return NULL;
        }

        if(getType(res1) == 1){
            int * intVal = (int *)malloc(sizeof(int));
            *intVal = (getInt(res1) * getInt(res2));
            result = createValue(1,(void *)intVal);
        }
        else{
            double * floatVal = (double *)malloc(sizeof(double));
            *floatVal = (getFloat(res1) * getFloat(res2));
            result = createValue(2,(void *)floatVal);
        }
        
        
    }
    else if(cast->identifier == 2){
        struct divideNode * data = (struct divideNode *)cast->term_node;
        void * res1 = executeTerm(data->term,table);
        void * res2 = executeFactor(data->factor,table);
        if(res1 == NULL || res2 == NULL) return NULL;
        if(getType(res1) != getType(res2)){
            errorFlag = 1;
            printf("Error: Data types does not match at line %d\n",__LINE__);
            return NULL;
        }

        if(getType(res1) == 1){
            int * intVal = (int *)malloc(sizeof(int));
            *intVal = (getInt(res1) / getInt(res2));
            result = createValue(1,(void *)intVal);
        }
        else{
            double * floatVal = (double *)malloc(sizeof(double));
            *floatVal = (getFloat(res1) / getFloat(res2));
            result = createValue(2,(void *)floatVal);
        }
    }
    else{
        struct factorTermNode * data = (struct factorTermNode *)cast->term_node;
        result = executeFactor(data->factor,table);

    }

    return result;
}

void * executeFactor(void * factor, void * table){
    if(errorFlag != 0) return NULL;
    struct factor * cast = (struct factor *)factor;   
    void * result = NULL;
    switch(cast->identifier){
        case 1:{
            struct exprFactorNode * data = (struct exprFactorNode *)cast->factor_node;
            result = executeExpr(data->expr,table);
            break;
        }
        case 2:{
            struct idNode * data = (struct idNode *)cast->factor_node;

            //returns void * dec 
            struct dec * searchResult = (struct dec *)lookUpTable(table,data->id);

            //value not declared
            if(searchResult == NULL){
                errorFlag = 1;
                printf("Error: Symbol \"%s\" not found at line %d\n",data->id,__LINE__);
                return NULL;
            }
            //value not initialized
            if(searchResult->value == NULL){
                errorFlag = 1;
                printf("Error: Symbol \"%s\" was not initialized at line %d\n",data->id,__LINE__);
                return NULL;
            }
            result = createValue(searchResult->type, searchResult->value);
            
            break;
        }
        break;
        case 3:{
            struct numIntNode * data = (struct numIntNode *)cast->factor_node;
            int * intVal = (int *)malloc(sizeof(int));
            *intVal = data->numInt;
            result = createValue(1,(void *)intVal);
            break;
        }
        break;
        case 4:{
            struct numFloatNode * data = (struct numFloatNode *)cast->factor_node;
            double * floatVal = (double *)malloc(sizeof(double));
            *floatVal = data->numFloat;
            result = createValue(2,(void *)floatVal);
            break;
        }
        break;
        default:
            printf("This was not supposed to happen...\n");
        break;
        
    }

    return result;
}

// | -1 error | 0 true  | 1 false | 
int executeExpression(void * expression, void * table){
    if(errorFlag != 0) return -1;
    struct expression * cast = (struct expression *)expression;

    switch(cast->identifier){
        case 1:{ //<
            struct lessThanNode * data = (struct lessThanNode *)cast->expression_node;

            struct value * res1 = (struct value *)executeExpr(data->expr1,table);
            struct value * res2 = (struct value *)executeExpr(data->expr2,table);

            if(res1->type != res2->type){
                errorFlag = 1;
                printf("Error: Types at comparison do not match at line %d\n", __LINE__);
                return -1;
            }

            if(res1->type == 1){
                int val1 = *(int *)res1->data;
                int val2 = *(int *)res2->data;

                if(val1 < val2){
                    return 0;
                }
                else{
                    return 1;
                }
            }
            else{
                double val1 = *(double *)res1->data;
                double val2 = *(double *)res2->data;

                if(val1 < val2){
                    return 0;
                }
                else{
                    return 1;
                }
            }
            break;
        }
        case 2:{// >
            struct moreThanNode * data = (struct moreThanNode *)cast->expression_node;

            struct value * res1 = (struct value *)executeExpr(data->expr1,table);
            struct value * res2 = (struct value *)executeExpr(data->expr2,table);

            if(res1->type != res2->type){
                errorFlag = 1;
                printf("Error: Types at comparison do not match at line %d", __LINE__);
                return -1;
            }

            if(res1->type == 1){
                int val1 = *(int *)res1->data;
                int val2 = *(int *)res2->data;

                if(val1 > val2){
                    return 0;
                }
                else{
                    return 1;
                }
            }
            else{
                double val1 = *(double *)res1->data;
                double val2 = *(double *)res2->data;

                if(val1 > val2){
                    return 0;
                }
                else{
                    return 1;
                }
            }
            break;
        }
        case 3:{// =
            struct equalsNode * data = (struct equalsNode *)cast->expression_node;

            struct value * res1 = (struct value *)executeExpr(data->expr1,table);
            struct value * res2 = (struct value *)executeExpr(data->expr2,table);

            if(res1->type != res2->type){
                errorFlag = 1;
                printf("Error: Types at comparison do not match at line %d", __LINE__);
                return -1;
            }

            if(res1->type == 1){
                int val1 = *(int *)res1->data;
                int val2 = *(int *)res2->data;

                if(val1 == val2){
                    return 0;
                }
                else{
                    return 1;
                }
            }
            else{
                double val1 = *(double *)res1->data;
                double val2 = *(double *)res2->data;

                if(val1 == val2){
                    return 0;
                }
                else{
                    return 1;
                }
            }
            break;
        }
        default:{
            printf("This was not supposed to happen\n");
            return -1;
            break;
        }
    }
}