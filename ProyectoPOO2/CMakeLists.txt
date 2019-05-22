cmake_minimum_required(VERSION 3.14)
project(ProyectoPOO2)

set(CMAKE_CXX_STANDARD 14)

set(SFML_INCLUDE_DIR "C:/SFML-2.5.1/include")
set(SFML_LIBRARY_DIR "C:/SFML-2.5.1/lib")
set(SFML_DIR "C:/SFML-2.5.1/lib/cmake/SFML")

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

if(SFML_FOUND)
    message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
    message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
    message(STATUS "SFML_VERSION: ${SFML_VERSION}")
endif()

add_executable(SFMLApp main.cpp Inicio.cpp Juego.cpp Salida.cpp Arena.cpp Bala.cpp Jugador.cpp Enemigo.cpp)
target_link_libraries (SFMLApp sfml-graphics sfml-window sfml-system)

