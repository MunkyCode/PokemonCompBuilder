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
    this->ability = abilityIn;
    this->generation = generationIn;
    //this-> eggGroup = eggGroupIn;
    this->typeEffectivness = new float[18];
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
        this->typeEffectivness[i] = array1[i]*array2[i];
    }
}
Pokemon::~Pokemon(){
    delete[] typeEffectivness;
}

Pokemon& Pokemon::operator=(const Pokemon &toCopy) {
    delete[] typeEffectivness;
    typeEffectivness = new float[18];
    for(int x = 0; x < 18; x++){
        typeEffectivness[x] = toCopy.typeEffectivness[x];
    }
    return *this;
}

Pokemon::Pokemon(const Pokemon &toCopy) {
    typeEffectivness = new float[18];
    for(int i = 0; i<18; i++){
        typeEffectivness[i] = toCopy.typeEffectivness[i];
    }
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

int Pokemon::getGeneration(){
    return generation;
}

std::string Pokemon::getAbility(){
    return ability;
}

/*std::string Pokemon::getEggGroup(){
    return eggGroup;
}*/

std::string Pokemon::toString(){
    //TODO
}

//Returns a list of type efficiencies. Each type is corrolated with a number
// return list must be deleted by calling function.
// and the efficiences are .25,.5,1,2 and 4 depending on the move.
float* Pokemon::getEffectiveTypes(){
    return typeEffectivness;
}