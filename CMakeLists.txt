cmake_minimum_required(VERSION 3.16)
project(LuaToLLVM)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES
    src/Main.cpp 
    src/Tokenizer.cpp
    src/Parser.cpp
)

set(HEADERS
    src/Tokenizer.hpp
    src/Parser.hpp
)

add_executable(LuaToLLVM ${SOURCES} ${HEADERS})

target_include_directories(LuaToLLVM PRIVATE src)
