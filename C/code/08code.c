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
	//�Լ������� �����
    double (*pf[4])(double,double) = {add,sub,mul,dvd};

	printf("===============\\n");
	printf("0. ����\\n");
	printf("1. ����\\n");
	printf("2. ����\\n");
	printf("3. ������\\n");
	printf("4. ����\\n");
	printf("===============\\n\\n");

	printf("�޴��� �����Ͻÿ� : ");
	scanf("%d", &select);
    
	printf("2���� ������ �Է��Ͻÿ� : ");
	scanf("%d %d", &a, &b);

	printf("������ = %f\\n", pf[select](a, b));
}