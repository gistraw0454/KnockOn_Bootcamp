#include <stdio.h>
int main(){
    int n;
    printf("숫자 하나를 입력해주세요:");
    scanf("%d",&n);
    if (n%2) printf("%d은 홀수입니다 :)",n);
    else printf("%d은 짝수입니다 :)",n);
}