#include <iostream>
#include <fstream>
#include "Pokemon.h"
#include "Team.h"
#include "ArrayList.h"
#include "TestLib.h"
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
void pokemonTest(){
    std::string types[18] = {"normal", "fighting", "flying", "poison", "ground", "rock", "bug", "ghost", "steel", "fire", "water", "grass", "electric", "psychic", "ice", "dragon", "dark", "fairy"};
    Pokemon* p1 = new Pokemon("Bulbasaur", 1, "grass","poison","['Overgrow', 'Chlorophyll']", 1);
    Pokemon* p2 = new Pokemon("Squirtle", 7, "water", "", "['Torrent', 'Rain Dish']", 1);
    Pokemon* p3 = new Pokemon("Charmander", 4, "fire","testing bad type","['Blaze', 'Solar Power']", 1);
    std::cout<<"-----------Pokemon Test----------"<<std::endl;
    std::cout<<"Getters testing:"<<std::endl;
    printAssertEquals("Bulbasaur",p1->getName());
    printAssertEquals("Squirtle",p2->getName());
    printAssertEquals("Charmander",p3->getName());
    printAssertEquals(1, p1->getPokedex());
    printAssertEquals(7, p2->getPokedex());
    printAssertEquals("grass", p1->getType());
    printAssertEquals("",p3->getType2());

    std::cout<<"Type Effectivness Testing:"<<std::endl;
    std::cout<<"Bulbasuar:"<<std::endl;
    float* p1Effectivness = p1->getEffectiveTypes();
    for(int x = 0; x < 18; x++){
        std::cout<<types[x]<<": "<<p1Effectivness[x]<<", ";
    }
    std::cout<<"\nSquirtle:\n";
    float* p2Effectivness = p2->getEffectiveTypes();
    for(int x = 0; x < 18; x++){
        std::cout<<types[x]<<": "<<p2Effectivness[x]<<", ";
    }
    std::cout<<"\nChamrander:\n";
    float* p3Effectivness = p3->getEffectiveTypes();
    for(int x = 0; x < 18; x++){
        std::cout<<types[x]<<": "<<p3Effectivness[x]<<", ";
    }
    std::cout<<std::endl;

}

void testArrayList(){
    std::cout<< "--------ArrayList test---------"<<std::endl;
    std::cout<<"Basic Tests:"<<std::endl;
    ArrayList<int>* intList = new ArrayList<int>(4);



    ArrayList<float>* floatList = new ArrayList<float>(4);
    floatList->insertAtEnd(10);
    std::cout<<floatList->itemCount()<<std::endl;
    std::cout<<floatList->removeValueAtEnd()<<std::endl;
    std::cout<<floatList->itemCount()<<std::endl;
    delete intList, floatList;
    Pokemon* p1 = new Pokemon("Bulbasaur", 1, "grass","poison","['Overgrow', 'Chlorophyll']", 1);
    Pokemon* p2 = new Pokemon("Squirtle", 7, "water", "", "['Torrent', 'Rain Dish']", 1);
    Pokemon* p3 = new Pokemon("Charmander", 4, "fire","","['Blaze', 'Solar Power']", 1);
    ArrayList<Pokemon*>* pokeList = new ArrayList<Pokemon*>(4);
    pokeList->insertAtEnd(p1);
    std::cout<<pokeList->getValueAt(0)->getName()<<std::endl;


}


int main() {
    //std::cout << "Hello, World!" << std::endl;
    //printToFile("testFile.txt");
    //printFromFile("testFile.txt");
    //testPokemonFromFile("PokemonData.csv");
    pokemonTest();
    testArrayList();



    return 0;
}