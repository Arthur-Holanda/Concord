/**
 * @file CanalTexto.cpp
 * @brief Implementação da classe CanalTexto.
 */
#include "../include/CanalTexto.h"

CanalTexto::CanalTexto(const std::string& nome) : Canal(nome) {}

void CanalTexto::adicionarMensagem(const Mensagem& mensagem) {
    mensagens.push_back(mensagem);
}

const std::vector<Mensagem>& CanalTexto::getMensagens() const {
    return mensagens;
}

Canal::Tipo CanalTexto::getTipo() const {
    return Tipo::TEXTO;
}