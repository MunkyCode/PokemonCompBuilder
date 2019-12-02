//
// Created by sjwel on 11/18/2019.
//
#include "Pokemon.h"
#include "TypeEffectiveness.cpp"
#include "ArrayList.h"

Pokemon::Pokemon(std::string nameIn, int pokedexIn, std::string typeIn, std::string type2In, std::string abilityIn, int generationIn, std::string eggGroupIn) {
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
// return list must be deleted by calling function.
// and the efficiences are .25,.5,1,2 and 4 depending on the move.
float* Pokemon::GetEffectiveTypes(){
    float* finalArray = new float[18];
    int array1Index, array2Index;
    for(int x = 0; x < 19; x++){
        if(types[x] == this->type){
            array1Index = x;
        }
        if(types[x] == this-> type2){
            array2Index = x;
        }
    }
    float* array1 = arrays[array1Index];
    float* array2 = arrays[array2Index];
    for(int i=0;i<18;i++){
        finalArray[i] = array1[i]*array2[i];
    }
    return finalArray;
    //TODOew
}