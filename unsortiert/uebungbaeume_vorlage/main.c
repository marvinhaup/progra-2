#include <stdio.h>
#include <stdlib.h>

enum Geschlecht {M,W};

typedef struct {
    int tag,monat,jahr;
} Datum;

typedef struct {
    char name[50];
    enum Geschlecht geschlecht;
    Datum geburtstag;
} Person;

typedef struct Knoten {
    Person *inhalt;
    struct Knoten* vater;
    struct Knoten* mutter;
} Knoten;

Knoten* createStammbaum(Person*);
Knoten* findKnoten(Person*,Knoten*);
void addPerson(Person*,Person*,Knoten*);
void printStammbaum(Knoten*);

int main()
{   
    Person karl = {"Karl I.", M,{19,3,1745}};
    Person otto = {"Otto", M, {19,3,1715}};
    Person maria = {"Maria", W, {19,3,1719}};
    Person anna = {"Anna", W, {12,2,1682}};
    Person gustav = {"Gustav", M, {12,12,1690}};
    Person franz = {"Franz", M, {12,12,1660}};

    Knoten* stammbaum = createStammbaum(&karl);
    
    addPerson(&otto,&karl,stammbaum);
    printf("\n%s", stammbaum->vater->inhalt->name);
    addPerson(&maria,&karl,stammbaum);
    printf("\n%s", stammbaum->mutter->inhalt->name);
    addPerson(&anna,&otto,stammbaum);
    printf("\n%s", stammbaum->vater->mutter->inhalt->name);
    addPerson(&franz,&anna,stammbaum);
    printf("\n%s", stammbaum->vater->mutter->vater->inhalt->name);
    addPerson(&gustav,&anna,stammbaum);
    printf("\n%s", stammbaum->vater->mutter->vater->inhalt->name);

    //printStammbaum(stammbaum);
    free(stammbaum);

    return 0;
}

Knoten* createStammbaum(Person *pers){
    Knoten* elem = (Knoten*) malloc(sizeof(Knoten));
    elem->inhalt = pers;
    elem->vater = NULL;
    elem->mutter = NULL;
    return elem;
}

void addPerson(Person *elternTeil,Person *kind,Knoten *baum){
    Knoten *tmp = (Knoten*) malloc(sizeof(Knoten));
            tmp->inhalt = elternTeil;
            tmp->vater = NULL;
            tmp->mutter = NULL;
    
    Knoten *temp = findKnoten(kind,baum);

    if(baum->inhalt == kind){               //einfache Abfrage, ob der inhalt der wurzel gleich dem Kind ist.
        if(elternTeil->geschlecht == M){    
            baum->vater = tmp;
        }
        else{
            baum->mutter = tmp;
        }
    }
    else if(temp != NULL){
        if(elternTeil->geschlecht == M){    
            temp->vater = tmp;
        }
        else{
            temp->mutter = tmp;
        }
    }
}

void printStammbaum(Knoten *baum){

    static int counter = 0;
    if(counter == 0){
        printf("\n%s", baum->inhalt->name);
    }
    counter++;

    if(baum->vater->inhalt != NULL){
        printf("\n|---->%s", baum->vater->inhalt->name);
        printStammbaum(baum->vater);
    }
    if(baum->mutter->inhalt != NULL){
        printf("\n|---->%s", baum->mutter->inhalt->name);
        printStammbaum(baum->mutter);
    }
    
}

Knoten* findKnoten(Person *elem,Knoten *baum){
    
    if(baum == NULL){
        return NULL;
    }
    if(baum->inhalt == elem){
        return baum;
    }

    Knoten *resultlinks = findKnoten(elem,baum->vater);
    Knoten *resultrechts = findKnoten(elem,baum->mutter);
    
    if(resultlinks != NULL){
        return resultlinks;
    }
    
    if(resultrechts != NULL){
        return resultrechts;
    }

    return NULL;
}