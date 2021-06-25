#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int bestimmeMax(int[], int);

int main()
{
    int arr[] = {7, 8, 14, 17, 19, 23, 45, 47, 56, 58, 61, 71, 75,
    79, 81, 88, 92, 95, 101, 110, 123, 125, 134, 135, 156, 167, 177,
    178, 179, 234, 237, 888};
    int len;

    printf("\nlen = %d", len);
    int max = bestimmeMax(arr, len);
    printf("\ndas maximum ist %d", max);
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
