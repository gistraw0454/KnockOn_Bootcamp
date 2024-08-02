#ifndef LIST_H
#define LIST_H

typedef struct Node {
    struct Node* prev;
    int data;
    struct Node* next;
} Node;

extern Node* head;
extern Node* tail;

Node* makeNode(int data);
void appendNode(int data);
void printList();
void insertNode(int data, int idx);
void deleteNode(int idx);

#endif // LIST_H
