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