#ifndef USUARIO_H
#define USUARIO_H

#include <string>

class Usuario {
private:
    int id;
    std::string nome;
    std::string email;
    std::string senha;

public:
    // Construtor padrão
    Usuario();

    // Construtor com parâmetros
    Usuario(int id, const std::string& nome, const std::string& email, const std::string& senha);

    // Getters
    int getId() const;
    std::string getNome() const;
    std::string getEmail() const;
    std::string getSenha() const;
};

#endif