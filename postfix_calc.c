#include <stdio.h>
#include <string.h>
#define MAX_STACK_SIZE 100
typedef int element;

typedef struct{
    element data[MAX_STACK_SIZE];
    int top;
}Stacktype;

int is_empty(Stacktype *s){
    return s->top == -1;
}

int is_full(Stacktype *s){
    return s->top == MAX_STACK_SIZE - 1;
}

void init_stack(Stacktype *s){
    s->top = -1;
}

void push(Stacktype *s,element item){
    if(is_full(&s)){
        return;
    }
    s->data[++(s->top)] = item;
}

element pop(Stacktype *s){
    if(is_empty(&s)){
        return 0;
    }
    return s->data[(s->top)--];
}

element peek(Stacktype *s){
    return s->data[s->top];
}

int eval(char a[]){
    int op1,op2,value;
    int len = strlen(a);
    char ch;
    Stacktype s;
    init_stack(&s);

    for(int i=0;i<len;i++){
        ch = a[i];
        if(ch != '+' &&ch != '-'&&ch != '/'&&ch != '*'){
            value = ch - '0';
            push(&s,value);
        }else{
            op2 = pop(&s);
            op1 = pop(&s);
            switch(ch){
                case '+':
                    push(&s,op1+op2); break;
                case '-':
                    push(&s,op1-op2); break;
                case '*':
                    push(&s,op1*op2); break;
                case '/':
                    push(&s,op1/op2); break;
            }
        }
    }
    return pop(&s);
}


int main(){
    int result;
    printf("후위표기식은 82/3-32*+\n");
    result = eval("82/3-32*+");
    printf("결과값은 %d\n", result); 
    return 0;
}