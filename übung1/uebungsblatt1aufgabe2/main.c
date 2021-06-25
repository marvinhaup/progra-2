#include<stdio.h>
#include<stdlib.h>

typedef struct{
	float x;
    float y;
} coordinate_t;

coordinate_t* getCoordinateArray(int n){
    coordinate_t *q1;
    q1 = (coordinate_t*) malloc(n * sizeof(float) + n * sizeof(float) + 1 * sizeof(int));
    for(int i = 0; i < n; i++){
        q1[i].x = 0;
        q1[i].y = 0;
    }
    return q1;
}

int main(void){

	coordinate_t *q;

	q = getCoordinateArray(10);

	for(int i = 0; i < 10; i++){
        printf("(%.2f,%.2f)\n", q[i].x, q[i].y);
	}

    free(q);
	return 0;
}
