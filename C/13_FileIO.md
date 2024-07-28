# 🌈 13. 파일 입출력
## 💡 파일 입출력?
1. **파일 입출력의 개념과 필요성**
- 프로그램이 꺼진 이후에도 데이터를 저장하기 위해 파일 입출력 필요
- 어떤 데이터를 프로그램 안에서만 사용되는게 아니라 프로그램 외부로 일시적으로 저장시켜놨다가 다시 프로그램을 실행하거나 데이터를 불러오도록해서 이전의 상태를 그대로 프로그램 내부로 가져올수 있게 하기위해서 필요
    - ram cpu는 휘발성 메모리라 사라짐.
    - 바탕화면에있는 파일들은 ssd 하드디스크와같은 보조 기억장치에 저장이되고, 그걸 실행하면 그 프로그램이 프로세스로 변환되며 ram에 들어가 구동하게되고, cpu가 ram을 읽어 실행함
2. **파일 열기와 닫기**
- 파일 입출력 변수는 file형식의 포인터 변수로 선언
- `fopen()`으로 열고 `fclose()`로 닫기
```c
FILE *fp;
fp = fopen(경로,접근방식);  // 동적할당된것이니 닫아줘야 메모리 누수가 없음
fclose(fp);
```
- `r` : 읽기모드
- `w` : 쓰기모드
- `a` : 파일에 접근해 데이터를 뒤에서부터 기록
3. **파일에서 데이터 읽고 쓰기**
- `fprintf(파일포인터, 서식, 형식지정자);`
- `fscanf(파일포인터, 서식, 형식지정자);`
4. **파일 위치 지시자 개념, 제어하는 함수들**
- 파일위치지시자
    - 파일을 어디까지 읽어들였는지, 받아들였는지에 대한 위치를 가리킨다.
    - 파일구조체
        - 환경에따라 다르다. 파일구조체가 어떻게 생겻는지 알기 어렵다
            - 파일 스트림을 만드는 주체는 프로그래머가 아닌 os기 때문
    - 파일위치지시자는 어느환경에서도 파일 구조체의 멤버중 하나다.
- `fseek(fp,-2,SEEK_END)`
    - 파일위치 지시자를 움직일 수 있게 해주는 함수
    - 두번째 인자 : 앞뒤방향으로 얼마나 움직일지 정수로 받음
        - 음수일때 앞, 양수일때 뒤
            - 파일내용이 123456789면, EOF->9->8 으로 8을 가리키게됨.
    - 세번째 인자 : 위치변경하기위한 기준 정수
        - SEEK_SET // 0과 같다. 이 상수는 파일의 시작을 기준으로 지정하겠다는 의미이다.
        - SEEK_CUR // 1과 같다. 이 상수는 현재 지시자의 위치를 기준으로 지정하겠다는 의미이다.
        - SEEK_END // 2와 같다. 이 상수는 파일의 끝을 기준으로 지정하겠다는 의미이다.

    ```c
    int main() {
        FILE *fp=fopen("seek.bin", "rb");
        char arr[6];
        char num;
        fread((void *)arr, sizeof(char), 5, fp);    //지시자가 Hello 뒤에있음
        arr[5]='\0';
        puts(arr);
        fseek(fp, SEEK_SET, 0); //지시자를 시작으로 옮김
        fread((void *)arr, sizeof(char), 5, fp);    //지시자가 Hello 뒤에있음
        arr[5]='\0';
        puts(arr);
        fseek(fp, SEEK_END, 0); //지시자를 파일 맨뒤로 옮김
        fread((void *)&num, sizeof(char), 1, fp);   //파일 끝에는 끝을 알리는 EOF가 존재(문자열의 \0 같은것). 이를 출력하게됨.
        putchar(num);
        fclose(fp);
    }
    //파일내용이 Hello SEEK! 면, 
    //Hello
    //Hello
    //EOF 출력됨
    ```

5. **파일 입출력과 에러 처리**
```c
#include <string.h>

char* strerror(int errnum);
```
- erro 라는 매크로를 넣어 문자열로 출력하면 어떤 오류가 있었느지 친절하게 알려준다.
- 파일이 제대로 열리지 않을때에 대한 예외처리코드는 아래와같이 작성가능
    ```c
    #include <stdio.h>
    #include <string.h>
    #include <errno.h>

    void use_file(const char* filename)
    {
        FILE* stream = fopen(filename, "rb");
        
        if (stream == NULL)
        {
            fprintf(stderr, "%s\n", strerror(errno));
            return;
        }
        
        /* code */
    }
    ```
    - 에러코드를 작성해주는 코드를 알아서 내부적으로 해주는 함수인 perror을 써도된다.
```c
#include <stdio.h>

void perror(const char* str);
```
- perror
    ```c
    #include <stdio.h>

    void use_file(const char* filename)
    {
        FILE* stream = fopen(filename, "rb");
        
        if (stream == NULL)
        {
            perror("오류오류오류");
            return;
        }
        
        /* code */
    }

    /*
    파일 열기에 실패하면 아래와 같은 결과가 나온다.

    오류오류오류: No such file or directory
    */
    ```
    - 오류가 생길때, 오류코드를 바로 반환해주거나 어딘가에 오류코드를 들고있다가 프로그래머가 필요하면 오류코드를 반환해준다.
6. **파일 디스크립터 (fd)**
- 파일에 접근하기위한 방법 (일반적 정규파일, 디렉토리, 소켓, 파이프, 블록디바이스, 캐릭터 등의 모든 객체)
    - 0 : 표준 입력 (Standard Input, STDIN_FILENO)
    - 1 : 표준 출력 (Standard Output, STDOUT_FILENO)
    - 2 : 표준 에러 (Standard Error, STDERR_FILENO)
- 파일을 open할때 (접근시) 파일 디스크립터는 0부터 N까지 숫자를 차례로 부여받으며, 0,1,2는 프로세스가 메모리에서 실행을 시작할때 기본적으로 할당되는 파일디스크립터이다.
```c
/* 데이터를 몇 번 읽었는지 반환 */
size_t fread(void* buffer, size_t size, size_t count, FILE* stream);

/* 데이터를 몇 번 썼는지 반환 */
size_t fwrite(const void* buffer, size_t size, size_t count, FILE* stream);

/* 스트림을 반환하고 열기 실패하면 NULL 반환 */
FILE* fopen(const char* filename, const char* mode);

/* 파일 닫기를 성공하면 0을 반환하고 실패하면 EOF 반환 */
int fclose(FILE* stream);

/* 스트림의 버퍼를 잘 비웠으면 0을 반환하고 실패하면 EOF 반환 */
int fflush(FILE* stream);

/* 스트림의 EOF표시자의 상태를 반환하며 EOF가 아니면 0, EOF면 0이 아닌 값을 반환 */
int feof(FILE* stream);

/* 스트림의 오류 표시자의 상태를 반환하며 오류가 없으면 0, 있으면 0이 아닌 값을 반환 */
int ferror(FILE* stream);

/* EOF표시자, 오류 표시자의 값이 잘 지워지지 않아서 그 값을 강제로 지워주는 함수 */
void clearerr(FILE* stream);
```
>파일 입출력은 프로그램이 파일에 데이터를 쓰거나 파일로부터 데이터를 읽는 작업을 말합니다. 파일 입출력을 이용하면 프로그램이 종료된 후에도 데이터를 유지할 수 있으며, 다른 프로그램과 데이터를 공유할 수 있습니다.

>파일 입출력은 fopen, fclose 함수를 이용하여 수행할 수 있으며, 파일에서 데이터를 읽고 쓰는 것은 fscanf, fprintf, fread, fwrite 등의 함수를 이용할 수 있습니다. 한편, fseek, ftell 등의 함수를 사용하여 파일 위치 지시자를 제어할 수 잇습니다.

## 📄 코드분석
```c
// 다양한 모드를 사용해 봅시다.
#include <stdio.h>

int main() {
    FILE *fp;
    fp = fopen("test.txt", "w");

    if(fp == NULL) {
        printf("파일 열기 실패");
        return 0;
    }

    fprintf(fp, "Hello, File!");

    fclose(fp);

    return 0;
}

```
```c
// 모든 줄을 읽을 수 있도록 코드를 수정하여 봅시다.
#include <stdio.h>

int main() {
    FILE *fp;
    char str[20];

    fp = fopen("test.txt", "r");

    if(fp == NULL) {
        printf("파일 열기 실패");
        return 0;
    }

    fscanf(fp, "%s", str);

    printf("%s\n", str);

    fclose(fp);

    return 0;
}

```
```c
// 다음과 같은 코드는 파일 위치 지시자를 이용한 예시입니다.
#include <stdio.h>

int main() {
    FILE *fp;
    char str[20];

    fp = fopen("test.txt", "r+");

    if(fp == NULL) {
        printf("파일 열기 실패");
        return 0;
    }

    fprintf(fp, "Hello, File!");

    fseek(fp, 0, SEEK_SET);

    fscanf(fp, "%s", str);

    printf("%s\n", str);

    fclose(fp);

    return 0;
}

```
## 🔥 Challenge !!
1. **1번째 예시에서 다른 모드로 파일을 열어보기 (예: "a", "r+", "w+")**
-  모두 같은 결과를 가져온다. 전부 쓰기 기능을 포함하고있음.
- a: 추가해서 쓰기 모드
- r+ : 읽고 쓰기 모드
- w+ : 쓰고 읽기 모드
2. **2번째 예시에서 파일 전체를 읽어보기 (while문과 feof 함수 사용)**
```c
// 모든 줄을 읽을 수 있도록 코드를 수정하여 봅시다.
#include <stdio.h>

int main() {
    FILE *fp;
    char str[20];

    fp = fopen("test.txt", "r");

    if(fp == NULL) {
        printf("파일 열기 실패");
        return 0;
    }

    while(!feof(fp)){
        fscanf(fp, "%s", str);
        printf("%s\n", str);

    }
    // while(fscanf(fp, "%s", str)!=EOF){
    //     printf("%s\n", str);
    // }
    fclose(fp);

    return 0;
}
```
3. **3번째 예시에서 fseek()를 이용하여 3번 반복하여 읽어보기**
```c
// 다음과 같은 코드는 파일 위치 지시자를 이용한 예시입니다.
#include <stdio.h>

int main() {
    FILE *fp;
    char str[20];

    fp = fopen("test.txt", "r+");

    if(fp == NULL) {
        printf("파일 열기 실패");
        return 0;
    }

    fprintf(fp, "Hello, File!");

    for (int i=0; i<3;i++){
    fseek(fp, 0, SEEK_SET);

    fscanf(fp, "%s", str);

    printf("%s ", str);
    fscanf(fp, "%s", str);

    printf("%s\n", str);
    }
    fclose(fp);

    return 0;
}
```