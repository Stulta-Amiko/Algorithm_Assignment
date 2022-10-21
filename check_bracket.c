#include <stdio.h>
#include <string.h>
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

int check_matching(const char *p){
    char ch,open_ch;
    int len = strlen(p);
    StackType s;
    init_stack(&s);
    for(int i=0;i<len;i++){
        ch = p[i];
        switch(ch){
            case '(': case '{': case '[':
            push(&s,ch); break;
            case ')': case '}': case ']':
            open_ch = pop(&s);
            if((ch == ')'&& open_ch !='(')||(ch == ']'&& open_ch !='[')||(ch == '}'&& open_ch !='{'))
                return 0;
        }
    }
    if(!is_empty(&s)) return 0;
    return 1;
}


int main(){
    char *p = "{ A[(i+1)]=0;} ";
    if (check_matching(p) == 1)
        printf("%s 괄호검사성공\n", p); 
    else 
        printf("%s 괄호검사실패\n", p);

return 0;
}