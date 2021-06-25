#include<stdio.h>
#include<stdlib.h>

int main(void){
	int *ar = NULL;
	int i, laenge;
	printf("\n\nWieviele Zahlen moechten Sie einlesen : ");
	scanf("%d", &laenge);

	ar = (int*) malloc(laenge * sizeof(int));

    printf("\ngeben Sie ihre %d buchstaben ein: ", laenge);
	for(i = 0; i < laenge; i++){
        printf("\nzahl %d: ", i+1);
        scanf("%d", &ar[i]);
	}

    printf("\nihre zahlen lauten:\n");
    for(i = 0; i < laenge; i++){
        printf("\nZahl %d: %d\n", i+1, *(ar + i ));
    }
    free(ar);
	return 0;
}
