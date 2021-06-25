#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
char* concatenate(char* er1, char* er2){

    char* er3;
    int laenge = strlen(er1) + strlen(er2) + 1;
    er3 = (char*) malloc(1* laenge);
    int laenge1 = strlen(er2);
    for(int i = 0; i < laenge1; i++){
        er3[i] = er1[i];
    }
    int laenge2 = strlen(er2);
    for(int i = 0; i < laenge2; i++){
        er3[laenge1+1] = er2[i];
    }
    return er3;
}


int main()
{
    char str1[] = "umwelt";
    char str2[] = "campus";

    char *erg;
    erg = (concatenate(str1,str2));
    for(int i = 0; i < (strlen(str1) + strlen(str2) + 1); i++){
        printf("ergebis: %s", erg[i]);
    }

    free(erg);

    return 0;
}
*/

//char* concatenate(char*, char*);

char* concatenate(char* wort1, char* wort2){
    int laenge1 = strlen(wort1);
    int laenge2 = strlen(wort2);
    int laenge3 = laenge1 +  laenge2;

    char *neueswort;
    neueswort = (char*) malloc(laenge3 * sizeof(char));

    int j = 0;
    for(int i = 0; i < laenge1; i++){
        neueswort[i] = wort1[j];
        j++;
    }

    j = 0;
    for(int i = laenge1; i < (laenge1 + laenge2); i++){
        neueswort[i] = wort2[j];
        j++;
    }
    return neueswort;
}

int main(){

    char str1[] = "Umwelt-";
    char str2[] = "Campus";
    char *erg;
    erg = concatenate(str1,str2);
    printf("\nzusammengefuegtes wort: %s\n", erg);
    free(erg);

    return 0;
}




