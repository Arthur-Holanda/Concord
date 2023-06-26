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

    // Outros métodos e funcionalidades podem ser adicionados aqui
};

#endif // CANALTEXTO_H
