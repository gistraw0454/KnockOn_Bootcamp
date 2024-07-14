#include <stdio.h>
int main(){
    int n;
    printf("input hte floor:");
    scanf("%d",&n);
    for (int i;i<n;i++){
        for(int j=0; j<n-i-1;j++){
            printf(" ");
        }
        for (int j=0; j<i+1;j++){
            printf("*");
        }
        printf("\n");
    }
}