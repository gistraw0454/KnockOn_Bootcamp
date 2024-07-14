# ? 06. �ݺ���
## ? C��� �ݺ���
- Loop : �˻縦 ���� �ݺ��ؼ� ����Ǵ� �ݺ���
1. **for��**
```
for(�ʱ��;���ǽ�;������){
    ����1;
}
```
2. **while��**
```
while(���ǽ�){
    ����1;
}
```
3. **do while��**
```
do{
    ����1;
}while(���ǽ�);
```
4. **�б⹮**
- ���α׷��� ������ ���� ������ ������ �ʰ� �ٸ� ����� �����ϵ��� ���� ��Ű�� ��ɾ�
- `return` : �ڽ��� ȣ���� ������ �ǵ��ư�.
- `break` : ���� �������� ������ ���� ����� ������ ����¸�ɾ�
- `continue` : ���� �������� ������ ó������ �ǵ��ư�.
    - ������ü�� ����� x
    - continue ���������� �����ϰ� ������ó������ ���ư�.
5. **���� �ݺ���**
- ���� �ۿ� �ִ� for���� outer Loop ����Ѵ�.
- inner loop �� ��� ���� -> outer loop ���� 1
## ? �ڵ�м�
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
- sum �� i=0 ���ͽ����ؼ� 99������ ������ ���� ���� ������.
- 0���� �����ؼ� 49������ ���� ����Ѵ�.
- 0���� �����ؼ� 49������ ���� ����Ѵ�.
## ? Challenge !
1. **�� ���**
    1.  ���� �� �� n�� �Է¹޴´�.
    2. ���� �� ���� ���� ���� ����Ѵ�.
    
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
2. **������ �� ���**
    1.  ���� �� �� n�� �Է¹޴´�.
    2. ���� �� ���� ���� ���� ����Ѵ�.
    
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
3. **Ʈ�����**
    1.  ���� �� �� n�� �Է¹޴´�.
    2. ���� �� ���� ���� ���� ����Ѵ�.

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
4. **�Ҽ� �Ǻ���**
    - �Է¹��� ���� �Ҽ����� �ƴ��� �Ǻ��ϴ� ���α׷��Դϴ�.
    1. ���� �ϳ��� �Է¹޴´�.
    2. �ش� ���ڰ� �Ҽ����� �ƴ��� �Ǻ��Ѵ�.

    ex)

    ���� �ϳ��� �Է����ּ��� : 111111

    111111�� �Ҽ��� �ƴմϴ�!
    ```c
    #include <stdio.h>
    int main(){
        int n;
        printf("���� �ϳ��� �Է����ּ��� : ");
        scanf("%d",&n);

        if (n<=1) printf("%d�� �Ҽ��� �ƴմϴ�!",n);
        int isPrime = 0;
        for (int i=2; i*i<=n;i++){
            if (n%i==0){
                isPrime =1;
                break;
            }
        }
        if (isPrime==1) printf("%d�� �Ҽ��� �ƴմϴ�!",n);
        else printf("%d�� �Ҽ� �Դϴ�!",n);
    }
    ```
    > for (int i=2; i*i<=n;i++)