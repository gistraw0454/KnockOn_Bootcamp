#include <stdio.h>
int main(){

    int n,m;
    printf("숫자 두개를 입력해주세요.:");
    scanf("%d %d",&n,&m);
    printf("입력받은 숫자:%d %d",n,m);
    printf("%d + %d = %d",n,m,n+m);
    printf("%d - %d = %d",n,m,n-m);
    printf("%d * %d = %d",n,m,n*m);
    printf("%d / %d = %d",n,m,n/m);
}