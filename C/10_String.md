# ? 10. ���ڿ�
## ? ���ڿ�?
1. **���ڿ��� ����� �뵵**
- ���ڿ�: ������ ����
    - ���ڹ迭 or �����͸� ����� ���ڿ��� �ٷ�
    - ���ڿ��� ���������� NULL (\0)�� ���ԵǾ� ������ ���� ��Ÿ��
2. **���ڿ��� ����� �ʱ�ȭ**
- ���ڹ迭�� ����� �����  �ʱ�ȭ
    - ���ڿ��� ������ ������ �޸𸮿� ���� �Ҵ��ϴ� ���
    - `char str1[14] = "Hello World!";  //����� ũ�� ����� �ʱ�ȭ`
    - `char str2[] = "Hello World!";    //�����Ϸ��� ũ�⸦ ����Ͽ� �Ҵ�`
- ���������͸� ����� ����� �ʱ�ȭ
    - ���ڿ� ���ͷ��� �ּҸ� ������ ������ ���� (�б��������� �޸� ������ �����)
    - `char *str = "Hello World!";`
3. **���ڿ��� �迭�� ����**
- ���ڿ��� char �迭�� �����̵ȴ�. �迭�� ����Ҵ� ���ڿ��� �����ϴ� �� �����̴�.
- �ε������� �����ϳ��ϳ��� ������ �� �ִ�.
- `char data[6] = "hello";`
    - {'h','e','l','l','o',0}
    - ���� ���� 5��, �迭�� ũ��� 6
4. **���ڿ��� �������� ����**
- ���ڿ��� ���ڹ迭�� ����Ű�� ������. 
- ���ڿ��� ����Ű�� �����͸� ����ϸ� ���ڿ��� �Լ��� �����ϰų� �Լ����� ��ȯ�ϴ� ���� �۾��� ���డ��
- `char str[] = "hello";`
- `char* str = "hello";`
5. **���ڿ� ���� �Լ���**
> string.h ������Ͽ� ����� ���ڿ� ���� �Լ���.
- ���ڿ� ����
    - `strlen(str)` : <ins>NULL ���� ����</ins>
- ���ڿ� ����
    - `strcpy(dest, src)` : src���ڿ��� dest�� ����
    - `strncpy(dest, src, n)` : src���ڿ��� ó�� n�� ���ڿ��� dest�� ���� (�ε� �˾Ƽ� �־������!)
- ���ڿ� ����
    - `strcat(dest, src)` : src���ڿ��� dest ���ڿ� ���� ����
    - `strncat(dest, src, n)`   : strc���ڿ��� ó�� n�� ���ڸ� dest���ڿ� ���� ���� (�� ���Եƴ��� Ȯ���ϱ� !)
- ���ڿ� ��
    - `strncmp(str1, str2)` : str1�� str2���ڿ��� ��. ������ 0, str1>str2�� ���, str1<str2�� ���� ��ȯ
    - `strcmp(str1, str2, n)`   : str1�� str2���ڿ� ó�� n�� ���� ��. ������ 0, str1>str2�� ���, str1<str2�� ���� ��ȯ
- ���ڿ� �˻�
    - `strchr(str, c)` : str���ڿ����� ó������ c�� ��Ÿ���� ��ġ ������ ��ȯ. ������ NULL ��ȯ
    - `strrchr(str, c)`   : str���ڿ����� ���������� c�� ��Ÿ���� ��ġ�� ������ ��ȯ
    - `strstr(str, needle)` : str���ڿ����� needle ���ڿ��� �����ϴ� ù��° ��ġ�� �����͸� ��ȯ. ������ NULL ��ȯ
- ���ڿ� ����Լ�
    - `sprintf()`   : ���ڿ��� ����� �Ѵ�.
        ```c
        #include <stdio.h>
        #include <string.h>

        void main(){
            char content[32] = "I am %s. My score is %d";
            char result[64] = {0,};

            sprintf(result,content,"Tory",100); //content�� tory�� 100�� �־� result�� ����Ѵ�.(�ִ´�)
            printf("result : %s\n",result);
        }
        ```
    - `snprintf()`

- ��Ÿ �Լ�
    - `strtok(str,"������")`    :���б�ȣ �������� ���ڿ� ��� ������
    ```c
    char str[] = "block D mask";
    char *ptr = strtok(str," ");    //  block\0D mask
    while (ptr != NULL){
        printf("%s\n",ptr);
        ptr = strtok(NULL," "); //  D\0mask
    }
    ```
    ![alt text](image.png)
    - `strlwr()`    : �ҹ��� ��ȯ
    - `strupr()`    : �빮�� ��ȯ
    - `strdup()`    : ���ڿ� ����

- 

## ? �ڵ� �м�
```c
// ������ ���� �ڵ带 �����غ��ô�.
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
- reverse �Լ� ���ڷ� ���ڿ� �迭�� �ּҸ� �����Ѵ�. 
- len���̸� �����ش�.(NULL ����X)
- len/2��ŭ ���� ���ڿ��� ������ �Ųٷ� �ٲ۴�.
- "!dlroW ,olleH" �� ��µ� ���̴�.

```c
// �Ʒ��� �ڵ��� ���� ����� �����Ͽ� ���ô�
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
- find_char �Լ��� str�� �ּҿ�, c�� ���ڷ� �����Ѵ�.
- pos = 4
- The character 'o' found at position 4�� ��µȴ�.
## ? Challenge !!
- **strcat(), strcpy(), strcmp() ��� �⺻ ���ڿ� �Լ��� �����غ��� (string ��� include ����!!)**

- myStrcat()
1. �� �ܾ �Է¹޴´�. 
2. �� �ܾ ��ģ ����� ����Ѵ�.

    ex)

    Input first word : Knock

    Input second word : On!

    KnockOn!
```c
#include <stdio.h>

// �δܾ �Է¹ް�, �δܾ ��ģ ����� ����Ѵ�.
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
1. �ܾ �Է¹޴´�.
2. �ٸ� �迭�� ���ڿ��� ������ �� ���纻�� ����Ѵ�.

    ex)

    Input word : KnockOn!

    KnockOn!
```c
#include <stdio.h>

// �ܾ �Է¹ް� �ٸ��迭�� ���ڿ��� �������� ���纻�� ����Ѵ�.
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
1. �� �ܾ �Է¹޴´�.
2. �� �ܾ��� �� ����� ����Ѵ�.

    ex)

    Input first word : Knock

    Input second word : On!

    Nope..
```c
#include <stdio.h>

// �δܾ �Է¹ް� �񱳰���� ����Ѵ�.
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
- **�߰����� ���ڿ� �Լ� ����� ����**
    - void myNoSpace(char* str) {}
    1. ������ �Է¹޴´�.
    2. ���ڿ� ���� ������ ������ �� ����Ѵ�.
    
    ex)
    
    Input sentence : Hello Knock On!
    
    HelloKnockOn!
    ```c
    #include <stdio.h>
    // ������ֱ�
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
        scanf("%99[^\n]",str1); //�������� ���ڿ��� �޾� str1�� ���� !!!!!!!!
        myNoSpace(str1);
    }
    ```
    - int myCountWord(char* str, char* target) {}
    1. ������ �Է¹޴´�.
    2. ���忡�� 2��° ���ڷ� �Ѿ�� �ܾ �� �� ���Դ��� ����Ѵ�.
    
    ex)
    
    Input sentence : Come on, come for corn. No onion, no corn, none for you or me
    
    Input word : on
    
    1
    
    Input word : no
    
    2
    
    Input word : om
    
    0

    ��Ʈ) ��ҹ��ڴ� �������� ������, �Էµ� �ܾ ���ԵǴ��� ��Ȯ�� �ش� �ܾ �ƴ϶�� ���� �ʴ´�.
    ```c
    #include <stdio.h>

    // ��������
    int isWordBoundary(char c) {
        return c == ' ' || c == '.' || c == ',' || c == '!' || c == '?' || c == '\0';
    }

    // �ҹ��ڷ� �ٲٱ�
    char toLower(char c) {
        if (c >= 'A' && c <= 'Z') {
            return c + ('a' - 'A');
        }
        return c;
    }

    int myCountWord(char* str, char* target) {
        int len = 0;
        // target ���� ���ϱ�
        while (target[len]) {
            target[len] = toLower(target[len]);
            len++;
        }

        int i = 0;
        int count = 0;

        // Loop through the main string
        while (str[i]) {
            // �ܾ��ǽ��ۺκ��̸鼭, target�� ���ۺκа� ������
            if ((i == 0 || isWordBoundary(str[i-1])) && toLower(str[i]) == target[0]) {
                int isSame = 1;
                for (int j = 0; j < len; j++) {
                    if (toLower(str[i + j]) != target[j]) {
                        isSame = 0;
                        break;
                    }
                }
                //�����鼭 �ܾ��� ���̸�
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