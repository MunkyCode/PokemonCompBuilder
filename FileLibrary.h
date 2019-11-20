//
// Created by Jolie Elins on 11/20/19.
//
#include <iostream>;
#include <fstream>;
#include "Pokemon.h";

#ifndef POKEMONCOMPBUILDER_FILELIBRARY_H
#define POKEMONCOMPBUILDER_FILELIBRARY_H
/**
 * Takes list of pokemon and writes it to file
 * @param fileName Name of file you wish to write to
 * @param pokeList arrayList of pokemon
 * @param size
 * @throws IDK my exeptions but wrong type if not a pokemon list
 */
void printToFilePokemon(std::string fileName, ArrayList* pokeList, int size);
/**
 *
 * @param fileName
 * @param teamList
 * @param size
 */
void printToFileTeam(std::string fileName, ArrayList* teamList int size);
/**
 *
 * @param fileName
 * @return
 */
ArrayList* readFromFilePokemon(std::string fileName);
/**
 *
 * @param fileName
 * @return
 */
ArrayList* readFromFileTeam(std::string fileName;)


#endif //POKEMONCOMPBUILDER_FILELIBRARY_H
