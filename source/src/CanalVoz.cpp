/**
 * @file CanalVoz.cpp
 * @brief Implementação da classe CanalVoz.
 */
#include "../include/CanalVoz.h"

CanalVoz::CanalVoz(const std::string& nome) : Canal(nome) {}

void CanalVoz::setUltimaMensagem(const Mensagem& mensagem) {
    ultimaMensagem = mensagem;
}

Mensagem CanalVoz::getUltimaMensagem() const {
    return ultimaMensagem;
}

Canal::Tipo CanalVoz::getTipo() const {
    return Tipo::VOZ;
}