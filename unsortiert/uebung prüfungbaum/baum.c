#include <stdio.h>
#include <stdlib.h>
//#define 

typedef enum position {links,rechts};

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
} node;

node* createstammbaum(int);
void addstammbaum(int,int,int,node*);
node* sucheknoten(int,node*);
int countnodes(node*);

int main(){

    int x = 5;
    node* root = createstammbaum(x);
    addstammbaum(3,5,links,root);
    addstammbaum(4,5,rechts,root);
    addstammbaum(6,3,links,root);
    addstammbaum(7,3,rechts,root);
    addstammbaum(2,4,links,root);
    addstammbaum(1,4,rechts,root);
    
    printf("\n\n%d", root->left->left->data);
    printf("\n\n%d", root->left->right->data);
    printf("\n\nanzahl kinder: %d", countnodes(root));

    return 0;
}

int countnodes(node* wurzel){
    static int count = 0;

    if(wurzel == NULL){
        return;
    }
    else{
        count++;
    }
    countnodes(wurzel->left);
    countnodes(wurzel->right);
    return count;
}

node* createstammbaum(int d){

    node* new = (node*) malloc(sizeof(node));
    new->data = d;
    new->left = NULL;
    new->right = NULL;
    return new;
}

void addstammbaum(int einf,int ziel,int pos,node* wurzel){

    if(wurzel == NULL){
        printf("\nEs gibt keinen Stammbaum.\n");
        return;
    }
    node* newelem = (node*) malloc(sizeof(node));
    newelem->data = einf;
    newelem->left = NULL;
    newelem->right = NULL;

    if(wurzel->data == ziel){
        if(pos == 0){
            wurzel->left = newelem;
        }    
        else{
            wurzel->right = newelem;
        }
    }
    node* tmp = sucheknoten(ziel, wurzel);
        if (tmp != NULL){
            if(pos == 0){
            tmp->left = newelem;
            }    
            else{
                tmp->right = newelem;
            }
        }
}

node* sucheknoten(int gesucht,node *wurzel){
    if(wurzel == NULL){
        return NULL;
    }
    if(wurzel->data == gesucht){
        return wurzel;
    }
    node* loesunglinks = sucheknoten(gesucht, wurzel->left);
    node* loseungrechts = sucheknoten(gesucht, wurzel->right);
    if(loesunglinks != NULL){
        return loesunglinks;
    }
    else if(loseungrechts != NULL){
        return loseungrechts;
    }
    return NULL;
}