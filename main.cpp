#include <iostream>
#include <fstream>
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


int main() {
    std::cout << "Hello, World!" << std::endl;
    printToFile("testFile.txt");
    printFromFile("testFile.txt");



    return 0;
}