cmake_minimum_required(VERSION 3.21)
project(videoLocadoraNova)

set(CMAKE_CXX_STANDARD 14)

add_executable(videoLocadoraNova main.cpp Cliente.cpp Filme.cpp Locado.cpp MenuOpcoes.cpp MenuPrincipal.cpp)
