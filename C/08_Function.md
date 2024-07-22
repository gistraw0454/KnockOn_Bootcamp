# 🌈 08. 함수
## 💡 C언어의 함수
1. **함수의 기본 개념과 용도**
- 특정 작업을 수행하는 코드의 집합
- 입력을 받아 처리하고 결과를 반환
- 코드의 재사용성을 높이고, 코드 구조를 개선하며, 프로그램의 가독성을 높임
2. **함수의 선언과 정의**
```c
//함수 선언 : 함수명, 반환타입, 매개변수타입을 컴파일러에게 알려주는 역할
return_type function_name(parameter list);

//함수 정의 : 실제 동작을 구현
return_type function_name(parameter list) {
    function body
}
```
3. **매개변수와 반환값**
- 인수 (argument) : 함수를 호출할 때 전달되는 값
- 매개변수 (Parameter) : 인수를 받기 위한 특별한 변수, 함수이름다음에있는 ()에서 선언, 인수와 대응하는 매개변수의 수를 서로 일치
- 반환값 (Return Value) : 호출된 함수가 호출한 곳으로 작업의 결과값을 전달하는 것
    - 반환값은 하나만 가능하다
- 보통은 헤더파일에 함수원형이 선언되어있음
    - 함수원형 : int square(int n); 이런거.

4. **함수의 범위 (Scope)**
- 변수가 프로그램 내에서 접근할 수 있는 범위를 의미
- 전역변수 : 함수외부에 선언되어 프로그램의 어느 곳에서든 접근 할 수 있는 변수
    - 프로그램이 실행되는 동안 계속 메모리에 남아있다.
    - extern
- 지역변수 : 함수 내부에서 선언되어 그 함수 내에서만 접근할 수 있는 변수
    - 함수가 호출될 때 생성되고, 함수가 종료될때 사라짐
    - auto
- <ins>정적변수</ins> : static으로 선언한 변수
    - 초기화와 함께 메모리가 할당된 후 , 블록을 나가더라도 메모리가 유지
    - <ins>프로그램 종료시 메모리가 해제, 단한번만 초기화됨 (전역변수와 동일) </ins>
    - <ins>선언된 블록내에서만 접근가능 (지역변수와 동일) </ins>
    - static
- 전역,정적변수는 data영역에 저장되며, 0으로 자동초기화됨. 지역변수는 stack에 저장되며 자동초기화 X


5. **재귀함수**
- 함수안에서 자기를 호출하는 함수
- 함수안에서 재귀호출을 멈추는 조건이 있어야한다.
```c
#include<stdio.h>

int factorial(int k);

int main()
{
    int result = factorial(5);
    printf("result: %d\n", result);
    
    return 0;
}

int factorial(int k)
{
    if(k == 0)
        return 1;
    else
        return k * factorial(k - 1);
}
```
6. **함수 포인터**
- 함수를 가리킬 수 있는 포인터를 의미
- 선언 : `int (*p)(int a,int b)`
- 사용 : 
    1. `ptrSum = &sum` 또는 `ptrSum=sum`으로 함수의 주소를 담고
    2. `(*ptrSum)(3,4)` 또는 `ptrSum(3,4)`로 포인터로 함수를 호출해 사용가능
```c
#include <stdio.h>
int sum(int a, int b) { 
        return a + b;
}

int main() {
        int(*ptrSum)(int a,int b); 
        ptrSum = sum; //ptrSum=&sum과 같음
        printf("sum의 주소: %p\n", &sum); //&sum은 sum과 같음 
        printf("ptrSum의 값: %p\n", ptrSum);    //함수포인터가 담고있는 주소값
        printf("ptrSum의 주소: %p\n", &ptrSum); //함수포인터변수 자체가 가지는 주소값
        printf("ptrSum(%d, %d) = %d\n", 3, 4, ptrSum(3, 4));   //가지고있는 값에 3,4를 보내주면 7이 나옴. (*ptrSum)(3,4)에서 *와괄호를 생략한거임. 동일함.
}
```
7. **가변인자 (variable argument)**
- printf, scanf와 같이 매개변수의 개수가 정해지지않은채 매번 함수에 들어가는 인수개수가 변하는것
- 고정 매개변수가 한개 이상 있어야 하며, 고정 매개변수뒤에 ...을 붙여 매개변수의 개수가 정해지지 않았다는 표시를 해준다.
    - ...뒤에는 다른 매개변수 지정 불가.
- `반환값자료형 함수이름(자료형 고정매개변수, ...){ ;}`

```c
#include <stdio.h>
#include <stdarg.h>    // va_list, va_start, va_arg, va_end가 정의된 헤더 파일

void printNumbers(int args, ...)    // 가변 인자의 개수를 받음, ...로 가변 인자 설정
{
    va_list ap;    // 가변 인자 목록 포인터

    va_start(ap, args);    // 가변 인자 목록 포인터 설정
    for (int i = 0; i < args; i++)    // 가변 인자 개수만큼 반복
    {
        int num = va_arg(ap, int);    // int 크기만큼 가변 인자 목록 포인터에서 값을 가져옴
                                      // ap를 int 크기만큼 순방향으로 이동
        printf("%d ", num);           // 가변 인자 값 출력
    }
    va_end(ap);    // 가변 인자 목록 포인터를 NULL로 초기화

    printf("\n");    // 줄바꿈
}

int main()
{
    printNumbers(1, 10);                // 인수 개수 1개
    printNumbers(2, 10, 20);            // 인수 개수 2개
    printNumbers(3, 10, 20, 30);        // 인수 개수 3개
    printNumbers(4, 10, 20, 30, 40);    // 인수 개수 4개

    return 0;
}
```
- `va_list`: 가변 인자 목록. 가변 인자의 메모리 주소를 저장하는 포인터입니다.
- `va_start`: 가변 인자를 가져올 수 있도록 포인터를 설정합니다.
- `va_arg`: 가변 인자 포인터에서 특정 자료형 크기만큼 값을 가져옵니다.
- `va_end`: 가변 인자 처리가 끝났을 때 포인터를 NULL로 초기화합니다.

## 📄 코드 분석

```c
// 다음과 같은 코드를 이해해봅시다.
#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int main() {
    int result = add(5, 10);
    printf("The result is %d\\n", result);
    return 0;
}

```

- add함수를 호출하여, 인자 5,10을 매개변수 a,b에 대입하여 함수를 수행한다.
- a+b 인 15를 리턴하고, 그 값을 result에 저장한다.
- The result is 15가 출력된다.

```c
// 아래의 코드의 실행 결과를 예상하여 봅시다
#include <stdio.h>

void print_hello(int n) {
    if (n <= 0) return;
    printf("Hello, World!\\n");
    print_hello(n - 1);
}

int main() {
    print_hello(5);
    return 0;
}

```

- Hello, World! 출력후 print_hello(4) 호출
- Hello, World! 출력후 print_hello(3) 호출
- Hello, World! 출력후 print_hello(2) 호출
- Hello, World! 출력후 print_hello(1) 호출
- Hello, World! 출력후 print_hello(0) 호출
- return 으로 빠져나간다.
- 따라서 총 5번의 Hello, World!가 출력이되고 함수를 나가게 된다.

```c
// 아래의 코드를 완성하여 봅시다
#include <stdio.h>

double add(double a, double b) {
	return a + b;
}

double sub(double a, double b) {
	return a - b;
}

double mul(double a, double b) {
	return a * b;
}

double dvd(double a, double b) {
	return a / b;
}

int main() {
	int select;
	int a, b;
	//함수포인터 선언부
    
	printf("===============\\n");
	printf("0. 덧셈\\n");
	printf("1. 뺄셈\\n");
	printf("2. 곱셈\\n");
	printf("3. 나눗셈\\n");
	printf("4. 종료\\n");
	printf("===============\\n\\n");

	printf("메뉴를 선택하시오 : ");
	scanf("%d", &select);
    
	printf("2개의 정수를 입력하시오 : ");
	scanf("%d %d", &a, &b);

	printf("연산결과 = %f\\n", pf[select](a, b));
}
```
- `double (*pf[4])(double, double) = {add, sub, mul, dvd};` 를 추가해준다.
## 🔥 Challenge !
1. **1번째 예시에서 뺄셈 동작을 하는 sub() 구현**
```c
int sub(int a, int b) {
    return a - b;
}
```
2. **2번째 예시에서 재귀함수의 동작 과정 및 실행결과 예상하기**
3. **3번째 예시에서 함수포인터를 이용하여 프로그램 완성하기**
4. **가변인자를 이용하여 n개 정수의 합을 구하는 함수 만들기**
```c
#include <stdio.h>
#include <stdarg.h> 

int sum(int args, ...)    
{
    va_list ap; 
    int sum=0;
    va_start(ap, args);  
    for (int i = 0; i < args; i++)   
    {
        sum += va_arg(ap, int);  
    }
    va_end(ap);   

    return sum;    
}
```