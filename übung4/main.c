#include <stdio.h>
#include <stdlib.h>

typedef struct position {
    int x, y;
} position;


const int size = 5;

int brett[size][size];


position* getmoves(position);
int validmove(position);
int solve(int, position);

int main()
{

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            brett[i][j] = 0;
        }
    }



    position start = {0,0};
    int zugnummer = 1;
    brett[0][0] = zugnummer;
    solve(zugnummer, start);

    return 0;
}

position* getmoves(position getpos){
    position *valmoves;
    valmoves = malloc(8 * sizeof(*position));
    valmoves[0].x = getpos.x -1;
    valmoves[0].x = getpos.y +2;
    valmoves[1].x = getpos.x -2;
    valmoves[1].x = getpos.y +1;
    valmoves[2].x = getpos.x -2;
    valmoves[2].x = getpos.y -1;
    valmoves[3].x = getpos.x -1;
    valmoves[3].x = getpos.y -2;
    valmoves[4].x = getpos.x +1;
    valmoves[4].x = getpos.y -2;
    valmoves[5].x = getpos.x +2;
    valmoves[5].x = getpos.y -1;
    valmoves[6].x = getpos.x +1;
    valmoves[6].x = getpos.y +2;
    valmoves[7].x = getpos.x +2;
    valmoves[7].x = getpos.y +1;
    return valmoves;
}

int validmove(position valpos){
    if((valpos.x >= 0 && valpos.y <= 5) && (valpos.y >= 0 && valpos.y <=5)){
        return 1;
    }

    return 0;
}

int solve(int zug, position solvpos){


    if(zug == size *size){
        printf("\nloesung gefunden.")
        return 1;
    }
    if()

    for(int i = 0; i < (size * size); i++){



    }




    return 1;
}





