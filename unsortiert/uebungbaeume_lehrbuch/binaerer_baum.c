#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char name[30];
    int number;
    struct *node; 
    struct *node;
} node;

const int leftnumber = 1;
const int rightnumber = 2;
node *rootpointer;

int calcnodenum(node*,int,int);
node* insertnode(node*, char*);
node* serachnode(node*, char*);
void printnode(node*);
void deletenode(node*);

int main(void){
    
    char buffer[30];
    node *new;
    node *ptr;
    printf("\n\nLese nun Knoten ein, (Abbruch mit $).\nGib den ersten Knoten ein: ");
    while (fgets(buffer,30,stdin) != NULL)
    {
        
    }
    


    return 0;
}






