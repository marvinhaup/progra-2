#include <stdio.h>
#include <stdlib.h>


int main()
{

    int zahl;
    printf("Geben Sie eine Zahl ein: ");
    scanf("%d",&zahl);

    int quersumme = berechneQuersummeIT(zahl);
    printf("Quersumme von %d: %d\n\n", zahl, quersumme);

    quersumme = berechneQuersummeRK(zahl);
    printf("Quersumme von %d: %d\n\n", zahl, quersumme);

    return 0;
}
