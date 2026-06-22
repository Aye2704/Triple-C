cmake_minimum_required(VERSION 3.16)
project(TripleC_QT LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Habilitar MOC (Meta-Object Compiler) para signals y slots
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

#encontrar dependencias de QT6
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

set(SOURCES
    src_cpp/maincpp/main.cpp
    src_cpp/movcpp/entidades.cpp
    src_cpp/movcpp/juego.cpp
    src_cpp/movcpp/mapa.cpp
    src_cpp/preguntascpp/pregBack.cpp
    src_cpp/userinterface/mainwindow.cpp
    src_cpp/userinterface/mainwindow.ui
    src_cpp/headerscpp/mainwindow.h
)

add_executable(TripleC_QT ${SOURCES})

target_include_directories(TripleC_QT PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/headers
)

target_link_libraries(TripleC_QT PRIVATE Qt6::Widgets)