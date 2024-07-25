// 다음과 같은 코드를 이해해봅시다.
#include <stdio.h>

struct Student {
    char name[20];
    int score;
};

void print_student(struct Student* s) {
    printf("Name: %s, Score: %d\n", s->name, s->score);
}

int main() {
    struct Student students[5];
    for (int i=0; i<5; i++){
        scanf("%s %d",&students[i].name,&students[i].score);
	    print_student(&students[i]);
    }
    return 0;
}