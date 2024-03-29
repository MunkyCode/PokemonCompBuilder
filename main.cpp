#include <iostream>
#include <fstream>
#include "Pokemon.h"
#include "Team.h"
#include "ArrayList.h"
#include "TestLib.h"
#include "PokemonList.h"
#include "FileLibrary.h"
#include "SmartBuilder.h"
#include "TypeEffectiveness.h"
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

void testFileLibrary(){
    std::cout<<"-------Testing FileLibrary------------"<<std::endl;
    PokemonList* pokeList;
    pokeList = createPokemonList("Pokemon - TestData.txt");
    printAssertEquals(false, pokeList->isEmpty());
    printAssertEquals(6, pokeList->find("Aggron"));
    for(int x = 0; x < pokeList->itemCount(); x++){
        std::cout<<pokeList->getValueAt(x)->toString()<<std::endl;
    }

    printToFilePokemon("hello.txt",pokeList, 10);

    Team* team1 = new Team("Test Team One");
    team1->addPokemon(pokeList->getValueAt(1));
    team1->addPokemon(pokeList->getValueAt(2));
    team1->addPokemon(pokeList->getValueAt(3));
    Team* team2 = new Team("Test Team Two");
    team2->addPokemon(pokeList->getValueAt(3));
    team2->addPokemon(pokeList->getValueAt(4));
    team2->addPokemon(pokeList->getValueAt(4));
    ArrayList<Team*>* teamList = new ArrayList<Team*>(2);
    teamList->insertAtEnd(team1);
    teamList->insertAtEnd(team2);

    printToFileTeam("hello2.txt",teamList,2);

    ArrayList<Team*>* teamList2 = createTeamList("hello2.txt",pokeList);
    printAssertEquals(true,teamList->getValueAt(0)->getPokemon(0)==teamList2->getValueAt(0)->getPokemon(0));
    printAssertEquals(true,teamList->getValueAt(1)->getPokemon(0)==teamList2->getValueAt(1)->getPokemon(0));
    printAssertEquals(true,teamList->getValueAt(0)->getPokemon(1)==teamList2->getValueAt(0)->getPokemon(1));
    printAssertEquals(true,teamList->getValueAt(1)->getPokemon(1)==teamList2->getValueAt(1)->getPokemon(1));

}

void pokemonTest(){
    std::string types[19] = {"null","normal", "fighting", "flying", "poison", "ground", "rock", "bug", "ghost", "steel", "fire", "water", "grass", "electric", "psychic", "ice", "dragon", "dark", "fairy"};
    float waterArray[18] = { 1, 1, 1, 1, 1, 1, 1, 1, 0.5, 0.5, 0.5, 2, 2, 1, 0.5, 1, 1, 1};
    float fireArray[18] = { 1, 1, 1, 1, 2, 2, 0.5, 1, 0.5, 0.5, 2, 0.5, 1, 1, 0.5, 1, 1, 0.5};
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
    for(int x = 1; x < 19; x++){
        std::cout<<types[x]<<": "<<p1Effectivness[x-1]<<", ";
    }
    std::cout<<"\nSquirtle:\n";
    float* p2Effectivness = p2->getEffectiveTypes();
    for(int x = 0; x < 18; x++){
        printAssertEquals(waterArray[x],p2Effectivness[x]);
    }
    std::cout<<"\nChamrander:\n";
    float* p3Effectivness = p3->getEffectiveTypes();
    for(int x = 0; x < 18; x++){
        printAssertEquals(fireArray[x], p3Effectivness);
    }
    std::cout<<std::endl;

}

void testArrayList(){
    std::cout<< "--------ArrayList test---------"<<std::endl;
    std::cout<<"Testing different Type, adding, and empty:"<<std::endl;
    ArrayList<int>* intList = new ArrayList<int>(4);
    ArrayList<float>* floatList = new ArrayList<float>(4);
    printAssertEquals(true, intList->isEmpty());
    printAssertEquals(true, floatList->isEmpty());
    floatList->insertAtEnd(10);
    intList->insertAtEnd(10);
    printAssertEquals(false, intList->isEmpty());
    printAssertEquals(false, floatList->isEmpty());
    printAssertEquals(10,intList->getValueAt(0));
    printAssertEquals(10.0,floatList->getValueAt(0));
    std::cout<<"Testing more size:"<<std::endl;
    for(int x = 0; x < 15; x ++){
        intList->insertAtEnd(x);
        floatList->insertAtEnd(x);
    }
    printAssertEquals(16, intList->itemCount());
    printAssertEquals(16, floatList->itemCount());
    std::cout<<"Testing Remove function:\n";
    printAssertEquals(14, intList->removeValueAtEnd());
    printAssertEquals(14.0, floatList->removeValueAtEnd());
    printAssertEquals(5, intList->removeValueAt(6));
    printAssertEquals(5.0, floatList->removeValueAt(6));


    delete intList, floatList;
    std::cout << "Testing with Pokemon pointer type: "<<std::endl;
    Pokemon* p1 = new Pokemon("Bulbasaur", 1, "grass","poison","['Overgrow', 'Chlorophyll']", 1);
    Pokemon* p2 = new Pokemon("Squirtle", 7, "water", "", "['Torrent', 'Rain Dish']", 1);
    Pokemon* p3 = new Pokemon("Charmander", 4, "fire","","['Blaze', 'Solar Power']", 1);
    ArrayList<Pokemon*>* pokeList = new ArrayList<Pokemon*>(4);
    pokeList->insertAtEnd(p1);
    pokeList->insertAtEnd(p2);
    pokeList->insertAtEnd(p3);
    printAssertEquals(p1, pokeList->getValueAt(0));
    printAssertEquals(p2->getName(), pokeList->getValueAt(1)->getName());

    delete pokeList, p1,p2,p3;
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
    delete p1,p2,p3,pokeList,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18;
}

void testTeam(){
    std::cout <<"-------------Team Tests------------"<<std::endl;
    PokemonList* pokeList = createPokemonList("Pokemon - TestData.txt");
    Pokemon* p1 = new Pokemon("Bulbasaur", 1, "grass","poison","['Overgrow', 'Chlorophyll']", 1);
    Pokemon* p2 = new Pokemon("Squirtle", 7, "water", "", "['Torrent', 'Rain Dish']", 1);
    Pokemon* p3 = new Pokemon("Charmander", 4, "fire","","['Blaze', 'Solar Power']", 1);
    Team* team1 = new Team("Test Team One");
    printAssertEquals("Test Team One", team1->getName());
    team1->changeName("new name");
    printAssertEquals("new name",team1->getName());
    team1->addPokemon(pokeList->getValueAt(pokeList->find("Aggron")));
    team1->addPokemon(p1);
    team1->addPokemon(p2);
    std::cout << team1->displayTeam()<<std::endl;
    team1->addPokemon(p3);
    team1->addPokemon(pokeList->getValueAt(pokeList->find("Abra")));
    team1->addPokemon(p1);
    std::cout << team1->displayTeam()<<std::endl;
    try{
    team1->addPokemon(p3);}
    catch(std::exception& e){
        std::cout<<e.what()<<std::endl;
    }
    try{
        team1->removePokemon("Aggron");
        std::cout << team1->displayTeam()<<std::endl;
    }
    catch(std::exception& e){
        std::cout<<"Fail\n";
    }
    team1->addPokemon(pokeList->getValueAt(pokeList->find("Aggron")));
    try{
        team1->removePokemon("Bulbasaur");
        std::cout << team1->displayTeam()<<std::endl;
        team1->removePokemon("Bulbasaur");
        std::cout << team1->displayTeam()<<std::endl;
        team1->removePokemon("Bulbasaur");
        std::cout <<"Fail should errored here\n";
    }
    catch(std::exception& e){
        std::cout<<"Fail if there is still a bulbasaur in the printed teams, otherwise pass\n";
    }
    float* team1Effec = team1->getEffectiveTypes();
    for(int x = 0; x < 18; x++){
        std::cout<<team1Effec[x]<<", ";
    }
    std::cout<<"\n";
    }

int main() {
    srand(time(NULL));
    PokemonList* pokeList = createPokemonList("Pokemon - Data.csv");
    //std::cout << "Hello, World!" << std::endl;
    //printToFile("testFile.txt");
    //printFromFile("testFile.txt");
    //testPokemonFromFile("PokemonData.csv");
    //pokemonTest();
    //testArrayList();
    //testPokemonList();
    //printFromFile("Pokemon - TestData.txt");
    //testFileLibrary();
    //testTeam();


/*
    Team* test = new Team("Test");
    test->addPokemon(pokeList->getValueAt(pokeList->find("Charmander")));
    std::cout<<test->displayTeam()<<std::endl;
    smartTeamFill(test, pokeList);
    std::cout<<test->getCount()<<std::endl;
    std::cout<<test->displayTeam()<<std::endl;
    float* eff = test->getEffectiveTypes();
    for(int x = 0; x < 18; x++){
        std::cout<<eff[x] << ", ";
    }
    std::cout<<"\n";

    Team* test2 = new Team("test2");
    test2->addPokemon(pokeList->getValueAt(pokeList->find("Charmander")));
    try{
    test2->addPokemon(pokeList->getValueAt(pokeList->find("Pikachu")));}
    catch(std::exception& e){
        std::cout<<e.what()<<std::endl;
    }
    smartTeamFill(test2, pokeList);
    std::cout<<test2->displayTeam()<<"\n";

    float* eff2 = test2->getEffectiveTypes();
    for(int x = 0; x < 18; x++){
        std::cout<<eff2[x] << ", ";
    }
    std::cout << "\n";

    Team* test3 = createBalancedTeam("woot", pokeList);
    std::cout<<test3->displayTeam()<<"\n";

    float* eff3 = test3->getEffectiveTypes();
    for(int x = 0; x < 18; x++){
        std::cout<<eff3[x] << ", ";
    }
    std::cout<<"\n";


*/
    //SmartBuilder Build Against test
    Team* teamToCounter = new Team("counterMe");

    int index = pokeList->find("Zangoose");
    Pokemon* genericMon = pokeList->getValueAt(index);
    teamToCounter->addPokemon(genericMon);

    index = pokeList->find("Zangoose");
    genericMon = pokeList->getValueAt(index);
    teamToCounter->addPokemon(genericMon);

    index = pokeList->find("Zangoose");
    genericMon = pokeList->getValueAt(index);
    teamToCounter->addPokemon(genericMon);

    index = pokeList->find("Zangoose");
    genericMon = pokeList->getValueAt(index);
    teamToCounter->addPokemon(genericMon);

    index = pokeList->find("Zangoose");
    genericMon = pokeList->getValueAt(index);
    teamToCounter->addPokemon(genericMon);

    index = pokeList->find("Zangoose");
    genericMon = pokeList->getValueAt(index);
    teamToCounter->addPokemon(genericMon);
    std::string types[19] = {"null","normal", "fighting", "flying", "poison", "ground", "rock", "bug", "ghost", "steel", "fire", "water", "grass", "electric", "psychic", "ice", "dragon", "dark", "fairy"};

    for(int x = 0; x < 18; x++){
        std::cout<<types[x+1]<<": "<<teamToCounter->getEffectiveTypes()[x]<<", ";
    }
    std::cout<<"\n";
    Team* teamCountered = createTeamCounter(teamToCounter,"Countered", pokeList);
    std::cout<<teamToCounter->displayTeam()<<std::endl;
    std::cout<<teamCountered->displayTeam()<<std::endl;
    return 0;



}



