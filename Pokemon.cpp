//
// Created by sjwel on 11/18/2019.
//
#include "Pokemon.h"
#include "TypeEffectiveness.cpp"
#include "ArrayList.h"
#include <string>

//Constructor
Pokemon::Pokemon(std::string nameIn, int pokedexIn, std::string typeIn, std::string type2In, std::string abilityIn, int generationIn) {
    this->name = nameIn;
    this->pokedex = pokedexIn;
    this->type = typeIn;
    this->type2 = type2In;
    this->ability = abilityIn;
    this->generation = generationIn;
    //this-> eggGroup = eggGroupIn;
    this->typeEffectivness = new float[18];
    int array1Index = 0, array2Index = 0;
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

//Destructor
Pokemon::~Pokemon(){
    delete[] typeEffectivness;
}

//Assignment Operator
Pokemon& Pokemon::operator=(const Pokemon &toCopy) {
    delete[] typeEffectivness;
    typeEffectivness = new float[18];
    for(int x = 0; x < 18; x++){
        typeEffectivness[x] = toCopy.typeEffectivness[x];
    }
    return *this;
}

//Copy Constructor
Pokemon::Pokemon(const Pokemon &toCopy) {
    typeEffectivness = new float[18];
    for(int i = 0; i<18; i++){
        typeEffectivness[i] = toCopy.typeEffectivness[i];
    }
}

    /**
     * @return name of current Pokemon
     */
std::string Pokemon::getName(){
    return name;
}

    /**
     * @return Pokedex number of current Pokemon
     */
int Pokemon::getPokedex(){
    return pokedex;
}

    /**
     * @return type of current Pokemon
     */
std::string Pokemon::getType(){
    return type;
}

    /**
     * @return Secondary type of current Pokemon
     */
std::string Pokemon::getType2(){
    return type2;
}

    /**
     * @return Generation of current Pokemon
     */
int Pokemon::getGeneration(){
    return generation;
}

    /**
     * @return Ability of current Pokemon
     */
std::string Pokemon::getAbility(){
    return ability;
}

/*std::string Pokemon::getEggGroup(){
    return eggGroup;
}*/

    /**
     * @return Current Pokemon with all listed attributes
     */
std::string Pokemon::toString() {
        std::string pokedexStr = std::to_string(pokedex);
        std::string pokemon = "Name: " + name + ", " + "Pokedex: " + pokedexStr + ", " + "Type: " + type + ", "+ "Secondary Type: " + type2 + ", " + "Ability: " + ability + ", " + "Generation: " + std::to_string(generation) ;
        return pokemon;

    }
//Returns a list of type efficiencies. Each type is correlated with a number
// return list must be deleted by calling function.
// and the efficiencies are .25,.5,1,2 and 4 depending on the move.
float* Pokemon::getEffectiveTypes(){
    return typeEffectivness;
}