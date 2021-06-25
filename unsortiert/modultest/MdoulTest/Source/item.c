#include "../Header/item.h"

Gegenstand* createGegenstand(char name[], int gewicht){
    Gegenstand *neu = (Gegenstand*) malloc(sizeof(Gegenstand));
    strcpy(neu->name,name);
    neu->gewicht = gewicht;
    return neu;
}

void printGegenstand(Gegenstand *ausgabe){
    printf("Name: %s\n", ausgabe->name);
    printf("Gewicht: %d", ausgabe->gewicht);
}

