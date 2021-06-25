#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct item{
    char itemname[20];
    int weight;
} item;

typedef struct backpack{
    int maxweight;
    int maxitems;
} backpack;

typedef struct invelement{
    item* item;
    struct invelement* next;
    struct invelement* prev;
} invelement;

typedef struct inventory{
    backpack* invbackpack;
    invelement* first;
    invelement* last;
} inventory;

inventory* createinventar(backpack*);
void printinventar(inventory*);
void countggstundgew(inventory*, int*, int*);
void addgegenstand(inventory*, item*);
void removegegenstand(inventory*, item*);
void changerucksack(inventory*, backpack*);


int main()
{
    system("chcp 1252");
    
    item axt = {"Axt", 5};
    item stab = {"Zauberstab", 3};
    item helm = {"Stahlhelm", 7};
    
    backpack rucksack = {30,6};
    backpack kleinerrucksack = {10,3};
    inventory *inventar = createinventar(&rucksack);
    
    printinventar(inventar);
    addgegenstand(inventar,&stab);
    addgegenstand(inventar,&axt);
    addgegenstand(inventar,&helm);
    printinventar(inventar);
    
    removegegenstand(inventar,&helm);
    printinventar(inventar);

    addgegenstand(inventar,&axt);
    addgegenstand(inventar,&helm);
    addgegenstand(inventar,&stab);

    printinventar(inventar);
    
    removegegenstand(inventar,&stab);
    
    printinventar(inventar);
    
    changerucksack(inventar,&kleinerrucksack);

    printinventar(inventar);

    return 0;
}

void changerucksack(inventory* inv, backpack *changeback){

    inv->invbackpack = changeback;

    int anz, gew;
    countggstundgew(inv,&anz,&gew);

    while(anz > inv->invbackpack->maxitems){
                invelement *tmp = inv->last;
                inv->last = tmp->prev;
                inv->last->next = NULL;
                free(tmp);
                printf("\n\nZu viele Gegenst�nde. Das letzte Element wurde gelöscht.");
                countggstundgew(inv,&anz,&gew);
    }

    while(gew > inv->invbackpack->maxweight){
                invelement *tmp = inv->last;
                inv->last = tmp->prev;
                inv->last->next = NULL;
                free(tmp);+
                printf("\n\nZu schwer. Das letzte Element wurde gelöscht.");
                countggstundgew(inv,&anz,&gew);
    }

}

void removegegenstand(inventory *inv, item* searchitem){

    invelement *tmp = inv->first;
    if(tmp == NULL){
        printf("\nDas Inventar ist leer.");
        return;
    }

    int counter = 1;
    do{
        if(tmp->item == searchitem){
            if(tmp->prev == NULL && tmp->next == NULL){
                inv->first = NULL;
                inv->last = NULL;
                free(tmp);
                printf("\n\nDas Element an Stelle: %d wurde gelöscht.", counter);
            }
            else if(tmp->prev != NULL && tmp->next == NULL){
                inv->last = tmp->prev;
                inv->last->next = NULL;
                free(tmp);
                printf("\n\nDas letzte Element wurde gelöscht.");
            }
            else if(tmp->prev == NULL && tmp->next != NULL){
                inv->first = tmp->next;
                inv->first->prev = NULL;
                free(tmp);
                printf("\n\nDas erste Element wurde gelöscht.");
            }
            return;
        }
        counter++;
        tmp = tmp->next;
    } while(tmp != NULL);

}

void addgegenstand(inventory *inv, item *item){

    int anz, gew;
    countggstundgew(inv, &anz, &gew);
    if(((gew + item->weight) <= inv->invbackpack->maxweight) && ((anz + 1) <= inv->invbackpack->maxitems)){
            invelement *tmp = (invelement*) malloc(sizeof(invelement));
            if(tmp == NULL){
                printf("\Es konnte kein neues Element erzeugt werden.");
                exit(-1);
            }
            tmp->item = item;
        if(inv->first == NULL){
            tmp->prev = NULL;
            tmp->next = NULL;
            inv->first = tmp;
            inv->last = tmp;
        }
        else{
            tmp->prev = inv->last;
            tmp->next = NULL;
            inv->last->next = tmp;
            inv->last = tmp;
        }
    }
    else{
        printf("\nGegenstand konnte nicht hinzugefügt werden.");
    }
}

void countggstundgew(inventory *inv, int *anz, int *gew){

    *gew = 0;
    *anz = 0;
    invelement *tmp = inv->first;
    while(tmp != NULL){
        *gew += tmp->item->weight;
        *anz += 1;
        tmp = tmp->next;
    }
}

inventory* createinventar(backpack* rucksack){

    inventory* newinv = (inventory*) malloc(sizeof(inventory));
    newinv->invbackpack = rucksack;
    newinv->first = NULL;
    newinv->last = NULL;

    return newinv;
}

void printinventar(inventory *inv){

    int gew, anz;
    countggstundgew(inv, &anz, &gew);
    printf("\n\n*** Inventar ***\nRucksack:\n");
    printf("          Gewicht: %d von %d\n", gew, inv->invbackpack->maxweight);
    printf("          Anzahl: %d von %d", anz, inv->invbackpack->maxitems);
    printf("\nInhalt:");

    if(inv->first == NULL){
        printf("\n          Der Rucksack ist Leer.");
    }

    else{
        invelement* tmp = inv->first;
        do{
        printf("\n          %s", tmp->item->itemname);
        tmp = tmp->next;
        } while(tmp != NULL);
    }
}


