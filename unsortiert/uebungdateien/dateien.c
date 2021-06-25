#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[21];
    char studiengang[51];
    float note;
} Alumni;

Alumni* ReadAlumniFile(char[], int*);

void printAlumni(Alumni*, int*);

int main(){

    int len = 0;
    Alumni *new = ReadAlumniFile("text.txt", &len);
    printAlumni(new, &len);
    fclose(new);
    return 0;
}

Alumni* ReadAlumniFile(char filename[], int* len){
    
    FILE *fp = fopen(filename, "r");
    if (fp == NULL){
        printf("\nDatei konnte nicht geoeffnet werden.");
        exit(-1);
    }
    
    fscanf(fp, "%d\n", len);
    //fgetc(fp);
    Alumni *new = (Alumni*) malloc(*len * sizeof(Alumni)); 
    
    for(int i = 0; i < *len; i++){
        fgets(new[i].name, 20, fp);
        fgets(new[i].studiengang, 50, fp);
        fscanf(fp, "%f\n", &new[i].note);
    }

    return new;
}

void printAlumni(Alumni* palumni, int* len){

    for(int i = 0; i < *len; i++){
        printf("\n\nName: %s", palumni[i].name);
        printf("\nStudiengang: %s", palumni[i].studiengang);
        printf("\nNote: %.1f\n", palumni[i].note);

    }
}