#ifndef MENSAGEM_H
#define MENSAGEM_H

#include <string>

class Mensagem {
private:
    std::string dataHora;
    int enviadaPor;
    std::string conteudo;

public:
    // Construtor padrão
    Mensagem();

    // Construtor com parâmetros
    Mensagem(const std::string& dataHora, int enviadaPor, const std::string& conteudo);

    // Getters
    std::string getDataHora() const;
    int getEnviadaPor() const;
    std::string getConteudo() const;
};

#endif