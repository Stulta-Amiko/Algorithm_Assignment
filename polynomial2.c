#include <stdio.h>
#define MAX_TERMS 100

struct{
    int coef;
    int expon;
} terms[MAX_TERMS] = {{8,3},{7,1},{1,0},{10,3},{3,2},{1,0}};

int avail = 6;
void print_poly(int s,int e){
    for(int i=s;i<e;i++){
        printf("%dx^%d+",terms[i].coef,terms[i].expon);
    }
    printf("%d\n",terms[e].coef);
}

void attach(int coef,int expon){
    terms[avail].coef = coef;
    terms[avail++].expon = expon;
}

char compare(int a,int b){
    if(a>b) return '>';
    else if(a==b) return '=';
    else return '<';
}

void poly_add2(int As,int Ae,int Bs,int Be,int *Cs,int *Ce){
    float temp;
    *Cs = avail;
    int Apos = As,Bpos = Bs;
    while(Apos<=Ae && Bpos <= Be){
        if(terms[Apos].expon>terms[Bpos].expon){
            attach(terms[Apos].coef,terms[Apos].expon);
            Apos++;
        }else if(terms[Apos].expon == terms[Bpos].expon){
            temp = terms[Apos].coef + terms[Bpos].coef;
            attach(temp,terms[Apos].expon);
            Apos++;Bpos++;
        }else{
            attach(terms[Bpos].coef,terms[Bpos].expon);
            Bpos++;
        }
    }
    *Ce = avail-1;
}

int main(){
    int As=0,Ae=2,Bs=3,Be=5,Cs,Ce;
    print_poly(As,Ae);
    print_poly(Bs,Be);
    poly_add2(As,Ae,Bs,Be,&Cs,&Ce);
    printf("--------------------------\n");
    print_poly(Cs,Ce);
    return 0;
}
