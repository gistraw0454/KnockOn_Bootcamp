// ������ ���� �ڵ带 �����غ��ô�.
#include <stdio.h>

struct Student {
    char name[20];
    int score;
};

void print_student(struct Student* s) {
    printf("Name: %s, Score: %d\n", s->name, s->score);
}

int main() {
    struct Student s1 = {"Nogony", 90};
	print_student(&s1);
    return 0;
}