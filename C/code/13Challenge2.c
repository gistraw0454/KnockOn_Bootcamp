// ��� ���� ���� �� �ֵ��� �ڵ带 �����Ͽ� ���ô�.
#include <stdio.h>

int main() {
    FILE *fp;
    char str[20];

    fp = fopen("test.txt", "r");

    if(fp == NULL) {
        printf("���� ���� ����");
        return 0;
    }

    while(!feof(fp)){
        fscanf(fp, "%s", str);
        printf("%s\n", str);

    }
    // while(fscanf(fp, "%s", str)!=EOF){
    //     printf("%s\n", str);
    // }
    fclose(fp);

    return 0;
}