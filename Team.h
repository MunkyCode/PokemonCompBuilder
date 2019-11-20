//
// Created by elimr on 11/20/2019.
//

#include <iostream>;
#include "pokemon.h";
#include <string>;

#ifndef POKEMONCOMPBUILDER_TEAM_H
#define POKEMONCOMPBUILDER_TEAM_H

#endif //POKEMONCOMPBUILDER_TEAM_H

Class Team{
private:
    int* pokemonArray;
    std::string name

public:
    Team();

    ~Team();

    Team(const Team& TeamToCopy);

    Team& operator=(const Team& TeamToCopy);

    void addPokemon(pokemon* pokemonToAdd);

    void removePokemon(pokemon* pokemonToRemove);

    std::string displayTeam();
};
