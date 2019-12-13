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
        std::cout<<"hello------------------------\n";
        float* effList = teamToFill->getEffectiveTypes();
        //TODO Fix this. It dosen't target the right thing.
        int max = 0;
        for(int i = 1; i < 18; i++){
            if(effList[i] > effList[max]){
                max = i;
            }
        }
        int count = 0;
        for(int i = 0; i < 18; i++){
            if(arrays[i][max] < 1){
                count++;
            }
        }
        int typesIndex[count+1];
        int count2 = 0;
        for(int i = 0; i < 18; i++){
            if(arrays[i][max] < 1){
                typesIndex[count2] = i;
                std::cout<<types[i]<<std::endl;
                count2++;
            }
        }
        int randInt = rand()% count-1;
        int chosenIndex = typesIndex[randInt];
        ArrayList<Pokemon*>* toChooseFrom = pokeData->subList(types[chosenIndex+1], "");
        randInt = rand()%toChooseFrom->itemCount()-1;
        Pokemon* toAdd = toChooseFrom->getValueAt(randInt);
        //std::cout<<"hello2\n";
        std::cout<<toAdd->getType()<<" - chosen\n";
        teamToFill->addPokemon(toAdd);

    }
    for(int x = 0; x<18; x++){
        delete[] arrays[x];
    }
}

Team* createTeamCounter(const Team* teamToCounter, std::string teamName, PokemonList pokeData);

Team* createBalancedTeam(std::string teamName, PokemonList pokeData);


