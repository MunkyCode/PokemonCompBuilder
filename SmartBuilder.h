//
// Created by Jolie Elins on 11/20/19.
//

#include <iostream>
#include "Pokemon.h"
#include "Team.h"
#include "PokemonList.h"
#include "ArrayList.h"
#include "TypeEffectiveness.h"

#ifndef POKEMONCOMPBUILDER_SMARTBUILDER_H
#define POKEMONCOMPBUILDER_SMARTBUILDER_H

void smartTeamFill(Team* teamToFill, PokemonList* pokeData);

Team* createTeamCounter(const Team* teamToCounter, std::string teamName, PokemonList* pokeData);

Team* createBalancedTeam(std::string teamName, PokemonList* pokeData);

#endif //POKEMONCOMPBUILDER_SMARTBUILDER_H
