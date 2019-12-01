//
// Created by elimr on 11/30/2019.
//
#include <iostream>;
#include "pokemon.h";
#include <string>;

#ifndef POKEMONCOMPBUILDER_TEAM_H
#define POKEMONCOMPBUILDER_TEAM_H


class Team{

    Team(std::string NameIn){
        int*pokemonArray[6];
        int size = 0;
        std::string name = NameIn;
    }

    ~Team(){
    }

    //Copy Constructor
    Team(const Team& TeamToCopy);

    //Assignment Operator
    Team& operator=(const Team& TeamToCopy);

    /**
     * @param
     */
    void addPokemon(const Pokemon* const pokemonToAdd){
        pokemonArray[size]=pokemonToAdd;
        size+=1;
    }

    /**
     *
     */
    void removePokemon(const Pokemon* const pokemonToRemove);

    /**
     * @return string list of pokemon in the team
     */

    pokemon::pokemon getPokemon(int index){
        return pokemonArray[index]
    }
    std::string displayTeam();

    float* getEffectiveTypes() {
        float *effectiveArray[18]
        for (int x = 0; x < 18; x++) {
            effectiveArray[x] = 1;
        }
        for (int i = 0; i < size; i++) {
            for (int y = 0; y < 18; y++) {
                effectiveArray[y] = effectiveArray[y] * team.getpokemon[i].GetEffectiveTypes;
            }
        }
        return effectiveArray;
    }

};


#endif //POKEMONCOMPBUILDER_TEAM_H
