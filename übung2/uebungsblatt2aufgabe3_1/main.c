#include <stdio.h>
#include <stdlib.h>


void sort(int*, int);

int* readnumbers(FILE*, int*);

int main()
{
    FILE *fp;
    int n = 0;
    int *p;
    char filename[20];
    printf("welche datei soll geoeffnet werden: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if(fp == NULL){
        printf("\noeffnen der datei fehlgeschlagen.");
        exit(-1);
    }
    p = readnumbers(fp, &n);
    for(int i = 0; i < n; i++){
        printf("\n p: %d", p[i]);
    }
    sort(p, n);
    for(int i = 0; i < n; i++){
        printf("\n p: %d", p[i]);
    }


    free(p);
    fclose(fp);
    return 0;
}

int* readnumbers(FILE *fptr, int *nptr){
    int *p;
    char zeile[10];
    fgets(zeile, 9, fptr);
    *nptr = atoi(zeile);
    printf("\n%d", *nptr);
    p = malloc(*nptr * sizeof(int));
    for(int i = 0; i < *nptr; i++){
        fgets(zeile, 9, fptr);
        p[i] = atoi(zeile);
    }
    return p;
}

void sort(int *pptr, int n){

    for(int i = 0; i < n; i++){
        if(pptr[i] > pptr[i+1]){
            int tmp = pptr[i];
            pptr[i] = pptr[i+1];
            pptr[i+1] = tmp;
        }
    }
}


