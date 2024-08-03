#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct Stack{
    Node* top;  //head 포인터라고 생각해도 된다.
}Stack;

// 초기화 함수 
void init(Stack* stack){
    stack-> top = NULL;
}

void push(Stack* stack, int data){
    Node* tmp = (Node*)malloc(sizeof(Node)); //새 노드 생성
    tmp->data = data;

    // stack이 비어있다면 ?
    if (stack->top == NULL){
        tmp->next = NULL;
    }
    else{
        tmp->next = stack->top;
    }
    stack->top = tmp;
}

int pop(Stack* stack){

    // stack이 비어있다면?
    if (stack->top == NULL){
        printf("비어있는 stack입니다 !");
        return ;
    }
    Node* tmp = stack->top;
    int data = tmp->data;
    stack->top = stack->top->next;
    free(tmp);
    return data;
}

void printStack(Stack* stack){
    Node* tmp = stack->top;
    printf("top (낮은주소) ----------> bottom (높은 주소) \n");
    while(tmp){
        printf("%d ",tmp->data);
        tmp = tmp->next;
    }
    printf("\n\n");
}

int main()
{   
	Stack s;
	init(&s);
	push(&s,11); printStack(&s);
	push(&s,22); printStack(&s);
	push(&s,33); printStack(&s);
	push(&s,44); printStack(&s);
	
	pop(&s); printStack(&s);
	pop(&s); printStack(&s);
	pop(&s); printStack(&s);
	pop(&s); printStack(&s);
	return 0;
}