/**
 * @file Mensagem.cpp
 * @brief Implementação da classe Mensagem.
 */
#include "../include/Mensagem.h"

// Construtor padrão
Mensagem::Mensagem() {}

// Construtor com parâmetros
Mensagem::Mensagem(const std::string& dataHora, int enviadaPor, const std::string& conteudo)
    : dataHora(dataHora), enviadaPor(enviadaPor), conteudo(conteudo) {}

// Getters
std::string Mensagem::getDataHora() const {
    return dataHora;
}

int Mensagem::getEnviadaPor() const {
    return enviadaPor;
}

std::string Mensagem::getConteudo() const {
    return conteudo;
}