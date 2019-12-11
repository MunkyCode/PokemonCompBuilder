//
// Created by elimr on 12/3/2019.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include<vector>
#include<sstream>
//#include <w32api/wsman.h>
#include "Pokemon.h"
#include"Team.h"
#include "ArrayList.h"
#include "PokemonList.h"


/*void printToFile(std::string fileName){
    std::ofstream outf(fileName);
    if (outf){
        outf <<"testing line 1"<< std::endl;
        outf <<"testing line 2"<< std::endl;
    }
    outf.close();
}*/

void printToFilePokemon(std::string fileName, PokemonList* pokeList, int size) {
    std::ofstream outf(fileName);
    if (outf) {
        for (int i = 0; i < size; i++) {
            outf << pokeList->getValueAt(i)->toFileString() << std::endl;
        }
        outf.close();
    }
}

void printToFileTeam(std::string fileName, ArrayList<Team*>* teamList, int size) {
    std::ofstream outf(fileName);
    if (outf) {
        for (int i = 0; i < size; i++) {
            outf << teamList->getValueAt(i)->getName() + ", " + teamList->getValueAt(i)->displayTeam() << std::endl;
        }
        outf.close();
    }
}

ArrayList<Team*>* createTeamList(std::string fileName){
    ArrayList<Team*>* TeamList = new ArrayList<Team*>(10);
    std::ifstream infile(fileName);
    std::string name;
    if (infile) {
        std::vector<std::string> result;
        while (infile) {
            std::string line;
            getline(infile,line);
            std::stringstream splitter(line); //create string stream from the string
            int count = 0;
            std::string substr;
            if(splitter) {
                getline(splitter, substr, ',');
                while (splitter) {
                    getline(splitter, substr, ',');
                    Team *generic = new Team(name);
                    if (count == 0) {
                        generic->changeName(substr);
                    } else {
                        //Pokemon generic =
                        //generic->addPokemon();
                    }
                    TeamList->insertAtEnd(generic);
                }
            }
    } return TeamList;
}
}


PokemonList* createPokemonList(std::string fileName){
    PokemonList* pokemonDatabase = new PokemonList(801);
    std::ifstream infile(fileName);
    //std::cout<<"working\n";
    std::string name;
    int dex;
    std::string type1;
    std::string type2;
    std::string abilities;
    int gen;
    if (infile) {
        //std::cout<<"working\n";
        int count = 0;
        while (infile) {
            std::string line;
            getline(infile, line);
            std::stringstream splitter(line); //create string stream from the string
            int count = 0;
            std::string substr;
            if(splitter) {
                //std::cout<<count<<" hello\n";
                getline(splitter, substr, ',');
                while (splitter) { //get first string delimited by comma
                    //std::cout<<count<<" hello\n";
                    if (count == 0) {
                        dex = std::stoi(substr);
                        //std::cout<<substr<<"hello"<<std::endl;
                    }
                    if (count == 1) {
                        name = substr;
                    }
                    if (count == 2) {
                        type1 = substr;
                    }
                    if (count == 3) {
                        type2 = substr;
                    }
                    if (count == 4) {
                        abilities = substr;
                    }
                    if (count == 5) {
                        gen = stoi(substr);
                        Pokemon *generic = new Pokemon(name, dex, type1, type2, abilities, gen);
                        pokemonDatabase->addPokemon(generic);
                    }
                    getline(splitter, substr, ',');
                    count += 1;
                }

            }
        }
    }
    else{std::cout<<"Nope\n";}
    return pokemonDatabase;
}