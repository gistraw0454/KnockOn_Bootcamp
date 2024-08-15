#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int pokemonNum = 0;

typedef struct Pokemon {
    char name[20];
    char type[10]; // 불, 물, 풀
    int damage; // 최소 공격력 0~100 사이의 값이 랜덤으로 더해져 결정됨
    int hp; // 최소 hp 0~150 사이의 값이 랜덤으로 더해져 결정됨
    int currentHp;
} Pokemon;

typedef struct Trainer {
    Pokemon** pokemonList;
    int money;  // 10000원 default
    int ball;
    int potion;
} Trainer;

// 트레이너 도감에 포켓몬 추가
void addPokemon(Pokemon* pokemon, Trainer* trainer) {
    Pokemon* newPokemon = malloc(sizeof(Pokemon));
    if (!pokemonNum) {
        trainer->pokemonList = malloc(sizeof(Pokemon*) * (pokemonNum + 1));
    } else {
        trainer->pokemonList = realloc(trainer->pokemonList, sizeof(Pokemon*) * (pokemonNum + 1));
    }

    strcpy(newPokemon->name, pokemon->name);
    strcpy(newPokemon->type, pokemon->type);
    newPokemon->damage = pokemon->damage + rand() % 101;
    newPokemon->hp = pokemon->hp + rand() % 151;
    newPokemon->currentHp = newPokemon->hp;

    trainer->pokemonList[pokemonNum] = newPokemon;
    pokemonNum++;
}

// 랜덤 포켓몬 만들기
Pokemon* makePokemon(Pokemon* newPokemon) {
    newPokemon->damage += rand() % 101;
    newPokemon->hp += rand() % 151;
    return newPokemon;
}

int main() {
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

    srand(time(NULL));
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
    trainer.pokemonList = NULL;
    trainer.money = 10000;    
    trainer.ball = 0;
    trainer.potion = 0;

    fp = fopen("savefile.txt", "r");

    if (fp == NULL || select == 1) {
        printf("===============================\n");
        printf("어느 포켓몬을 선택하시겠습니까?\n");
        printf("1. 파이리 2. 이상해씨 3. 꼬부기\n>>");

        scanf("%d", &select);

        switch (select) {
            case 1: 
                addPokemon(makePokemon(&Pokedex[0]), &trainer);
                break;
            case 2:
                addPokemon(makePokemon(&Pokedex[1]), &trainer);
                break;
            case 3:
            default:
                addPokemon(makePokemon(&Pokedex[2]), &trainer);
                break;
        }
    } else if (select == 2) {
        fscanf(fp, "%d\n", &pokemonNum);
        fscanf(fp, "%d\n", &trainer.money);
        fscanf(fp, "%d\n", &trainer.ball);
        fscanf(fp, "%d\n", &trainer.potion);
        trainer.pokemonList = malloc(sizeof(Pokemon*) * pokemonNum);

        for (int i = 0; i < pokemonNum; i++) {
            trainer.pokemonList[i] = malloc(sizeof(Pokemon));
            fscanf(fp, "%s %s %d %d %d\n", trainer.pokemonList[i]->name, 
                                            trainer.pokemonList[i]->type,
                                            &trainer.pokemonList[i]->damage,
                                            &trainer.pokemonList[i]->hp,
                                            &trainer.pokemonList[i]->currentHp);
        }
        fclose(fp);
    }
    while(1) {
        printf("===============================\n");
        printf("모험을 진행하시겠습니까?\n");
        printf(" 1. 네  2. 저장  3. 상점  4. 포켓몬센터  5. 포켓몬 도감\n>>");
        scanf("%d", &select);
        
        if (select == 1) {
            printf("===============================\n");
            printf("포켓몬을 탐색하는중 ");
            sleep(1);
            printf("...");
            sleep(1);
            printf("...");
            sleep(1);
            printf("...\n");

            Pokemon* newPokemon = makePokemon(&Pokedex[rand() % totalnum]);
            int myCurrentHp = trainer.pokemonList[0]->hp;
            int yourCurrentHp = newPokemon->hp;
            printf("===============================\n");
            printf("									%s\n", newPokemon->name);
            printf("									 %d/%d\n", yourCurrentHp, newPokemon->hp);
            printf("%s\n", trainer.pokemonList[0]->name);
            printf("%d/%d\n", myCurrentHp, trainer.pokemonList[0]->hp);
            printf("===============================\n");
            printf("앗! 야생의 포켓몬이 나타났다!\n");
            printf("무엇을 해야할까?\n");
            printf("1. 공격 2. 가방열기 3. 도망치기\n>>");

            scanf("%d", &select);

            if (select == 1) {
                // 공격 로직 추가
            } else if (select == 2) {
                // 가방 로직 추가
            } else if (select == 3) {
                // 도망 로직 추가
            } else {
                printf("잘못된 입력. 다시 입력해주세요.\n");
            }

        } else if (select == 2) {   
            fp = fopen("savefile.txt", "w");
            fprintf(fp, "%d\n%d\n%d\n%d\n", pokemonNum, trainer.money, trainer.ball, trainer.potion);
            for (int i = 0; i < pokemonNum; i++) {
                fprintf(fp, "%s %s %d %d %d\n", trainer.pokemonList[i]->name, 
                                                trainer.pokemonList[i]->type,
                                                trainer.pokemonList[i]->damage, 
                                                trainer.pokemonList[i]->hp, 
                                                trainer.pokemonList[i]->currentHp);
            }
            fclose(fp);
            printf("===============================\n");
            printf("리포트 작성 중입니다");
            sleep(1);
            printf("...");
            sleep(1);
            printf("...");
            sleep(1);
            printf("...\n");
            printf("저장이 완료되었습니다!\n");
            printf("===============================\n");
            printf("게임을 종료하시겠습니까?(Y/N)\n>>");
            while (1) {
                char answer;
                scanf(" %c", &answer);
                if (answer == 'Y') return 1;
                else if (answer == 'N') break;
            }
        } else if (select == 3) {
            while(1) {
                printf("===============================\n");
                printf("상점                지갑 : %d원\n", trainer.money);
                printf("1. 포켓몬볼 1000원\n");
                printf("2. 상처약 500원\n");
                printf("===============================\n");
                printf("무엇을 구매할까? (나가기 0)\n>>");

                scanf("%d", &select);

                if (select == 0) break;
                else if (select == 1) {
                    printf("포켓몬볼을 몇 개 구매할까? (취소 -1)\n>>");
                    int count = 0;
                    scanf("%d", &count);

                    if (count == -1) continue;
                    else if (trainer.money >= count * 1000) {
                        trainer.money -= count * 1000;
                        trainer.ball += count;
                        printf("성공적으로 구매하였습니다! (잔액 %d원)\n", trainer.money);
                    } else {
                        printf("돈이 부족합니다!\n");
                    }
                } else if (select == 2) {
                    printf("상처약을 몇 개 구매할까? (취소 -1)\n>>");
                    int count = 0;
                    scanf("%d", &count);

                    if (count == -1) continue;
                    else if (trainer.money >= count * 500) {
                        trainer.money -= count * 500;
                        trainer.potion += count;
                        printf("성공적으로 구매하였습니다! (잔액 %d원)\n", trainer.money);
                    } else {
                        printf("잔액이 부족합니다.\n");
                    }
                } else {
                    printf("잘못된 입력입니다. 다시 시도해주세요.\n");
                }  
            }
        } else if (select == 4) {
            printf("===============================\n");
            printf("포켓몬을 치료하는 중입니다");
            sleep(1);
            printf("...");
            sleep(1);
            printf("...");
            sleep(1);
            printf("...\n");
            printf("치료가 완료되었습니다!\n");
            printf("===============================\n");
            for (int i = 0; i < pokemonNum; i++) {
                trainer.pokemonList[i]->currentHp = trainer.pokemonList[i]->hp;
                printf("%s\t%s\t%d\t%d\n",
                    trainer.pokemonList[i]->name, 
                    trainer.pokemonList[i]->type, 
                    trainer.pokemonList[i]->currentHp, 
                    trainer.pokemonList[i]->hp);
            }
            printf("(엔터 입력 후 메인화면으로)\n");
            do {
                scanf("%c", &ch);
            } while (ch != '\n');
        } else if (select == 5) {
            for (int i = 0; i < pokemonNum; i++) {
                printf("포켓몬 도감\n");
                printf("no | 이름 | 속성 | 최소HP | 최소공격 |\n");
                printf("%d\t%s\t%s\t%d\t%d\n",
                        i + 1, 
                    trainer.pokemonList[i]->name, 
                    trainer.pokemonList[i]->type, 
                    trainer.pokemonList[i]->hp, 
                    trainer.pokemonList[i]->damage);
            }
            printf("(엔터 입력 후 메인화면으로)\n");
            do {
                scanf("%c", &ch);
            } while (ch != '\n');
        } else {
            printf("잘못된 입력입니다. 다시 시도해주세요!\n\n");
        }
    }

    for (int i = 0; i < pokemonNum; i++) {
        free(trainer.pokemonList[i]);
    }
    free(trainer.pokemonList);
    free(Pokedex);

    return 0;
}
