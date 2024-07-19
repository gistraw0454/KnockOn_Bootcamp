#include <stdio.h>
#include <stdarg.h>    // va_list, va_start, va_arg, va_end�� ���ǵ� ��� ����

int sum(int args, ...)    // ���� ������ ������ ����, ...�� ���� ���� ����
{
    va_list ap;    // ���� ���� ��� ������
    int sum=0;
    va_start(ap, args);    // ���� ���� ��� ������ ����
    for (int i = 0; i < args; i++)    // ���� ���� ������ŭ �ݺ�
    {
        sum += va_arg(ap, int);    // int ũ�⸸ŭ ���� ���� ��� �����Ϳ��� ���� ������
                                      // ap�� int ũ�⸸ŭ ���������� �̵�
    }
    va_end(ap);    // ���� ���� ��� �����͸� NULL�� �ʱ�ȭ

    return sum;    // �ٹٲ�
}

int main(){
    printf("%d",sum(5,1,2,3,4,5));
}