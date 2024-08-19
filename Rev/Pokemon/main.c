#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "pokemon.h"
#include "trainer.h"
#include "game.h"
#include "init.h"


int main() {
    
    srand(time(NULL));

    Pokemon* Pokedex;
    FILE* fp = fopen("pokemon.txt", "r");
    int totalnum = 0;
    if (fp == NULL) {
        printf("도감 파일이 없습니다.\n");
        return 1;
    }

    fscanf(fp, "%d\n", &totalnum);
    Pokedex = (Pokemon*)malloc(sizeof(Pokemon) * totalnum);
    if (Pokedex == NULL) {
        printf("포켓몬리스트를 찾을 수 없습니다.\n");
        fclose(fp);
        return 1;
    }

    for (int i = 0; i < totalnum; i++) {
        fscanf(fp, "%s %s %d %d\n", Pokedex[i].name, Pokedex[i].type, &Pokedex[i].damage, &Pokedex[i].hp);
    }
    fclose(fp);
    
    int select;

    printf("===============================\n");
    printf("     KnockOn Pokemon Game\n\n");
    printf("     press enter to start\n");
    printf("===============================\n");

    char ch;
    do {
        scanf("%c", &ch);
        if (ch == 'q') return 0;
    } while (ch != '\n');
    
    printf("===============================\n");
    printf("     1. 새로하기   2. 이어하기\n>>");
    while(1){
        scanf("%d", &select);
        if(select==1 ||select==2) break;
    } 

    Trainer trainer;

    //리턴값이 0이면 게임종료, 1이면 재시작
    int result = 1;
    while(result){
        init(&trainer, Pokedex, totalnum,select);
        result = startGame(&trainer, Pokedex,totalnum);
        for (int i = 0; i < pokemonNum; i++) {
            free(trainer.pokemonList[i]);
        }
        free(trainer.pokemonList);
        if (result ==0) break;
    }

    
    free(Pokedex);

    return 0;
}
