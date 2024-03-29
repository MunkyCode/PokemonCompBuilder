//
// Created by elimr on 11/30/2019.
//
#include <iostream>
#include "Pokemon.h"
#include "Team.h"
#include <string>
#include "ArrayList.h"

    //Constructor
    Team::Team(std::string NameIn){
        this->pokemonArray = new ArrayList<Pokemon*>(6);
        this->name = NameIn;
    }

    //Destructor
    Team::~Team(){
        delete [] pokemonArray;
    }

    //Copy Constructor
    Team::Team(const Team& TeamToCopy){
        pokemonArray = new ArrayList<Pokemon*>(6);
        for(int i = 0; i < 6; i++){
            pokemonArray[i] = TeamToCopy.pokemonArray[i];
        }
    }

    //Assignment Operator
    Team& Team::operator=(const Team& TeamToCopy){
        delete [] pokemonArray;
        pokemonArray = new ArrayList<Pokemon*>(6);
        for(int i = 0; i < 6; i++){
            pokemonArray[i] = TeamToCopy.pokemonArray[i];
        }
    }
    std::string Team::getName(){
    return name;
}

void Team::changeName(std::string nameIn) {
    name = nameIn;
}
    /**
     * Adds a pokemon to pokemon array
    * @param pokemonToAdd
     * @throws exception if array is larger than 6 (team is full)
    */
    void Team::addPokemon(Pokemon* pokemonToAdd){
        if(pokemonArray->itemCount() >= 6){
            throw std::invalid_argument("Team is Full");
        }
        pokemonArray->insertAtEnd(pokemonToAdd);
    }

    /**
     * Removes a specific pokemon from pokemon array
     * @param name of pokemon to remove
     * @throws exception if pokemon is not in array
     */
    void Team::removePokemon(std::string pokemonToRemove){
        int index = -1;
        for(int i = pokemonArray->itemCount(); i > 0; i--){
            if(pokemonArray->getValueAt(i-1)->getName()==pokemonToRemove){
                index = i-1;
            }
        }
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
    std::string Team::displayTeam(){
        std::string team = name;
        if(!(pokemonArray->isEmpty())){
            team+=": ";
            for (int i = 0; i < pokemonArray->itemCount()-1; i++){
                team += pokemonArray->getValueAt(i)->getName() + ", ";
            }
            team += pokemonArray->getValueAt(pokemonArray->itemCount()-1)->getName();
            return team;
        }
        return team;
    }

std::string Team::displayTeamFile(){
    std::string team = name;
    if(!(pokemonArray->isEmpty())){
        team+=",";
        for (int i = 0; i < pokemonArray->itemCount()-1; i++){
            team += pokemonArray->getValueAt(i)->getName() + ",";
        }
        team += pokemonArray->getValueAt(pokemonArray->itemCount()-1)->getName();
        return team;
    }
    return team;
}


    /**
     * @param index
     * @return pokemon name at given index
     */
    Pokemon* Team::getPokemon(int index){
        return pokemonArray->getValueAt(index);
    }


    float* Team::getEffectiveTypes() {
        float* effectiveArray = new float[18];
        for (int x = 0; x < 18; x++) {
            effectiveArray[x] = 1;
        }
        for (int i = 0; i < pokemonArray->itemCount(); i++) {
            float* currPoke = pokemonArray->getValueAt(i)->getEffectiveTypes();
            for(int x = 0; x < 18; x++){
                effectiveArray[x] = effectiveArray[x] * currPoke[x];
            }
        }

        return effectiveArray;
    }

    int Team::getCount(){
        return pokemonArray->itemCount();
    }



