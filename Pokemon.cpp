//
// Created by sjwel on 11/18/2019.
//
#include "Pokemon.h"
#include "TypeEffectiveness.h"
#include "ArrayList.h"
#include <string>

//Constructor
Pokemon::Pokemon(std::string nameIn, int pokedexIn, std::string typeIn, std::string type2In, std::string abilityIn, int generationIn) {
    std::string types[18] = {"normal", "fighting", "flying", "poison", "ground", "rock", "bug", "ghost", "steel", "fire", "water", "grass", "electric", "psychic", "ice", "dragon", "dark", "fairy"};
    this->name = nameIn;
    this->pokedex = pokedexIn;
    this->type = typeIn;
    this->ability = abilityIn;
    this->generation = generationIn;
    //this-> eggGroup = eggGroupIn;
    bool test = false;
    for(int x = 0; x < 18; x++){
        if(types[x] == type2In){
            test = true;
        }
    }
    if(!test){
        type2 = "null";
    }
    else{
        type2 = type2In;
    }
    this->typeEffectivness = new float[18];
    float* type1Arr = returnTypeArray(type);
    float* type2Arr = returnTypeArray(type2);
    for(int x = 0; x < 18; x++){
        typeEffectivness[x] = type1Arr[x]*type2Arr[x];
    }
    delete[] type1Arr, type2Arr;
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

bool Pokemon::operator==(const Pokemon &rhs){
    return name == rhs.name && pokedex == rhs.pokedex && ability == rhs.ability && type == rhs.type &&
           type2 == rhs.type2 && generation == rhs.generation;
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

    std::string Pokemon::toFileString(){
        std::string pokedexStr = std::to_string(pokedex);
        std::string pokemon = name + ", " + pokedexStr + ", " + type + ", "+ type2 + ", " + ability + ", " + std::to_string(generation);
        return pokemon;
}
//Returns a list of type efficiencies. Each type is correlated with a number
// return list must be deleted by calling function.
// and the efficiencies are .25,.5,1,2 and 4 depending on the move.
float* Pokemon::getEffectiveTypes(){
    return typeEffectivness;
}