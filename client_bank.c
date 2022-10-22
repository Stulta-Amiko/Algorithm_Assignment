#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_QUEUE_SIZE 100

typedef struct{
    int id;
    int arrival_time;
    int service_time;
    int is_VIP;
}element;

typedef struct{
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
}Queuetype;

void init_queue(Queuetype *q){
    q->front = 0;
    q->rear = 0;
}

int is_full(Queuetype *q){
    return (((q->front + 1)%MAX_QUEUE_SIZE) == ((q->rear)&MAX_QUEUE_SIZE));
}

int is_empty(Queuetype* q){
    return (q->front == q->rear);
}

void enqueue(Queuetype *q,element item){
    if(is_full(&q))
        return;
    q->rear = (q->rear + 1)%MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

element dequeue(Queuetype *q){
    if(is_empty(&q))
        exit(1);
    q->front = (q->front + 1)%MAX_QUEUE_SIZE;
    return q->data[q->front];
}

int main(){
    int minutes = 50000; //시간
    int total_wait = 0; //전체 대기 시간
    int gen_wait = 0; // 일반 고객 대기 시간
    int VIP_wait = 0; // VIP 고객 대기 시간
    int total_customers = 0; // 전체 방문 고객수
    int gen_customers = 0; // 일반고객 방문 수
    int VIP_customers = 0; // VIP 고객 방문 수
    int service_time = 0; // 서비스 제공 시간
    int gen_service_time = 0; //일반 고객 서비스 제공시간
    int VIP_service_time = 0; //VIP 고객 서비스 제공시간
    int service_customer;
    Queuetype general_queue; 
    Queuetype VIP_queue;
    init_queue(&general_queue);
    init_queue(&VIP_queue);
    srand(time(NULL));
    for(int clock=0;clock<minutes;clock++){
        printf("현재시각 %d\n",clock);
        int percentage = rand()%10;
        if(percentage<1){
            element VIP;
            VIP.is_VIP = 1;
            VIP.arrival_time = clock;
            VIP.id = total_customers++;
            VIP_customers++;
            VIP.service_time = rand()%3+1;
            enqueue(&VIP_queue,VIP);
            printf("VIP 고객 %d가 %d분에 들어옵니다 업무처리시간 %d분\n",VIP.id,VIP.arrival_time,VIP.service_time);
        }else if(percentage>0 && percentage<3){
            element gen_customer;
            gen_customer.is_VIP = 0;
            gen_customer.arrival_time = clock;
            gen_customer.id = total_customers++;
            gen_customers++;
            gen_customer.service_time = rand()%3+1; 
            enqueue(&general_queue,gen_customer);
            printf("일반 고객 %d가 %d분에 들어옵니다 업무처리시간 %d분\n",gen_customer.id,gen_customer.arrival_time,gen_customer.service_time);
        }
        if(service_time>0){
            //printf("고객 %d 업무처리중입니다. \n",service_customer);
            service_time--;
        }else{
            if (!is_empty(&VIP_queue)) {
                    element VIP_customer = dequeue(&VIP_queue);
                    service_customer = VIP_customer.id;
                    service_time = VIP_customer.service_time;
                    VIP_service_time = VIP_customer.service_time; 
                    printf("VIP 고객 %d이 %d분에 업무 시작, 대기시간은 %d분.\n",
                    VIP_customer.id, clock, clock - VIP_customer.arrival_time); 
                    total_wait += clock - VIP_customer.arrival_time;
                    VIP_wait += clock - VIP_customer.arrival_time;
            }else if(is_empty(&VIP_queue)&&!is_empty(&general_queue)){
                    element gen_customer = dequeue(&general_queue);
                    service_customer = gen_customer.id;
                    service_time = gen_customer.service_time;
                    gen_service_time = gen_customer.service_time;
                    printf("일반 고객 %d이 %d분에 업무 시작, 대기시간은 %d분.\n",
                    gen_customer.id, clock, clock - gen_customer.arrival_time);
                    total_wait += clock - gen_customer.arrival_time; 
                    gen_wait += clock - gen_customer.arrival_time; 
            }
        }
    }
    printf("전체 대기 시간=%d분 VIP 대기시간 %d분 일반 고객 대기시간 %d분\n", total_wait,VIP_wait,gen_wait);
    printf("전체 방문 수%d명 VIP 고객 방문 수 %d명 일반 고객 방문 수 %d명\n", total_customers,VIP_customers,gen_customers);
    printf("전체 평균 대기 시간=%d분 VIP 평균 대기 시간 %d분 일반 평균 고객 대기시간 %d분\n", total_wait/total_customers,VIP_wait/VIP_customers,gen_wait/gen_customers);
    return 0;
}