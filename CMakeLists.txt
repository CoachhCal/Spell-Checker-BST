cmake_minimum_required(VERSION 3.30)
project(Spell_Checker)

set(CMAKE_CXX_STANDARD 23)

add_executable(Spell_Checker
                src/main.cpp
                src/spell_checker.cpp
                src/binary_search_tree.cpp)
