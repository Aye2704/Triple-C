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
    src_cpp/movcpp/mapitawidget.cpp
    src_cpp/preguntascpp/pregBack.cpp
    src_cpp/userinterface/mainwindow.cpp

    src_cpp/headerscpp/entidades.hpp
    src_cpp/headerscpp/juego.hpp
    src_cpp/headerscpp/mapa.hpp
    src_cpp/headerscpp/preg.hpp
    src_cpp/headerscpp/mainwindow.h
    src_cpp/headerscpp/mapitawidget.h

    src_cpp/userinterface/mainwindow.ui
)

add_executable(TripleC_QT ${SOURCES})

target_include_directories(TripleC_QT PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src_cpp/headerscpp
)

target_link_libraries(TripleC_QT PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)

#Copiar automaticamente la base de datos de preguntas al directorio build
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/build/archivopregs.txt
    ${CMAKE_CURRENT_BINARY_DIR}/archivopregs.txt
    COPYONLY
)