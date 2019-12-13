//
// Created by sjwel on 12/12/2019.
//
#include "SmartBuilder.h"

void smartTeamFill(Team* teamToFill, PokemonList* pokeData){
    float* arrays[18];
    std::string types[19] = {"null","normal", "fighting", "flying", "poison", "ground", "rock", "bug", "ghost", "steel", "fire", "water", "grass", "electric", "psychic", "ice", "dragon", "dark", "fairy"};
    for(int x = 1 ; x < 19; x++){
        arrays[x-1] = returnTypeArray(x);
    }
    for(int x = 6-teamToFill->getCount(); x > 0; x--){
        float* effList = teamToFill->getEffectiveTypes();
        int max = 0;
        for(int i = 1; i < 18; i++){
            if(effList[i] > effList[max]){
                max = i;
            }
        }
        int count = 0;
        for(int x = 0; x < 18; x++){
            if(arrays[x][max] < 1){
                count++;
            }
        }
        int typesIndex[count];
        int count2 = 0;
        for(int x = 0; x < 18; x++){
            if(arrays[x][max] < 1){
                typesIndex[count2] = x;
                count2++;
            }
        }
        int randInt = rand()% count;
        int chosenIndex = typesIndex[randInt];
        ArrayList<Pokemon*>* toChooseFrom = pokeData->subList(types[chosenIndex], "");
        randInt = rand()%toChooseFrom->itemCount();
        Pokemon* toAdd = toChooseFrom->getValueAt(randInt);
        teamToFill->addPokemon(toAdd);

    }
}

Team* createTeamCounter(const Team* teamToCounter, std::string teamName, PokemonList pokeData);

Team* createBalancedTeam(std::string teamName, PokemonList pokeData);


