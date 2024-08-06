// 탐색 알고리즘 - 이진 탐색
// 중간부터 1/2씩 조회해가며 탐색
#include <stdio.h>
#define N 10

void BinarySearch(int arr[],int key){
    int left= 0;
    int right = N-1;
    int middle;

    int InArr=0;
    
    while(left<=right){
        middle = left + (left+right)/2;
        // key 값이 크면 오른쪽으로
        if (arr[middle]<key){
            left = middle+1;
        }
        else if (arr[middle]>key){
            right = middle-1;
        }
        else{
            InArr=1;
            break;
        }
    }

    if (!InArr){
        printf("찾을 수 없습니다.");
    }
    else{
        printf("%d번째에 존재합니다.",middle+1);
    }
}

int main(){

    int arr[N]= {1,2,3,4,5,6,7,8,9,10};
    
    BinarySearch(arr,5);



}