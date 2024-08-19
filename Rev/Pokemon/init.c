#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "init.h"
#include "trainer.h"

// 초기화 함수
void init(Trainer* trainer, Pokemon* Pokedex, int totalnum,int select) {
    FILE* fp;

    trainer->pokemonList = malloc(sizeof(Pokemon*) * 6);
    trainer->money = 10000;
    trainer->ball = 0;
    trainer->potion = 0;

    fp = fopen("savefile.txt", "r");


    if (fp == NULL || select == 1) {
        printf("===============================\n");
        printf("어느 포켓몬을 선택하시겠습니까?\n");
        printf("1. 파이리 2. 이상해씨 3. 꼬부기\n>>");

        scanf("%d", &select);

        switch (select) {
            case 1:
                addPokemon(&Pokedex[0], trainer);
                break;
            case 2:
                addPokemon(&Pokedex[1], trainer);
                break;
            case 3:
            default:
                addPokemon(&Pokedex[2], trainer);
                break;
        }
    }else if (select == 2) {

        fscanf(fp, "%d\n", &pokemonNum);
        fscanf(fp, "%d\n", &trainer->money);
        fscanf(fp, "%d\n", &trainer->ball);
        fscanf(fp, "%d\n", &trainer->potion);

        trainer->pokemonList = malloc(sizeof(Pokemon*) * pokemonNum);

        for (int i = 0; i < pokemonNum; i++) {
            trainer->pokemonList[i] = malloc(sizeof(Pokemon));
            fscanf(fp, "%s %s %d %d %d\n", trainer->pokemonList[i]->name,
                                            trainer->pokemonList[i]->type,
                                            &trainer->pokemonList[i]->damage,
                                            &trainer->pokemonList[i]->hp,
                                            &trainer->pokemonList[i]->currentHp);
        }
        fclose(fp);
    }
}
