#include <stdio.h>
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MAX_DEGREE 101

typedef struct{
    int degree;
    float coef[MAX_DEGREE];
}polynomial;

polynomial poly_add(polynomial p1,polynomial p2){
    polynomial c;
    int Apos = 0,Bpos = 0,Cpos = 0;
    int degree_p1 = p1.degree;
    int degree_p2 = p2.degree;
    c.degree = MAX(degree_p1,degree_p2);
    while(Apos <= p1.degree && Bpos <= p2.degree){
        if(degree_p1>degree_p2){
            c.coef[Cpos++] = p1.coef[Apos++];
            degree_p1--;
        }else if(degree_p1 == degree_p2){
            c.coef[Cpos++] = p1.coef[Apos++] + p2.coef[Bpos++];
            degree_p1--; degree_p2--;
        }else{
            c.coef[Cpos++] = p2.coef[Bpos++];
            degree_p2--;
        }
    }
    return c;
}

void poly_print(polynomial p1){
    for(int i = 0;i<p1.degree;i++){
        printf("%.1fx^%d+",p1.coef[i],p1.degree-i);
    }
    printf("%.1f",p1.coef[p1.degree]);
}

int main(){
    polynomial a = {5,{3,6,0,0,0,10}};
    polynomial b = {4,{7,0,5,0,1}};
    polynomial c;

    c = poly_add(a,b);
    poly_print(c);
    return 0;
}