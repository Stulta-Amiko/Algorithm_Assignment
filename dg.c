#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;

int is_empty()
{
   return(top == -1);
}

int is_full()
{
   return(top == MAX_STACK_SIZE - 1);
}

void push(element item)
{
   if (is_full()) {
      fprintf(stderr, "스택포화에러\n");
      return;
   }
   else stack[++top] = item;

}

element pop()
{  
   if (is_empty()) {
      fprintf(stderr, "스택공백에러\n");
      exit(1);
   }
   else return stack[top--];
}

element peek()
{
   if (is_empty()) {
      fprintf(stderr, "스택공백에러\n");
      exit(1);
   }
   else return stack[top];
}

int fib(int n)
{

   if (n == 0){ push(0); return 0;}
   if (n == 1) {push(0); push(1); return 1;}

   int pp = 0;
   int p = 1;
   int result = 0;
   int pop_result;
   push(0);
   push(1);

   for (int i = 2; i <= n; i++) {
      result = p + pp;
      pp = p;
      p = result;
      push(result);
   }

   for (int i = n; i > 0; i--) {
      pop_result = pop();
      printf("%d ", pop_result);
   }
   return result;
}

int main()
{
   int fib_number;
   printf("숫자를 입력하세요.");
   scanf("%d", &fib_number);
   printf("%d", fib(fib_number));
}