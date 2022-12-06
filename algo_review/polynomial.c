#include <stdio.h>
#define MAX(a,b) ((a)>(b) ? (a):(b))
#define MAX_DEGREE 101


typedef struct{
    int degree;
    float coef[MAX_DEGREE];
}polynomial;

polynomial poly_add(polynomial a,polynomial b){
    polynomial C;
    int Apos = 0, Bpos = 0, Cpos = 0;
    int degree_a = a.degree;
    int degree_b = b.degree;
    C.degree = MAX(degree_a,degree_b);

    while(Apos <= a.degree && Bpos <= b.degree){
        if(degree_a>degree_b){
            C.coef[Cpos++] = a.coef[Apos++];
            degree_a--;
        }else if(degree_a == degree_b){
            C.coef[Cpos++] = a.coef[Apos++] + b.coef[Bpos++];
            degree_a--; degree_b--;
        }else{
            C.coef[Cpos++] = b.coef[Bpos++];
            degree_b--;
        }
    }
    return C;
}

void poly_print(polynomial p){
    for(int i=p.degree;i>0;i--){
        printf("%.1fx^%d +",p.coef[p.degree-i],i);
    }
    printf("%.1f \n",p.coef[p.degree]);
}

int main(){
    polynomial a = {5,{3,6,0,0,0,10}};
    polynomial b = {4,{7,0,5,0,1}};
    polynomial c;
    poly_print(a);
    poly_print(b);
    printf("====================\n");
    c = poly_add(a,b);
    poly_print(c);
    return 0;
}