#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct{
    int front;
    int rear;
    int data[MAX_QUEUE_SIZE];
}QueueType;

void init_queue(QueueType *q){
    q->front = -1;
    q->rear = -1;
}

int is_empty(QueueType *q){
    return(q->front == q->rear);
}

int is_full(QueueType *q){
    return q->front == MAX_QUEUE_SIZE -1;
}

void enqueue(QueueType *q,element item){
    if(is_full(q))
        exit(1);
    q->data[++(q->rear)] = item;
}

element dequeue(QueueType *q){
    if(is_empty(q))
        return 0;
    return q->data[++(q->front)];
}

void queue_print(QueueType *q){
    for(int i=0;i<MAX_QUEUE_SIZE;i++){
        if(i<=q->front || i>q->rear)
        printf("    |");
        else
        printf("%d | ",q->data[i]);
    }
    printf("\n");
}

int main(){
int item = 0;
QueueType q;
init_queue(&q);
enqueue(&q, 10); queue_print(&q); enqueue(&q, 20); queue_print(&q); enqueue(&q, 30); queue_print(&q); item = dequeue(&q); queue_print(&q); item = dequeue(&q); queue_print(&q); item = dequeue(&q); queue_print(&q);
    return 0;
}