/**
 * @file CanalVoz.h
 * @brief Definição da classe CanalVoz.
 */

#ifndef CANALVOZ_H
#define CANALVOZ_H

#include "Canal.h"
#include "Mensagem.h"

/**
 * @class CanalVoz
 * @brief Classe que representa um canal de voz.
 * @details CanalVoz herda da classe Canal.
 */
class CanalVoz : public Canal {
private:
    Mensagem ultimaMensagem; /**< Última mensagem enviada no canal de voz. */

public:
    /**
     * @brief Construtor da classe CanalVoz.
     * @param nome O nome do canal de voz.
     */
    CanalVoz(const std::string& nome);

    /**
     * @brief Define a última mensagem enviada no canal de voz.
     * @param mensagem A mensagem a ser definida como a última.
     */
    void setUltimaMensagem(const Mensagem& mensagem);

    /**
     * @brief Obtém a última mensagem enviada no canal de voz.
     * @return A última mensagem enviada.
     */
    Mensagem getUltimaMensagem() const;
};

#endif // CANALVOZ_H
