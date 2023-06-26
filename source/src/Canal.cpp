#include "../include/Canal.h"

Canal::Canal(const std::string& nome) : nome(nome) {}

Canal::~Canal() {}

std::string Canal::getNome() const {
    return nome;
}