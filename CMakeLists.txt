cmake_minimum_required(VERSION 3.14)
project(Head_First_C C)

set(CMAKE_C_STANDARD 99)

add_executable(Head_First_C main.c)
include_directories(Chapter2_Memory_Pointers)
include_directories(Chapter2.5_String_Theory)