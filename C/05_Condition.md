# ? 05. ���ǹ�
## ? ���ǹ�?
1. **if��**
```
if(����){
    ����;
}
```
2. **else if��**
```
if(����1){
    ����1;
}
else if (����2){
    ����2;
}
else if (����3){
    ����3;
}
else{
    ����4;
}

```
3. **else��**
```
if(����){
    ����1;
}
else(����){
    ����2;
}
```
4. **switch/case��**
```
switch(������ ����){
    case ��1:
        ����1;
        break;
    case ��2:
        ����2;
        break;
    ...
    default:
        ���ึ����;
        break;
}
```
## ? �ڵ� �м�
```c
#include <stdio.h>

int main(){
	int a;

	printf("������ �Է����ּ���\n");
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
- �Է��� ���� 90���� ũ�ų� ������ A�� ���, 90���� �۰� 80���� ũ�ų� ������ B�� ���, �׿ܿ� C�� ���
```c
#include <stdio.h>

int main(){
	int choose;
	int a,b;
	printf("�ൿ�� �����ּ���\n");
	printf("1. �� ���� �� ���ϱ�, 2. �� ���� �� ���ϱ�, 3. �� ���� �� ���ϱ� : ");
	scanf("%d",&choose);
	switch(choose){
		case 1:
			printf("�� ���� �Է����ּ���.\n");
			scanf("%d %d",&a,&b);
			printf("%d",a+b);
			break;
		case 2:
			printf("�� ���� �Է����ּ���.\n");
			scanf("%d %d",&a,&b);
			printf("%d",a-b);
			break;
		case 3:
			printf("�� ���� �Է����ּ���.\n");
			scanf("%d %d",&a,&b);
			printf("%d",a*b);
			break;
		default:
			printf("�߸��� �Է��Դϴ�.");
			break;
	}
}
```
- 1�� �Է��ϸ� �μ��� �Է¹ް� ���� ���
- 2�� �Է��ϸ� �μ��� �Է¹ް� ���� ���
- 3�� �Է��ϸ� �μ��� �Է¹ް� ���� ���
- �׿ܰ��� �߸��� �Է��̶�� ���� ���

## ? Challenge !
1. **Ȧ¦�Ǻ���**
    1. ���ڸ� �ϳ� �Է¹޴´�
    2. �ش� ���ڰ� Ȧ������ ¦������ ���
    
    ex) 

    ���� �ϳ��� �Է����ּ���:11
    11�� Ȧ���Դϴ� :)
    ```c
    #include <stdio.h>
    int main(){
    int n;
    printf("���� �ϳ��� �Է����ּ���:");
    scanf("%d",&n);
    if (n%2) printf("%d�� Ȧ���Դϴ� :)",n);
    else printf("%d�� ¦���Դϴ� :)",n);
}
    ```