cmake_minimum_required(VERSION 3.14)
project(PokemonCompBuilder)

set(CMAKE_CXX_STANDARD 14)

add_executable( PokemonCompBuilder Team.cpp main.cpp Pokemon.cpp FileLibrary.h SmartBuilder.h ArrayList.h Team.h ArrayListFunctions.cpp ArrayListFunctions.h)