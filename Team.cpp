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

    Team::~Team(){
        delete [] pokemonArray;
    }

    Team::Team(const Team& TeamToCopy){
        pokemonArray = new ArrayList<const Pokemon*>(6);
        for(int i = 0; i < 6; i++){
            pokemonArray[i] = TeamToCopy.pokemonArray[i];
        }
    }


    Team& Team::operator=(const Team& TeamToCopy){
        delete [] pokemonArray;
        pokemonArray = new ArrayList<const Pokemon*>(6);
        for(int i = 0; i < 6; i++){
            pokemonArray[i] = TeamToCopy.pokemonArray[i];
        }
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
        else{
            throw std::invalid_argument("Pokemon Not Found");
        }
    }

    /**
     * @return string list of pokemon in the team
     */
    std::string displayTeam(){
        std::string team = "";
        for (int i = 0; i < 5; i++){
            team += pokemonArray?? getPokemon??? smth here[i] + ", ";
        }
        team += whateverGoesHere[i];
        return team;
    }


    const Pokemon* Team::getPokemon(int index){
        return pokemonArray->getValueAt(index);
    }


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



