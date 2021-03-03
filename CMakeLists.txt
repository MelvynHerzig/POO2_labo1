cmake_minimum_required(VERSION 3.17)
project(POO2_labo1)

set(CMAKE_CXX_STANDARD 11)

add_executable(POO2_labo1 main.cpp Matrix.cpp Matrix.h MatrixOperator.h MatrixAdd.cpp MatrixAdd.h MatrixSub.cpp MatrixSub.h MatrixMult.cpp MatrixMult.h Utils.cpp Utils.h)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wconversion -Wpedantic -Wsign-conversion")