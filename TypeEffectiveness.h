//
// Created by sjwel on 12/6/2019.
//

#ifndef POKEMONCOMPBUILDER_TYPEEFFECTIVNESS_H
#define POKEMONCOMPBUILDER_TYPEEFFECTIVNESS_H
std::string types[19] = {"null","normal", "fighting", "flying", "poison", "ground", "rock", "bug", "ghost", "steel", "fire", "water", "grass", "electric", "psychic", "ice", "dragon", "dark", "fairy"};
float nullArray[18] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
float normalArray[18] = { 1, 2, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
float fightingArray[18] = { 1, 1, 2,1, 1, 0.5, 0.5, 1, 1, 1, 1, 1, 1, 2, 1, 1, 0.5, 2};
float flyingArray[18] = { 1, 0.5, 1, 1, 0, 2, 0.5, 1, 1, 1, 1, 0.5, 2, 1, 2, 1, 1, 1};
float poisonArray[18] = { 1, 0.5, 1, 0.5, 2, 1, 0.5, 1, 1, 1, 1, 0.5, 1, 2, 1, 1, 1, 0.5};
float groundArray[18] = { 1, 1, 1, 0.5, 1, 0.5, 1, 1, 1, 1, 2, 2, 0, 1, 2, 1, 1, 1};
float rockArray[18] = { 0.5, 2, 0.5, 0.5, 2, 1, 1, 1, 2, 0.5, 2, 0.5, 1, 1, 1, 1, 1, 1};
float bugArray[18] = { 1, 0.5, 2, 1, 0.5, 2, 1, 1, 1, 2, 1, 0.5, 1, 1, 1, 1, 1, 1};
float ghostArray[18] = { 0, 0, 1, 0.5, 1, 1, 0.5, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1};
float steelArray[18] = { 0.5, 2, 0.5, 0, 2, 0.5, 0.5, 1, 0.5, 2, 1, 0.5, 1, 0.5, 0.5, 0.5, 1, 0.5};
float fireArray[18] = { 1, 1, 1, 1, 2, 2, 0.5, 1, 0.5, 0.5, 2, 0.5, 1, 1, 0.5, 1, 1, 0.5};
float waterArray[18] = { 1, 1, 1, 1, 1, 1, 1, 1, 0.5, 0.5, 0.5, 2, 2, 1, 0.5, 1, 1, 1};
float grassArray[18] = { 1, 1, 2, 2, 0.5, 1, 2, 1, 1, 2, 0.5, 0.5, 0.5, 1, 2, 1, 1, 1};
float electricArray[18] = { 1, 1, 0.5, 1, 2, 1, 1, 1, 0.5, 1, 1, 1, 0.5, 1, 1, 1, 1, 1};
float psychicArray [18]= { 1, 0.5, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 0.5, 1, 1, 2, 1};
float iceArray[18] = { 1, 2, 1, 1, 1, 2, 1, 1, 2, 2, 1, 1, 1, 1, 0.5, 1, 1, 1};
float dragonArray[18] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 0.5, 0.5, 0.5, 0.5, 1, 2, 2, 1, 2};
float darkArray[18] = { 1, 2, 1, 1, 1, 1, 2, 0.5, 1, 1, 1, 1, 1, 0, 1, 1, 0.5, 2};
float fairyArray[18] = { 1, 0.5, 1, 2, 1, 1, 0.5, 1, 2, 1, 1, 1, 1, 1, 1, 0, 0.5, 1};
float* arrays[19] = {nullArray, normalArray, fightingArray, flyingArray, poisonArray, groundArray, rockArray, bugArray, ghostArray, steelArray,
                     fireArray, waterArray, grassArray, electricArray, psychicArray, iceArray, dragonArray, darkArray, fairyArray};

#endif //POKEMONCOMPBUILDER_TYPEEFFECTIVNESS_H
