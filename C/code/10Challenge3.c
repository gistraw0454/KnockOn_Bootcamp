#include <stdio.h>

// �δܾ �Է¹ް� �񱳰���� ����Ѵ�.
int myStrcmp(char* str1, char* str2){
    int i=0;
    int result = 0;
    while(str1[i]){
        if(str2[i]!=str1[i]){
            result = 1;
            break;
        }
        i++;
    }
    return result;
}

int main(){
    char str1[100];
    char str2[100];
    scanf("%99s",str1);
    scanf("%99s",str2);
    if (!myStrcmp(str1,str2)) printf("same!");
    else printf("Nope..");
}