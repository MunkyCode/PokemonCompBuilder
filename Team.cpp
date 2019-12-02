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


    void Team::addPokemon(const Pokemon* pokemonToAdd){
        if(pokemonArray->itemCount() >= 6){
            throw std::invalid_argument("Team is Full");
        }
        pokemonArray->insertAtEnd(pokemonToAdd);
    }

    /**
     *
     */
    void Team::removePokemon(const Pokemon* pokemonToRemove){
        int index = pokemonArray->find(pokemonToRemove);
        if(index != -1){
            pokemonArray->removeValueAt(index);
        }
    }


    /**
     * @return string list of pokemon in the team
     */

    const Pokemon* Team::getPokemon(int index){
        return pokemonArray->getValueAt(index);
    }
    std::string displayTeam();

    float* Team::getEffectiveTypes() {
        float* effectiveArray = new float(18);
        for (int x = 0; x < 18; x++) {
            effectiveArray[x] = 1;
        }
        for (int i = 0; i < pokemonArray->itemCount(); i++) {
            float* currPoke = const_cast<Pokemon*>(pokemonArray->getValueAt(i))->getEffectiveTypes();
            for(int x = 0; x < 18; x++){
                effectiveArray[x] *=currPoke[x];
            }
        }
        return effectiveArray;
    }



