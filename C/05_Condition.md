# ? 05. 조건문
## ? 조건문?
1. **if문**
```
if(조건){
    실행;
}
```
2. **else if문**
```
if(조건1){
    실행1;
}
else if (조건2){
    실행2;
}
else if (조건3){
    실행3;
}
else{
    실행4;
}

```
3. **else문**
```
if(조건){
    실행1;
}
else(조건){
    실행2;
}
```
4. **switch/case문**
```
switch(정수형 변수){
    case 값1:
        실행1;
        break;
    case 값2:
        실행2;
        break;
    ...
    default:
        실행마지막;
        break;
}
```
## ? 코드 분석
```c
#include <stdio.h>

int main(){
	int a;

	printf("점수를 입력해주세요\n");
	scanf("%d",%a);
	if(a >= 90){
		printf("A\n");
	}
	else if(a >= 80){
		printf("B\n");
	}
	else{
		printf("C\n");
	}

}
```
- 입력한 값이 90보다 크거나 같으면 A가 출력, 90보다 작고 80보다 크거나 같으면 B가 출력, 그외엔 C가 출력
```c
#include <stdio.h>

int main(){
	int choose;
	int a,b;
	printf("행동을 정해주세요\n");
	printf("1. 두 수의 합 구하기, 2. 두 수의 차 구하기, 3. 두 수의 곱 구하기 : ");
	scanf("%d",&choose);
	switch(choose){
		case 1:
			printf("두 수를 입력해주세요.\n");
			scanf("%d %d",&a,&b);
			printf("%d",a+b);
			break;
		case 2:
			printf("두 수를 입력해주세요.\n");
			scanf("%d %d",&a,&b);
			printf("%d",a-b);
			break;
		case 3:
			printf("두 수를 입력해주세요.\n");
			scanf("%d %d",&a,&b);
			printf("%d",a*b);
			break;
		default:
			printf("잘못된 입력입니다.");
			break;
	}
}
```
- 1을 입력하면 두수를 입력받고 합을 출력
- 2를 입력하면 두수를 입력받고 차를 출력
- 3을 입력하면 두수를 입력받고 곱을 출력
- 그외값은 잘못된 입력이라는 문구 출력

## ? Challenge !
1. **홀짝판별기**
    1. 숫자를 하나 입력받는다
    2. 해당 숫자가 홀수인지 짝수인지 출력
    
    ex) 

    숫자 하나를 입력해주세요:11
    11은 홀수입니다 :)
    ```c
    #include <stdio.h>
    int main(){
    int n;
    printf("숫자 하나를 입력해주세요:");
    scanf("%d",&n);
    if (n%2) printf("%d은 홀수입니다 :)",n);
    else printf("%d은 짝수입니다 :)",n);
}
    ```