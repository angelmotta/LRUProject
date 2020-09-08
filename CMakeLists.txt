cmake_minimum_required(VERSION 3.17)
project(LRUProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(LRUProject main.cpp LRUCache.cpp LRUCache.h DoublyLinkedList.cpp DoublyLinkedList.h)