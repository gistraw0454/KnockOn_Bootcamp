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
