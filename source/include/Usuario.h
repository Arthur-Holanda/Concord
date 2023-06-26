/**
 * @file Usuario.h
 * @brief Definição da classe Usuario.
 */
#ifndef USUARIO_H
#define USUARIO_H

#include <string>
/**
 * @class Usuario
 * @brief Classe que representa um usuário.
 */
class Usuario {
private:
    int id; /**< Identificador do usuário. */
    std::string nome; /**< Nome do usuário. */
    std::string email; /**< E-mail do usuário. */
    std::string senha; /**< Senha do usuário. */

public:
    /**
     * @brief Construtor padrão da classe Usuario.
     */
    Usuario();

    /**
     * @brief Construtor da classe Usuario.
     * @param id O identificador do usuário.
     * @param nome O nome do usuário.
     * @param email O e-mail do usuário.
     * @param senha A senha do usuário.
     */
    Usuario(int id, const std::string& nome, const std::string& email, const std::string& senha);

    /**
     * @brief Obtém o identificador do usuário.
     * @return O identificador do usuário.
     */
    int getId() const;

    /**
     * @brief Obtém o nome do usuário.
     * @return O nome do usuário.
     */
    std::string getNome() const;

    /**
     * @brief Obtém o e-mail do usuário.
     * @return O e-mail do usuário.
     */
    std::string getEmail() const;

    /**
     * @brief Obtém a senha do usuário.
     * @return A senha do usuário.
     */
    std::string getSenha() const;
};

#endif //USUARIO_H