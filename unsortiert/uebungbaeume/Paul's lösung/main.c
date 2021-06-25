#include <stdio.h>
#include <stdlib.h>
#include <string.h>


enum Geschlecht {m, w};

typedef struct {
    int tag, monat, jahr;
} Datum;

typedef struct{
    char name[50];
    enum Geschlecht geschlecht;
    Datum geburtsdatum;
} Person;

typedef struct Knoten{
    Person *inhalt;
    struct Knoten *vater;
    struct Knoten *mutter;
} Knoten;



Knoten* createStammbaum(Person*);
void printStammbaum(Knoten*);
void addPerson(Person*, Person*, Knoten*);

int main() {
    Person karl = {"Karl I.", m, {19,3,1745}};
    Knoten *stammbaum = createStammbaum(&karl);     
    
    
    Person otto = {"Otto", m, {19,3,1715}};
    Person maria = {"Maria", w, {19,3,1719}};
    Person anna = {"Anna", w, {19,3,1746}};
    
    addPerson(&otto, &karl, stammbaum);
    addPerson(&anna, &otto, stammbaum);
    addPerson(&maria, &karl, stammbaum);
    
    stammbaum->vater->mutter = malloc(sizeof(Knoten));
    stammbaum->vater->mutter->inhalt = (Person*) malloc(sizeof(Person));
    strcpy(stammbaum->vater->mutter->inhalt->name, "Anna");
    
    printf("%s\n", stammbaum->inhalt->name);
    printf("%s\n", stammbaum->vater->inhalt->name);
    printf("%s\n", stammbaum->mutter->inhalt->name);
    printf("%s\n\n\n", stammbaum->vater->mutter->inhalt->name);
    
    printStammbaum(stammbaum);
    
    
    return 0;
}



Knoten* createStammbaum(Person *person) {
    Knoten *elem = (Knoten*) malloc(sizeof(Knoten));
    elem->inhalt = person;
    elem->vater = NULL;
    elem->mutter = NULL;
    return elem;
}



void printStammbaum(Knoten *baum) {
    if (baum == NULL) {
        printf("leer\n");
        return;
    }
    else {
        if (baum->inhalt != NULL) {
            printf("%s\n", baum->inhalt->name);
        }
        if (baum->vater != NULL) {
            printStammbaum(baum->vater);
        }
        if (baum->mutter != NULL) {
            printStammbaum(baum->mutter);
        }
    }
}




void addPerson(Person *elternTeil, Person *kind, Knoten *baum) {
    
    // wenn "kind" der Wurzelknoten ist
    if (baum->inhalt->geburtsdatum.jahr == kind->geburtsdatum.jahr) {
        if (elternTeil->geschlecht == m) {
            baum->vater = (Knoten*) malloc(sizeof(Knoten));
            baum->vater->inhalt = elternTeil;
            baum->vater->mutter = NULL;
            baum->vater->vater = NULL;
        }
        else {
            baum->mutter = (Knoten*) malloc(sizeof(Knoten));
            baum->mutter->inhalt = elternTeil;
            baum->vater->mutter = NULL;
            baum->vater->vater = NULL;
        }
    }
    else {
    // ansonten finde den Knoten "kind"
    Knoten *tempKnoten = NULL;
    tempKnoten = baum;
        while (baum->inhalt->geburtsdatum.jahr != kind->geburtsdatum.jahr) {
            if (baum->inhalt->geschlecht == m && baum->vater != NULL) {
                baum = tempKnoten->vater;
            }
            else {
                if (baum->mutter != NULL) {
                    baum = baum->mutter;
                }
            }
        }
        
    if (elternTeil->geschlecht == m) {
        baum->vater = (Knoten*) malloc(sizeof(Knoten));
        baum->vater->inhalt = (Person*) malloc(sizeof(Person));
        baum->vater->inhalt = elternTeil;
        baum->vater->mutter = NULL;
        baum->vater->vater = NULL;
        //baum = tempKnoten;
    }
    else {
        baum->mutter = (Knoten*) malloc(sizeof(Knoten));
        //baum->mutter->inhalt = (Person*) malloc(sizeof(Person));
        baum->mutter->inhalt = elternTeil;
        baum->mutter->mutter = NULL;
        baum->mutter->vater = NULL;
        //baum = tempKnoten;
    }
    }
    
}
