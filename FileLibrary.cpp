//
// Created by elimr on 12/3/2019.
//
#include <iostream>
#include <fstream>
#include "Pokemon.h"
#include"Team.h"
#include "ArrayList.h"


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