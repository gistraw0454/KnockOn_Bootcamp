#include <stdio.h>
int main(){
    int n;
    printf("���� �ϳ��� �Է����ּ��� : ");
    scanf("%d",&n);

    if (n<=1) printf("%d�� �Ҽ��� �ƴմϴ�!",n);
    int isPrime = 0;
    for (int i=2; i*i<=n;i++){
        if (n%i==0){
            isPrime =1;
            break;
        }
    }
    if (isPrime==1) printf("%d�� �Ҽ��� �ƴմϴ�!",n);
    else printf("%d�� �Ҽ� �Դϴ�!",n);
}