cmake_minimum_required(VERSION 3.23)
project(test)

set(CMAKE_CXX_STANDARD 14)

add_executable(test finals/LinkedList.cpp finals/StackLinkedList.cpp finals/StackArray.cpp finals/Queue.cpp finals/Sorting.cpp finals/Tree.cpp)
