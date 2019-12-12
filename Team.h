//
// Created by elimr on 11/20/2019.
//

#include <iostream>
#include "Pokemon.h"
#include <string>
#include "ArrayList.h"

#ifndef POKEMONCOMPBUILDER_TEAM_H
#define POKEMONCOMPBUILDER_TEAM_H


class Team{
private:
    ArrayList<const Pokemon*>* pokemonArray; //TODO change this to a pokemonList
    std::string name;

public:
    Team(std::string NameIN);

    //Destructor
    ~Team();

    //Copy Constructor
    Team(const Team& TeamToCopy);

    //Assignment Operator
    Team& operator=(const Team& TeamToCopy);

    int getCount();

    std::string getName();

    void changeName(std::string nameIn);
    /**
     * @param
     */
    void addPokemon(const Pokemon* pokemonToAdd);

    /**
     *
     */
    void removePokemon(std::string pokemonToRemove);

    /**
     * @return string list of pokemon in the team
     */
    std::string displayTeam();
    std::string displayTeamFile();

    //Returns the pokemon in given index.
    const Pokemon* getPokemon(int Index);

    //Returns type effectivenss of the team
    float* getEffectiveTypes();

};


#endif //POKEMONCOMPBUILDER_TEAM_H