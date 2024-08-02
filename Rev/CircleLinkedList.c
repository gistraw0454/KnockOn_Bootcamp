#include <stdio.h>
#include <stdlib.h>

//노드 정의
typedef struct Node{
    int data;
    struct Node* next;  //아직 Node 가 선언되지않았으니, Node* next 하면안됨.
}Node;

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
        }
        prev = node;
        node = node->next;
    }
    while(node!=head);  // NULL 대신 head 나올때 까지 (처음이 head니까 do로 먼저 돌려줌)
}

int main()
{
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = 0;
    head->next = head;  //NULL 대신 head연결
    appendNode(head, 11);
    appendNode(head, 22);
    appendNode(head, 33);
    appendNode(head, 44);
    appendNode(head, 55);
    printList(head);

    deleteNode(head, 44);
    printList(head);

    return 0;
}