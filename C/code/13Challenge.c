// �پ��� ��带 ����� ���ô�.
#include <stdio.h>

int main() {
    FILE *fp;
    fp = fopen("test.txt", "w+");

    if(fp == NULL) {
        printf("���� ���� ����");
        return 0;
    }

    fprintf(fp, "Hello, File!");

    fclose(fp);

    return 0;
}