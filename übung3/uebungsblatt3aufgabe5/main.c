#include <stdio.h>
#include <stdlib.h>

typedef struct BBaum BBaum;

typedef struct BBaum {
    BBaum* left;
    BBaum* right;
    int value;
}BBaum;


int main()
{
    BBaum b_15 = {NULL,NULL,15};
    BBaum b_7 = {NULL,&b_15,7};
    BBaum b_24 = {NULL,&b_7,24};
    BBaum b_4 = {NULL,NULL,4};
    BBaum b_13 = {NULL,NULL,13};
    BBaum b_8 = {&b_13,&b_4,8};
    BBaum root = {&b_8,&b_24,19};

    int summe = berechneSumme(&root);

    printf("Die Summe betr�gt: %d", summe);

    return 0;
}
