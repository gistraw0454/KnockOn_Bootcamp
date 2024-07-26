#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    arr = (int*)malloc(sizeof(int) * 5);

    for(int i = 0; i < 5; i++){
        arr[i] = i;
    }

	//여기에 작성
    arr = (int*)realloc(arr,sizeof(int)*10);

	for(int i = 5; i < 10; i++){
        arr[i] = i;
    }

    for(int i = 0; i < 10; i++){
        printf("%d ", arr[i]);
    }
    free(arr);

    return 0;
}