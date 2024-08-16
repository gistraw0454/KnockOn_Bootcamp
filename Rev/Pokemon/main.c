#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int pokemonNum = 0;

void loadPrintf(){
    sleep(1);
    printf("...");
    sleep(1);
    printf("...");
    sleep(1);
    printf("...\n");
}
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
    newPokemon->currentHp = newPokemon->hp;
    return newPokemon;
}

//포켓몬 포획 성공 여부 함수
int catch(int percent){
    int randomNumber = rand() %100;
    if (randomNumber<percent) return 1;
    return 0;
}

//도망 성공 여부 함수
int run(int percent){
    int randomNumber = rand() %100;
    if (percent == 100){
        if (randomNumber<10){
            return 1;
        }
    }
    else if (percent >=60){
        if (randomNumber<40){
            return 1;
        }
    }
    else if (percent >=40){
        if (randomNumber<60){
            return 1;
        }
    }
    else{
        if (randomNumber<90){
            return 1;
        }
    }
    return 0;
}

int attack(Trainer* trainer, Pokemon* newPokemon, int pokemonNum, int giveDamage, char* giveMsg, int* i)
{
    sleep(1);
    printf("===============================\n");
    printf("%s의 공격!\n",trainer->pokemonList[0]->name);

    if (catch(20)==1){
        int tmp = giveDamage;
        giveDamage *=(1.5);
        printf("%s는 %d의 데미지를 입었다.\n",newPokemon->name,giveDamage);
        newPokemon->currentHp-=giveDamage;
        giveDamage = tmp;
        printf("급소에 맞았다!\n");
    }
    else {
        printf("%s는 %d의 데미지를 입었다.\n",newPokemon->name,giveDamage);
        newPokemon->currentHp-=giveDamage;
        printf("%s",giveMsg);
    }
    printf("===============================\n");

    
    if (newPokemon->currentHp<=0){
        printf("%s(이)가 쓰러졌다!\n",newPokemon->name);
        int getmoney = 300 + rand()%200;
        trainer->money+= getmoney;
        printf("%d원을 손에 넣었다!\n",getmoney);
        return 1;
    }
    return 0;
}

int defense(Trainer* trainer, Pokemon* newPokemon, int pokemonNum, int haveDamage, char* haveMsg, int* i, int* canFight)
{
    sleep(1);
    int select;

    printf("===============================\n");
    printf("%s의 공격!\n",newPokemon->name);
    if (catch(20)==1){
        int tmp = haveDamage;
        haveDamage *=(1.5);
        printf("%s는 %d의 데미지를 입었다.\n",trainer->pokemonList[*i]->name,haveDamage);
        trainer->pokemonList[*i]->currentHp-=haveDamage;
        haveDamage = tmp;
        printf("급소에 맞았다!\n");
    }
    else {
        printf("%s는 %d의 데미지를 입었다.\n",trainer->pokemonList[*i]->name,haveDamage);
        trainer->pokemonList[*i]->currentHp-=haveDamage;
        printf("%s",haveMsg);
    }
    printf("===============================\n");

    // 현재 포켓몬이 기절했을 때 처리
    if (trainer->pokemonList[*i]->currentHp <= 0) {
        printf("%s(이)가 쓰러졌다!\n", trainer->pokemonList[*i]->name);

        *canFight = 0;
        // 살아있는 포켓몬이 있는지 확인
        for (int j = 0; j < pokemonNum; j++) {
            if (trainer->pokemonList[j]->currentHp > 0) {
                *canFight = 1;
                break;
            }
        }

        // 살아있는 포켓몬이 있으면 교체 제안
        if (*canFight == 1) {
            printf("어느 포켓몬을 내보낼까?\n");
            for (int j = 0; j < pokemonNum; j++) {
                if (trainer->pokemonList[j]->currentHp > 0) {
                    printf("%d. %s (%d/%d 체력)\n", j + 1, trainer->pokemonList[j]->name, trainer->pokemonList[j]->currentHp, trainer->pokemonList[j]->hp);
                }
            }
            printf("0. 도망가기\n>>");
            scanf("%d", &select);

            if (0 < select && select <= pokemonNum) {
                while (1) {
                    if (trainer->pokemonList[select - 1]->currentHp > 0) {
                        *i = select - 1;
                        printf("%s를 내보냈습니다!\n", trainer->pokemonList[*i]->name);
                        break;
                    } else {
                        printf("해당 포켓몬은 전투에 참여할 수 없습니다.\n");
                    }
                }
            } else {
                printf("무사히 도망쳤습니다\n");
                return 1; // 전투 종료
            }
        } else {
            // 모든 포켓몬이 기절한 경우 패배 처리
            printf("눈앞이 깜깜해졌다...\n");
            printf("1000원을 잃었다\n");
            trainer->money -= 1000;
            return 1; // 전투 종료
        }
    }
    return 0; // 전투 계속 진행
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
        
        //모험진행
        if (select == 1) {
            printf("===============================\n");
            printf("포켓몬을 탐색하는중 ");
            loadPrintf();

            Pokemon* newPokemon = makePokemon(&Pokedex[rand() % totalnum]);
            int start=1;
            int i =0;
            int canFight =1;
            if (trainer.pokemonList[i]->currentHp<=0){
                for (i=1; i<pokemonNum; i++){
                    if(trainer.pokemonList[i]->currentHp>0){
                        canFight=1;
                        break;
                    }
                    canFight=0;
                }
            }
            
            while(1){
            if (canFight==0){
                printf("살아있는 포켓몬이 없습니다.\n");
                break;
            }
            //보낼 데미지, 받을 데미지
            int giveDamage=trainer.pokemonList[i]->damage, haveDamage= newPokemon->damage;
            //공격할때 메세지, 공격받을때 메세지
            char giveMsg[30] = "";
            char haveMsg[30] = "";
            if (strcmp(trainer.pokemonList[i]->type, "풀") == 0){
                if (strcmp(newPokemon->type, "불") == 0){
                    giveDamage *= 0.5;
                    haveDamage *= 1.5;
                    strcpy("효과가 별로인 듯 하다.\n",giveMsg);
                    strcpy("효과가 굉장했다!\n",haveMsg);
                }
                else if (strcmp(newPokemon->type, "물") == 0){
                    giveDamage *= 1.5;
                    haveDamage *= 0.5;
                    strcpy("효과가 별로인 듯 하다.\n",haveMsg);
                    strcpy("효과가 굉장했다!\n",giveMsg);
                }
            }
            else if (strcmp(trainer.pokemonList[i]->type, "물") == 0){
                if (strcmp(newPokemon->type, "풀") == 0){
                    giveDamage *= 0.5;
                    haveDamage *= 1.5;
                    strcpy("효과가 별로인 듯 하다.\n",giveMsg);
                    strcpy("효과가 굉장했다!\n",haveMsg);
                }
                else if (strcmp(newPokemon->type, "불") == 0){
                    giveDamage *= 1.5;
                    haveDamage *= 0.5;
                    strcpy("효과가 별로인 듯 하다.\n",haveMsg);
                    strcpy("효과가 굉장했다!\n",giveMsg);
                }
            }
            else if (strcmp(trainer.pokemonList[i]->type, "불") == 0){
                if (strcmp(newPokemon->type, "물") == 0){
                    giveDamage *= 0.5;
                    haveDamage *= 1.5;
                    strcpy("효과가 별로인 듯 하다.\n",giveMsg);
                    strcpy("효과가 굉장했다!\n",haveMsg);
                }
                else if (strcmp(newPokemon->type, "풀") == 0){
                    giveDamage *= 1.5;
                    haveDamage *= 0.5;
                    strcpy("효과가 별로인 듯 하다.\n",haveMsg);
                    strcpy("효과가 굉장했다!\n",giveMsg);
                }
            }


                printf("===============================\n");
                printf("						%s\n", newPokemon->name);
                printf("						%d/%d\n", newPokemon->currentHp, newPokemon->hp);
                printf("%s\n", trainer.pokemonList[i]->name);
                printf("%d/%d\n", trainer.pokemonList[i]->currentHp, trainer.pokemonList[i]->hp);
                printf("===============================\n");
                if (start==1) {
                    printf("앗! 야생의 포켓몬이 나타났다!\n");
                    start = 0;
                }
                printf("무엇을 해야할까?\n");
                printf("1. 공격 2. 가방열기 3. 도망치기\n>>");

                scanf("%d", &select);

                //공격
                if (select == 1) {
                    //catch함수 이용해서 공수 정하기
                    if (catch(50) == 1) {  // 공격 먼저
                    if (attack(&trainer, newPokemon, pokemonNum, giveDamage, giveMsg, &i) == 1) break;
                    if (defense(&trainer, newPokemon, pokemonNum, haveDamage, haveMsg, &i, &canFight) == 1) break;
                    } 
                    else {   // 수비 먼저
                        if (defense(&trainer, newPokemon, pokemonNum, haveDamage, haveMsg, &i, &canFight) == 1) break;
                        if (attack(&trainer, newPokemon, pokemonNum, giveDamage, giveMsg, &i) == 1) break;                   
                    }
                }
                    //가방
                    else if (select == 2) {
                        
                        printf("===============================\n");
                        printf("									%s\n", newPokemon->name);
                        printf("									 %d/%d\n", newPokemon->currentHp, newPokemon->hp);
                        printf("%s\n", trainer.pokemonList[i]->name);
                        printf("%d/%d\n", trainer.pokemonList[i]->currentHp, trainer.pokemonList[i]->hp);
                        printf("===============================\n");
                        printf("1. 몬스터볼 x %d\n2. 회복약 x %d\n>>",trainer.ball,trainer.potion);

                        scanf("%d",&select);
                        
                        if (select==1 && trainer.ball>=1){
                            printf("몬스터 볼을 던졌다!\n");
                            loadPrintf();
                            int percent = 100-(float)newPokemon->currentHp/newPokemon->hp*100;
                            //포획 성공
                            if(catch(percent)==1){
                                printf("%s을 잡았다!\n",newPokemon->name);
                                printf("별명을 정하시겠습니까? (Y/N)\n>>");
                                while (1) {
                                    char answer;
                                    scanf(" %c", &answer);
                                    if (answer == 'Y') {
                                        printf("%s의 별명을 정해주세요!\n>>",newPokemon->name);
                                        char newname[20];
                                        scanf("%s",newname);
                                        strcpy(newname,newPokemon->name);
                                        break;
                                    }
                                    else if (answer == 'N') break;
                                }
                                addPokemon(newPokemon,&trainer);
                                break;
                            }
                            //포획 실패
                            else{
                                printf("포켓몬이 몬스터볼에서 빠져나왔다!\n");                            
                            }
                            //공격받기
                            if(defense (&trainer, &newPokemon, pokemonNum, haveDamage, haveMsg, &i,&canFight)==1) break; 
                        }
                        //회복약 선택시
                        else if (select==2 && trainer.potion>=1){
                            int prevHp = trainer.pokemonList[i]->currentHp;
                            trainer.pokemonList[i]->currentHp += (int)(trainer.pokemonList[i]->hp*0.3);
                            if (trainer.pokemonList[i]->currentHp >= trainer.pokemonList[i]->hp)
                                trainer.pokemonList[i]->currentHp = trainer.pokemonList[i]->hp;
                            printf("===============================\n");
                            printf("회복약을 사용하였다!");
                            printf("%s(은)는 %d의 체력을 회복하였다.",trainer.pokemonList[i]->name,trainer.pokemonList[i]->currentHp-prevHp);
                            printf("===============================\n");
                        }
                        else if (select==2 && trainer.potion<1)
                            printf("회복약이 부족합니다\n");
                        else if (select==1 && trainer.ball<1)
                            printf("몬스터볼이 부족합니다\n");
                        else printf("아무일도 일어나지 않았다..\n");
                        //공격받기
                        if(defense (&trainer, &newPokemon, pokemonNum, haveDamage, haveMsg, &i,&canFight)==1) break; 

                    }
                    //도망가기 
                    else if (select == 3) {
                        int percent = (float)newPokemon->currentHp/newPokemon->hp*100;
                        if (run (percent)==1)break;
                        else ;
                        //공격받기
                        if(defense (&trainer, &newPokemon, pokemonNum, haveDamage, haveMsg, &i,&canFight)==1) break; 
                    }
                    // 1,2,3 중에 고르지 않은 경우 
                    else {
                        printf("잘못된 입력. 다시 입력해주세요.\n");
                    }
            }

            free(newPokemon);   //메모리 해제부분이 계속 문제임.......
        }


        //저장
        else if (select == 2) {   
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
            loadPrintf();
            printf("저장이 완료되었습니다!\n");
            printf("===============================\n");
            printf("게임을 종료하시겠습니까? (Y/N)\n>>");
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
            loadPrintf();
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
