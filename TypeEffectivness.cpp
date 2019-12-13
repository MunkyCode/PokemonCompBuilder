//
// Created by Stephen on 12/12/2019.
//

#include "TypeEffectiveness.h"

float* returnTypeArray(std::string type){
    std::string types[19] = {"null","normal", "fighting", "flying", "poison", "ground", "rock", "bug", "ghost", "steel", "fire", "water", "grass", "electric", "psychic", "ice", "dragon", "dark", "fairy"};
    float* nullArray = new float[18]{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    float* normalArray =new float[18] { 1, 2, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    float* fightingArray =new float[18] { 1, 1, 2,1, 1, 0.5, 0.5, 1, 1, 1, 1, 1, 1, 2, 1, 1, 0.5, 2};
    float* flyingArray =new float[18] { 1, 0.5, 1, 1, 0, 2, 0.5, 1, 1, 1, 1, 0.5, 2, 1, 2, 1, 1, 1};
    float* poisonArray =new float[18] { 1, 0.5, 1, 0.5, 2, 1, 0.5, 1, 1, 1, 1, 0.5, 1, 2, 1, 1, 1, 0.5};
    float* groundArray =new float[18] { 1, 1, 1, 0.5, 1, 0.5, 1, 1, 1, 1, 2, 2, 0, 1, 2, 1, 1, 1};
    float* rockArray= new float[18]{ 0.5, 2, 0.5, 0.5, 2, 1, 1, 1, 2, 0.5, 2, 0.5, 1, 1, 1, 1, 1, 1};
    float* bugArray = new float[18]{ 1, 0.5, 2, 1, 0.5, 2, 1, 1, 1, 2, 1, 0.5, 1, 1, 1, 1, 1, 1};
    float* ghostArray= new float[18]{ 0, 0, 1, 0.5, 1, 1, 0.5, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1};
    float* steelArray = new float[18]{ 0.5, 2, 0.5, 0, 2, 0.5, 0.5, 1, 0.5, 2, 1, 0.5, 1, 0.5, 0.5, 0.5, 1, 0.5};
    float* fireArray =new float[18] { 1, 1, 1, 1, 2, 2, 0.5, 1, 0.5, 0.5, 2, 0.5, 1, 1, 0.5, 1, 1, 0.5};
    float* waterArray = new float[18]{ 1, 1, 1, 1, 1, 1, 1, 1, 0.5, 0.5, 0.5, 2, 2, 1, 0.5, 1, 1, 1};
    float* grassArray=new float[18] { 1, 1, 2, 2, 0.5, 1, 2, 1, 1, 2, 0.5, 0.5, 0.5, 1, 2, 1, 1, 1};
    float* electricArray =new float[18] { 1, 1, 0.5, 1, 2, 1, 1, 1, 0.5, 1, 1, 1, 0.5, 1, 1, 1, 1, 1};
    float* psychicArray = new float[18]{ 1, 0.5, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 0.5, 1, 1, 2, 1};
    float* iceArray = new float[18]{ 1, 2, 1, 1, 1, 2, 1, 1, 2, 2, 1, 1, 1, 1, 0.5, 1, 1, 1};
    float* dragonArray = new float[18]{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 0.5, 0.5, 0.5, 0.5, 1, 2, 2, 1, 2};
    float* darkArray= new float[18]{ 1, 2, 1, 1, 1, 1, 2, 0.5, 1, 1, 1, 1, 1, 0, 1, 1, 0.5, 2};
    float* fairyArray = new float[18]{ 1, 0.5, 1, 2, 1, 1, 0.5, 1, 2, 1, 1, 1, 1, 1, 1, 0, 0.5, 1};
    float* arrays[19] = {nullArray, normalArray, fightingArray, flyingArray, poisonArray, groundArray, rockArray, bugArray, ghostArray, steelArray,
                         fireArray, waterArray, grassArray, electricArray, psychicArray, iceArray, dragonArray, darkArray, fairyArray};
    for(int x = 0; x< 19; x++){
        if(type == types[x]){
            for(int i = 0; i< 19; i++){
                if(i != x){
                    delete[] arrays[i];
                }
            }
            return arrays[x];
        }
    }
    for(int i = 1; i< 19; i++){
        delete[] arrays[i];
    }
    return arrays[0];
}

float* returnTypeArray(int type){
    float* nullArray = new float[18]{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    float* normalArray =new float[18] { 1, 2, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    float* fightingArray =new float[18] { 1, 1, 2,1, 1, 0.5, 0.5, 1, 1, 1, 1, 1, 1, 2, 1, 1, 0.5, 2};
    float* flyingArray =new float[18] { 1, 0.5, 1, 1, 0, 2, 0.5, 1, 1, 1, 1, 0.5, 2, 1, 2, 1, 1, 1};
    float* poisonArray =new float[18] { 1, 0.5, 1, 0.5, 2, 1, 0.5, 1, 1, 1, 1, 0.5, 1, 2, 1, 1, 1, 0.5};
    float* groundArray =new float[18] { 1, 1, 1, 0.5, 1, 0.5, 1, 1, 1, 1, 2, 2, 0, 1, 2, 1, 1, 1};
    float* rockArray= new float[18]{ 0.5, 2, 0.5, 0.5, 2, 1, 1, 1, 2, 0.5, 2, 0.5, 1, 1, 1, 1, 1, 1};
    float* bugArray = new float[18]{ 1, 0.5, 2, 1, 0.5, 2, 1, 1, 1, 2, 1, 0.5, 1, 1, 1, 1, 1, 1};
    float* ghostArray= new float[18]{ 0, 0, 1, 0.5, 1, 1, 0.5, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1};
    float* steelArray = new float[18]{ 0.5, 2, 0.5, 0, 2, 0.5, 0.5, 1, 0.5, 2, 1, 0.5, 1, 0.5, 0.5, 0.5, 1, 0.5};
    float* fireArray =new float[18] { 1, 1, 1, 1, 2, 2, 0.5, 1, 0.5, 0.5, 2, 0.5, 1, 1, 0.5, 1, 1, 0.5};
    float* waterArray = new float[18]{ 1, 1, 1, 1, 1, 1, 1, 1, 0.5, 0.5, 0.5, 2, 2, 1, 0.5, 1, 1, 1};
    float* grassArray=new float[18] { 1, 1, 2, 2, 0.5, 1, 2, 1, 1, 2, 0.5, 0.5, 0.5, 1, 2, 1, 1, 1};
    float* electricArray =new float[18] { 1, 1, 0.5, 1, 2, 1, 1, 1, 0.5, 1, 1, 1, 0.5, 1, 1, 1, 1, 1};
    float* psychicArray = new float[18]{ 1, 0.5, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 0.5, 1, 1, 2, 1};
    float* iceArray = new float[18]{ 1, 2, 1, 1, 1, 2, 1, 1, 2, 2, 1, 1, 1, 1, 0.5, 1, 1, 1};
    float* dragonArray = new float[18]{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 0.5, 0.5, 0.5, 0.5, 1, 2, 2, 1, 2};
    float* darkArray= new float[18]{ 1, 2, 1, 1, 1, 1, 2, 0.5, 1, 1, 1, 1, 1, 0, 1, 1, 0.5, 2};
    float* fairyArray = new float[18]{ 1, 0.5, 1, 2, 1, 1, 0.5, 1, 2, 1, 1, 1, 1, 1, 1, 0, 0.5, 1};
    float* arrays[19] = {nullArray, normalArray, fightingArray, flyingArray, poisonArray, groundArray, rockArray, bugArray, ghostArray, steelArray,
                         fireArray, waterArray, grassArray, electricArray, psychicArray, iceArray, dragonArray, darkArray, fairyArray};
    if(type> 18 || type < 0){
        for(int x = 1; x < 19; x++){
            delete[] arrays[x];
        }
        return arrays[0];
    }

    for(int x = 0; x < 19; x++){
        if(x != type){
            delete[] arrays[x];
        }
    }
    return arrays[type];
}