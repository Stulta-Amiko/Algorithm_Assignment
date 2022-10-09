#include <stdio.h>

int fact(int a){
    if(a<=1){
        return 1;
    }else{
        return fact(a-1)*a;
    }
}

int forfact(int a){
    int fact = 1;
    for(int i=a;i>0;i--){
        fact *= i;
    }
    return fact;
}

int main(){
    printf("%d \n", fact(10));
    printf("%d",forfact(10));
    return 0;
}