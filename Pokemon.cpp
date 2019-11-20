//
// Created by sjwel on 11/18/2019.
//
#include "Pokemon.h"

Pokemon::Pokemon(std::string nameIn, int pokedexIn, std::string typeIn) {
    this->name = nameIn;
    this->pokedex = pokedexIn;
    this->type = typeIn;
}

std::string Pokemon::getName(){
    return name;
}

int Pokemon::getPokedex(){
    return pokedex;
}

std::string Pokemon::getType(){
    return type;
}

int getGeneration(){
    return generation;
}

std::string getAbility(){
    return ability;
}

std::string getEggGroup(){
    return eggGroup;
}

std::string Pokemon::toString(){
    //TODO
}

//Returns a list of type efficiencies. Each type is corrolated with a number
// and the efficiences are .25,.5,1,2 and 4 depending on the move.
float* GetEffectiveTypes(){
    //TODO
}