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


    std::string input = "";



    //balance team and counter team unde create ne
    std::cout <<" 1: Display all pokemon \n 2: Search for a pokemon \n 3: Display pokemon by type \n"
                " 4: Display all current teams \n 5: Display type effectiveness of a team \n"
                " 6: Create a new team \n 7: Edit a team \n  8: Fill a team \n"
                "'help' to repeat menu \n 'quit' if done \n -> ";

    std::getline(std::cin, input);
    while (input != "quit"){
        if (input == "help"){
           std::cout << " 1: Display all pokemon \n 2: Search for a pokemon \n 3: Display pokemon by type \n"
                        " 4: Display all current teams \n 5: Display type effectiveness of a team \n"
                        " 6: Create a new team \n 7: Edit a team \n  8: Fill a team \n"
                        "'help' to repeat menu \n 'quit' if done \n -> ";
        }
        else if (input == "1"){
            std::cout << createPokemonList;
        }
        else if (input == "2"){
            std::cout <<"Would you like to search by name or pokedex? \n -> ";
            std::string searchInput = "";
            getline(std::cin, searchInput);
            if (searchInput == "name") {
                std::cout <<"What name? \n ->";
                std::string nameInput = "";
                getline(std::cin, nameInput);
                pokeList ->find(nameInput);
            }
            else if (searchInput == "pokedex"){
                std::cout <<"What pokedex number? \n ->";
                std::string dexInput = "";
                getline(std::cin, dexInput);
                pokeList ->find(dexInput);
            }
            else {
                std::cout << " TODO put a catch here?";
            }
        }
        else if (input == "3"){
            std::cout <<" type display in development";
        }
        else if (input == "4"){
            std::cout <<" team display in development";
        }
        else if (input == "5"){
            std::cout <<" type effectiveness display in development";
        }
        else if (input == "6"){
            std::cout <<" create team in development";
        }
        else if (input == "7"){
            std::cout <<" edit team in development";
        }
        else if (input == "8"){
            std::cout <<" fill team in development";
        }
        std::cout<<" -> ";
        getline(std::cin, input);
    }
}
