/**
 * @file CanalVoz.cpp
 * @brief Implementação da classe CanalVoz.
 */
#include "../include/CanalVoz.h"

// Construtor com parâmetros
CanalVoz::CanalVoz(const std::string& nome) : Canal(nome) {}


void CanalVoz::setUltimaMensagem(const Mensagem& mensagem) {
    ultimaMensagem = mensagem;
}

Mensagem CanalVoz::getUltimaMensagem() const {
    return ultimaMensagem;
}