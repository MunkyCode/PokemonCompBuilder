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

    //Destructor
    ~Team();

    //Copy Constructor
    Team(const Team& TeamToCopy);

    //Assignment Operator
    Team& operator=(const Team& TeamToCopy);

    /**
     * @param
     */
    void addPokemon(const pokemon* const pokemonToAdd);

    /**
     *
     */
    void removePokemon(const pokemon* const pokemonToRemove);

    /**
     * @return string list of pokemon in the team
     */
    std::string displayTeam();

};
