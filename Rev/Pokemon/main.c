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

//트레이너 도감에 포켓몬 추가
void addPokemon(char* inputName, char *inputType, int inputDamage, int inputHp, Trainer* Trainer){
    Pokemon* newPokemon = malloc(sizeof(Pokemon));
    if (!pokemonNum) Trainer->pokemonList = malloc(sizeof(Pokemon*)*(pokemonNum+1));
    else Trainer->pokemonList = realloc(Trainer->pokemonList,sizeof(Pokemon*)*(pokemonNum)+1);

    newPokemon->name = inputName;
    newPokemon->type = inputType;
    newPokemon->damage = inputDamage;
    newPokemon->hp = inputHp;

    Trainer->pokemonList[pokemonNum] = newPokemon;
    pokemonNum++;
}

//랜덤 포켓몬 만들기
Pokemon* makePokemon(Pokemon* newpokemon){
    newpokemon->damage += rand()%101;
    newpokemon->hp += rand()%151;
    return newpokemon;
}


int main(){
    //포켓몬 도감 pokemon.txt로부터 불러오기
        // 12
        // 파이리 불 50 50
        // 이상해씨 풀 50 50
        // 꼬부기 물 50 50
        // 브케인 불 50 50
        // 치코리타 풀 50 50
        // 리아코 물 50 50
        // 불꽃숭이 불 50 50
        // 모부기 풀 50 50
        // 팽도리 물 50 50
        // 뚜꾸리 불 50 50
        // 주리비얀 풀 50 50
        // 수댕이 물 50 50
    Pokemon* Pokedex;
    FILE * fp = fopen("pokemon.txt", "w");
    int totalnum=0;  // pokemon total num
    if (fp == NULL)
    {
        printf("파일이 없습니다.");
        return 1;
    }

    else{
        fscanf("%d\n",&totalnum);
        Pokedex = (Pokemon*)malloc(sizeof(Pokemon)*totalnum);
        for (int i=0; i<totalnum; i++){
            fscanf(fp, "%s %s %d %d\n",&Pokedex[i].name,&Pokedex[i].type,&Pokedex[i].damage,&Pokedex[i].hp);
        }
        fclose(fp);
    }
    
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
    fp = fopen("savefile.txt","r+");

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
                addPokemon("파이리","불",rand()%101,rand()%151,&trainer);
                break;
            case 2:
                addPokemon("이상해씨","풀",rand()%101,rand()%151,&trainer);
                break;
            case 3:
            default:
                addPokemon("꼬부기","물",rand()%101,rand()%151,&trainer);
                break;
        }
        trainer.money = 10000;    

    }
    while(1){
        printf("===============================\n");
        printf("모험을 진행하시겠습니까?\n");
        printf(" 1. 네  2. 저장  3. 상점  4. 포켓몬센터  5. 포켓몬 도감\n>>");
        scanf("%d",&select);
        
        if (select==1){
            printf("===============================\n");
            printf("포켓몬을 탐색하는중 ");
            sleep(1000);
            printf(".");
            sleep(1000);
            printf(".");
            sleep(1000);
            printf(".\n");

            //랜덤 포켓몬에게 랜덤 hp와 랜덤 damage를 준다.
            Pokemon *newPokemon = makePokemon(&Pokedex[rand()%12]);
            
            printf("===============================\n");
            printf("									%s\n");
            printf("									 %d/%d\n",newPokemon->hp,newPokemon->hp);
            printf("%s\n",trainer.pokemonList[0]->name);
            printf("%d/%d\n",trainer.pokemonList[0]->hp,trainer.pokemonList[0]->hp);
            printf("===============================\n");
            pritnf("앗! 야생의 포켓몬이 나타났다!\n");
            pritnf("무엇을 해야할까?\n");
            pritnf("1. 공격 2. 가방열기 3. 도망치기\n>>");
            
        }
        else if (select==2){
            
        }
        else if (select==3){

        }
        else if (select==4){

        }
        else if (select==5){
             // 포켓몬 정보 출력 예시
            for (int i = 0; i < pokemonNum; i++) {
                printf("포켓몬 도감\n");
                printf("no| 이름 | 속성 | 최소HP | 최소공격 |");
                printf("%d\t%s\t%s\t%d\t%d\n",
                        i+1, 
                    trainer.pokemonList[i]->name, 
                    trainer.pokemonList[i]->type, 
                    trainer.pokemonList[i]->hp, 
                    trainer.pokemonList[i]->damage);
            }
            // enter 입력시 메인화면으로
            printf("press enter to go back\n");
            do{
                scanf("%c",&ch);
            }while(ch!='\n');
        }
        else{
            printf("잘못된 입력입니다. 다시 시도해주세요!\n\n");
        }

    }
    
    
    
    
   



    // 메모리 해제
    for (int i = 0; i < pokemonNum; i++) {
        free(trainer.pokemonList[i]);
    }
    free(trainer.pokemonList);

    fclose(fp);
    return 0;
}