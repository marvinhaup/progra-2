#include <stdio.h>
#include <stdlib.h>

typedef struct listelement{
    int key;
    struct listelement* next;
} listelement;



int main()
{
    listelement *meineliste;

    meineliste = (listelement*) malloc(sizeof(listelement));
    meineliste->key = 3;
    meineliste->next = NULL;

    //element einfügen
    listelement* neueselement;
    neueselement = (listelement*) malloc(sizeof(listelement));
    neueselement->next = meineliste;
    meineliste = neueselement;

    //löschen des anfangselementes
    listelement* tmp = (listelement*) malloc(sizeof(listelement));
    tmp = meineliste;
    meineliste = meineliste->next;
    free(tmp);

    //löschen des zweiten elementes
    listelement* tmpo = (listelement*) malloc(sizeof(listelement));
    tmpo = meineliste->next;
    meineliste->next = tmpo->next;
    free(tmpo);

    //element suchen
    listelement* sucher = (listelement*) malloc(sizeof(listelement));
    sucher = meineliste;
    do{
        if(sucher->key == 38){
            break;
        }
        sucher = sucher->next;

    } while(meineliste->next != NULL);
    free(sucher);


    //liste drucken
    do{
        int i = 1;
        printf("\ninhalt meinerliste an der stelle %d: %d", i, meineliste->key);
        i++;
    } while(meineliste->next != NULL);

    free(meineliste);
    return 0;
}
