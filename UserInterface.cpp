//
// Created by Jolie Elins on 12/11/19.
//

#include <iostream>
#include <string>
#include <fstream>
#include "Pokemon.h"
#include "Team.h"
#include "ArrayList.h"
#include "TestLib.h"
#include "PokemonList.h"
#include "FileLibrary.h"
#include "SmartBuilder.h"


int main() {
    srand(time(NULL));
    PokemonList* pokeList;
    pokeList = createPokemonList("Pokemon - Data.csv");
    ArrayList<Team*>* teamList;
    teamList = createTeamList("team.txt", pokeList);
    //teamList = new ArrayList<Team*>(10);

    std::string input = "";



    //balance team and counter team unde create ne
    std::cout <<" 1: Display all pokemon \n 2: Search for a pokemon \n 3: Display pokemon by type \n"
                " 4: Display all current teams \n 5: Display type effectiveness of a team \n"
                " 6: Create a new team \n 7: Edit a team \n 8: Fill a team with compatible pokemon\n"
                "'help' to repeat menu \n 'quit' if done \n -> ";

    std::getline(std::cin, input);
    while (input != "quit"){
        if (input == "help"){
           std::cout << " 1: Display all pokemon \n 2: Search for a pokemon \n 3: Display pokemon by type \n"
                        " 4: Display all current teams \n 5: Display type effectiveness of a team \n"
                        " 6: Create a new team \n 7: Edit a team \n  8: Fill a team with compatible pokemon\n"
                        "'help' to repeat menu \n 'quit' if done \n";
        }
        else if (input == "1"){
            for(int i = 0; i < pokeList->itemCount(); i++){
                std::cout << pokeList->getValueAt(i)->toString()<<std::endl;
            }
        }
        else if (input == "2"){
            std::cout <<"Would you like to search by name or pokedex? \n -> ";
            std::string searchInput = "";
            getline(std::cin, searchInput);
            if (searchInput == "name") {
                std::cout <<"What name? \n ->";
                std::string nameInput = "";
                getline(std::cin, nameInput);
                try{
                    std::cout<<pokeList->getValueAt(pokeList->find(nameInput))->toString() <<std::endl;
                }
                catch(std::exception& e){
                    std::cout<<"Invalid Pokemon Name\n";
                }
            }
            else if (searchInput == "pokedex"){
                std::cout <<"What pokedex number? \n ->";
                std::string dexInput = "";
                getline(std::cin, dexInput);
                int dex = -1;
                try{
                    dex = stoi(dexInput);
                    try{
                        std::cout<<pokeList->getValueAt(pokeList->find(dex))->toString() <<std::endl;
                    }
                    catch(std::out_of_range& e){
                        std::cout<<"No such pokedex\n";
                    }
                }
                catch(std::exception&e){
                    std::cout<<"Input must be a Number\n";
                }
            }
            else {
                std::cout << "Invalid search type \n";
            }
        }
        else if (input == "3"){
            std::cout<< "Would you like to search for one type, or a combination? ('one' or 'combination') \n -> ";
            std::string val = "";
            getline(std::cin, val);
            if (val == "one"){
                std::cout<<"What type would you like to search for? \n";
                std::string type = "";
                getline(std::cin, type);
                ArrayList<Pokemon*>* subList;
                try{
                    subList = pokeList->subList(type,"");
                    for(int x = 0; x<subList->itemCount(); x++){
                        std::cout<<subList->getValueAt(x)->toString()<<std::endl;
                    }
                    delete(subList);
                }
                catch(std::invalid_argument& e){
                    std::cout<<"Invalid Type\n";
                }

            }
            else if (val == "combination"){
                std::cout<<"What is the first type would you like to search for? \n -> ";
                std::string type1 = "";
                getline(std::cin, type1);
                std::cout<<"What is the second type would you like to search for? \n -> ";
                std::string type2 = "";
                getline(std::cin, type2);
                ArrayList<Pokemon*>* subList;
                try{
                    subList = pokeList->subList(type1, type2);
                    for(int x = 0; x<subList->itemCount(); x++){
                        std::cout<<subList->getValueAt(x)->toString()<<std::endl;
                    }
                    delete(subList);
                }
                catch(std::invalid_argument& e){
                    std::cout<<"One or more types is invalid\n";
                }

            }
            else{
                std::cout << "Invalid entry \n";
            }

        }
        else if (input == "4"){
            if(teamList->isEmpty()) {
                std::cout <<"There are no teams in the list \n";
            }
            else {
                //std::cout <<teamList->getValueAt(0)->getName()<<"\n";
                for (int i = 0; i < teamList->itemCount(); i++){
                    std::cout << teamList->getValueAt(i)->displayTeam() << "\n";
                }
            }
        }
        else if (input == "5"){
            std::cout <<"What is the name of the team you would like to see? \n -> ";
            std::string teamName = "";
            getline(std::cin, teamName);
            int index = -1;
            for (int i = 0; i < teamList->itemCount(); i++){
                if (teamList->getValueAt(i)->getName() == teamName){
                    index = i;
                }
            }
            if (index != -1) {
                float* effectiveTypes = teamList->getValueAt(index)->getEffectiveTypes();
                std::string types[18] = {"normal", "fighting", "flying", "poison", "ground", "rock", "bug", "ghost", "steel", "fire", "water", "grass", "electric", "psychic", "ice", "dragon", "dark", "fairy"};
                for(int i = 0; i < 17; i++){
                    std::cout << types[i] << ": "<<effectiveTypes[i] << ", ";
                }
                std::cout<< types[17] << ": "<<effectiveTypes[17]<<"\n";
            }
            else{
                std::cout << "Team Not Found\n";
            }
        }
        else if (input == "6"){
            std::cout <<"Would you like to: \n 1: Create a new team\n 2: Create a balanced team\n 3: Counter a given team\n -> ";
            std::string teamType = "";
            getline(std::cin, teamType);
            bool valid = false;
            std::string teamName;
            bool validType = false;
            if(teamType=="1"||teamType=="2"||teamType == "3"){
                validType = true;
                std::cout <<"What would you like to name your team? \n -> ";
                teamName = "";
                getline(std::cin, teamName);
                valid = true;
                for(int o = 0; o < teamList->itemCount(); o++){
                    if(teamList->getValueAt(o)->getName() == teamName){
                        valid = false;
                    }
                }
            }
            if(valid){
                if(teamType == "1"){
                    Team* newTeam = new Team(teamName);
                    teamList -> insertAtEnd(newTeam);
                    std::cout <<"Would you like to: \n 1: Add a pokemon\n 2: Remove a pokemon\n 3: Change the name \n 'done' to finish editing \n 'help' to bring up this menu again\n -> ";
                    std::string editOption = "";
                    getline(std::cin, editOption);
                    while (editOption != "done"){
                        if(editOption == "1"){
                            std::cout <<"What is the name of the pokemon you would like to add? \n -> ";
                            std::string pokemonName = "";
                            getline(std::cin, pokemonName);
                            try{
                                newTeam->addPokemon(pokeList->getValueAt(pokeList->find(pokemonName)));
                            }
                            catch(std::invalid_argument& e){
                                std::cout<<"Team is full\n";
                            }
                            catch(std::out_of_range& e){
                                std::cout<<"Invalid Pokemon name\n";
                            }
                        }
                        else if(editOption == "2"){
                            std::cout <<"What is the name of the pokemon you would like to remove? \n -> ";
                            std::string pokemonName = "";
                            getline(std::cin, pokemonName);
                            try{
                                newTeam->removePokemon(pokemonName);
                            }
                            catch(std::invalid_argument& e){
                                std::cout<<"Pokemon not in team\n";
                            }
                        }
                        else if(editOption == "3"){
                            std::cout <<"What would you like the new name to be? \n -> ";
                            std::string newTeamName = "";
                            getline(std::cin, newTeamName);
                            newTeam->changeName(newTeamName);
                        }
                        else if(editOption == "help"){
                            std::cout <<"Would you like to: \n 1: Add a pokemon\n 2: Remove a pokemon\n 3: Change the name \n 'done' to finish editing \n 'help' to bring up this menu again\n";
                        }
                        else{
                            std::cout<<"Not a valid option\n";
                        }
                        std::cout << " -> ";
                        getline(std::cin, editOption);
                    }
                }
                else if(teamType == "2"){
                    Team* newTeam = createBalancedTeam(teamName, pokeList);
                    teamList -> insertAtEnd(newTeam);
                }
                else if(teamType == "3"){
                    std::cout <<"What is the name of the team you would like to counter? \n -> ";
                    std::string counterTeam = "";
                    getline(std::cin, counterTeam);
                    Team* teamCounter = nullptr;
                    for(int x = 0; x < teamList->itemCount(); x++){
                        if(counterTeam==teamList->getValueAt(x)->getName()){
                            teamCounter = teamList->getValueAt(x);
                        }
                    }
                    if(teamCounter!=nullptr){
                        Team* newTeam = createTeamCounter(teamCounter, teamName, pokeList);
                        teamList -> insertAtEnd(newTeam);
                    }
                    else{
                        std::cout<< "Invalid Team Name\n";
                    }
                }
                else {
                    std::cout << "Invalid entry \n";
                }
            }
            else if(validType){
                std::cout<<"Team Already exists\n";
            }
            else{
                std::cout<<"Invalid Option\n";
            }
        }
        else if (input == "7"){
            std::cout << "Which team would you like to edit? \n -> ";
            std::string teamName = "";
            getline(std::cin, teamName);
            Team* teamEdit= nullptr;
            for(int x = 0; x < teamList->itemCount(); x++){
                if(teamList->getValueAt(x)->getName() == teamName){
                    teamEdit = teamList->getValueAt(x);
                }
            }
            if (teamEdit!= nullptr){
                std::cout <<"Would you like to: \n 1: Add a pokemon\n 2: Remove a pokemon\n 3: Change the name \n 4: Delete Team\n 'done' to finish editing \n 'help' to bring up this menu again\n -> ";
                std::string editOption = "";
                getline(std::cin, editOption);
                while (editOption != "done"){
                    if(editOption == "1"){
                        std::cout <<"What is the name of the pokemon you would like to add? \n -> ";
                        std::string pokemonName = "";
                        getline(std::cin, pokemonName);
                        try{
                            teamEdit->addPokemon(pokeList->getValueAt(pokeList->find(pokemonName)));
                        }
                        catch(std::invalid_argument& e){
                            std::cout<<"Team is full\n";
                        }
                        catch(std::out_of_range& e){
                            std::cout<<"Invalid Pokemon name\n";
                        }
                    }
                    else if(editOption == "2"){
                        std::cout <<"What is the name of the pokemon you would like to remove? \n -> ";
                        std::string pokemonName = "";
                        getline(std::cin, pokemonName);
                        try{
                            teamEdit->removePokemon(pokemonName);
                        }
                        catch(std::invalid_argument& e){
                            std::cout<<"Pokemon not in team\n";
                        }
                    }
                    else if(editOption == "3"){
                        std::cout <<"What would you like the new name to be? \n -> ";
                        std::string newTeamName = "";
                        getline(std::cin, newTeamName);
                        teamEdit->changeName(newTeamName);
                    }
                    else if(editOption == "help"){
                        std::cout <<"Would you like to: \n 1: Add a pokemon\n 2: Remove a pokemon\n 3: Change the name \n 'done' to finish editing \n 'help' to bring up this menu again\n -> ";
                    }
                    else if(editOption == "4"){}
                    else{
                        std::cout<<"Not a valid option\n";
                    }
                    if(editOption == "4"){
                        for(int x = 0; x < teamList->itemCount(); x++){
                            if(teamList->getValueAt(x)->getName() == teamName){
                                teamList->removeValueAt(x);
                            }
                        }
                        editOption = "done";
                    }
                    else{
                        std::cout << " -> ";
                        getline(std::cin, editOption);
                    }
                }
            }
            else{
                std::cout<<"Invalid Team Name";
            }

        }
        else if (input == "8"){
            std::cout <<"What is the name of the team you would like to fill?\n -> ";
            std::string teamName = "";
            getline(std::cin, teamName);
            Team* teamEdit= nullptr;
            for(int x = 0; x < teamList->itemCount(); x++){
                if(teamList->getValueAt(x)->getName() == teamName){
                    teamEdit = teamList->getValueAt(x);
                }
            }
            if (teamEdit!= nullptr){
                smartTeamFill(teamEdit, pokeList);
            }
            else{
                std::cout<<"Invalid Team\n";
            }
        }
        else{
            std::cout<<"Invalid Option\n";
        }
        std::cout<<" -> ";
        getline(std::cin, input);
    }
    printToFileTeam("team.txt", teamList, teamList->itemCount());
}
