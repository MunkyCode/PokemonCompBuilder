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

std::string Pokemon::toString(){
    
}