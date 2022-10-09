#include <stdio.h>

double power(double x,int a){
    if(a == 0){
        return 1;
    }else if(a%2 == 0){
        return power(x*x,a/2);
    }else{
        return x*power(x*x,(a-1)/2);
    }
}

double slowpower(double x,int a){
    double result = 1;
    for(int i = a;i>0;i--){
        result *= x;
    }
    return result;
}

int main(){
    printf("%.1f\n",power(2,10));
    printf("%.1f",slowpower(2,10));
    return 0;
}