# 🌈 10. 문자열
## 💡 문자열?
1. **문자열의 개념과 용도**
- 문자열: 문자의 집합
    - 문자배열 or 포인터를 사용해 문자열을 다룸
    - 문자열의 마지막에는 NULL (\0)이 포함되어 문자의 끝을 나타냄
2. **문자열의 선언과 초기화**
- 문자배열을 사용한 선언과  초기화
    - 문자열을 저장할 공간을 메모리에 직접 할당하는 방식
    - `char str1[14] = "Hello World!";  //명시적 크기 선언과 초기화`
    - `char str2[] = "Hello World!";    //컴파일러가 크기를 계산하여 할당`
- 문자포인터를 사용한 선언과 초기화
    - 문자열 리터럴의 주소를 포인터 변수에 저장 (읽기전용으로 메모리 영역에 저장됨)
    - `char *str = "Hello World!";`
3. **문자열과 배열의 관계**
- 문자열은 char 배열에 저장이된다. 배열의 각요소는 문자열을 구성하는 각 문자이다.
- 인덱싱으로 문자하나하나에 접근할 수 있다.
- `char data[6] = "hello";`
    - {'h','e','l','l','o',0}
    - 문자 개수 5개, 배열의 크기는 6
4. **문자열과 포인터의 관계**
- 문자열은 문자배열을 가리키는 포인터. 
- 문자열을 가리키는 포인터를 사용하면 문자열을 함수에 전달하거나 함수에서 반환하는 등의 작업을 수행가능
- `char str[] = "hello";`
- `char* str = "hello";`
5. **문자열 관련 함수들**
> string.h 헤어파일에 선언되 문자열 관련 함수들.
- 문자열 길이
    - `strlen(str)` : <ins>NULL 제외 길이</ins>
- 문자열 복사
    - `strcpy(dest, src)` : src문자열을 dest로 복사
    - `strncpy(dest, src, n)` : src문자열의 처음 n개 문자열을 dest로 복사 (널도 알아서 넣어줘야함!)
- 문자열 연결
    - `strcat(dest, src)` : src문자열을 dest 문자열 끝에 연결
    - `strncat(dest, src, n)`   : strc문자열의 처음 n개 문자를 dest문자열 끝에 연결 (널 포함됐는지 확인하기 !)
- 문자열 비교
    - `strncmp(str1, str2)` : str1과 str2문자열을 비교. 같으면 0, str1>str2면 양수, str1<str2면 음수 반환
    - `strcmp(str1, str2, n)`   : str1과 str2문자열 처음 n개 문자 비교. 같으면 0, str1>str2면 양수, str1<str2면 음수 반환
- 문자열 검색
    - `strchr(str, c)` : str문자열에서 처음으로 c가 나타나는 위치 포인터 반환. 없으면 NULL 반환
    - `strrchr(str, c)`   : str문자열에서 마지막으로 c가 나타나는 위치의 포인터 반환
    - `strstr(str, needle)` : str문자열에서 needle 문자열이 시작하는 첫번째 위치의 포인터를 반환. 없으면 NULL 반환
- 문자열 출력함수
    - `sprintf()`   : 문자열에 출력을 한다.
        ```c
        #include <stdio.h>
        #include <string.h>

        void main(){
            char content[32] = "I am %s. My score is %d";
            char result[64] = {0,};

            sprintf(result,content,"Tory",100); //content에 tory와 100을 넣어 result에 출력한다.(넣는다)
            printf("result : %s\n",result);
        }
        ```
    - `snprintf()`

- 기타 함수
    - `strtok(str,"구분자")`    :구분기호 기준으로 문자열 토근 나누기
    ```c
    char str[] = "block D mask";
    char *ptr = strtok(str," ");    //  block\0D mask
    while (ptr != NULL){
        printf("%s\n",ptr);
        ptr = strtok(NULL," "); //  D\0mask
    }
    ```
    ![alt text](image.png)
    - `strlwr()`    : 소문자 변환
    - `strupr()`    : 대문자 변환
    - `strdup()`    : 문자열 복제

- 

## 📄 코드 분석
```c
// 다음과 같은 코드를 이해해봅시다.
#include <stdio.h>

void reverse(char* str) {
    int len = 0;
    while(str[len] != '\0') {
        len++;
    }

    for(int i=0; i<len/2; i++) {
        char temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}

int main() {
    char str[] = "Hello, World!";
    reverse(str);
    printf("%s\n", str);
    return 0;
}
```
- reverse 함수 인자로 문자열 배열의 주소를 전달한다. 
- len길이를 구해준다.(NULL 포함X)
- len/2만큼 돌며 문자열의 순서를 거꾸로 바꾼다.
- "!dlroW ,olleH" 가 출력될 것이다.

```c
// 아래의 코드의 실행 결과를 예상하여 봅시다
#include <stdio.h>
#include <string.h>

int find_char(char* str, char c) {
    for(int i=0; str[i] != '\0'; i++) {
        if(str[i] == c) {
            return i;
        }
    }
    return -1;
}

int main() {
    char str[] = "Hello, World!";
    char c = 'o';
    int pos = find_char(str, c);
    if(pos != -1) {
        printf("The character '%c' found at position %d\n", c, pos);
    } else {
        printf("The character '%c' not found\n", c);
    }
    return 0;
}
```
- find_char 함수에 str의 주소와, c를 인자로 전달한다.
- pos = 4
- The character 'o' found at position 4로 출력된다.
## 🔥 Challenge !!
- **strcat(), strcpy(), strcmp() 등등 기본 문자열 함수를 구현해보기 (string 헤더 include 금지!!)**

- myStrcat()
1. 두 단어를 입력받는다. 
2. 두 단어를 합친 결과를 출력한다.

    ex)

    Input first word : Knock

    Input second word : On!

    KnockOn!
```c
#include <stdio.h>

// 두단어를 입력받고, 두단어를 합친 결과를 출력한다.
char* myStrcat(char* str1, char* str2){
    int len=0;
    while (str1[len] != '\0') {
        len++;
    }

    int i=0;
    for (i=0; str2[i];i++){
        str1[len+i]= str2[i];
    }
    str1[len+i]='\0';
    return str1;
}

int main(){
    char str1[200];
    char str2[100];
    scanf("%99s",str1);
    scanf("%99s",str2);
    printf("%s",myStrcat(str1,str2));
}
```

- myStrcpy()
1. 단어를 입력받는다.
2. 다른 배열에 문자열을 복사한 후 복사본을 출력한다.

    ex)

    Input word : KnockOn!

    KnockOn!
```c
#include <stdio.h>

// 단어를 입력받고 다른배열의 문자열을 복사한후 복사본을 출력한다.
void myStrcpy(char* str1, char* str2){
    int i=0;
    while(str1[i]){
        str2[i]=str1[i];
        i++;
    }
}

int main(){
    char str1[100];
    char str2[100];
    scanf("%99s",str1);
    myStrcpy(str1,str2);
    printf("%s",str2);
}
```

- myStrcmp()
1. 두 단어를 입력받는다.
2. 두 단어의 비교 결과를 출력한다.

    ex)

    Input first word : Knock

    Input second word : On!

    Nope..
```c
#include <stdio.h>

// 두단어를 입력받고 비교결과를 출력한다.
int myStrcmp(char* str1, char* str2){
    int i=0;
    int result = 0;
    while(str1[i]){
        if(str2[i]!=str1[i]){
            result = 1;
            break;
        }
        i++;
    }
    return result;
}

int main(){
    char str1[100];
    char str2[100];
    scanf("%99s",str1);
    scanf("%99s",str2);
    if (!myStrcmp(str1,str2)) printf("same!");
    else printf("Nope..");
}
```
- **추가적인 문자열 함수 만들어 보기**
    - void myNoSpace(char* str) {}
    1. 문장을 입력받는다.
    2. 문자열 사이 공백을 제거한 후 출력한다.
    
    ex)
    
    Input sentence : Hello Knock On!
    
    HelloKnockOn!
    ```c
    #include <stdio.h>
    // 공백없애기
    void myNoSpace(char* str){
        int i=0;
        int j=0;
        char str2[100];
        while (str[i] != '\0') {
            if (str[i] != ' ') {
                str2[j] = str[i];
                j++;
            }
            i++;
        }
        str2[j] = '\0';
        printf("%s", str2);
    }

    int main(){
        char str1[100];
        scanf("%99[^\n]",str1); //공백포함 문자열을 받아 str1에 저장 !!!!!!!!
        myNoSpace(str1);
    }
    ```
    - int myCountWord(char* str, char* target) {}
    1. 문장을 입력받는다.
    2. 문장에서 2번째 인자로 넘어온 단어가 몇 번 나왔는지 출력한다.
    
    ex)
    
    Input sentence : Come on, come for corn. No onion, no corn, none for you or me
    
    Input word : on
    
    1
    
    Input word : no
    
    2
    
    Input word : om
    
    0

    힌트) 대소문자는 구분하지 않으며, 입력된 단어가 포함되더라도 정확히 해당 단어가 아니라면 세지 않는다.
    ```c
    #include <stdio.h>

    // 글자인지
    int isWordBoundary(char c) {
        return c == ' ' || c == '.' || c == ',' || c == '!' || c == '?' || c == '\0';
    }

    // 소문자로 바꾸기
    char toLower(char c) {
        if (c >= 'A' && c <= 'Z') {
            return c + ('a' - 'A');
        }
        return c;
    }

    int myCountWord(char* str, char* target) {
        int len = 0;
        // target 길이 구하기
        while (target[len]) {
            target[len] = toLower(target[len]);
            len++;
        }

        int i = 0;
        int count = 0;

        // Loop through the main string
        while (str[i]) {
            // 단어의시작부분이면서, target의 시작부분과 같으면
            if ((i == 0 || isWordBoundary(str[i-1])) && toLower(str[i]) == target[0]) {
                int isSame = 1;
                for (int j = 0; j < len; j++) {
                    if (toLower(str[i + j]) != target[j]) {
                        isSame = 0;
                        break;
                    }
                }
                //같으면서 단어의 끝이면
                if (isSame && isWordBoundary(str[i + len])) {
                    count++;
                    i += (len - 1);
                }
            }
            i++;
        }
        return count;
    }

    int main() {
        char str1[100];
        char target[100];

        scanf("%99[^\n]", str1); // Read a line including spaces

        scanf("%99s", target);

        printf("%d\n", myCountWord(str1, target));

        return 0;
    }

    ```