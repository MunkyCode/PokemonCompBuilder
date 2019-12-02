//
// Created by elimr on 11/30/2019.
//
#include <iostream>
#include "pokemon.h"
#include "Team.h"
#include <string>
#include "ArrayList.h"

    Team::Team(std::string NameIn){
        this->pokemonArray = new ArrayList<Pokemon*>(6);
        this->size = 0;
        this->name = NameIn;
    }


    void addPokemon(const Pokemon* const pokemonToAdd){
        pokemonArray[size] = pokemonToAdd;
        size+=1;
    }

    /**
     *
     */
    void removePokemon(const Pokemon* const pokemonToRemove);

    /**
     * @return string list of pokemon in the team
     */

    pokemon::getPokemon(int index){
        return pokemonArray[index]
    }
    std::string displayTeam();

    float* getEffectiveTypes() {
        float* effectiveArray[18];
        for (int x = 0; x < 18; x++) {
            effectiveArray[x] = 1.0;
        }
        for (int i = 0; i < size; i++) {
            for (int y = 0; y < 18; y++) {
                effectiveArray[y] = effectiveArray[y] * Team.getpokemon[i].GetEffectiveTypes;
            }
        }
        return effectiveArray;
    }

};


#endif //POKEMONCOMPBUILDER_TEAM_H
