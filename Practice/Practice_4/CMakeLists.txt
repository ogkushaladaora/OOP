cmake_minimum_required(VERSION 3.5)
project(P1_War)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        main.cpp deck.h game_of_war.h)

add_executable(P1_War ${SOURCE_FILES})
