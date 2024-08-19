#ifndef POKEMON_H
#define POKEMON_H

typedef struct Pokemon {
    char name[50];
    char type[50]; // ��, ��, Ǯ
    int damage; // �ּ� ���ݷ� 0~100 ������ ���� �������� ������ ������
    int hp; // �ּ� hp 0~150 ������ ���� �������� ������ ������
    int currentHp;
} Pokemon;

#endif // POKEMON_H
