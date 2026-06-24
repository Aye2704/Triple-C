cmake_minimum_required(VERSION 3.16)
project(TripleC_QT LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#encontrar dependencias de QT6
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

# Habilitar MOC (Meta-Object Compiler) para signals y slots
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

#Cabeceras
include_directories(src_cpp/headerscpp)


set(SOURCES
    src_cpp/maincpp/main.cpp
    src_cpp/movecpp/entidades.cpp
    src_cpp/movecpp/juego.cpp
    src_cpp/movecpp/mapa.cpp
    src_cpp/preguntascpp/pregBack.cpp
    src_cpp/userinterface/mainwindow.cpp
)

add_executable(TripleC_QT ${SOURCES})
target_link_libraries(TripleC_QT PRIVATE Qt6::Widgets)