#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node *next;
} node;


node* createlist(int);
void addbeginning(node*,int);
void addending(node*,int);
void printlist(node*);
void deletefirst(node*);
node* sucher(node*,int);
void deletenode(node*, int);


int main(){

    node *mylist = createlist(5);
    addbeginning(mylist, 4);
    addbeginning(mylist, 3);
    addbeginning(mylist, 2);
    addbeginning(mylist, 1);

    addending(mylist,6);
    addending(mylist,7);
    addending(mylist,8);
    addending(mylist,9);

    deletefirst(mylist);
    deletefirst(mylist);

    printlist(mylist);
    
    free(mylist);

    return 0;
}

node* createlist(int val){

    node *newlist = (node*) malloc(sizeof(node));
    newlist->value = val;
    newlist->next = NULL;
    return newlist;
}

void addbeginning(node *list, int val){
    node *newelem = (node*) malloc(sizeof(node));
    newelem->next = list->next;
    list->next = newelem;
    newelem->value = list->value;
    list->value = val;
}

void addending(node *list, int val){
    node* newelem = (node*) malloc(sizeof(node));
    newelem->value = val;
    newelem->next = NULL;
    node* tmp = list;
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = newelem;
}

void printlist(node* list){
    node *tmp = list;
    int counter = 0;
    while(tmp != NULL){
        printf("\nWert der Liste an der Stelle %d: %d", counter, tmp->value);
        counter++;
        tmp = tmp->next;
    }
}

void deletefirst(node* list){
    node *tmp = list;
    list = list->next;
    free(tmp);
}

node* sucher(node* list, int val){
    node* tmp = list;
    while(tmp != NULL && tmp->value != val){
        tmp = tmp->next;
    }
    return tmp;
}

void deletenode(node* list, int val){
    node* snode


}
