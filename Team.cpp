//
// Created by elimr on 11/30/2019.
//
#include <iostream>
#include "pokemon.h"
#include "Team.h"
#include <string>
#include "ArrayList.h"

    Team::Team(std::string NameIn){
        this->pokemonArray = new ArrayList<const Pokemon*>(6);
        this->name = NameIn;
    }


    void Team::addPokemon(Pokemon* const pokemonToAdd){
        pokemonArray->insertAtEnd(pokemonToAdd);
    }

    /**
     *
     */
    void Team::removePokemon(Pokemon* const pokemonToRemove){
        int index = pokemonArray->find(pokemonToRemove);
        pokemonArray->removeValueAt(index);

    /**
     * @return string list of pokemon in the team
     */

    const Pokemon* Team::getPokemon(int index){
        return pokemonArray->getValueAt(index);
    }
    std::string displayTeam();

    float* Team::getEffectiveTypes() {
        float* effectiveArray[18];
        for (int x = 0; x < 18; x++) {
            effectiveArray[x] = 1;
        }
        for (int i = 0; i < size; i++) {
            for (int y = 0; y < 18; y++) {
                effectiveArray[y] = effectiveArray[y] * Team.getpokemon[i].GetEffectiveTypes;
            }
        }
        return effectiveArray;
    }

};

