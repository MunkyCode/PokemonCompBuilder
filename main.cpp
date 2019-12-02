#include <iostream>
#include <fstream>
#include "Pokemon.h"
#include "ArrayList.h"
//COMMENT to boost my commit and contributions

void printToFile(std::string fileName){
    std::ofstream outf(fileName);
    if (outf){
        outf <<"testing line 1"<< std::endl;
        outf <<"testing line 2"<< std::endl;
    }
    outf.close();
}
void printFromFile(std::string fileName){
std::ifstream infile(fileName);
    if (infile) {
        while (infile) {
            std::string line;
            getline(infile, line);
            std::cout<<line<<std::endl;
        }
    } else {
    }
}

void pokemonFromString(std::string line);

void testPokemonFromFile(std::string fileName){
    std::ifstream inFile("pokemonData.csv");
    if(inFile){
        while(inFile){
            std::string line;
            getline(inFile, line);
            pokemonFromString(line);
        }
    }
}

void testArrayList(){
    std::cout<< "--------ArrayList test---------"<<std::endl;
    ArrayList<int>* intList = new ArrayList<int>(4);
    std::cout << intList->isEmpty()<<std::endl;
}


int main() {
    //std::cout << "Hello, World!" << std::endl;
    //printToFile("testFile.txt");
    //printFromFile("testFile.txt");
    //testPokemonFromFile("PokemonData.csv");
    testArrayList();



    return 0;
}