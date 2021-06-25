#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    struct node* next;
} node;

void addnode(int);
void deletefirstnode();
void printlist();
void deletelastnde();

node* start = NULL;

int main()
{




    return 0;
}

void deletelastnode(){

    node* ptr = start;
    if(start == NULL){
        printf("\nKeine Liste vorhanden.\n");
        return;
    }
    else if(start->next == NULL){
        free(start);
        start = NULL;
    }
    else{

    }
}

void deletefirstnode(){

    if(start == NULL){
        printf("\nerror");
        return;
    }
    else if(start->next == NULL){
        free(start);
        start = NULL;
        printf("\nListe ist nun leer.\n");
        return;
    }
    else{
        node* ptr = start;
        start = start->next;
        free(ptr);
        return;
    }
}

void addnode(int addkey){

    node* ptr = start;
    if(ptr == NULL){
        ptr = (node*) malloc(sizeof(node));
        ptr->key = addkey;
        ptr->next = NULL;
        start = ptr;
        return;
    }
    else{
        node* tmp;
        tmp = (node*) malloc(sizeof(node));
        if(tmp == NULL){
            printf("\nerror");
            return;
        }
        tmp->key = addkey;
        tmp->next = NULL;
        start->next = tmp;
        return;
    }
}

void printlist(){

    node* ptr;
    ptr = start;
    while(ptr != NULL){
        int i = 1;
        printf("\nnode-key an der stelle %d: %d", i, ptr->key);
        i++;
        ptr = ptr->next;
    }
}
