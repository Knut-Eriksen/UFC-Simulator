cmake_minimum_required(VERSION 3.27)
project(UFC_Simulator)

set(CMAKE_CXX_STANDARD 17)

add_executable(UFC_Simulator main.cpp
        fighters.cpp
        fighters.h
        Match.cpp
        Match.h
        FightCommentary.cpp
        FightCommentary.h
        Tournament.cpp
        Tournament.h
        UserInterface.cpp
        UserInterface.h)
