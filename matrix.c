#include <stdio.h>
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

void print_Matrix(SparseMatrix s){
    for(int i = 0;i<s.terms;i++){
        printf("{%d,%d,%d}\n",s.data[i].row,s.data[i].col,s.data[i].value);
    }
}

SparseMatrix transpose_Matrix(SparseMatrix s){
    SparseMatrix b;
    int bindex = 0;
    b.cols = s.rows;
    b.rows = s.cols;
    b.terms = s.terms;
    if(s.terms>0){
        for(int i=0;i<s.cols;i++){
            for(int j=0;j<s.terms;j++){
                if(s.data[j].col == i){
                    b.data[bindex].col = s.data[j].row;
                    b.data[bindex].row = s.data[j].col;
                    b.data[bindex].value = s.data[j].value;
                    bindex++;
                }
            }
        }
    }
    return b;
}

int main(){
    SparseMatrix m = {{{0,3,7},{1,0,9},{1,5,8},{3,0,6},{3,1,5},{4,5,1},{5,2,2}},
    6,6,7
    };
    SparseMatrix result;
    result = transpose_Matrix(m);
    print_Matrix(result);
    return 0;
}