#include <stdio.h>
#define N 10

int main(){
    int arr[N] = { 4, 6, 2, 7, 5, 1, 8, 9, 10, 3 };
     int min;

    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    for (int i=0; i<N-1; i++){
        // ÃÖ¼Ú°ª Ã£±â
        min = arr[i+1];
        int index=i+1;
        for (int j=i+2;j<N;j++){
            if (arr[j]<min) {
                min= arr[j];
                index = j;
            }
        }

        int temp;
        if (arr[i]>min){
            temp = arr[i];
            arr[i] = arr[index];
            arr[index]= temp;
        }
    }

    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }

}