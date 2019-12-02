//
// Created by sjwel on 11/18/2019.
//
#include "Pokemon.h"
#include "TypeEffectiveness.cpp"
#include "ArrayList.h"

Pokemon::Pokemon(std::string nameIn, int pokedexIn, std::string typeIn, std::string type2In, std::string abilityIn, int generationIn) {
    this->name = nameIn;
    this->pokedex = pokedexIn;
    this->type = typeIn;
    this->type2 = type2In;
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
    int* finalArray[18];
    int* array1 = arrays[types.find(type)];
    int* array2 = arrays[types.find(type2)];
    for(int i=0;i<18;i++){
        finalArray[i] = array1[i]*array2[i];
    }
    return finalArray;
    //TODOew
}