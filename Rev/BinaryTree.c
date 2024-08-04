#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;

    struct Node* right;
    struct Node* left;
}Node;

void Insert(Node** root, int data) {
    if (*root == NULL) {
        *root = (Node*)malloc(sizeof(Node));
        (*root)->data = data;
        (*root)->left = NULL;
        (*root)->right = NULL;
    } else {
        if ((*root)->data < data) {
            Insert(&((*root)->right), data);
        } else if ((*root)->data > data) {
            Insert(&((*root)->left), data);
        } else {
            printf("�ߺ� ���x\n");
        }
    }
}
// Node* Insert(Node* root, int data) {
//     if (root == NULL) {
//         Node* newNode = (Node*)malloc(sizeof(Node));
//         newNode->data = data;
//         newNode->left = NULL;
//         newNode->right = NULL;
//         return newNode;
//     } else {
//         if (root->data < data) {
//             root->right = Insert(root->right, data);
//         } else if (root->data > data) {
//             root->left = Insert(root->left, data);
//         } else {
//             printf("�ߺ����x\n");
//         }
//         return root;
//     }
// }
// �̰� �̷����ϰ� main���� insert�Ҷ� root = insert(root, 11); �̷������� �־��൵��

void printInOrder(Node* root) {
    if (root != NULL) {
        printInOrder(root->left);
        printf("%d - ", root->data);
        printInOrder(root->right);
    }
}

void printPreOrder(Node* root) {
    if (root != NULL) {
        printf("%d - ", root->data);
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

void printPostOrder(Node* root) {
    if (root != NULL) {
        printPostOrder(root->left);
        printPostOrder(root->right);
        printf("%d - ", root->data);
    }
}

int main(){
    Node* root = NULL;

    Insert(&root, 20);
    Insert(&root, 10);
    Insert(&root, 32);
    Insert(&root, 4);
    Insert(&root, 13);
    Insert(&root, 25);
    Insert(&root, 55);

    printf("In-order: ");
    printInOrder(root);
    printf("\n");

    printf("Pre-order: ");
    printPreOrder(root);
    printf("\n");

    printf("Post-order: ");
    printPostOrder(root);
    printf("\n");
}