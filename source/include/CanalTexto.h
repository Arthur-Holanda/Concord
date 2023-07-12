/**
 * @file CanalTexto.h
 * @brief Definição da classe CanalTexto.
 */

#ifndef CANALTEXTO_H
#define CANALTEXTO_H

#include "Canal.h"
#include "Mensagem.h"
#include <vector>

/**
 * @class CanalTexto
 * @brief Classe que representa um canal de texto.
 * 
 * A classe CanalTexto herda da classe Canal e representa um canal de texto em um servidor.
 */
class CanalTexto : public Canal {
public:
    /**
     * @brief Construtor da classe CanalTexto.
     * 
     * Este construtor cria um novo objeto da classe CanalTexto com o nome especificado.
     * 
     * @param nome O nome do canal de texto.
     */
    CanalTexto(const std::string& nome);

    /**
     * @brief Adiciona uma mensagem ao canal de texto.
     *
     * Este método adiciona uma nova mensagem ao vetor de mensagens do canal de texto.
     *
     * @param mensagem A mensagem a ser adicionada ao canal de texto.
     */
    void adicionarMensagem(const Mensagem& mensagem);

    /**
     * @brief Obtém as mensagens do canal de texto.
     *
     * Este método retorna um vetor contendo todas as mensagens presentes no canal de texto.
     *
     * @return Um vetor com as mensagens do canal de texto.
     */
    const std::vector<Mensagem>& getMensagens() const;

    /**
     * @brief Obtém o tipo do canal de texto.
     *
     * Este método sobrescreve o método getTipo() da classe base Canal e retorna o tipo do canal de texto (TEXTO).
     *
     * @return O tipo do canal de texto (TEXTO).
     */
    Tipo getTipo() const override;

private:
    std::vector<Mensagem> mensagens; /**< Vetor de mensagens no canal de texto. */
};

#endif // CANALTEXTO_H