// 모든 줄을 읽을 수 있도록 코드를 수정하여 봅시다.
#include <stdio.h>

int main() {
    FILE *fp;
    char str[20];

    fp = fopen("test.txt", "r");

    if(fp == NULL) {
        printf("파일 열기 실패");
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