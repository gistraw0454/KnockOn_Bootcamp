#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void appendNode(Node* head, int data){  //1번에 넣는방법
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    if (head==NULL){
        head = newNode;
        newNode->next = head;
    }
    else{
        newNode->next = head->next;
        head->next = newNode;
    }
}

void printList(Node* head) {
    if (head->next == head) {
        printf("List is empty\n");
        return;
    }
    Node* node = head->next;
    do {
        printf("%d ", node->data);
        node = node->next;
    } while (node != head); // NULL 대신 head 나올때 까지 (처음이 head니까 do로 먼저 돌려줌)
    printf("\n");
}

void deleteNode(Node* head, int target){   //해당 인덱스 값 삭제
    Node* node;
    node = head->next;
    Node* prev = head;

    do{
        if (node->data == target){
            prev->next = node->next;
            free(node);
            return;
        }
        prev = node;
        node = node->next;
    }
    while(node!=head);  // NULL 대신 head 나올때 까지 (처음이 head니까 do로 먼저 돌려줌)
}
