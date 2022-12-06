#include <stdio.h>
#define MAX_LIST_SIZE 100

typedef int element;
typedef struct{
    element array[MAX_LIST_SIZE];
    int size;
}ArrayListType;

void init(ArrayListType *list){
    list->size = 0;
}

int is_empty(ArrayListType *list){
    return list->size == 0;
}

int is_full(ArrayListType *list){
    return list->size == MAX_LIST_SIZE;
}

element get_entry(ArrayListType *list,int pos){
    if(pos < 0 || list->size <= pos)
        return 0;
    return list->array[pos];
}

void print_list(ArrayListType *list){
    for(int i = 0;i<list->size;i++){
        printf("%d->",list->array[i]);
    }
    printf("\n");
}

void insert_last(ArrayListType *list,element item){
    if(is_full(list))
        printf("오류");
    list->array[list->size++] = item;
}

void insert_pos(ArrayListType *list,int pos,element item){
    if(is_full(list))
        printf("배열이 꽉참");
    if(pos>=0 && pos<=list->size){
        for(int i = (list->size)-1;i>=pos;i--)
            list->array[i+1] = list->array[i];
        list->array[pos] = item;
        list->size++;
    }
}
element delete_pos(ArrayListType *list,int pos){
    element item;
    if(is_empty(list)||pos>=list->size || pos<0){
        printf("비어있는 리스트임");
        return 0;
    }

        item = list->array[pos];
        for(int i=pos;i<(list->size)-1;i++)
            list->array[i] = list->array[i+1];
        list->size--;
        return item;
}
int main(){
    ArrayListType list;
    init(&list);
    insert_pos(&list, 0, 10); print_list(&list);
    insert_pos(&list, 0, 20); print_list(&list);
    insert_pos(&list, 0, 30); print_list(&list);
    insert_last(&list,40);  print_list(&list);
    delete_pos(&list, 0); print_list(&list);
    return 0;
}