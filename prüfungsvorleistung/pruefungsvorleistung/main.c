#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef enum { head = 1, neck, armor, lefthand, righthand, foot} itemposition;
typedef enum { north, south, east, west} orientation;

typedef struct {
    char name[26];
    itemposition pos;
    float weight;
    int value;
    int lp_change;
} item;

typedef struct{
    char name[26];
    int lifepoints;
    item itemslots[7];
    item inventory[11];
} hero;

typedef struct{
    char name[21];
    int lifepoints;
    int staerke;
    int wuerfelwert;
    item dropitem;
} monster;

typedef struct{
    char name[26];
    int sideroom[5];
    int lpdiff;
    monster monst;
    item schatz;
} room;

// global variables
item NOTHING;
room wall;

void printitem(item);
hero createhero(char[], int);
item createitem(char[], itemposition, float, int, int);
int rolldice(int);
void wearitem(hero*, item);
int addtoinventory(hero*, item);
monster createmonster(char[], int, int, int, item);
void monsteraddloot(monster*, item);
void printmonster(monster*);


int main(){

    NOTHING = createitem("LEER", 0, 0, 0, 0);
    item eisenschild = createitem("eisenschild", lefthand, 5.0, 20, 0);
    item holschwert = createitem("holzschwert", righthand, 2.5, 30, 0);
    item eisenschwert = createitem("eisenschwert", righthand, 3.0, 35, -1);

    printitem(eisenschild);
    hero hero1 = createhero("Zelda", 10);
    printhero(hero1);
    wearitem(&hero1,holschwert);
    printhero(hero1);
    wearitem(&hero1,eisenschwert);

    item heiltrank = createitem("heiltrank", 0, 0, 0, 5);
    addtoinventory(&hero1,heiltrank);
    printhero(hero1);

    monster zombie = createmonster("zombie", 3, 4, 6, NOTHING);
    monster magier = createmonster("magier", 5, 2, 8, NOTHING);
    monsteraddloot(&magier,heiltrank);
    printmonster(&zombie);
    printmonster(&magier);

    return 0;
}

void printmonster(monster *pmonster){
    printf("\n***** Monster-Info *****");
    printf("\nName: %s", pmonster->name);
    printf("\nLebenspunkte: %d", pmonster->lifepoints);
    printf("\nStaerke: %d", pmonster->staerke);
    printf("\nWuerfel: %d-seitig", pmonster->wuerfelwert);
    printf("\nLoot: %s", pmonster->dropitem.name);
    printf("\n*************************************\n");
}

void monsteraddloot(monster *modmonster, item additem){
    strcpy(modmonster->dropitem.name,additem.name);
    modmonster->dropitem.pos = additem.pos;
    modmonster->dropitem.weight = additem.weight;
    modmonster->dropitem.value = additem.value;
    modmonster->dropitem.lp_change = additem.lp_change;
}

monster createmonster(char name[], int lp, int staerke, int ww, item item1){

    monster newmonster;
    strcpy(newmonster.name,name);
    newmonster.lifepoints = lp;
    newmonster.staerke = staerke;
    newmonster.wuerfelwert = ww;
    strcpy(newmonster.dropitem.name,NOTHING.name);
    newmonster.dropitem.pos = NOTHING.pos;
    newmonster.dropitem.weight = NOTHING.weight;
    newmonster.dropitem.value = NOTHING.value;
    newmonster.dropitem.lp_change = NOTHING.lp_change;

    return newmonster;
}

int addtoinventory(hero *heroptr, item ggst){

    int erg = -1;
    for(int i = 0; i < 10; i++){
        if(strcmp(heroptr->inventory[i].name,"LEER") == 0){
        strcpy(heroptr->inventory[i].name,ggst.name);
        heroptr->inventory[i].pos = ggst.pos;
        heroptr->inventory[i].weight = ggst.weight;
        heroptr->inventory[i].value = ggst.value;
        heroptr->inventory[i].lp_change = ggst.lp_change;
        erg = 1;
        break;
        }
    }
    if(erg == -1){
        printf("\nEs ist kein Platz im Inventar");
    }

    return erg;
}

void wearitem(hero *heroptr, item ggst){

    int i = ggst.pos;
    if(strcmp(heroptr->itemslots[i].name,"LEER") == 0){
        strcpy(heroptr->itemslots[i].name,ggst.name);
        heroptr->itemslots[i].pos = ggst.pos;
        heroptr->itemslots[i].weight = ggst.weight;
        heroptr->itemslots[i].value = ggst.value;
        heroptr->itemslots[i].lp_change = ggst.lp_change;
    }
    else{
        printf("\nItem anlegen fehlgeschlagen, Slot schon belegt.");
    }
}

int rolldice(int seiten){

    srand (time(NULL));
    int wurf = rand() % seiten +1;
    return wurf;
}

void printitem(item item1){

    printf("\n***** Gegenstands-Info *****");
    printf("\nName: %s", item1.name);
    printf("\nPosition: %d", item1.pos);
    printf("\nGewicht: %.2f", item1.weight);
    printf("\nWert: %d", item1.pos);
    printf("\nVeraenderung LP: %d", item1.lp_change);
    printf("\n****************************");
}

void printhero(hero hero1){

    printf("\n***** Helden-Info *****");
    printf("\nName: %s", hero1.name);
    printf("\nLebenspunkte: %d", hero1.lifepoints);
    printf("\nSlots: ");
    printf("\n      Kopf: %s", hero1.itemslots[1].name);
    printf("\n      Hals: %s", hero1.itemslots[2].name);
    printf("\n      Ruestung: %s", hero1.itemslots[3].name);
    printf("\n      Linke Hand: %s", hero1.itemslots[4].name);
    printf("\n      Rechte Hand: %s", hero1.itemslots[5].name);
    printf("\n      Fuesse: %s", hero1.itemslots[6].name);
    printf("\nInventar: ");
    for(int i = 0; i < 10; i++){
        printf("\n      %d. Item: %s", i+1, hero1.inventory[i].name);
    }
    printf("\n*****************************");
}

item createitem(char name[], itemposition pos, float gew, int wert, int difflp){

    item newitem;
    strcpy(newitem.name,name);
    newitem.pos = pos;
    newitem.weight = gew;
    newitem.value = wert;
    newitem.lp_change = difflp;

    return newitem;
}

hero createhero(char name[], int lp){

    hero newhero;
    strcpy(newhero.name,name);
    newhero.lifepoints = lp;
    for(int i = 0; i <  7; i++){
        newhero.itemslots[i] = NOTHING;
    }
    for(int i = 0; i < 11; i++){
        newhero.inventory[i] = NOTHING;
    }
    return newhero;
}
