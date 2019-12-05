#include <iostream>
#include <fstream>
#include "Pokemon.h"
#include "Team.h"
#include "ArrayList.h"
#include "TestLib.h"
#include "PokemonList.h"
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
    printAssertEquals("testing bad type",p3->getType2());

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

void testPokemonList(){
    std::cout<< "--------PokemonList test---------"<<std::endl;
    std::cout<<"Basic Tests:"<<std::endl;
    Pokemon* p1 = new Pokemon("Bulbasaur", 1, "grass","poison","['Overgrow', 'Chlorophyll']", 1);
    Pokemon* p2 = new Pokemon("Squirtle", 7, "water", "", "['Torrent', 'Rain Dish']", 1);
    Pokemon* p3 = new Pokemon("Charmander", 4, "fire","","['Blaze', 'Solar Power']", 1);
    PokemonList* pokeList = new PokemonList(4);
    pokeList->addPokemon(p1);
    pokeList->addPokemon(p2);
    pokeList->addPokemon(p3);
    printAssertEquals("Bulbasaur", pokeList->getValueAt(0)->getName());
    printAssertEquals("Charmander", pokeList->getValueAt(1)->getName());
    pokeList->clearList();
    printAssertEquals(true, pokeList->isEmpty());

    Pokemon* t1 = new Pokemon("a",1,"","","",1);
    Pokemon* t2 = new Pokemon("b",2,"","","",1);
    Pokemon* t3 = new Pokemon("c",3,"","","",1);
    Pokemon* t4 = new Pokemon("d",4,"","","",1);
    Pokemon* t5 = new Pokemon("e",5,"","","",1);
    Pokemon* t6 = new Pokemon("f",6,"","","",1);
    Pokemon* t7 = new Pokemon("g",7,"","","",1);
    Pokemon* t8 = new Pokemon("h",8,"","","",1);
    Pokemon* t9 = new Pokemon("i",9,"","","",1);
    Pokemon* t10 = new Pokemon("j",11,"","","",1);
    Pokemon* t11 = new Pokemon("k",12,"","","",1);
    Pokemon* t12 = new Pokemon("l",13,"","","",1);
    Pokemon* t13 = new Pokemon("m",14,"","","",1);
    Pokemon* t14 = new Pokemon("n",15,"","","",1);
    Pokemon* t15 = new Pokemon("o",16,"","","",1);
    Pokemon* t16 = new Pokemon("p",17,"","","",1);
    Pokemon* t17 = new Pokemon("q",18,"","","",1);
    Pokemon* t18 = new Pokemon("r",19,"","","",1);
    pokeList->addPokemon(t1);
    pokeList->addPokemon(t2);
    pokeList->addPokemon(t3);
    pokeList->addPokemon(t4);
    pokeList->addPokemon(t5);
    pokeList->addPokemon(t6);
    pokeList->addPokemon(t7);
    pokeList->addPokemon(t8);
    pokeList->addPokemon(t9);
    pokeList->addPokemon(t10);
    pokeList->addPokemon(t11);
    pokeList->addPokemon(t12);
    pokeList->addPokemon(t13);
    pokeList->addPokemon(t14);
    pokeList->addPokemon(t15);
    pokeList->addPokemon(t16);
    pokeList->addPokemon(t17);
    pokeList->addPokemon(t18);

    std::cout << "Testing find function for name:\n";
    printAssertEquals(7, pokeList->find("h"));
    printAssertEquals(17, pokeList->find("r"));
    printAssertEquals(0, pokeList->find("a"));
    printAssertEquals(-1, pokeList->find("x"));
    printAssertEquals(7, pokeList->find(8));
    printAssertEquals(17, pokeList->find(19));
    printAssertEquals(0, pokeList->find(1));
    printAssertEquals(-1,pokeList->find(20));
}


int main() {
    //std::cout << "Hello, World!" << std::endl;
    //printToFile("testFile.txt");
    //printFromFile("testFile.txt");
    //testPokemonFromFile("PokemonData.csv");
    pokemonTest();
    //testArrayList();
    testPokemonList();



    return 0;
}