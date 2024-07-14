#include <stdio.h>

int main(){
	int i = 0;
	int sum = 0;

	for(i=0;i<100;i++){
		sum += i;
	}
	
	int j = 0;

	while(j<50){
		printf("%d ",j++);
	}

	printf("\n\n");

	int k=0;
	do{
		printf("%d ",k++);
	}while(k<50);

	printf("\n");
}