#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct{
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
}QueueType;

void init_queue(QueueType *q){
    q->front = q->rear = 0;
}

int is_full(QueueType *q){
    return(((q->rear+1)%MAX_QUEUE_SIZE) == (q->front&MAX_QUEUE_SIZE));
}

int is_empty(QueueType *q){
    return(q->rear == q->front);
}

void enqueue(QueueType *q,element data){
    if(is_full(q))
        exit(1);
    q->rear = (q->rear+1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = data;
}

element dequeue(QueueType *q){
    if(is_empty(q))
        return 0;
    q->front = (q->front+1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

void queue_print(QueueType *q){
    printf("QUEUE(front: %d,rear: %d)",q->front,q->rear);
    if(!is_empty(q)){
        int i=q->front;
        do{
            i = (i+1) %MAX_QUEUE_SIZE;
            printf("%d |",q->data[i]);
            if(i == q->rear)
                break;
        }while(i!=q->front);
    }
    printf("\n");
}


int main(){
    QueueType q;
    init_queue(&q);
    int element;
    while(!is_full(&q)){
        printf("수를 입력하세요");
        scanf("%d",&element);
        enqueue(&q,element);
        queue_print(&q);
    }

    while(!is_empty(&q)){
        printf("꺼내진 정수: %d\n",dequeue(&q));
        queue_print(&q);
    }
    return 0;
}