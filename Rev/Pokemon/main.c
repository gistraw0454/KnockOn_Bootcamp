#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int pokemonNum=0;

typedef struct Pokemon{
    char* name; 
    char* type; //불, 물, 풀
    int damage; //최소 공격력 0~100 사이의 값이 랜덤으로 더해져 결정됨
    int hp; //최소 hp 0~150 사이의 값이 랜덤으로 더해져 결정됨
}Pokemon;

typedef struct Trainer{
    Pokemon** pokemonList;
    int money;  //10000원 default
}Trainer;

void addPokemon(char* inputName, char *inputType, Trainer* Trainer){
    Pokemon* newPokemon = malloc(sizeof(Pokemon));
    if (!pokemonNum) Trainer->pokemonList = malloc(sizeof(Pokemon*)*(pokemonNum+1));
    else Trainer->pokemonList = realloc(Trainer->pokemonList,sizeof(Pokemon*)*(pokemonNum)+1);

    newPokemon->name = inputName;
    newPokemon->type = inputType;
    newPokemon->damage = rand()%101;
    newPokemon->hp = rand()%151;

    Trainer->pokemonList[pokemonNum] = newPokemon;
    pokemonNum++;
}

int main(){
    srand(time(NULL));
    int select;

    //게임 시작화면
    printf("===============================\n");
    printf("     KnockOn Pokemon Game\n\n");
    printf("     press enter to start\n");
    printf("===============================\n");

    //enter 입력시 시작
    char ch;
    do{
        scanf("%c",&ch);
        if(ch=='q') return 0;
    }while(ch!='\n');
    
    //1. 새로하기, 2. 이어하기
    printf("===============================\n");
    printf("     1. 새로하기   2. 이어하기\n>>");
    scanf("%d",&select);

    FILE *fp;
    fp = fopen("pokemon.txt","r+");

    Trainer trainer;
    trainer.pokemonList=NULL;

    // 새로하기 입력하였을 경우 (or 세이브파일이 없을 경우)
    if (fp == NULL || select == 1){
        printf("===============================\n");
        printf("어느 포켓몬을 선택하시겠습니까?\n");
        printf("1. 파이리 2. 이상해씨 3. 꼬부기\n>>");

        scanf("%d",&select);

        switch(select){
            case 1: 
                addPokemon("파이리","불",&trainer);
                break;
            case 2:
                addPokemon("이상해씨","풀",&trainer);
                break;
            case 3:
            default:
                addPokemon("꼬부기","물",&trainer);
                break;
        }
        trainer.money = 10000;    

    }

    // 포켓몬 정보 출력 예시
    for (int i = 0; i < pokemonNum; i++) {
        printf("포켓몬: %s, 타입: %s, 공격력: %d, HP: %d\n", 
               trainer.pokemonList[i]->name, 
               trainer.pokemonList[i]->type, 
               trainer.pokemonList[i]->damage, 
               trainer.pokemonList[i]->hp);
    }


    // 메모리 해제
    for (int i = 0; i < pokemonNum; i++) {
        free(trainer.pokemonList[i]);
    }
    free(trainer.pokemonList);

    fclose(fp);
    return 0;
}