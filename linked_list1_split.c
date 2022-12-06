#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;
typedef struct Listnode{
    element data;
    struct Listnode* link;
}Listnode;

Listnode* insert_first(Listnode *head,int value){
    Listnode *p = (Listnode *)malloc(sizeof(Listnode));
    p->data = value;
    p->link = head;
    head = p;
    return head;
}

Listnode* insert(Listnode *head,Listnode *pre,int value){
    Listnode *p = (Listnode *)malloc(sizeof(Listnode));
    p->data = value;
    p->link = pre->link;
    pre->link = p;
    return head;
}

Listnode* delete_first(Listnode *head){
    Listnode *removed;
    if(head==NULL) return NULL;
    removed = head;
    head = removed->link;
    free(removed);
    return head;
}

Listnode* delete(Listnode *head,Listnode *pre){
    Listnode *removed;
    if(head==NULL || pre==NULL) return NULL;
    removed = pre->link;
    pre->link = removed->link;
    free(removed);
    return head;
}

void print_list(Listnode *head){
    for(Listnode *p=head;p!=NULL;p = p->link){
        printf("%d ",p->data);
    }
    printf("\n");
}

Listnode* reverse(Listnode *head){
    Listnode *p,*q,*r;
    p = head;
    q = NULL;
    while(p != NULL){
        r = q;
        q = p;
        p = p->link;
        q->link = r;
    }
    return q;
}

int main(){
    Listnode *a,*b,*c,*d = NULL;
    Listnode *f = NULL;
    int input;
    printf("입력값 크기:"); 
    scanf("%d",&input);    
    printf("정수를 입력 하시오: "); 
    char input_arr[100];

    scanf(" %[^\n,]",input_arr);
    char *ptr = strtok(input_arr," ");
    while(ptr != NULL){
        int in = atoi(ptr);
        a = insert_first(a,in);
        ptr = strtok(NULL," ");
    }
    a = reverse(a);
    int cnt = 0;
    Listnode *tmp = a;
    while(tmp != NULL){
        int s = tmp->data;
        switch(cnt%3){
            case 0:
                b = insert_first(b,s);
                break;
            case 1:
                f = insert_first(f,s);
                break;
            case 2:
                d = insert_first(d,s);
                break;
            default:
                printf("잘못되었습니다.");
        }
        cnt++;
        tmp = tmp->link;
    }
    b = reverse(b);
    f = reverse(f);
    d = reverse(d);
    printf("B: ");
    print_list(b);
    printf("C: ");
    print_list(f);
    printf("D: ");
    print_list(d);
return 0;
}