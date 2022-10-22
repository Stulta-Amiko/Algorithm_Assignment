#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUEUE_SIZE 100
typedef struct {
   int id;
   int arrival_time;
   int service_time;
} element;
typedef struct {
   element data[MAX_QUEUE_SIZE];
   int front, rear;
} QueueType;

void error(const char *message)
{
   fprintf(stderr, "%s\n", message);
   exit(1);
}

void init_queue(QueueType* q)
{
   q->front = q->rear = 0;
}

int is_empty(QueueType* q)
{
   return(q->front == q->rear);
}

int is_full(QueueType* q)
{
   return(((q->rear + 1) % MAX_QUEUE_SIZE) == (q->front % MAX_QUEUE_SIZE));
}

void queue_print(QueueType* q)
{
   printf("QUEUE(front=%d rear=%d", q->front, q->rear);
   if (!is_empty(q)) {
      int i = q->front;
      do {
         i = (i + 1) % MAX_QUEUE_SIZE;
         printf("%d|", q->data[i]);
         if (i == q->rear)
            break;
      } while (i != q->front);
   }
   printf("\n");
}

void enqueue(QueueType* q, element item)
{
   if (is_full(q))
    return;   
   q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
   q->data[q->rear] = item;

}

element dequeue(QueueType* q)
{
   if (is_empty(q))
      exit(1);
   q->front = (q->front + 1) % MAX_QUEUE_SIZE;
   return q->data[q->front];
}

element peek(QueueType* q)
{
   if (is_empty(q))
      error("큐가 공백상태입니다.");
   return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

int main(void)
{
   int minutes = 60;
   int total_wait = 0;
   int vip_wait = 0;
   int normal_wait = 0;
   int total_customers = 0;
   int vip_customers = 1;
   int normal_customers = 1;
   int normal_service_time = 0;
   int vip_service_time = 0;
   int service_customer;
   int avg_normal_wait;
   int avg_vip_wait;
   int avg_total_wait;
   QueueType vip_queue;
   QueueType normal_queue;
   init_queue(&vip_queue);
   init_queue(&normal_queue);

   srand(time(NULL));
   for (int clock = 0; clock < minutes; clock++) {
      printf("현재시각 =%d\n", clock);
      if ((rand() % 10 < 1)) {
         element vip_customer;
         vip_customer.id = vip_customers++;
         vip_customer.arrival_time = clock;
         vip_customer.service_time = rand() % 3 + 1;
         enqueue(&vip_queue, vip_customer);
         printf("vip 고객 %d이 %d분에 들어옵니다. 업무처리시간= %d분\n", vip_customer.id, vip_customer.arrival_time, vip_customer.service_time);
      }
      if((rand() % 10 < 2)) {
         element normal_customer;
         normal_customer.id = normal_customers++;
         normal_customer.arrival_time = clock;
         normal_customer.service_time = rand() % 3 + 1;
         enqueue(&normal_queue, normal_customer);
         printf("일반 고객 %d이 %d분에 들어옵니다. 업무처리시간= %d분\n", normal_customer.id, normal_customer.arrival_time, normal_customer.service_time);
      }
      
      if (vip_service_time > 0)
      {
         printf("vip고객 %d 업무처리중입니다. \n", service_customer);
         vip_service_time--;
      }
      else if (vip_service_time ==0 && normal_service_time > 0)
      {
         printf("일반고객 %d 업무처리중입니다.\n", service_customer);
         normal_service_time--;
      }
      else {
         if (!is_empty(&vip_queue)) {
            element vip_customer = dequeue(&vip_queue);
            service_customer = vip_customer.id;
            vip_service_time = vip_customer.service_time;
            printf("vip고객 %d이 %d분에 업무를 시작합니다. 대기시간은 %d분이었습니다.\n", vip_customer.id,clock, clock - vip_customer.arrival_time);
            vip_wait += clock - vip_customer.arrival_time;
         }
         else if (!is_empty(&normal_queue)) {
            element normal_customer = dequeue(&normal_queue);
            service_customer = normal_customer.id;
            normal_service_time = normal_customer.service_time;
            printf("일반고객 %d이 %d분에 업무를 시작합니다. 대기시간은 %d분이었습니다.\n", normal_customer.id,clock, clock - normal_customer.arrival_time);
            normal_wait += clock - normal_customer.arrival_time;
         }
      }   
   }
   total_customers = normal_customers + vip_customers;
   total_wait = vip_wait + normal_wait;
   avg_normal_wait = normal_wait / normal_customers;
   avg_vip_wait = vip_wait / vip_customers;
   avg_total_wait = total_wait / total_customers;
   printf("vip고객의 전체 대기 시간은 %d,방문수는%d, 평균대기시간은 %d입니다.\n", vip_wait, vip_customers, avg_vip_wait);
   printf("일반고객의 전체 대기 시간은 %d,방문수는%d, 평균대기시간은 %d입니다.\n", normal_wait, normal_customers, avg_normal_wait);
   printf("전체 고객의 전체 대기 시간은 %d,방문수는%d, 평균대기시간은 %d입니다.\n", total_wait, total_customers, avg_total_wait);
   
   return 0;
}
