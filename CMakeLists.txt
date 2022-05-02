cmake_minimum_required(VERSION 3.16)
set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED True)

project(LuaToLLVM)

set(SOURCE)

add_executable(LuaToLLVM src/Main.cpp ${SOURCE})
