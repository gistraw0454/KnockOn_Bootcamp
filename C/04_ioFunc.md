# 🌈 04. 입출력함수
## 💡 입출력함수?
1. **포멧 스트링 이란?**
- 포멧 함수의 인자이며, 다음과 같은 텍스트 및 포멧인자를 포함하는 ASCII 문자열

    `printf("The magic number is:%d\n",1911);`

    - 포멧함수
        - fprint, printf, sprintf, snprintf, vfprintf, vprintf, vsprintf, vsnprintf
    - 포멧인자
        - %%, %p, %d, %c, %u, %x, %s, %n(쓰인 총 바이트 수), %f, %lf
    - +포멧스트링 공격
        - 프로그램에 입력된 문자열 데이터가 명령으로 해석될 때 발생. 공격자는 코드를 실행하거나 스택 메모리 일부를 읽거나 실행중인 프로그램에 segementation fault 발생시켜 시스템에 의도되지 않은 동작 일으킴.
        - `printf("%s",argv[1]);`은 안전하지만, `printf(argv[1])`는 위험하다.
            - ./example 'Hello world %s%s%s%s%s%s'를 실행하면, 문자열 포인터에 대한 참조로 파싱되므로 모든 %s를 문자열에 대한 포인터로 해석한다. 특정 시점에서 잘못된 주소에 도달하여 액세스를 시도하면 프로그램이 중단된다.
        - `snprintf(buf,sizeof buf, argv[1])` 위험
            - `./example 'Hello World %s%s%s%s%s%s`를 실행하면 앱크래시가 발생함.
        
2. **이스케이프시퀀스란?**
- 프로그래밍 언어 특성상 표현 할 수 없는 기능, 문자를 표현
- 컴퓨터를 제어하는 목적으로 사용되는 특수 문자
- `\a`(경고), `\n`, `\t`(수평탭), `\v`(수직탭), `\b`(백스페이스), `\f`(폼 피드), `\r`(캐리지 리턴), `\\`, `\'`, `\"`, `\ooo`(8진수 숫자를 사용하여 ASCII 코드의 문자 표현), `\xhh`(16진수 숫자를 사용하여 ASCII 코드의 문자 표현)
3. **C언어의 출력함수**
- `printf("출력내용 %d", integer);`
- `putchar(c)` : 화면에 한 문자씩 출력, 파라미터의 ASCII 값에 해당하는 문자 출력
- `puts(str)` : 문자열을 화면에 출력, \0을 만나면 \n으로 바꾸어 출력함.
- `fputc(ch,FILE *stream)` : 지정된 스트림에 문자 하나를 출력(저장)하는 함수
- `fputs(const char* restrict s, FILE * restrict stream)` : 지정된 스트림에 문자열을 출력(저장)하는 함수
    - 첫번째 인수는 쓰고자하는 문자열의 주소, 두번째 인수는 스트림을 결정한 FILE 구조체 변수포인터, 전달된 스트림이 stdout이면 모니터에 출력, 파일이면 문자열을 해당파일에 저장
- `fprintf(FILE * restrict stream, const char * restrict format,...)` : 지정된 스트림에 다양한 서식 변환 문자를 이용하여 문자열을 출력(저장)하는 함수
    - 첫번째 인수는 스트림을 결정한 FILE 구조체 변수 포인터, 두번째 변수는 인수를 출력할 문자열의 서식
    - 성공시 저장한 문자열의 크기를 바이트 단위로 반환, 실패시 음수 반환
4. **C언어의 입력함수**
- `scanf("%d %f",&interger, &gloat);`
- `c = getchar()` : 키보드로부터 한번에 한 문자씩 읽어들이는 함수, <ins>숫자를 입력받을시, 두자리 이상 숫자를 받을 수 없음</ins>
- `gets(str)` : 키보드로부터 문자열을 읽어들여 문자열 포인터가 가리키는 장소에 기억시키며, 그 포인터를 되돌려준다.space도 공백 문자열에 포함시킴.
- `fgetc(FILE *stream)` : 지정된 스트림으로부터 하나의 문자를 읽어들이는 함수, 성공하면 읽은 문자를 반환하고, 파일끝에 도달하면 EOF 반환.
- `fgets(str, n, FILE* restrict stream)` : 지정된 스트림으로부터 문자열을 읽어들이는 함수. 
    - stream에서 문자열을 받는다.
    - (n-1)개의 문자를 입력 받을때 까지나, 개행문자나 파일끝에 도달할때까지 입력을 받아서 C형식의 문자열로 저장. 
    - 성공적으로 읽었으면 str을 리턴, 실패하면 NULL 리턴
- `fscanf(FILE * restrict stream, const char* restrict format,...)` : 지정된 스트림으로부터 다양한 서식 변환 문자를 이용하여 문자열을 읽어들이는 함수.
    - 첫번째 인수는 스트림을 결정한 FILE 구조체 변수 포인터, 두번째 인수는 읽어들일 문자열의 서식
    - 성공하면 읽어들인 변수의 개수를 반환하고 실패시 EOF 반환

### 📄 코드분석
```c
#include <stdio.h>

int main(){
	float a = 10.123351;
	int b;
	scanf("%d", &b);
	printf("\na\t:\t%.3f\tb\t:\t%d\n",a, b);

	puts("Is a bigger than b?")
	//이외에도 많은 입출력함수가 존재합니다. 공부하고 넘어갑시다!
}
```
- 예상.. (O)
    ```

    a   :   10.123  b   :   입력값

    ```

## 🔥 Challenge !
1. **입력받은 값 출력하기**
    1. 숫자 1개를 입력받는다.
    2. 해당 숫자를 출력한다.
    
        //볼드가 사용자 입력값입니다.
    
        ex)
        숫자를 입력해주세요. : 3

        입력받은 숫자 : 3
        ```c
        #include <stdio.h>
        int main(){
            int n;
    
        printf("숫자를 입력해주세요.:");
        scanf("%d",&n);
        printf("입력 받은 숫자:%d",n);
        }
        ```
2. **입력받은 값 연산 출력하기**
    1. 숫자 2개를 입력받는다.
    2. 숫자 2개의 합, 차, 곱, 몫을 출력한다.
        //볼드가 사용자 입력값입니다.

        ex)

        숫자 두개를 입력해주세요. : 3 10

        입력받은 숫자 : 3 10

        3 + 10 = 13

        3 - 10 = -7

        3 * 10 = 30

        3 / 10 = 0.3
        ```c
        #include <stdio.h>
        int main(){

            int n,m;
            printf("숫자 두개를 입력해주세요.:");
            scanf("%d %d",&n,&m);
            printf("입력받은 숫자:%d %d",n,m);
            printf("%d + %d = %d",n,m,n+m);
            printf("%d - %d = %d",n,m,n-m);
            printf("%d * %d = %d",n,m,n*m);
            printf("%d / %d = %d",n,m,n/m);
        }
        ```
    
