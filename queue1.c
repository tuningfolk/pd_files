#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int value;
    struct node* next;
}node;

typedef struct queue{
    node* head;
    node* tail; 
}queue;

node* create(char k){
    node* n = malloc(sizeof(node));
    n->value = k;
    n->next = NULL;
    return n;
}

void enqueue(queue* q, int k){
    if(q->head == NULL){
        node* n = create(k);
        q->head = n;
        q->tail = q->head;
    }else{
        node* n = create(k);
        q->tail->next = n;
        q->tail = n;
        
    }
}

void dequeue(queue* q){
        printf("hello");
    if(q->head = NULL){
        printf("NULL\n");
        return;
    }
    if(q->head == q->tail){
        // free(q->head);
        q->head = NULL;
    }else{
        printf("%d\n", (q->head->value));
        // node* n = q->head->next;
        // free(q->head);
        q->head = q->head->next;
    }
}
void freelist(node* n){
    while(n!=NULL){
        freelist(n->next);
        free(n);
    }
}

void print(queue* q){
    if(q->head == NULL){
        printf("NULL\n");
        return;
    }else{
        node* n = q->head;
        while(n!=NULL){
            printf("%d ", n->value);
            n = n->next;
        }printf("\n");
    }
}

int main(){
    queue* q = malloc(sizeof(queue));
    q->head = NULL;
    q->tail = NULL; 

    enqueue(q, 5);
    enqueue(q, 6);
    enqueue(q, 9);
    print(q);
        printf("%d\n", q->head->next->value);
    dequeue(q);
    print(q);
    dequeue(q);
    print(q);
    free(q->head);
    free(q);
    return 0;
}