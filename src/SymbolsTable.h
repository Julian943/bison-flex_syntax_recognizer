
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Gramatic structure

void printDecls(void *);
void printDec(void *);

void * lookUpTable(void *, char *);
void * searchId(void *, char *);


struct opt_decls{
    void * decls;
};
    //methods
    void * createOptDecls(void * decls){
        void * newOptDecls = malloc(sizeof(struct opt_decls));
        ((struct opt_decls *)newOptDecls)->decls = decls;;

        return newOptDecls;
    }

    void printOptDecls(void * opt_decls){
        if(opt_decls == NULL){

        }
        else{
            printf("Symbols table:\n");
            struct opt_decls * node = (struct opt_decls *)opt_decls;
            printDecls(node->decls);
            printf("Done\n\n");
        }
    }

struct decls{
    void * dec;
    void * decls;
};
    //methods 
    void * createDecls(void * dec, void * decls){
        void * newDecls = malloc(sizeof(struct decls));
        ((struct decls *)newDecls)->dec = dec;
        ((struct decls *)newDecls)->decls = decls;

        return newDecls;
    }

    void printDecls(void * decls){
        if(decls == NULL){

        }
        else{
            struct decls * node = (struct decls *)decls;
            printDec(node->dec);
            printDecls(node->decls);
        }
    }

struct dec{
    char * id;
    int type;
    void * value;
};
    //methods
    void * createDec(char * id, int type){
        void * newDec = malloc(sizeof(struct dec));
        ((struct dec *)newDec)->type = type;
        ((struct dec *)newDec)->id = (char *)malloc(strlen(id));
        ((struct dec *)newDec)->value = NULL;
        strcpy(((struct dec *)newDec)->id,id);

        return newDec;
    }

    void printDec(void * dec){
        struct dec * node = (struct dec *)dec;
        if(node->type == 1){
            printf("int ");
        }
        else{
            printf("double ");
        }
        printf("%s ",node->id);
        if(node->value == NULL){
            printf("No data\n");
        }
        else{
            if(node->type == 1){
                printf("%d\n", *((int *)node->value));
            }
            else{
                printf("%lf\n", *((double *)node->value));
            }
        }
    }

//search utilities

void * lookUpTable(void * void_table, char * id){
    struct opt_decls * table = (struct opt_decls *)void_table;
    if(table == NULL){
        printf("\n");
        return NULL;
    }
    else{
        if(table->decls == NULL){
            return NULL;
        }
        else{
            return searchId(table->decls, id);
        }
    }
}

void * searchId(void * decls, char * id){
    struct decls * table = (struct decls *)decls;
    if(table == NULL){
        return NULL;
    }
    else{
        struct dec * dec = (struct dec *)table->dec;
        if( strcmp(dec->id,id) == 0 ){
            return table->dec;
        }
        else{
            return searchId(table->decls,id);
        }
    }
}