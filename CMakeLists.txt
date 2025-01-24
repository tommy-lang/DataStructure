cmake_minimum_required(VERSION 3.27)
project(DataStructure)

set(CMAKE_CXX_STANDARD 17)

add_executable(DataStructure
        LinearList/SqList.c
        LinearList/SingleLinkedList.c
        LinearList/SqList.cpp
        LinearList/SingleLinkedList.cpp
        LinearList/HeadInsertion.cpp
        LinearList/HeadInsertion.c
        LinearList/RearInsertion.cpp
        LinearList/RearInsertion.c)
