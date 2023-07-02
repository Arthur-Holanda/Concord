/**
 * @file CanalTexto.h
 * @brief Definição da classe CanalTexto.
 */

#ifndef CANALTEXTO_H
#define CANALTEXTO_H

#include "Canal.h"
#include <vector>
#include "Mensagem.h"

/**
 * @class CanalTexto
 * @brief Classe que representa um canal de texto.
 * @details CanalTexto herda da classe Canal.
 */
class CanalTexto : public Canal {
private:
    std::vector<Mensagem> mensagens; /**< Vetor de mensagens no canal de texto. */

public:
    /**
     * @brief Construtor da classe CanalTexto.
     * @param nome O nome do canal de texto.
     */
    CanalTexto(const std::string& nome);

    /**
     * @brief Adiciona uma mensagem ao canal de texto.
     * 
     * Esta função adiciona uma nova mensagem ao canal de texto.
     * 
     * @param mensagem A mensagem a ser adicionada.
     */
    void adicionarMensagem(const Mensagem& mensagem);
    
    /**
     * @brief Obtém todas as mensagens do canal de texto.
     * 
     * Esta função retorna um vetor contendo todas as mensagens presentes no canal de texto.
     * 
     * @return Um vetor com as mensagens do canal de texto.
     */
    const std::vector<Mensagem>& getMensagens() const;
};

#endif // CANALTEXTO_H
