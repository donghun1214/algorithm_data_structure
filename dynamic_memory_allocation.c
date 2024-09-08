#include <stdio.h>
#include <stdlib.h>
int main(){
    int **arr;
    int height = 10, width = 15;
    arr = (int **)malloc(sizeof(int *) * height);

    for(int i = 0; i < height; i++){
        arr[i] = (int *)malloc(sizeof(int)*width);
    }
    for(int i = 0; i < height; i++){
        free(arr[i]);
    }
    free(arr);

    return 0;
}