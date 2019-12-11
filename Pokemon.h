//
// Created by sjwel on 11/18/2019.
//
#include <string>
#ifndef POKEMONCOMPBUILDER_POKEMON_H
#define POKEMONCOMPBUILDER_POKEMON_H
class Pokemon{
private:

    //Name of Pokemon
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
    //std::string eggGroup;

    //Array of type effectivness
    float* typeEffectivness;
public:
    //constructor
    Pokemon(std::string nameIn, int pokedexIn, std::string typeIn, std::string type2In, std::string abilityIn, int generationIn);
    ~Pokemon();
    Pokemon(const Pokemon& toCopy);
    Pokemon& operator=(const Pokemon& toCopy);
    bool operator==(const Pokemon &rhs);


    //Getters
    std::string getName();
    int getPokedex();
    //returns both types as one string
    std::string getType();
    std::string getType2();
    int getGeneration();
    std::string getAbility();
    std::string getEggGroup();

    //To string
    std::string toString();
    std::string toFileString();

    //Returns a list of type efficiencies. Each type is correlated with a number
    // and the efficiencies are .25,.5,1,2 and 4 depending on the move.
    float* getEffectiveTypes();
};

#endif //POKEMONCOMPBUILDER_POKEMON_H
