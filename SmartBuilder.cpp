//
// Created by sjwel on 12/12/2019.
//
#include "SmartBuilder.h"
#include "ArrayList.h"

void smartTeamFill(Team* teamToFill, PokemonList* pokeData){
    float* arrays[18];
    std::string types[18] = {"normal", "fighting", "flying", "poison", "ground", "rock", "bug", "ghost", "steel", "fire", "water", "grass", "electric", "psychic", "ice", "dragon", "dark", "fairy"};
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
                count2++;
            }
        }
        int randInt = rand()% (count-1);
        int chosenIndex = typesIndex[randInt];
        ArrayList<Pokemon*>* toChooseFrom = pokeData->subList(types[chosenIndex], "");
        randInt = rand()%toChooseFrom->itemCount();
        Pokemon* toAdd = toChooseFrom->getValueAt(randInt);
        teamToFill->addPokemon(toAdd);
        delete toChooseFrom;
        delete[] effList;

    }
    for(int x = 0; x<18; x++){
        delete[] arrays[x];
    }
}

Team* createTeamCounter(Team* teamToCounter, std::string teamName, PokemonList* pokeData){
    Team *NewTeam = new Team(teamName);
    std::string types[18] = {"normal", "fighting", "flying", "poison", "ground", "rock", "bug", "ghost", "steel", "fire", "water", "grass", "electric", "psychic", "ice", "dragon", "dark", "fairy"};
    ArrayList<float> arrayToCounter = ArrayList<float>(18);
    float* EffectiveTypes = teamToCounter->getEffectiveTypes();
    for(int y=0;y<18;y++) {
        float itemToAdd = EffectiveTypes[y];
        //std::cout<<itemToAdd<<std::endl;
        arrayToCounter.insertAtEnd(itemToAdd);
    }
    for(int i = 0;i<6;i++){
    int typeIndex = arrayToCounter.getMaxIndex();
        //std::cout<<i<<"  "<< typeIndex<<std::endl;
    int value = arrayToCounter.getValueAt(typeIndex)/2;
    //std::cout<<value<<std::endl;
    arrayToCounter.insertAt(value,typeIndex);
    ArrayList<Pokemon*>* toChooseFrom = pokeData->subList(types[typeIndex], "");
    int randInt = rand()%toChooseFrom->itemCount();
    Pokemon* NewPokemon = toChooseFrom->getValueAt(randInt);
    delete toChooseFrom;
    NewTeam->addPokemon(NewPokemon);
    }
    return NewTeam;
}

Team* createBalancedTeam(std::string teamName, PokemonList* pokeData){
    int randInt = rand()%pokeData->itemCount();
    Team* toReturn = new Team(teamName);
    toReturn->addPokemon(pokeData->getValueAt(randInt));
    smartTeamFill(toReturn, pokeData);
    return toReturn;
}


