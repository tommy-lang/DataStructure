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
        LinearList/RearInsertion.c
        LinearList/DoublyLinkedList.cpp
        LinearList/CircularStructureSingleLinkedList.cpp
        LinearList/CircularStructureSingleLinkedList.c
        LinearList/DoublyLinkedList.c
        LinearList/CircularStructureDoublyLinkedList.cpp
        LinearList/CircularStructureDoublyLinkedList.c
        LinearList/课后算法设计题/AlgorithmDesign1.cpp
        LinearList/课后算法设计题/AlgorithmDesign1.c
        StackQueueArray/SqStack.cpp
        StackQueueArray/SqStack.c
        StackQueueArray/LinkedStack.cpp
        StackQueueArray/LinkedStack.c
        StackQueueArray/CircularSqQueue.cpp
        StackQueueArray/CircularSqQueue.c
        StackQueueArray/CircularSqQueue.c
        StackQueueArray/LinkedQueue.cpp
        StackQueueArray/LinkedQueue.c
        StackQueueArray/课后算法设计题/AlgorithmDesign1.cpp)
