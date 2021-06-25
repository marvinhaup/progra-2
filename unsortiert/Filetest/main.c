#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    fp = fopen("test.txt", "w");
    fprintf(fp, "ich mag kaese\n");
    fclose(fp);
    fp = fopen("test.txt", "r");
    char buffer[20];
    fgets(buffer,19,fp);
    fclose(fp);
    printf("%s", buffer);

    return 0;
}
