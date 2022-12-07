#include <stdio.h>
#include <stdlib.h>

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
        printf("%d->",p->data);
    }
    printf("\n");
}

Listnode* searchlist(Listnode *head,int value){
    Listnode *p = head;
    while(p != NULL){
        if(p->data == value)
            return p;
        p = p->link;
    }
    return NULL;
}

Listnode* concatlsit(Listnode *first,Listnode *second){
    if(first == NULL)return second;
    else if(second == NULL)return second;
    else{
        Listnode *p;
        while(p->link != NULL)
            p = p->link;
        p->link = second;
        return first;
    }
    return NULL;
}

int main(){
    Listnode *head = NULL;
    for (int i = 0; i < 5; i++) {
        head = insert_first(head, i);
        print_list(head);
    }
    for (int i = 0; i < 5; i++) {
        head = delete_first(head);
        print_list(head);
    }
return 0;
}