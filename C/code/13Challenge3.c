// ������ ���� �ڵ�� ���� ��ġ �����ڸ� �̿��� �����Դϴ�.
#include <stdio.h>

int main() {
    FILE *fp;
    char str[20];

    fp = fopen("test.txt", "r+");

    if(fp == NULL) {
        printf("���� ���� ����");
        return 0;
    }

    fprintf(fp, "Hello, File!");

    for (int i=0; i<3;i++){
    fseek(fp, 0, SEEK_SET);

    fscanf(fp, "%s", str);

    printf("%s ", str);
    fscanf(fp, "%s", str);

    printf("%s\n", str);
    }
    fclose(fp);

    return 0;
}