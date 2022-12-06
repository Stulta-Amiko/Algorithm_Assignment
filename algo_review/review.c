#include <stdio.h>

int factorial(int n){
    if(n==1) return 1;
    return n*factorial(n-1);
}

int fibo_recur(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    return fibo_recur(n-1) + fibo_recur(n-2);
}

int fibo_for(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    int p = 0;
    int pp = 1;
    int result = 0;
    for(int i=2;i<=n;i++){
        result = p+pp;
        p = pp;
        pp = result;
    }
    return result;
}

void hanoi(int n,char from,char tmp,char to){
    if(n==1) printf("원반 1을 %c에서 %c로 옮긴다.\n",from, to);
    else{
        hanoi(n-1,from,to,tmp);
        printf("원판 %d를 %c에서 %c로 옮긴다.\n",n,from,to);
        hanoi(n-1,tmp,from,to);
    }
}

int main(){
    printf("%d %d %d",factorial(10),fibo_for(10),fibo_recur(10));
    hanoi(4,'A','B','C');
    return 0;
}