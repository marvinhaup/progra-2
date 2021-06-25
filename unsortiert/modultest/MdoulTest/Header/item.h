#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

typedef struct {
    char name[25];
    int gewicht;
} Gegenstand;

Gegenstand* createGegenstand(char[], int);
void printGegenstand(Gegenstand*);

#endif // ITEM_H_INCLUDED
