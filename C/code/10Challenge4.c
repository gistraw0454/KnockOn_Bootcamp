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
