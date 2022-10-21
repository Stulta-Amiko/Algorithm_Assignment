#include <stdio.h>
#define MAX_STACK_SIZE 100

typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;

int is_full(){
    return(top==MAX_STACK_SIZE-1);
}

int is_empty(){
    return(top==-1);
}

void push(element item){
    if(is_full()){
        return;
    }
    stack[++top] = item;
}

element pop(){
    return stack[top--];
}

element peek(){
    return stack[top];
}

void fibo(int a){
    int first = 0;
    int sec = 0;
    int result = 0;
    push(0);
    push(1);
    for(int i=1;i<a;i++){
        sec = pop();
        first = pop();
        result = first+sec;
        push(first);
        push(sec);
        push(result);
    }
    for(int i=0;i<=top;i++){
        printf("%d ",stack[i]);
    }
}
int main(){
    fibo(10);
    return 0;
}