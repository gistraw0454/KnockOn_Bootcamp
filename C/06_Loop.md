# ? 06. 반복문
## ? C언어 반복문
- Loop : 검사를 통해 반복해서 실행되는 반복문
1. **for문**
```
for(초기식;조건식;증감식){
    실행1;
}
```
2. **while문**
```
while(조건식){
    실행1;
}
```
3. **do while문**
```
do{
    실행1;
}while(조건식);
```
4. **분기문**
- 프로그램의 순차적 수행 순서에 따르지 않고 다른 명령을 수행하도록 이행 시키는 명령어
- `return` : 자신을 호출한 곳으로 되돌아감.
- `break` : 현재 수행중인 루프중 가장 가까운 루프를 벗어나는명령어
- `continue` : 현재 수행중인 루프의 처음으로 되돌아감.
    - 루프자체를 벗어나지 x
    - continue 다음내용을 무시하고 루프의처음으로 돌아감.
5. **이중 반복문**
- 가장 밖에 있는 for문을 outer Loop 라고한다.
- inner loop 가 모두 수행 -> outer loop 수행 1
## ? 코드분석
```c
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
```
- sum 는 i=0 부터시작해서 99까지의 정수를 더한 값을 가진다.
- 0부터 시작해서 49까지의 수를 출력한다.
- 0부터 시작해서 49까지의 수를 출력한다.
## ? Challenge !
1. **별 찍기**
    1.  별의 층 수 n을 입력받는다.
    2. 별에 층 수에 따른 별을 출력한다.
    
    ex) 
    
    input the floor : 5
    
    *

    **
    
    ***
    
    ****
    
    *****
    ```c
    #include <stdio.h>
    int main(){
        int n;
        printf("input hte floor:");
        scanf("%d",&n);
        for (int i;i<n;i++){
            for (int j=0; j<i+1;j++){
                printf("*");
            }
            printf("\n");
        }
    }
    ```
2. **리버스 별 찍기**
    1.  별의 층 수 n을 입력받는다.
    2. 별에 층 수에 따른 별을 출력한다.
    
    ex) 
    
    input the floor : 5

        *

       **

      ***

     ****

    *****
    ```c
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
    ```
3. **트리찍기**
    1.  별의 층 수 n을 입력받는다.
    2. 별에 층 수에 따른 별을 출력한다.

    ex) 

    input the floor : 5

        *

       ***

      *****

     *******

    *********
    ```c
    #include <stdio.h>
    int main(){
        int n;
        printf("input hte floor:");
        scanf("%d",&n);
        for (int i;i<n;i++){
            for(int j=0; j<n-i-1;j++){
                printf(" ");
            }
            for (int j=0; j<i*2+1;j++){
                printf("*");
            }
            printf("\n");
        }
    }
    ```
4. **소수 판별기**
    - 입력받은 수가 소수인지 아닌지 판별하는 프로그램입니다.
    1. 숫자 하나를 입력받는다.
    2. 해당 숫자가 소수인지 아닌지 판별한다.

    ex)

    숫자 하나를 입력해주세요 : 111111

    111111은 소수가 아닙니다!
    ```c
    #include <stdio.h>
    int main(){
        int n;
        printf("숫자 하나를 입력해주세요 : ");
        scanf("%d",&n);

        if (n<=1) printf("%d은 소수가 아닙니다!",n);
        int isPrime = 0;
        for (int i=2; i*i<=n;i++){
            if (n%i==0){
                isPrime =1;
                break;
            }
        }
        if (isPrime==1) printf("%d은 소수가 아닙니다!",n);
        else printf("%d은 소수 입니다!",n);
    }
    ```
    > for (int i=2; i*i<=n;i++)