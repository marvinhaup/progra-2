#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char filename[20];
    FILE *fp;
    printf("in welche datei soll geschrieben werden: ");
    scanf("%s", filename);

    fp = fopen(filename, "w");
    if(fp == NULL){
        printf("\noeffnen der datei fehlgeschlagen.");
    }
    else{
        printf("\noeffnen der datei erfolgreich.");
    }
    fprintf(fp,"Name: Mustermann\n");
    fprintf(fp,"Vorname: Manfred\n");
    fprintf(fp, "Strasse: Campus-Allee 1\n");
    fprintf(fp, "Ort: 55761 Birkenfeld\n");
    fclose(fp);
    printf("\nschreiben erfolgreich.\n");

    fp = fopen(filename, "r");
    if(fp == NULL){
        exit(-1);
    }
    char name[101];
    fgets(name,100,fp);
    printf("%s", name);
    fgets(name,100,fp);
    printf("%s", name);
    fgets(name,100,fp);
    printf("%s", name);
    fgets(name,100,fp);
    printf("%s", name);

    return 0;
}





