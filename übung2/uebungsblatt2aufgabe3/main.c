#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(int*, int);

int* readnumbers(FILE*, int*);

int main(){

    int n = 0;
    int *p;
    char filename[30];
    FILE* fp;
    printf("\nWelche Datei soll geoeffnet werden?");
    scanf("%s", filename);

    if((fp = fopen(filename, "r") == NULL)){
        printf("\ndie datei %s konnte nicht geoeffnet werden.", filename);
        exit(-1);
    }
    else{
        printf("\nDie datei: %s wurde geoeffnet.", filename);
    }


    free(p);
    fclose(fp);

    return 0;

}

int* readnumbers(FILE *fptr, int *nptr){
    int *p;

    return p;
}


