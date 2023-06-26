#include "../include/Usuario.h"

// Construtor padrão
Usuario::Usuario() {}

// Construtor com parâmetros
Usuario::Usuario(int id, const std::string& nome, const std::string& email, const std::string& senha)
    : id(id), nome(nome), email(email), senha(senha) {}

// Getters
int Usuario::getId() const {
    return id;
}

std::string Usuario::getNome() const {
    return nome;
}

std::string Usuario::getEmail() const {
    return email;
}

std::string Usuario::getSenha() const {
    return senha;
}
