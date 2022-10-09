#include <stdio.h>

int fibo_for(int a){
    if(a == 0) return 0;
    if(a == 1) return 1;
    int first = 0;
    int sec = 1;
    int result;
    for(int i = 2;i<=a;i++){
        result = first + sec;
        first = sec;
        sec = result;
    }
    return result;
}

int fibo_recursion(int a){
    if(a == 0) return 0;
    else if(a == 1) return 1;
    else{
        return fibo_recursion(a-2)+fibo_recursion(a-1);
    }
}

int main(){
    printf("%d \n",fibo_recursion(10));
    printf("%d \n",fibo_for(10));
    return 0;
}