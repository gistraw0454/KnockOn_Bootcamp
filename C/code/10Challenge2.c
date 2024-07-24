#include <stdio.h>

// 단어를 입력받고 다른배열의 문자열을 복사한후 복사본을 출력한다.
void myStrcpy(char* str1, char* str2){
    int i=0;
    while(str1[i]){
        str2[i]=str1[i];
        i++;
    }
}

int main(){
    char str1[100];
    char str2[100];
    scanf("%99s",str1);
    myStrcpy(str1,str2);
    printf("%s",str2);
}