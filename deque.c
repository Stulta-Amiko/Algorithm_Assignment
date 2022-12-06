#include <stdio.h>
#include <stdlib.h>
#define MAX_DEQUE_SIZE 7

typedef int element;
typedef struct{
    int front;
    int rear;
    int data[MAX_DEQUE_SIZE];
}DequeType;

void deque_init(DequeType *d){
    d->front = 0;
    d->rear = 0;
}

int is_empty(DequeType *d){
    return(d->front == d->rear);
}

int is_full(DequeType *d){
    return((d->rear+1)%MAX_DEQUE_SIZE == d->front % MAX_DEQUE_SIZE);
}

void add_front(DequeType *d,element item){
    if(is_full(d))
        return;
    d->data[d->front] = item;
    d->front = (d->front - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
    
}

void add_rear(DequeType *d,element item){
    if(is_full(d))
        return;
    d->rear = (d->rear +1) %MAX_DEQUE_SIZE;
    d->data[d->rear] = item;
}

element delete_front(DequeType *d){
    if(is_empty(d))
        exit(1);
    d->front = (d->front+1)%MAX_DEQUE_SIZE;
    return d->data[d->front];
}

element delete_rear(DequeType *d){
    if(is_empty(d))
        exit(1);
    d->rear = (d->rear -1)%MAX_DEQUE_SIZE;
    return d->data[d->rear];
}

element get_front(DequeType *d){
   if(is_empty(d))
        exit(1);
    return d->data[d->front]; 
}

element get_rear(DequeType *d){
       if(is_empty(d))
        exit(1);
    return d->data[d->rear]; 
}