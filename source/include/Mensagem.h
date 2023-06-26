/**
 * @file Mensagem.h
 * @brief Definição da classe Mensagem.
 */
#ifndef MENSAGEM_H
#define MENSAGEM_H

#include <string>
/**
 * @class Mensagem
 * @brief Classe que representa uma mensagem.
 */
class Mensagem {
private:
    std::string dataHora; /**< Data e hora da mensagem. */
    int enviadaPor; /**< Identificador de quem enviou a mensagem. */
    std::string conteudo; /**< Conteúdo da mensagem. */

public:
    /**
     * @brief Construtor padrão da classe Mensagem.
     */
    Mensagem();

    /**
     * @brief Construtor da classe Mensagem.
     * @param dataHora A data e hora da mensagem.
     * @param enviadaPor O identificador de quem enviou a mensagem.
     * @param conteudo O conteúdo da mensagem.
     */
    Mensagem(const std::string& dataHora, int enviadaPor, const std::string& conteudo);

    /**
     * @brief Obtém a data e hora da mensagem.
     * @return A data e hora da mensagem.
     */
    std::string getDataHora() const;

    /**
     * @brief Obtém o identificador de quem enviou a mensagem.
     * @return O identificador de quem enviou a mensagem.
     */
    int getEnviadaPor() const;

    /**
     * @brief Obtém o conteúdo da mensagem.
     * @return O conteúdo da mensagem.
     */
    std::string getConteudo() const;
};

#endif //MENSAGEM_H