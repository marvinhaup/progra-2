#include <stdio.h>
#include <stdlib.h>
#include "Header/item.h"


int main()
{
    Gegenstand *helm = createGegenstand("Helm", 5);
    printGegenstand(helm);
    return 0;
}
