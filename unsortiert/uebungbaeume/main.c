#include <stdio.h>
#include <stdlib.h>

enum Geschlecht {m,w};

typedef struct {
    int tag, monat, jahr;
} Datum;

typedef struct {
    char name[30];
    enum Geschlecht geschlecht;
    Datum geburtstag;
} person;

typedef struct {
    person inhalt;
    struct Knoten* vater;
    struct Knoten* mutter;
} Knoten;

Knoten* createstammbaum(person*);

int main()
{
    person karl = {"Karl I.", M, {19,3,1745}};
    Knoten* stammbaum = createstammbaum(&karl);
    
    person otto = {"otto", M, {19,3,1715}};
    person maria = {"Maria", W, {19,3,1719}};
    
    addperson(&otto,&karl,stammbaum);

    return 0;
}

Knoten* createstammbaum(person *pers){
    Knoten* elem = (Knoten*) malloc(sizeof(Knoten));
    elem->inhalt = pers;

}
