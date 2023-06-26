cmake_minimum_required(VERSION 3.20.0)
project(Concordo)

set(CMAKE_CXX_FLAGS "-g")

include_directories(include)

add_executable(Concordo
               src/main.cpp
               src/Usuario.cpp
               src/Mensagem.cpp
               src/Canal.cpp
               src/CanalTexto.cpp
               src/CanalVoz.cpp
               src/Servidor.cpp
               src/Sistema.cpp)