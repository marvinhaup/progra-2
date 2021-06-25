#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Enumerations

typedef enum { head, neck, armor, lefthand, righthand, foot} itemposition;
typedef enum { wall, north, south, east, west} orientierung;

// Structs

typedef struct {
    char name[26];
    itemposition position;
    float weight;
    int value;
    int lp_change;
} item;

typedef struct {
    char name[21];
    int lp;
    int staerke;
    int seitenzahl;
    item dropitem;
} monster;

typedef struct room;

typedef struct {
    char name[26];
    int lpchange;
    monster *rmonster;
    item *rtreasure;
    Room *
} room;

typedef struct {
    char name[26];
    int lifepoints;
    item itemslots[7];
    item inventory[11];
    room *currentroom;
} hero;

// global Variables

item NOTHING = {"Leer", head, 0, 0};
room WALL = {"Wand", NULL, 0, NULL, NULL};
item* trasures;

// Functions

void wearitem(hero*, item*);
void printitem(item*);
void printhero(hero*);
void printmonster(monster*);
void monsterAddLoot(monster*, item*);
int addtoinventory(hero*, item*);
int rolldice(int*);
item* createitem(char[], itemposition, float, int, int);
hero* createhero(char[], int);
monster* createmonster(char[], int, int, int);
room* createroom(char[], int, monster*, item*);

int main()
{
    NOTHING = createitem("Leer", 0, 0, 0, 0);
    WALL = createroom()

    int seiten;
    printf("\nWie viele seiten hat ihr Wuerfel: ");
    scanf("%d", &seiten);
    printf("\n%d", rolldice(&seiten));

    item *holzschwert = createitem("holzschwert", righthand, 2.50, 30, 0);
    printitem(holzschwert);

    item *eisenschild = createitem("eisenschild", lefthand, 5.0, 20, 0);

    hero *hero1 = createhero("zelda", 10);
    printhero(hero1);

    wearitem(hero1, holzschwert);
    printhero(hero1);
    item *eisenschwert = createitem("eisenschwert", righthand, 5.0, 40, -2);
    wearitem(hero1,eisenschwert);
    printhero(hero1);
    item *heiltrank = createitem("heiltrank", 0, 0, 0, 5);
    addtoinventory(hero1,heiltrank);
    printhero(hero1);

    monster *zombie = createmonster("zombie", 3, 4, 6);
    monster *magier = createmonster("magier", 5, 2, 8);
    monsterAddLoot(magier,heiltrank);
    printmonster(zombie);
    printmonster(magier);



    free(eisenschwert);
    free(eisenschild);
    free(holzschwert);
    free(NOTHING);
    return 0;
}

// Liefert einen Pointer auf den im Heap befindlichen Room zurück.
room* createroom(char rname[], int lpdiff, monster *rmonster, item *ritem){

    room *newroom = malloc(sizeof(room));
    strcpy(newroom->name,rname);
    newroom->lpchange = lpdiff;
    newroom->rmonster = rmonster;
    newroom->rtreasure = ritem;
    r->rooms[north] = &WALL;
    r->rooms[east] = &WALL;
    r->rooms[south] = &WALL;
    r->rooms[west] = &WALL;

    return newroom;
}

monster* createmonster(char monstername[], int lp, int stk, int szahl){

    monster *newmonster = malloc(sizeof(monster));
    strcpy(newmonster->name,monstername);
    newmonster->lp = lp;
    newmonster->staerke = stk;
    newmonster->seitenzahl = szahl;
    strcpy(newmonster->dropitem.name,NOTHING->name);
    newmonster->dropitem.lp_change = NOTHING->lp_change;
    newmonster->dropitem.position = NOTHING->position;
    newmonster->dropitem.value = NOTHING->value;
    newmonster->dropitem.weight = NOTHING->weight;

    return newmonster;
}

void printmonster(monster *mptr){

    printf("\n***** Monster-Info *****");
    printf("\nName: %s \nLebenspunte: %d\nStaerke: %d\nwuerfel: %d-seitig\nloot: %s", mptr->name, mptr->lp, mptr->staerke, mptr->seitenzahl, mptr->dropitem.name);
    printf("\n************************");
}

void monsterAddLoot(monster *mptr, item *itemptr){

    strcpy(mptr->dropitem.name,itemptr->name);
    mptr->dropitem.lp_change = itemptr->lp_change;
    mptr->dropitem.position = itemptr->position;
    mptr->dropitem.value = itemptr->value;
    mptr->dropitem.weight = itemptr->weight;
}

void wearitem(hero *heroptr, item *itemptr){

    if(strcmp(heroptr->itemslots[itemptr->position].name,"Leer") == 0){
        strcpy(heroptr->itemslots[itemptr->position].name,itemptr->name);
        heroptr->itemslots[itemptr->position].position = itemptr->position;
        heroptr->itemslots[itemptr->position].weight = itemptr->weight;
        heroptr->itemslots[itemptr->position].value = itemptr->value;
        heroptr->itemslots[itemptr->position].lp_change = itemptr->lp_change;
        printf("\nItem wurde in Slot %d angelegt.", itemptr->position);
    }
    else if(addtoinventory(heroptr, &heroptr->itemslots[itemptr->position]) == 1){

        printf("\nAltes Item ist nun im Inventar.");
        strcpy(heroptr->itemslots[itemptr->position].name,itemptr->name);
        heroptr->itemslots[itemptr->position].position = itemptr->position;
        heroptr->itemslots[itemptr->position].weight = itemptr->weight;
        heroptr->itemslots[itemptr->position].value = itemptr->value;
        heroptr->itemslots[itemptr->position].lp_change = itemptr->lp_change;
        printf("\nNeues Item wurde im Slot %d angelegt.", itemptr->position);
    }
    else{
        printf("\nEs ist weder Platz im Slot %d, noch inventar.\n", itemptr->position);
    }
}

int addtoinventory(hero *heroptr, item *itemptr){

    int erg = -1;
    for(int i = 0; i < 10; i++){
        if(strcmp(heroptr->inventory[i].name,"Leer") == 0){
            strcpy(heroptr->inventory[i].name,itemptr->name);
            heroptr->inventory[i].position = itemptr->position;
            heroptr->inventory[i].weight = itemptr->weight;
            heroptr->inventory[i].value = itemptr->value;
            heroptr->inventory[i].lp_change = itemptr->lp_change;
            erg = 1;
            printf("\nDas item wurde an stelle %d im iventar abgelegt\n", i);
            break;
        }

    }
    if(erg == -1){
        printf("\nes war kein platz im inventar\n");
    }
    return erg;
}

hero *createhero(char name[], int lp){

    hero *newhero = malloc(sizeof(hero));
    strcpy(newhero->name,name);
    newhero->lifepoints = lp;
    for(int i = 0; i < 6; i++){
        strcpy(newhero->itemslots[i].name,NOTHING->name);
        newhero->itemslots[i].position = NOTHING->position;
        newhero->itemslots[i].weight = NOTHING->weight;
        newhero->itemslots[i].value = NOTHING->value;
        newhero->itemslots[i].lp_change = NOTHING->lp_change;
    }
    for(int i = 0; i < 10; i++){
        strcpy(newhero->inventory[i].name,NOTHING->name);
        newhero->inventory[i].position = NOTHING->position;
        newhero->inventory[i].weight = NOTHING->weight;
        newhero->inventory[i].value = NOTHING->value;
        newhero->inventory[i].lp_change = NOTHING->lp_change;
    }
    return newhero;
}

void printhero(hero *heroptr){

    printf("\n***** Helden-Info *****");
    printf("\nName: %s", heroptr->name);
    printf("\nLebenspunkte: %d", heroptr->lifepoints);
    printf("\nSlots:");
    printf("\n      Kopf: %s", heroptr->itemslots[0].name);
    printf("\n      Hals: %s", heroptr->itemslots[1].name);
    printf("\n      Ruestung: %s", heroptr->itemslots[2].name);
    printf("\n      Linke Hand: %s", heroptr->itemslots[3].name);
    printf("\n      Rechte Hand: %s", heroptr->itemslots[4].name);
    printf("\n      Fuesse: %s", heroptr->itemslots[5].name);
    printf("\nInventar:");
    for(int i = 0; i < 10; i++){
        printf("\n      %d. Item: %s", i+1, heroptr->inventory[i].name);
    }
}

item* createitem(char name[], itemposition pos, float gew, int wert, int lpdiff){

    item *newitem = malloc(sizeof(item));
    strcpy(newitem->name,name);
    newitem->position = pos;
    newitem->weight = gew;
    newitem->value = wert;
    newitem->lp_change = lpdiff;

    return newitem;
}

void printitem(item *itemptr){

    printf("\n***** Gegenstands-Info *****");
    printf("\nName: %s", itemptr->name);
    printf("\nPosition: %d", itemptr->position);
    printf("\nGewicht: %.2f", itemptr->weight);
    printf("\nWert: %d", itemptr->value);
    printf("\nVeraenderung: %d", itemptr->lp_change);
    printf("\n***************************");
}

int rolldice(int *seiten){

    srand (time(NULL));
    int erg = rand() % *seiten + 1;

    return erg;
}
