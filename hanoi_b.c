#include <stdio.h>

int cnt = 0;

int hanoi(int n,int a,int b,int c){
    if(n == 1) cnt++;
    else{
        hanoi(n-1,a,c,b);
        cnt++;
        hanoi(n-1,b,a,c);
    }
    return cnt;
}

void hanoi_print(int n,int a,int b,int c){
    if(n == 1) printf("%d %d\n",a,c);
    else{
        hanoi_print(n-1,a,c,b);
        printf("%d %d\n",a,c);
        hanoi_print(n-1,b,a,c);
    }
}

int main(){
    int input;
    scanf("%d", &input);
    printf("%d\n",hanoi(input,1,2,3));
    hanoi_print(input,1,2,3);
}