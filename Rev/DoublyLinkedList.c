#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    struct Node* prev;
    int data;
    struct Node* next;
}Node;

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

    //첫노드 생성이면
    if (head == NULL) {
        head= newNode;
        tail = newNode;
    } 
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void printList(){
    Node* node= head; //head에는 담겨있는 data가 없으니 node로 옮겨준다.
    while(node!=tail){
        printf("%d ",node->data);
        node = node->next;
    }
    printf("%d\n",node->data);
}

void insertNode(int data, int idx){
    Node* newNode = makeNode(data);
    Node* tmp = head;
    if (idx==0){
        newNode->next = head;
        if ( head != NULL ){
            head->prev = newNode;
            tail= newNode;
        }
        head = newNode;
    }
    int i=0;
    
    while(tmp!=NULL && i+1 < idx ){
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
    int i=0;
    
    while(tmp!=NULL && i+1 < idx ){
        tmp = tmp->next;
        i++;
    }

    tmp->prev->next = tmp->next;
    tmp->next->prev = tmp->prev;
    tmp->prev = NULL;
    tmp->next = NULL;
    free(tmp);
}


int main()
{   
    appendNode(11);
    appendNode(22);
    appendNode(33);
    appendNode(44);
    appendNode(55);
    printList();

    insertNode(66, 2);
    printList();

    deleteNode(4);
    printList();
    
    return 0;
}