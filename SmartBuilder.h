//
// Created by Jolie Elins on 11/20/19.
//

#include <iostream>;
#include "Pokemon.h";
#include "Team.h";

#ifndef POKEMONCOMPBUILDER_SMARTBUILDER_H
#define POKEMONCOMPBUILDER_SMARTBUILDER_H

void smartTeamFill(Team& teamTofill);

Team* createTeamCounter(const Team& teamToCounter, std::string teamName);

Team* createBalancedTeam(std::string teamName);

#endif //POKEMONCOMPBUILDER_SMARTBUILDER_H
