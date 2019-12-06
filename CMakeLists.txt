cmake_minimum_required(VERSION 3.14)
project(PokemonCompBuilder)

set(CMAKE_CXX_STANDARD 14)

add_executable(PokemonCompBuilder Team.cpp main.cpp Pokemon.cpp SmartBuilder.h ArrayList.h TestLib.cpp PokemonList.h FileLibrary.cpp)