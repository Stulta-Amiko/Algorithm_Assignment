#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;
typedef struct Listnode{
    struct Listnode *link;
    element data;
}Listnode;

Listnode *insert_first(Listnode *head,element data){
    Listnode *node = (Listnode *)malloc(sizeof(Listnode));
    node->data = data;
    if(head==NULL){
        head = node;
        node->link = head;
    }else{
        node->link = head->link;
        head->link = node;
    }
    return head;
}

Listnode *insert_last(Listnode *head,element data){
    Listnode *node = (Listnode *)malloc(sizeof(Listnode));
    node->data = data;
    if(head == NULL){
        head = node;
        node->link = head;
    }else{
        node->link = head->link;
        head->link = node;
        head = node;
    }
    return head;
}

Listnode *search(Listnode *head, element data){
    Listnode *p = head;
    if(head == NULL) return NULL;
    p = head->link;
    do{
        if(p->data == data) return p;
        p = p->link;
    }while(p!=head);
    if(p->data == data) return p;
    else return NULL;
}

void print_list(Listnode *head){
    Listnode *p;
    if(head == NULL) return;
    p = head->link;
    do{
        printf("%d->",p->data);
        p = p->link;
    }while(p!=head);
    printf("%d->",p->data);
}

int main(){
    Listnode *a = NULL;
    int input,cnt;
    printf("입력값 크기:"); 
    scanf("%d",&input);    
    printf("정수를 입력 하시오: "); 
    char input_arr[100];
    scanf(" %[^\n,]",input_arr);
    int find;
    char *ptr = strtok(input_arr," ");
    while(ptr != NULL){
        int in = atoi(ptr);
        a = insert_first(a,in);
        ptr = strtok(NULL," "); 
        cnt++; 
    }
    if(cnt != input){
        printf("입력값과 입력한 숫자의 갯수가 일치하지 않습니다.");
        return 0;
    }
    printf("찾으려는 숫자를 입력하시오: ");
    scanf(" %d",&find);
    if(search(a,find) != NULL)
        printf("%d가 리스트내에 존재합니다.\n",find);
    else
        printf("%d는 리스트에 없습니다.\n",find);
}