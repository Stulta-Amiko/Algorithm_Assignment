#include <stdio.h>

int main(void){
    int num1,num2,p,q;

    printf("출력");
    scanf("%d %d", &num1,&num2);

    q = num1;
    p = num2;

    printf("\n %d %d", q/p,q%p);
}