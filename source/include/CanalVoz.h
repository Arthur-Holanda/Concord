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
 *
 * A classe CanalVoz herda da classe Canal e representa um canal de voz em um servidor. Um canal de voz armazena apenas a última mensagem enviada no canal.
 */
class CanalVoz : public Canal {
public:
    /**
     * @brief Construtor da classe CanalVoz.
     *
     * Este construtor cria um novo objeto da classe CanalVoz com o nome especificado.
     *
     * @param nome O nome do canal de voz.
     */
    CanalVoz(const std::string& nome);

    /**
     * @brief Define a última mensagem enviada no canal de voz.
     *
     * Este método define a última mensagem enviada no canal de voz. Como um canal de voz armazena apenas a última mensagem enviada, este método sobrescreve qualquer mensagem anteriormente armazenada no canal de voz.
     *
     * @param mensagem A última mensagem enviada no canal de voz.
     */
    void setUltimaMensagem(const Mensagem& mensagem);

    /**
     * @brief Obtém a última mensagem enviada no canal de voz.
     *
     * Este método retorna a última mensagem enviada no canal de voz.
     *
     * @return A última mensagem enviada no canal de voz.
     */
    Mensagem getUltimaMensagem() const;

    /**
     * @brief Obtém o tipo do canal de voz.
     *
     * Este método sobrescreve o método getTipo() da classe base Canal e retorna o tipo do canal de voz (VOZ).
     *
     * @return O tipo do canal de voz (VOZ).
     */
    Tipo getTipo() const override;

private:
    Mensagem ultimaMensagem; /**< Última mensagem enviada no canal de voz. */
};

#endif // CANALVOZ_H