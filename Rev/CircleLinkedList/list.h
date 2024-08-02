#ifndef LIST_H
#define LIST_H

typedef struct Node{
    int data;
    struct Node* next;
} Node;

void appendNode(Node* head, int data);
void printList(Node* head);
void deleteNode(Node* head, int target);

#endif // LIST_H
