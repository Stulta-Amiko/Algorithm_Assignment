#include <stdio.h>
#define MAX_TERMS 101
#define ROWS 3
#define COLS 3

void transpose_matrix(int arr1[ROWS][COLS],int arr2[ROWS][COLS]){
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            arr2[i][j] = arr1[j][i];
        }
    }
}

void print_matrix(int arr[ROWS][COLS]){
for(int i = 0;i<ROWS;i++){
    for(int j=0;j<COLS;j++){
        printf("%d ",arr[i][j]);
    }
    printf("\n");
}
}
int main(){
    int arr1[ROWS][COLS] = {{2,3,0},{8,9,1},{7,0,5}};
    int arr2[ROWS][COLS];
    transpose_matrix(arr1,arr2);
    print_matrix(arr1);
    print_matrix(arr2);
    return 0;
}