cmake_minimum_required(VERSION 3.14)
project(PokemonCompBuilder)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(PokemonCompBuilder Team.cpp Main.cpp Pokemon.cpp SmartBuilder.cpp ArrayList.h TestLib.cpp PokemonList.h FileLibrary.cpp TypeEffectivness.cpp)
