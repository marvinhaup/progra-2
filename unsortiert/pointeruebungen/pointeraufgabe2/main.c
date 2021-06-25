#include <stdio.h>
#include <stdlib.h>

void printarray(int*, int);

void swaparray(int*, int*, int);

int main()
{
    int zahlen[] = {1,2,3,4};
    int negzahlen[] = {-1,-2,-3,-4};

    printf("Vor swap:\n");
    printarray(zahlen,4);
    printarray(negzahlen,4);

    swaparray(zahlen,negzahlen,4);

    printf("Nach swap:\n");
    printarray(zahlen,4);
    printarray(negzahlen,4);

    return 0;
}

void printarray(int *ptr, int laenge){
    for(int i = 0; i < laenge; i++){
        printf("array an der stelle %d: %d\n", i, *(ptr + i));
    }
}

void swaparray(int *ptr1, int *ptr2, int laenge){
    for(int i = 0; i < laenge; i++){
    int var = *(ptr1 + i);
    *(ptr1 + i) = *(ptr2 + i);
    *(ptr2 + i) = var;
    }
}
