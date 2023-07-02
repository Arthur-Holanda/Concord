/**
 * @file Mensagem.h
 * @brief Definição da classe Mensagem.
 */
#ifndef MENSAGEM_H
#define MENSAGEM_H

#include <string>
#include <ctime>
/**
 * @class Mensagem
 * @brief Classe que representa uma mensagem.
 */
class Mensagem {
private:
    time_t dataHora; /**< Data e hora da mensagem. */
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
    Mensagem(const time_t& dataHora, int enviadaPor, const std::string& conteudo);

    /**
     * @brief Obtém a data e hora da mensagem.
     * @return A data e hora da mensagem.
     */
    time_t getDataHora() const;

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

    /**
     * @brief Define a data e hora da mensagem.
     * 
     * Esta função define a data e hora da mensagem para o valor fornecido.
     * 
     * @param novaDataHora A nova data e hora da mensagem.
     */
    void setDataHora(time_t novaDataHora);

    /**
     * @brief Define o identificador de quem enviou a mensagem.
     * 
     * Esta função define o identificador de quem enviou a mensagem para o valor fornecido.
     * 
     * @param novoEnviadaPor O novo identificador de quem enviou a mensagem.
     */
    void setEnviadaPor(int novoEnviadaPor);

    /**
     * @brief Define o conteúdo da mensagem.
     * 
     * Esta função define o conteúdo da mensagem para o valor fornecido.
     * 
     * @param novoConteudo O novo conteúdo da mensagem.
     */
    void setConteudo(const std::string& novoConteudo);

};

#endif //MENSAGEM_H