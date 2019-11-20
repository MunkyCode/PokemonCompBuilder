cmake_minimum_required(VERSION 3.14)
project(PokemonCompBuilder)

set(CMAKE_CXX_STANDARD 14)

add_executable(PokemonCompBuilder main.cpp PokemonData.csv Pokemon.cpp FileLibrary.h)