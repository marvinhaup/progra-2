#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countletters(FILE*);


int main(){

    int numberofletters;
    char filename[256];

    printf("\ngeben sie den namen der datei ein:");
    scanf("%s", filename);
    FILE* fp;
    fp = fopen(filename, "r");
    if(fp == NULL){
        printf("\ndie datei konnte nicht geoeffnet werden.");
        exit(-1);
    }
    else{
        printf("\ndie datei wurde geoeffnet.");
    }
    numberofletters = countletters(fp);
    printf("\ndie datei %s hat %d buchstaben", filename, numberofletters);
    fclose(fp);
    return 0;
}

int countletters(FILE *fpo){
    int erg = 0;
    char c = fgetc(fpo);
    while(c != EOF){
        if((c >= 'a' && c <= 'z')||(c >= 'A' && c <='Z')){
            erg++;
        }
        c = fgetc(fpo);
    }
    return erg;
    }
