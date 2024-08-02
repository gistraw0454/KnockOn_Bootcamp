#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// head 와 tail을 전역변수로 설정
Node* head = NULL;
Node* tail = NULL;

// 노드 생성 함수
Node* makeNode(int data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->prev = NULL;
    node->data = data;
    node->next = NULL;
    return node;
}

void appendNode(int data){
    Node* newNode = makeNode(data);

    // 첫 노드 생성이면
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void printList(){
    Node* node = head;
    while(node != tail){
        printf("%d ", node->data);
        node = node->next;
    }
    printf("%d\n", node->data);
}

void insertNode(int data, int idx){
    Node* newNode = makeNode(data);
    Node* tmp = head;
    if (idx == 0){
        newNode->next = head;
        if (head != NULL){
            head->prev = newNode;
            tail = newNode;
        }
        head = newNode;
    }
    int i = 0;

    while(tmp != NULL && i + 1 < idx){
        tmp = tmp->next;
        i++;
    }

    newNode->prev = tmp->prev;
    newNode->next = tmp;
    tmp->prev->next = newNode;
    tmp->prev = newNode;
}

void deleteNode(int idx){
    Node* tmp = head;
    int i = 0;

    while(tmp != NULL && i + 1 < idx){
        tmp = tmp->next;
        i++;
    }

    tmp->prev->next = tmp->next;
    tmp->next->prev = tmp->prev;
    tmp->prev = NULL;
    tmp->next = NULL;
    free(tmp);
}
