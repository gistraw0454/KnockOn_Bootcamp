// 아래의 코드를 개선하여 봅시다.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char name[20];
    int age;
}Student;

int main() {
    Student *s;
    s = (Student*)malloc(sizeof(Student));

    strcpy(s->name, "Nogony");
    s->age = 20;

    printf("Name: %s, Age: %d\n", s->name, s->age);
    free(s);

    return 0;
}