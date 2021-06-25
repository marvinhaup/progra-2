#include <stdio.h>
#include <stdlib.h>


#define N 9


int solveSudoku(int[N][N]);
void printGrid(int [N][N]);
int counter = 0;
int findUnassignedCell(int [N][N], int*, int*);
int UsedInRow(int[N][N], int, int);
int UsedInCol(int[N][N], int, int);
int UsedInBox(int[N][N], int, int, int);

int main()
{
    int grid[N][N] = {{0,0,0,5,0,0,0,0,0},
                      {7,0,5,0,0,0,4,0,3},
                      {0,3,0,0,0,8,5,9,0},
                      {8,0,4,3,0,0,7,0,2},
                      {0,0,3,0,1,0,9,0,0},
                      {5,0,9,0,0,7,3,0,4},
                      {0,5,1,2,0,0,0,7,0},
                      {3,0,7,0,0,0,2,0,5},
                      {0,0,0,0,0,4,0,0,0}};

     printGrid(grid);
     if(solveSudoku(grid)== 1){
        printf("\nGeloest in %d Schritten\n\n", counter);
        printGrid(grid);

     }
       else
            printf("Keine loesung gefunden");

    return 0;
}

int solveSudoku(int grid[N][N]){

    counter++;

    int row, col;

    if( findUnassignedCell(grid, &row, &col) == 0){
        return 1;
    }

    for(int i=0; i<=9; i++){
        if( UsedInRow(grid, row, i) == 0 && UsedInCol(grid, col, i) == 0 && UsedInBox(grid, row, col, i) == 0){
        grid[row][col] = i;
        if(solveSudoku(grid) == 1){
            return 1;
        }
        
        grid[row][col] = 0;
        }
    }
    return 0;
}


void printGrid(int arr[N][N]){

    for(int i=0; i < N; i++){
        for(int j=0; j<N; j++){
            printf("%d", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");

}

int findUnassignedCell(int grid[N][N], int *row, int *col){

    for(int i=0; i < N; i++){
        for(int j=0; j<N; j++){
            if(grid[i][j]==0){
                *row = i;
                *col = j;
                return 1;
            }
        }
    }
    return 0;
}

int UsedInRow(int grid[N][N], int row, int number){

    // liefert 1 zurück, falls die gesuchte zahl bereits in der Reihe enthalten ist.

    for(int i=0; i<N; i++){
        if (grid[row][i] == number){
            return 1;
        }
    }
        return 0;
}

int UsedInCol(int grid[N][N], int col, int number){

    // liefert 1 zurück, falls die gesuchte nummer bereits in der Spalte enthalten ist.

    for(int i=0; i<N; i++){
        if (grid[i][col] == number){
            return 1;
        }
    }
    return 0;
}



int UsedInBox(int grid[N][N], int row, int col, int number){

    // liefert 1 zurück, falls die gesuchte zahl bereits in dem block enthalten ist.

    int boxRow = (row / 3) * 3;
    int boxCol = (col / 3) * 3;

    for(int i=boxRow; i < 3; i++){
        for(int j=boxCol; j<3; j++){
            if(grid[i][j]==number){
                return 1;
            }
        }
    }
    return 0;
}
