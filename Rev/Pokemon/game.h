#ifndef GAME_H
#define GAME_H

#include "trainer.h"

extern int gameclear;
int startGame(Trainer* trainer, Pokemon* Pokedex, int totalnum);
int catchpokemon(int percent);
int run(int percent);
int attack(Trainer* trainer, Pokemon* wildPokemon, int pokemonNum, int giveDamage, char* giveMsg, int* i);
int defense(Trainer* trainer, Pokemon* wildPokemon, int pokemonNum, int haveDamage, char* haveMsg, int* i, int* canFight);
void calculateDamage(Trainer* trainer, Pokemon* newPokemon, int* giveDamage, int* haveDamage, char* giveMsg, char* haveMsg,int i);
#endif // GAME_H
