/**
 * @file main.cpp
 * @brief Arquivo de ponto de entrada para o sistema de mensagens.
 */
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "../include/Sistema.h"

/**
 * @brief Função principal que inicia o sistema de mensagens.
 * @return 0 em caso de execução bem-sucedida.
 */
int main()
{
    Sistema sistema;
    sistema.iniciar();
    return 0;
}