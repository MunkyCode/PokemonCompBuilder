//
// Created by sjwel on 11/18/2019.
//
#include <string>
#ifndef POKEMONCOMPBUILDER_POKEMON_H
#define POKEMONCOMPBUILDER_POKEMON_H
class Pokemon{
private:

    //Name of Poekmon
    std::string name;

    //Pokedex Number
    int pokedex;

    //Pokemon type
    std::string type;
    std::string type2;

    //pokemon ability
    std::string ability;

    //Generation that the pokemon first occurred in
    int generation;

    //Pokemon egg group. Pokemon can breed within their egg group
    std::string eggGroup;
public:
    //constructor
    //ToDO: update this to include all params.
    Pokemon(std::string nameIn, int pokedexIn, std::string typeIn);

    //Getters
    std::string getName();
    int getPokedex();
    //returns both types as one string
    std::string getType();
    int getGeneration();
    std::string getAbility();
    std::string getEggGroup();

    //To string
    std::string toString();

    //Returns a list of type efficiencies. Each type is corrolated with a number
    // and the efficiences are .25,.5,1,2 and 4 depending on the move.
    float* GetEffectiveTypes();
};
#endif //POKEMONCOMPBUILDER_POKEMON_H
