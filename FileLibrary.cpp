//
// Created by elimr on 12/3/2019.
//
#include <iostream>
#include <fstream>
#include<vector>
#include<sstream>
#include <w32api/wsman.h>
#include "Pokemon.h"
#include"Team.h"
#include "ArrayList.h"
#include "PokemonList.h"


void printToFile(std::string fileName){
    std::ofstream outf(fileName);
    if (outf){
        outf <<"testing line 1"<< std::endl;
        outf <<"testing line 2"<< std::endl;
    }
    outf.close();
}

void printToFilePokemon(std::string fileName, ArrayList<Pokemon*>* pokeList, int size) {
    std::ofstream outf(fileName);
    if (outf) {
        for (int i = 0; i < size; i++) {
            outf << pokeList->getValueAt(i)->getName() << std::endl;
        }
        outf.close();
    }
}

void printToFileTeam(std::string fileName, ArrayList<Team*>* teamList, int size) {
    std::ofstream outf(fileName);
    if (outf){
        for(int i = 0; i<size;i++) {
            outf <<teamList->getValueAt(i)->getName() + ": " + teamList->getValueAt(i)->displayTeam()<<std::endl;
    }
    outf.close();
}

}
ArrayList<Pokemon*>* CreatePokemonList(std::string fileName){
    ArrayList<Pokemon*>* pokemonDatabase = new ArrayList<Pokemon*>*(801);
    std::ifstream infile(fileName);
    std::string name;
    int dex;
    std::string type1;
    std::string type2;
    std::string abilities;
    int gen;
    if (infile) {
        std::vector<std::string> result;
        int count = 0;
        while (infile) {
            std::string line;
            std::stringstream s_stream(line); //create string stream from the string
            int count = 0;
            while (s_stream.good()) {
                std::string substr;
                getline(s_stream, substr, ','); //get first string delimited by comma
                if(count==0){
                    name = substr;
                }
                if(count==1){
                    dex = std::stoi(substr);
                }
                if(count==2){
                    type1 = substr;
                }
                if(count==3){
                    type2 = substr;
                }
                if(count==4){
                    abilities = substr;
                }
                if(count==5){
                    gen = stoi(substr);
                }
                count +=1;
            }
            Pokemon* generic = new Pokemon(name,dex,type1,type2,abilities,gen);
            getline(infile, line);
            pokemonDatabase->insertAtEnd(generic);
        }
    } else {
    }
}