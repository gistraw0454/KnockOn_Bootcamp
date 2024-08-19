#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trainer.h"

int pokemonNum = 0;

// 트레이너 도감에 포켓몬 추가
void addPokemon(Pokemon* newPokemon, Trainer* trainer) {
    // 포켓몬 리스트가 NULL이면 메모리 할당
    if (trainer->pokemonList == NULL) {
        trainer->pokemonList = malloc(sizeof(Pokemon*)); // 처음 포켓몬을 추가할 때 메모리 할당
        if (trainer->pokemonList == NULL) {
            perror("Initial allocation failed");
            return;
        }
    } else {
        // realloc을 사용하여 pokemonList의 크기를 조정
        Pokemon** temp = realloc(trainer->pokemonList, sizeof(Pokemon*) * (pokemonNum + 1));
        if (temp == NULL) {
            perror("Memory reallocation failed");
            return;
        }
        trainer->pokemonList = temp;
    }

    // 새 포켓몬을 위한 메모리 할당
    trainer->pokemonList[pokemonNum] = (Pokemon*)malloc(sizeof(Pokemon));
    if (trainer->pokemonList[pokemonNum] == NULL) {
        perror("Memory allocation for new Pokemon failed");
        return;
    }

    // 포인터를 덮어쓰지 말고, 각각의 필드를 복사
    strcpy(trainer->pokemonList[pokemonNum]->name, newPokemon->name);
    strcpy(trainer->pokemonList[pokemonNum]->type, newPokemon->type);
    trainer->pokemonList[pokemonNum]->damage = newPokemon->damage + rand() % 101;
    trainer->pokemonList[pokemonNum]->hp = newPokemon->hp + rand() % 151;
    trainer->pokemonList[pokemonNum]->currentHp = trainer->pokemonList[pokemonNum]->hp;

    pokemonNum++;
}