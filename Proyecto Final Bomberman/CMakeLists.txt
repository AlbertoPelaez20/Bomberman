cmake_minimum_required(VERSION 3.13)
project(Proyecto_Final_Bomberman)

set(CMAKE_CXX_STANDARD 14)
find_package(SFML 2.5.1 COMPONENTS system window graphics network audio  )
add_executable(Proyecto_Final_Bomberman main.cpp CEscenario.cpp CEscenario.h funciones.h CControlmapa.cpp CControlmapa.h CBomberman.cpp CBomberman.h CBomba.cpp CBomba.h)
target_link_libraries ( Proyecto_Final_Bomberman sfml-system sfml-window sfml-graphics sfml-network sfml-audio  )