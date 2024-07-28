// 다음과 같은 코드는 파일 위치 지시자를 이용한 예시입니다.
#include <stdio.h>

int main() {
    FILE *fp;
    char str[20];

    fp = fopen("test.txt", "r+");

    if(fp == NULL) {
        printf("파일 열기 실패");
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