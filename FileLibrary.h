//
// Created by Jolie Elins on 11/20/19.
//
#include <iostream>;
#include <fstream>;
#include "Pokemon.h";

#ifndef POKEMONCOMPBUILDER_FILELIBRARY_H
#define POKEMONCOMPBUILDER_FILELIBRARY_H

void printToFilePokemon(std::string fileName, ArrayList* pokeList, int size);
void printToFileTeam(std::string fileName, ArrayList* teamList int size);
ArrayList* readFromFilePokemon(std::string fileName);
ArrayList* readFromFileTeam(std::string fileName;)


#endif //POKEMONCOMPBUILDER_FILELIBRARY_H
