#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
    //1) 10개 원소의 랜덤 배열 만들기
    srand(time(NULL));
    int arr[10];
    for(int i=0; i<10;i++){
        arr[i]=rand()%100+1;
	printf("%d ",arr[i]);
    }
    
    printf("\n");

    //2) 최댓값
    int max = arr[0];
	for(int i=1;i<10;i++){
		if(max<arr[i]) max= arr[i];
	}
    printf("max: %d\n",max);

    //3) 최솟값
	int min = arr[0];
	for(int i=1;i<10;i++){
		if(min>arr[i]) min=arr[i];
	}
    printf("min: %d\n",min);

    //4) 오름차순 1 2 3 4 5 6 7 8 9 10
    for (int j=0; j<9;j++){
    for (int i=0; i<9-j; i++){
        if(arr[i]>arr[i+1]){
            int temp=0;
            temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;    
        }
    }
    for (int i=0; i<10;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    }
    

    //5) 내림차순
    //4) 오름차순 1 2 3 4 5 6 7 8 9 10
    for (int j=0; j<9;j++){
    for (int i=0; i<9-j; i++){
        if(arr[i]<arr[i+1]){
            int temp=0;
            temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;    
        }
    }
    for (int i=0; i<10;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    }
}