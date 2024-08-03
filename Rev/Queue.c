#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct Queue{
    Node* front;
    Node* rear;
}Queue;

// 초기화 함수
void init(Queue* queue){
    queue-> front = NULL;
    queue-> rear = NULL;
}

void printQueue(Queue* queue){
    Node* tmp = queue->front;
    while(tmp!=NULL){
        printf("%d ",tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

void enqueue(Queue* queue,int data){
    
    Node* tmp=(Node*)malloc(sizeof(Node));
    tmp->data= data;
    tmp->next= NULL;
    //queue 가 비어있다면?
    if (queue->front== NULL&& queue->rear==NULL){
        queue->front = tmp;
        queue->rear = tmp; 
    }
    else{
        queue->rear->next = tmp;
        queue->rear = tmp;
    }
}

int dequeue(Queue* queue){
    if (queue->front==NULL&& queue->rear == NULL){
        printf("비어있는 queue입니다.\n");
        return -1;
    }
    Node* tmp = queue->front;
    int data= tmp->data;
    queue->front = tmp->next;
    if (queue->front == NULL) { // 큐가 비어있는 상태로 만들 때 rear도 NULL로 설정 이게 필요한진 모르겠음
        queue->rear = NULL;
    }
    free(tmp);
    return data;

}


int main()
{
	Queue que; 
	
	init(&que); // 초기화 
	
	enqueue(&que,10); printQueue(&que); // 10 삽입
	enqueue(&que,30); printQueue(&que); // 30 삽입
	enqueue(&que,40); printQueue(&que); // 40 삽입
	enqueue(&que,60); printQueue(&que); // 60 삽입
	dequeue(&que); printQueue(&que); // 10 삭제
	dequeue(&que); printQueue(&que); // 30 삭제
	dequeue(&que); printQueue(&que); // 40 삭제
	dequeue(&que); printQueue(&que); // 60 삭제
	return 0;
}