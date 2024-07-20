# ? 08. �Լ�
## ? C����� �Լ�
1. **�Լ��� �⺻ ����� �뵵**
- Ư�� �۾��� �����ϴ� �ڵ��� ����
- �Է��� �޾� ó���ϰ� ����� ��ȯ
- �ڵ��� ���뼺�� ���̰�, �ڵ� ������ �����ϸ�, ���α׷��� �������� ����
2. **�Լ��� ����� ����**
```c
//�Լ� ���� : �Լ���, ��ȯŸ��, �Ű�����Ÿ���� �����Ϸ����� �˷��ִ� ����
return_type function_name(parameter list);

//�Լ� ���� : ���� ������ ����
return_type function_name(parameter list) {
    function body
}
```
3. **�Ű������� ��ȯ��**
- �μ� (argument) : �Լ��� ȣ���� �� ���޵Ǵ� ��
- �Ű����� (Parameter) : �μ��� �ޱ� ���� Ư���� ����, �Լ��̸��������ִ� ()���� ����, �μ��� �����ϴ� �Ű������� ���� ���� ��ġ
- ��ȯ�� (Return Value) : ȣ��� �Լ��� ȣ���� ������ �۾��� ������� �����ϴ� ��
    - ��ȯ���� �ϳ��� �����ϴ�
- ������ ������Ͽ� �Լ������� ����Ǿ�����
    - �Լ����� : int square(int n); �̷���.

4. **�Լ��� ���� (Scope)**
- ������ ���α׷� ������ ������ �� �ִ� ������ �ǹ�
- �������� : �Լ��ܺο� ����Ǿ� ���α׷��� ��� �������� ���� �� �� �ִ� ����
    - ���α׷��� ����Ǵ� ���� ��� �޸𸮿� �����ִ�.
    - extern
- �������� : �Լ� ���ο��� ����Ǿ� �� �Լ� �������� ������ �� �ִ� ����
    - �Լ��� ȣ��� �� �����ǰ�, �Լ��� ����ɶ� �����
    - auto
- <ins>��������</ins> : static���� ������ ����
    - �ʱ�ȭ�� �Բ� �޸𸮰� �Ҵ�� �� , ����� �������� �޸𸮰� ����
    - <ins>���α׷� ����� �޸𸮰� ����, ���ѹ��� �ʱ�ȭ�� (���������� ����) </ins>
    - <ins>����� ��ϳ������� ���ٰ��� (���������� ����) </ins>
    - static
- ����,���������� data������ ����Ǹ�, 0���� �ڵ��ʱ�ȭ��. ���������� stack�� ����Ǹ� �ڵ��ʱ�ȭ X


5. **����Լ�**
- �Լ��ȿ��� �ڱ⸦ ȣ���ϴ� �Լ�
- �Լ��ȿ��� ���ȣ���� ���ߴ� ������ �־���Ѵ�.
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
6. **�Լ� ������**
- �Լ��� ����ų �� �ִ� �����͸� �ǹ�
- ���� : `int (*p)(int a,int b)`
- ��� : 
    1. `ptrSum = &sum` �Ǵ� `ptrSum=sum`���� �Լ��� �ּҸ� ���
    2. `(*ptrSum)(3,4)` �Ǵ� `ptrSum(3,4)`�� �����ͷ� �Լ��� ȣ���� ��밡��
```c
#include <stdio.h>
int sum(int a, int b) { 
        return a + b;
}

int main() {
        int(*ptrSum)(int a,int b); 
        ptrSum = sum; //ptrSum=&sum�� ����
        printf("sum�� �ּ�: %p\n", &sum); //&sum�� sum�� ���� 
        printf("ptrSum�� ��: %p\n", ptrSum);    //�Լ������Ͱ� ����ִ� �ּҰ�
        printf("ptrSum�� �ּ�: %p\n", &ptrSum); //�Լ������ͺ��� ��ü�� ������ �ּҰ�
        printf("ptrSum(%d, %d) = %d\n", 3, 4, ptrSum(3, 4));   //�������ִ� ���� 3,4�� �����ָ� 7�� ����. (*ptrSum)(3,4)���� *�Ͱ�ȣ�� �����Ѱ���. ������.
}
```
7. **�������� (variable argument)**
- printf, scanf�� ���� �Ű������� ������ ������������ä �Ź� �Լ��� ���� �μ������� ���ϴ°�
- ���� �Ű������� �Ѱ� �̻� �־�� �ϸ�, ���� �Ű������ڿ� ...�� �ٿ� �Ű������� ������ �������� �ʾҴٴ� ǥ�ø� ���ش�.
    - ...�ڿ��� �ٸ� �Ű����� ���� �Ұ�.
- `��ȯ���ڷ��� �Լ��̸�(�ڷ��� �����Ű�����, ...){ ;}`

```c
#include <stdio.h>
#include <stdarg.h>    // va_list, va_start, va_arg, va_end�� ���ǵ� ��� ����

void printNumbers(int args, ...)    // ���� ������ ������ ����, ...�� ���� ���� ����
{
    va_list ap;    // ���� ���� ��� ������

    va_start(ap, args);    // ���� ���� ��� ������ ����
    for (int i = 0; i < args; i++)    // ���� ���� ������ŭ �ݺ�
    {
        int num = va_arg(ap, int);    // int ũ�⸸ŭ ���� ���� ��� �����Ϳ��� ���� ������
                                      // ap�� int ũ�⸸ŭ ���������� �̵�
        printf("%d ", num);           // ���� ���� �� ���
    }
    va_end(ap);    // ���� ���� ��� �����͸� NULL�� �ʱ�ȭ

    printf("\n");    // �ٹٲ�
}

int main()
{
    printNumbers(1, 10);                // �μ� ���� 1��
    printNumbers(2, 10, 20);            // �μ� ���� 2��
    printNumbers(3, 10, 20, 30);        // �μ� ���� 3��
    printNumbers(4, 10, 20, 30, 40);    // �μ� ���� 4��

    return 0;
}
```
- `va_list`: ���� ���� ���. ���� ������ �޸� �ּҸ� �����ϴ� �������Դϴ�.
- `va_start`: ���� ���ڸ� ������ �� �ֵ��� �����͸� �����մϴ�.
- `va_arg`: ���� ���� �����Ϳ��� Ư�� �ڷ��� ũ�⸸ŭ ���� �����ɴϴ�.
- `va_end`: ���� ���� ó���� ������ �� �����͸� NULL�� �ʱ�ȭ�մϴ�.
## ? �ڵ� �м�
```c
// ������ ���� �ڵ带 �����غ��ô�.
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
- add�Լ��� ȣ���Ͽ�, ���� 5,10�� �Ű����� a,b�� �����Ͽ� �Լ��� �����Ѵ�.
- a+b �� 15�� �����ϰ�, �� ���� result�� �����Ѵ�.
- The result is 15�� ��µȴ�.
```c
// �Ʒ��� �ڵ��� ���� ����� �����Ͽ� ���ô�
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
- Hello, World! ����� print_hello(4) ȣ��
- Hello, World! ����� print_hello(3) ȣ��
- Hello, World! ����� print_hello(2) ȣ��
- Hello, World! ����� print_hello(1) ȣ��
- Hello, World! ����� print_hello(0) ȣ��
- return ���� ����������.
- ���� �� 5���� Hello, World!�� ����̵ǰ� �Լ��� ������ �ȴ�.
```c
// �Ʒ��� �ڵ带 �ϼ��Ͽ� ���ô�
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
```
- `double (*pf[4])(double, double) = {add, sub, mul, dvd};` �� �߰����ش�.
## ? Challenge !
1. **1��° ���ÿ��� ���� ������ �ϴ� sub() ����**
```c
int sub(int a, int b) {
    return a - b;
}
```
2. **2��° ���ÿ��� ����Լ��� ���� ���� �� ������ �����ϱ�**
3. **3��° ���ÿ��� �Լ������͸� �̿��Ͽ� ���α׷� �ϼ��ϱ�**
4. **�������ڸ� �̿��Ͽ� n�� ������ ���� ���ϴ� �Լ� �����**
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