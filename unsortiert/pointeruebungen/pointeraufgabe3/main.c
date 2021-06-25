#include <stdio.h>
#include <stdlib.h>

void swappointer(int*, int*);

int main()
{
    int a = 1, b = 2;
    int *ap, *bp;

    ap = &a;
    bp = &b;

    printf("Vor dem Tausch\n");
    printf("Gespeicherte Adresse in ap: %p, Dereferenzierung von ap: %d \n", ap, *ap);
    printf("Gespeicherte Adresse in bp: %p, Dereferenzierung von bp: %d \n", bp, *bp);

    swappointer(&ap, &bp);

    printf("Gespeicherte Adresse in ap: %p, Dereferenzierung von ap: %d \n", ap, *ap);
    printf("Gespeicherte Adresse in bp: %p, Dereferenzierung von bp: %d \n", bp, *bp);

    return 0;
}

void swappointer(int *ptr1, int *ptr2){
    int tmp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = tmp;
}
