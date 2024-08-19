#ifndef TRAINER_H
#define TRAINER_H

#include "pokemon.h"

typedef struct Trainer {
    Pokemon** pokemonList;
    int money; 
    int ball;
    int potion;
} Trainer;

#define MONSTER_BALL_COST 1000
#define POTION_COST 500

extern int pokemonNum;

void addPokemon(Pokemon* newPokemon, Trainer* trainer);

#endif // TRAINER_H