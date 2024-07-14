#include <stdio.h>
int main(){
    int n;
    printf("숫자 하나를 입력해주세요 : ");
    scanf("%d",&n);

    if (n<=1) printf("%d은 소수가 아닙니다!",n);
    int isPrime = 0;
    for (int i=2; i*i<=n;i++){
        if (n%i==0){
            isPrime =1;
            break;
        }
    }
    if (isPrime==1) printf("%d은 소수가 아닙니다!",n);
    else printf("%d은 소수 입니다!",n);
}