#include <stdio.h>
#include "list.h"

int main() {   
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
