//
// Created by sjwel on 11/18/2019.
//

#ifndef POKEMONCOMPBUILDER_POKEMON_H
#define POKEMONCOMPBUILDER_POKEMON_H
class Pokemon{
private:
    std::string name;
    int pokedex;
    std::string type;
public:
    //constructor
    Pokemon(std::string nameIn, int pokedexIn, std::string typeIn);

    //Getters
    std::string getName();
    int getPokedex();
    std::string getType();

    //To string
    std::string toString();


};
#endif //POKEMONCOMPBUILDER_POKEMON_H
