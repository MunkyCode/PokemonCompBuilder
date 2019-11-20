//
// Created by Jolie Elins on 11/20/19.
//
#include <iostream>;
#include <fstream>;
#include "Pokemon.h";

#ifndef POKEMONCOMPBUILDER_FILELIBRARY_H
#define POKEMONCOMPBUILDER_FILELIBRARY_H

void printToFile(std::string fileName, Pokemon* pokeList, int size);
void printToFile(std::string fileName, Team* teamList, int size);
Pokemon* readFromFilePokemon(std::string fileName);
Team* readFromFileTeam(std::string fileName;)


#endif //POKEMONCOMPBUILDER_FILELIBRARY_H
