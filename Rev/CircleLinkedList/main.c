#include <stdio.h>
#include <stdlib.h>
#include "list.h"

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
