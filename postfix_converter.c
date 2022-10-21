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

int prec(char c){
    switch(c){
        case '(': case')': return 0; break;
        case '*': case'/': return 2; break;
        case '+': case'-': return 1; break;
    }
}

char infix_to_postfix(char exp[]){
    char ch,top_op;
    int len = strlen(exp);
    Stacktype s;
    init_stack(&s);
    for(int i=0;i<len;i++){
        ch = exp[i];
        switch(ch){
            case '+': case '-': case '*': case '/':
                while(!is_empty(&s)&&(prec(ch)<=prec(peek(&s))))
                    printf("%c",pop(&s));
                    push(&s,ch);
                    break;
            case '(': push(&s,ch); break;
            case ')':
                top_op = pop(&s);
                while(top_op!='('){
                    printf("%c",top_op);
                    top_op = pop(&s);
                }break;
            default :
                printf("%c",ch);
        }
    }
    while(!is_empty(&s))
        printf("%c",pop(&s));
}

int main(){
    char *s = "(2+3)*4+9";
     printf("중위표시수식 %s \n", s); 
     printf("후위표시수식 "); 
     infix_to_postfix(s); 
     printf("\n");
    return 0;
}