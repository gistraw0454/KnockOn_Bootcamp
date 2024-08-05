#include <stdio.h>
#define N 10

int main(){
    int arr[N] = { 4, 6, 2, 7, 5, 1, 8, 9, 10, 3 };
     int key;

    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    for (int i=1; i<N; i++){
        key = arr[i];
        int j=0;
        for (j=i-1; j>=0&& arr[j]>key; j--){
            arr[j+1]= arr[j];
        }
        arr[j+1] = key;
    }

    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }

}