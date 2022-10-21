#include <stdio.h>
#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
}StackType;

void init_stack(StackType* stack){
    stack->top = -1;
}

int is_full(StackType* s){
    return(s->top==MAX_STACK_SIZE-1);
}

int is_empty(StackType* s){
    return(s->top==-1);
}

void push(StackType* s,element item){
    if(is_full(s)){
        return;
    }
    s->data[++s->top] = item;
}

element pop(StackType* s){
    return s->data[s->top--];
}

element peek(StackType* s){
    return s->data[s->top];
}
int main(){

}