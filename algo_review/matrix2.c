#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 100
typedef struct{
    int row;
    int col;
    int value;
}element;

typedef struct SparseMatrix{
    element data[MAX_TERMS];
    int rows;
    int cols;
    int terms;
}SparseMatrix;

SparseMatrix matrix_transpose(SparseMatrix a){
    SparseMatrix b;
    int bindex;
    b.rows = a.cols;
    b.cols = a.rows;
    b.terms = a.terms;
    if(a.terms>0){
        bindex = 0;
        for(int i=0;i<a.cols;i++){
            for(int j=0;j<a.terms;j++){
                if(a.data[j].col == i){
                    b.data[bindex].row = a.data[j].col;
                    b.data[bindex].col = a.data[j].row;
                    b.data[bindex].value = a.data[j].value;
                    bindex++;
                }
            }
        }
    }
    return b;
}


void print_Matrix(SparseMatrix s){
    for(int i = 0;i<s.terms;i++){
        printf("{%d,%d,%d}\n",s.data[i].row,s.data[i].col,s.data[i].value);
    }
}


int main(){
    SparseMatrix m = {{{0,3,7},{1,0,9},{1,5,8},{3,0,6},{3,1,5},{4,5,1},{5,2,2}},
    6,6,7
    };
    SparseMatrix result;
    result = matrix_transpose(m);
    print_Matrix(result);
    return 0;
}