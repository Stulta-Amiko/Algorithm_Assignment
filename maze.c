#include <stdio.h>
#define MAX_STACK_SIZE 100
#define MAZE_SIZE 6

typedef struct{
    short r;
    short c;
}element;

typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
}StackType;

element here = {1,0},entry = {1,0};

char maze[MAZE_SIZE][MAZE_SIZE] = { { '1', '1', '1', '1', '1', '1' },
{ 'e', '0', '1', '0', '0', '1' },
{ '1', '0', '0', '0', '1', '1' },
{ '1', '0', '1', '0', '1', '1' },
{ '1', '0', '1', '0', '0', 'x' },
{ '1', '1', '1', '1', '1', '1' },
};

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
    int r,c;
    StackType s;
    init_stack(&s);
    while(maze[here.r][here.c] == 'x')
    return 0;
}