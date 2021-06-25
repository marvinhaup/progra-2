#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//{ Aufz�hlungen
enum EItemPosition { head, neck, armor, rightHand, leftHand, foot };
enum EDirection { north, east, south, west };
//}

//{ Strukturen
struct Room;
typedef struct Room Room;

typedef struct {
	char name[26];
	enum EItemPosition pos;
	float weight;
	int value;
	int lp_change;
} Item;

typedef struct {
	char name[26];
	int lp;
	Item** slots;
	Item** inventory;
	Room *room;
} Hero;

typedef struct {
	char name[21];
	int lp;
	int strength;
	int dice;
	Item* loot;
} Monster;

typedef struct Room{
	char name[26];
	Room** rooms;
	int lp_change;
	Monster* m;
	Item* treasure;
}Room;
//}



//{ Funktionsprototypen
int rollDice(int);
void printItem(Item*);
Item* createItem(char*, enum EItemPosition, float, int, int);
Hero* createHero(char*, int);
void printHero(Hero*);
void setRoom(Hero*, Room*);
void walkInDirection(Hero*, enum EDirection);
void wearItem(Hero*, Item*);
int addToInventory(Hero*, Item*);
Monster* createMonster(char*, int, int, int, Item*);
void printMonster(Monster*);
void monsterAddLoot(Monster*, Item*);
Room* createRoom(char*, int, Monster*, Item*);
Room* getRooms(Room);
void setRoomInDirection(Room*, Room*, enum EDirection);
void printRoom(Room*);
int countRooms(Room* room, enum EDirection dir);
//}

//{ Globalen Variablen
Item NOTHING = { "Leer", head, 0, 0 };
Room WALL = { "Wand", NULL, 0, NULL, NULL };
Item* treasures;
//}

int main()
{
	Item* sword = createItem("Holzschwert", rightHand, 2.5, 30, 0);
	Item* ironSword = createItem("Eisenschwert", rightHand, 5, 55, 0);
	Item* healPotion = createItem("Heiltrank", leftHand, 0.5, 10, 5);

	printItem(sword);

	Hero* zelda = createHero("Zelda", 10);
	wearItem(zelda, sword);
	wearItem(zelda, ironSword);

	strcpy(ironSword->name, "Platinschwert");

	addToInventory(zelda, healPotion);

	Monster* zombie = createMonster("Zombie", 3, 4, 6, &NOTHING);
	Monster* mage = createMonster("Magier", 5, 2, 8, &NOTHING);

	monsterAddLoot(mage, healPotion);

	Room *entrance = createRoom("Eingang", 0, zombie, healPotion);
	Room *throneRoom = createRoom("Thronsaal", 0, mage, &NOTHING);
	Room *kerker = createRoom("Kerker", 0, mage, &NOTHING);

	setRoomInDirection(entrance, throneRoom, west);
	setRoomInDirection(throneRoom, kerker, west);

	setRoom(zelda, entrance);
	walkInDirection(zelda, west);
	walkInDirection(zelda,east);

	strcpy(entrance->name, "Start");
	int countraeume = 0;
	countraeume = countRooms(entrance, west);

	printHero(zelda);
	printMonster(zombie);
	printMonster(mage);
	printRoom(entrance);
	printRoom(throneRoom);
	printf("\n\nAnzahl der Raumdurchlaeufe: %d", countraeume);


	return 0;
}

// zaehle raeume

int countRooms(Room* room, enum EDirection dir){
	
	static int erg = 0;
	if (room == &WALL){
		return;
	}
	ergnord




	return erg;
}

//{ W�rfel-Funktionen

/*
 * Function:  rollDice
 * --------------------
 * Liefert das Ergebnis eines N-seitigen W�rfelwurfs
 *
 *  w: Anzahl der Seiten des W�rfels
 *
 *  returns: W�rfelergebnis
 */
int rollDice(int w) {
	srand(time(NULL));
	return rand() % w + 1;
}

//}

//{ Gegenstandsfunktionen

/*
 * Function:  printItem
 * --------------------
 * Gibt die Werte eines Gegenstandes auf der Konsole aus
 *
 *  *i: Pointer auf ein Item
 *
 */
void printItem(Item* i) {

	printf("***** Gegenstands-Info *****\n");
	printf("Name: %s\n", i->name);
	printf("Position: %d\n", i->pos);
	printf("Gewicht: %.2f\n", i->weight);
	printf("Wert: %d\n", i->value);
	printf("Veraenderung LP: %d\n", i->lp_change);
	printf("****************************\n\n");
}


/*
 * Function:  createItem
 * --------------------
 * Erstellt einen neuene Gegenstand
 *
 *  name: Der Name des Gegenstandes als Zeichekette (max. 25 Zeichen)
 *  pos: die Trageposition des Gegenstandes als enum
 *  w: das Gewicht des Gegenstandes
 *  v: der Wert des Gegenstandes
 *  c: die Ver�nderung des Gegenstandes auf die Lebenspunkte
 *
 *  returns: Pointer auf den neuen Gegenstand im HEAP
 */
Item* createItem(char name[26], enum EItemPosition pos, float w, int v, int c) {
	Item* newItem = (Item*) malloc(sizeof(Item));
	strcpy(newItem->name, name);
	newItem->pos = pos;
	newItem->weight = w;
	newItem->value = v;
	newItem->lp_change = c;
	return newItem;
}


//{ Helden-Funktionen

/*
 * Function:  createHero
 * --------------------
 * Erzeugt einen neuen Helden
 *
 *  name: eine Zeichenkette mit dem Namen des Helden (max. 25 Zeichen)
 *  lp: die Anzahl der Lebenspunkte des Helden
 *
 *  returns: Pointer auf den Helden im HEAP
 *
 */
Hero* createHero(char name[26], int lp) {

	Hero* newHero = (Hero*) malloc(sizeof(Hero));
	strcpy(newHero->name, name);
	newHero->lp = lp;
	int i;

	newHero->slots = (Item*) malloc(6*sizeof(Item*));
	for(i = head; i <= foot; i++)
        newHero->slots[i] = &NOTHING;

    newHero->inventory = (Item*) malloc(10*sizeof(Item*));
	for(i = 0; i <= 9; i++)
        newHero->inventory[i] = &NOTHING;

	return newHero;
}



/*
 * Function:  printHero
 * --------------------
 * Gibt die Werte des Helden auf der Konsole aus
 *
 *  *h: ein Pointer auf einen Helden
 *
 */
void printHero(Hero* h){
	printf("***** Helden-Info *****\n");
	printf("Name: %s\n", h->name);
	printf("Lebenspunkte: %d\n", h->lp);
	printf("Raum: %s\n", h->room->name);
	printf("Slots: \n");
	printf("\t Kopf: %s\n", h->slots[head]->name);
	printf("\t Hals: %s\n", h->slots[neck]->name);
	printf("\t Ruestung: %s\n", h->slots[armor]->name);
	printf("\t Linke Hand: %s\n", h->slots[rightHand]->name);
	printf("\t Rechte Hand: %s\n", h->slots[leftHand]->name);
	printf("\t Fuesse: %s\n", h->slots[foot]->name);
	printf("Inventar: \n");
	int i;
	for (i = 0; i < 10; i++)
		printf("\t %d. Item: %s\n", i + 1, h->inventory[i]->name);
	printf("****************************\n\n");
}



/*
 * Function:  wearItem
 * --------------------
 * Legt einem Helden einen Gegenstand an. Sollte an der Position bereits
 * ein Gegenstand vorhanden sein, wird dieser in das Inventar gelegt.
 * Sollte das Inventar voll sein, dann kann der Gegenstand nicht getragen werden.
 *
 *  *h: Pointer auf den Helden der den Gegenstand tragen soll
 *  *i: Pointer auf den Gegenstand der getragen werden soll
 *
 */
void wearItem(Hero *h, Item* i){
	if (strcmp(h->slots[i->pos]->name, "Leer") == 0)
		h->slots[i->pos] = i;
	else {
		if (addToInventory(h, h->slots[i->pos]) == 1)
			h->slots[i->pos] = i;
		else
			printf("\n Slot belegt und Inventar voll \n\n");
	}

}


/*
 * Function:  addToInventory
 * --------------------
 * Legt einen Gegenstand in das Inventar, wenn dort noch Platz vorhanden ist.
 *
 *  *h: Pointer auf den Helden in dessen Inventar der Gegenstand gelegt werden soll
 *  *item: Pointer auf den Gegenstand, der ins Inventar gelegt werden soll
 *
 *  returns: 1, wenn Gegenstand erfolgreich ins Inventar gelegt, ansonsten -1
 *
 */
int addToInventory(Hero *h, Item *item) {
	int i;
	for (i = 0; i < 10; i++)
		if (h->inventory[i]->weight == 0) {
		h->inventory[i] = item;
		return 1;
		}
	return -1;
}

/*
 * Function:  setRoom
 * --------------------
 * Setzt einen Helden in einen Raum
 *
 *  *h: Pointer auf einen Helden, der in den Raum gesetzt werden soll
 *  *r: Pointer auf den Raum, in den der Held gesetzt wird
 *
 *
 */
void setRoom(Hero *h, Room *r){
	h->room = r;
}

/*
 * Function:  walkInDirection
 * --------------------
 * Bewegt einen Helden in den Raum der angegebenen Richtung. Sollte in dieser Richtung eine Wand sein
 * wird der Held nicht bewegt.
 *
 *  *h: Pointer auf einen Helden, der sich in die Richtung bewegen soll
 *  d: die zu bewegende Richtung als Enum
 *
 *
 */
void walkInDirection(Hero* h, enum EDirection d){
	if (strcmp(h->room->rooms[d]->name,"Wall"))
		h->room = h->room->rooms[d];
}
//}

//{ Monster-Funktionen

/*
 * Function:  createMonster
 * --------------------
 * Erzeugt ein Monster mit den angegebenen Werten
 *
 *  *name: Zeichenkette mit dem Namen des Monster (max. 25 Zeichen)
 *  lp: Lebenspunkte des Monster
 *  s: St�rke des Monster
 *  d: verwendter W�rfel des Monsters f�r den Angriff (Seitenanzahl)
 *  *i: Pointer auf ein Item, dass das Monster fallen l�sst
 *
 *  return: Pointer auf das neue Monster im HEAP
 */
Monster* createMonster(char* name, int lp, int s, int d, Item* i) {
	Monster* newMonster = (Monster*) malloc(sizeof(Monster));
	strcpy(newMonster->name, name);
	newMonster->dice = d;
	newMonster->loot = i;
	newMonster->lp = lp;
	newMonster->strength = s;
	return newMonster;
}

/*
 * Function:  printMonster
 * --------------------
 * Gibt die Werte des Monsters auf der Konsole aus
 *
 *  *m: ein Pointer auf ein Monster
 *
 */
void printMonster(Monster* m){
	printf("***** Monster-Info *********\n");
	printf("Name: %s\n", m->name);
	printf("Lebenspunkte: %d\n", m->lp);
	printf("Staerke: %d\n", m->strength);
	printf("Wuerfel: %d-seitig\n", m->dice);
	printf("Loot: %s\n", m->loot->name);
	printf("****************************\n\n");
}

/*
 * Function:  monsterAddLoot
 * --------------------
 * F�gt einem Monster einen Gegenstand als Schatz hinzu
 *
 *  *m: ein Pointer auf ein Monster
 *  *i: ein Pointer auf den Gegenstand
 *
 */
void monsterAddLoot(Monster* m, Item* i){
	m->loot = i;
}
//}


//{ Raum-Funktionen

/*
 * Function:  createRoom
 * --------------------
 * Erzeugt einen Raum mit den angegebenen Werten
 *
 *  *name: Zeichenkette mit dem Namen des Raums (max. 25 Zeichen)
 *  change: Ver�nderung der Lebenspunkte in dem Raum
 *  *m: Pointer auf ein Monster, dass in dem Raum ist
 *  *i: Pointer auf einen Gegenstand, der in dem Raum als Schatz versteckt ist
 *
 *  return: Pointer auf den neuen Raum im HEAP
 */
Room* createRoom(char *name, int change, Monster *m, Item *i){
	//Room r = {"", {&WALL,&WALL,&WALL,&WALL}, change, m, i};
	Room *r = (Room*)malloc(sizeof(Room));
	strcpy(r->name, name);
	r->lp_change = change;
	r->m = m;
	r->treasure = i;
	r->rooms = malloc(4 * sizeof(Room*));
	r->rooms[north] = &WALL;
	r->rooms[east] = &WALL;
	r->rooms[south] = &WALL;
	r->rooms[west] = &WALL;
	return r;
}


/*
 * Function:  printRoom
 * --------------------
 * Gibt die Werte des Raums auf der Konsole aus
 *
 *  *r: ein Pointer auf den Raum
 *
 */
void printRoom(Room *r) {
	printf("***** Raum-Info *****\n");
	printf("Name: %s\n", r->name);
	printf("Nachbarraeume: \n");

	char directions[4][5] = { "Nord", "Ost", "Sued", "West" };
	int i;

	for (i = north; i <= west; i++)
		printf("\t %s: %s \n", directions[i], r->rooms[i]->name);

	printf("Monster: %s \n", r->m->name);
	printf("Schatz: %s \n", r->treasure->name);

	printf("****************************\n\n");

}


/*
 * Function:  setRoomInDirection
 * --------------------
 * Setzt zwei R�ume als benachbart in der angegebenen Richtung. Dabei wird
 * bei Raum2 der Raum1 in der entgegengesetzten Richtung gesetzt.
 *
 *  *start: ein Pointer auf den ersten Raum
 *  *end: ein Pointer auf den zweiten Raum
 *  d: die Richtung in der der zweite Raum vom ersten Raum aus zu setzen ist
 *
 */
void setRoomInDirection(Room* start, Room* end, enum EDirection d) {
	switch (d){
	case north:
		start->rooms[north] = end;
		end->rooms[south] = start;
		break;
	case east:
		start->rooms[east] = end;
		end->rooms[west] = start;
		break;
	case south:
		start->rooms[south] = end;
		end->rooms[north] = start;
		break;
	case west:
		start->rooms[west] = end;
		end->rooms[east] = start;
		break;
	}
}

//}
