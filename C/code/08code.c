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
    double (*pf[4])(double,double) = {add,sub,mul,dvd};

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