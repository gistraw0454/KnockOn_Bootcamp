// 동적할당을 이용하여 이중 포인터를 활용한 2차원 배열 구현 한 모습입니다.
// 아래의 코드에서 오류가 나는 이유를 찾아 수정하여 봅시다.
#include <stdio.h>
#include <stdlib.h>

int main() {
    int **arr;
    int row = 3;
    int col = 4;

    arr = (int**)malloc(sizeof(int*) * row);
    
    // 오류! 각 행에 대해서도 동적할당을 해줘야한다.!! 
    for (int i=0; i<row ; i++){
        arr[i] = (int*)malloc(sizeof(int)*col);
    }


    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            arr[i][j] = i * col + j;
        }
    }

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < row; i++){
        free(arr[i]);
    }
    free(arr);

    return 0;
}