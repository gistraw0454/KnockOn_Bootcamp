#include <stdio.h>

// �δܾ �Է¹ް�, �δܾ ��ģ ����� ����Ѵ�.
char* myStrcat(char* str1, char* str2){
    int len=0;
    while (str1[len] != '\0') {
        len++;
    }

    int i=0;
    for (i=0; str2[i];i++){
        str1[len+i]= str2[i];
    }
    str1[len+i]='\0';
    return str1;
}

int main(){
    char str1[200];
    char str2[100];
    scanf("%99s",str1);
    scanf("%99s",str2);
    printf("%s",myStrcat(str1,str2));
}