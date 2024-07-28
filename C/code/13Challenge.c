// 다양한 모드를 사용해 봅시다.
#include <stdio.h>

int main() {
    FILE *fp;
    fp = fopen("test.txt", "w+");

    if(fp == NULL) {
        printf("파일 열기 실패");
        return 0;
    }

    fprintf(fp, "Hello, File!");

    fclose(fp);

    return 0;
}