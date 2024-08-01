#include <stdio.h>
#include <stdlib.h>

//노드 정의
typedef struct Node{
    int data;
    struct Node* next;  //아직 Node 가 선언되지않았으니, Node* next 하면안됨.
}Node;

void appendNode(Node* head, int data){
    while(head->next!=NULL){    //head->next 가 NULL인 head 찾아가기
        head = head->next;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    head->next = newNode;
    newNode->data = data;
    newNode->next = NULL;
}

void printList(Node* head){
    Node* node;
    node = head->next;  //진짜 head 말고, 그 이후부터 쭉 next를 따라가며 출력을 해보자.
    while(node!=NULL){
        printf("%d ",node->data);
        node = node->next;
    }
    printf("\n");
}

void insertNode(Node* head, int data, int idx)
{
    Node* preNode = head;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    for (int i=0; i < idx; i++){
        if (preNode->next == NULL){
            free(newNode);
            return; // 말도안되는 idx를 넣으면 실행
        }
        preNode= preNode->next;
    }
    newNode->next = preNode->next;
    preNode->next = newNode; 
}

void deleteNode(Node* head, int idx){   //해당 인덱스 값 삭제
    Node* tmp = head;
    Node* target = NULL;

    for (int i=0; i < idx; i++){
        tmp= tmp->next; //target 앞 노드를 가리킴
    }
    target = tmp->next; //target 포인터 설정
    tmp->next = target->next;   // 해당 target 연결삭제
    free(target);
}

int main()
{
	Node* head = (Node*)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    appendNode(head, 11);
    appendNode(head, 22);
    appendNode(head, 33);
    appendNode(head, 44);
    appendNode(head, 55);
    printList(head);

    insertNode(head, 66, 2);
    printList(head);

    deleteNode(head, 4);
    printList(head);
    
    return 0;
}