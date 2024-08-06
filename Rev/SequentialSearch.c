// 탐색 알고리즘 - 순차 탐색
// 앞에서부터 차례로 조회해가며 탐색
#include <stdio.h>

void SequentialSearch(int arr[],int key){
    int i=0;
    int InArr=0;
    for (i=0; i<10; i++){
        if (arr[i]==key){
            InArr=1;
            break;
        }
    }
    if (!InArr){
        printf("찾을 수 없습니다.");
    }
    else{
        printf("%d번째에 존재합니다.",i+1);
    }
}

int main(){

    int arr[10]= {1,2,3,4,5,6,7,8,9,10};
    
    SequentialSearch(arr,5);



}