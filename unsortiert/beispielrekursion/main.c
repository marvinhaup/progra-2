#include <stdio.h>
#include <stdlib.h>

int berechneit(int*, int);
int berechnerk(int*, int,  int*);

int main()
{
    int zahlen[] = {3,67,39,-6,534,97,59,342};
    int summe1, summe2;
    int rekursionstiefe = 0;

    summe1 = berechneit(zahlen, (sizeof(zahlen)/sizeof(int)));
    summe2 = berechnerk(zahlen, sizeof(zahlen)/sizeof(int), &rekursionstiefe);

    printf("\nSumme1 : %d", summe1);
    printf("\nSumme2 : %d", summe2);
    
    return 0;
}

int berechneit(int *arr, int len){
    int erg = 0;
        for(int i = 0; i  < len; i++){
            erg += arr[i];
        }
    return erg;
}

int berechnerk(int *arr, int len, int *tiefe){

    (*tiefe)++;
    printf("\ntiefe = %d", *tiefe);
    if(*tiefe > 100){
        printf("rekursionstiefe ueberschritten");
        exit(-1);
    }

    if(len == 1)
        return arr[0];
    else{
        int zwerg = berechnerk(arr+1, len - 1, tiefe) + arr[0];
        return zwerg;
    }
}
