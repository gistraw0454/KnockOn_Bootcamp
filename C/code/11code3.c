#define SIZE 200
#include <string.h>
#include <stdio.h>
struct Wc {
	char word[30];
	int count;
};

struct Wc simbol_table[SIZE];
int idx=0;

void count(input) {
    // �̰��� �ϼ�
    strcpy(simbol_table[idx].word,input);
    simbol_table[idx].count = strlen(input);
    idx++;
}

#define INPUT_SIZE 4
int main() {
	char buf[100];

	for (int i = 0; i < INPUT_SIZE; i++)
	{
		printf("�ܾ �Է��ϼ��� : ");
		scanf("%s", buf);
		count(buf);
	}

	printf("\n[�󵵼�]\n");
	for (int i = 0; i < idx; i++)
	{
		printf("%s : %d\n", simbol_table[i].word, simbol_table[i].count);
	}
}