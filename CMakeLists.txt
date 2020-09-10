cmake_minimum_required(VERSION 3.17)
project(LRUProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(LRUProject main.cpp LRUCache.h DoublyLinkedList.h Node.h ICache.h)