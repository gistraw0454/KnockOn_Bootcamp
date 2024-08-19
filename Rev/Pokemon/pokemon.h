#ifndef POKEMON_H
#define POKEMON_H

typedef struct Pokemon {
    char name[50];
    char type[50]; // 불, 물, 풀
    int damage; // 최소 공격력 0~100 사이의 값이 랜덤으로 더해져 결정됨
    int hp; // 최소 hp 0~150 사이의 값이 랜덤으로 더해져 결정됨
    int currentHp;
} Pokemon;

#endif // POKEMON_H
