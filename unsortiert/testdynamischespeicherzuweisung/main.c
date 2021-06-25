#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct element_typ{
    char name[20];
    int alter;
};

struct element_typ* element_erzeugen();

void edit_element(struct element_typ*);

void element_ausgeben(struct element_typ*);

int main(void){

    struct element_typ *ptr_object;
    ptr_object = element_erzeugen();
    edit_element(ptr_object);
    element_ausgeben(ptr_object);
    free(ptr_object);
    return 0;
}

struct element_typ* element_erzeugen(){

    struct element_typ *newelement;
    newelement = malloc(sizeof(struct element_typ));
    return newelement;
};

void edit_element(struct element_typ *editelemet){
    strcpy(editelemet->name,"frank");
    editelemet->alter = 24;
}

void element_ausgeben(struct element_typ *ausgabeelement){
    printf("\nname des elementes: %s \nalter des elementes: %d", ausgabeelement->name, ausgabeelement->alter);
}


/*struct struktur{
    int recordnummer;
    char inhalt[10];
};

void pointeraufrecord();

int main(void){

    printf("\nhier ist main");
    pointeraufrecord();
    return 0;
}

void pointeraufrecord(){

    struct struktur *structptr;
    structptr = malloc(sizeof(struct struktur));
    strcpy(structptr->inhalt,"hallo");
    structptr->recordnummer = 3;
    printf("\ndie recordnummer ist: %d", structptr->recordnummer);
    printf("\nder inhalt ist: %s", structptr->inhalt);
    free(structptr);
}





void pointeraufint();

int main()
{
    printf("\nhier ist main");
    pointeraufint();
    return 0;
}

void pointeraufint(){
    int *ptr;
    ptr = malloc(sizeof(int));
    *ptr = 3;
    printf("\nint-wert des pointers: %d", *ptr);
    free(ptr);
}
*/
