/**
 * @file Mensagem.cpp
 * @brief Implementação da classe Mensagem.
 */
#include "../include/Mensagem.h"

// Construtor padrão
Mensagem::Mensagem() {}

// Construtor com parâmetros
Mensagem::Mensagem(const time_t& dataHora, int enviadaPor, const std::string& conteudo)
    : dataHora(dataHora), enviadaPor(enviadaPor), conteudo(conteudo) {}

// Getters
time_t Mensagem::getDataHora() const {
    return dataHora;
}

int Mensagem::getEnviadaPor() const {
    return enviadaPor;
}

std::string Mensagem::getConteudo() const {
    return conteudo;
}


// Setters

void Mensagem::setDataHora(time_t novaDataHora) {
    dataHora = novaDataHora;
}
void Mensagem::setEnviadaPor(int novoEnviadaPor) {
    enviadaPor = novoEnviadaPor;
}
void Mensagem::setConteudo(const std::string& novoConteudo) {
    conteudo = novoConteudo;
}