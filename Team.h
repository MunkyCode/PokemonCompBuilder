//
// Created by elimr on 11/20/2019.
//

#include <iostream>;
#include "pokemon.h";
#include <string>;
#include "ArrayList.h";

#ifndef POKEMONCOMPBUILDER_TEAM_H
#define POKEMONCOMPBUILDER_TEAM_H


class Team{
private:
    ArrayList<Pokemon*>* pokemonArray;
    std::string name;
    int size;

public:
    Team(std::string NameIN);

    //Destructor
    ~Team();

    //Copy Constructor
    Team(const Team& TeamToCopy);

    //Assignment Operator
    Team& operator=(const Team& TeamToCopy);

    /**
     * @param
     */
    void addPokemon(const Pokemon* const pokemonToAdd);

    /**
     *
     */
    void removePokemon(const Pokemon* const pokemonToRemove);

    /**
     * @return string list of pokemon in the team
     */
    std::string displayTeam();

};


#endif //POKEMONCOMPBUILDER_TEAM_H