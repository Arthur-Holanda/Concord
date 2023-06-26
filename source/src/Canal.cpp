/**
 * @file Canal.cpp
 * @brief Implementação da classe Canal.
 */
#include "../include/Canal.h"

Canal::Canal(const std::string& nome) : nome(nome) {}

Canal::~Canal() {}

std::string Canal::getNome() const {
    return nome;
}