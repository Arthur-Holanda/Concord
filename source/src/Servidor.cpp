#include "../include/Servidor.h"

// Construtor com parâmetros
Servidor::Servidor(int usuarioDonoId, const std::string& nome, const std::string& descricao, const std::string& codigoConvite)
    : usuarioDonoId(usuarioDonoId), nome(nome), descricao(descricao), codigoConvite(codigoConvite) {}

// Destrutor
Servidor::~Servidor() {
    for (auto canal : canais) {
        delete canal;
    }
}

void Servidor::adicionarParticipante(int id) {
    participantesIDs.push_back(id);
}

void Servidor::adicionarCanal(Canal* canal) {
    canais.push_back(canal);
}

// Getters
int Servidor::getUsuarioDonoId() const {
    return usuarioDonoId;
}

std::string Servidor::getNome() const {
    return nome;
}

std::string Servidor::getDescricao() const {
    return descricao;
}

std::string Servidor::getCodigoConvite() const {
    return codigoConvite;
}

std::vector<Canal*> Servidor::getCanais() const {
    return canais;
}

std::vector<int> Servidor::getParticipantesIDs() const {
    return participantesIDs;
}

// Setters
void Servidor::setUsuarioDonoId(int id) {
    usuarioDonoId = id;
}

void Servidor::setNome(const std::string& novoNome) {
    nome = novoNome;
}

void Servidor::setDescricao(const std::string& novaDescricao) {
    descricao = novaDescricao;
}

void Servidor::setCodigoConvite(const std::string& novoCodigoConvite) {
    codigoConvite = novoCodigoConvite;
}

void Servidor::setCanais(const std::vector<Canal*>& novosCanais) {
    canais = novosCanais;
}

void Servidor::setParticipantesIDs(const std::vector<int>& novosParticipantesIDs) {
    participantesIDs = novosParticipantesIDs;
}