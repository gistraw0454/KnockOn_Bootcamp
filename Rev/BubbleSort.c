#include <stdio.h>
#define N 10

int main(){
    int arr[N] = { 4, 6, 2, 7, 5, 1, 8, 9, 10, 3 };
     int temp;

    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    for (int i=0; i<N-1;i++){
        for (int j=0; j<N-i-1;j++){
            if (arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }

}