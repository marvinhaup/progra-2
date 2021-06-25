#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int bestimmeMax(int[], int);

int main()
{
    int arr[] = {3,17,5,21,8,20};
    int max = bestimmeMax(arr,5);

    printf("das maximum ist %d", max);

    return 0;
}

int bestimmeMax(int arr[], int len){
    if(len == 1){
        return arr[0];
    }
    else if(arr[0] < bestimmeMax(arr+1, len-1)){
        return bestimmeMax(arr+1, len-1);
    }
    else{
        return arr[0];
    }
}
