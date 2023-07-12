/**
 * @file Canal.h
 * @brief Definição da classe Canal.
 */

#ifndef CANAL_H
#define CANAL_H

#include <string>

/**
 * @class Canal
 * @brief Classe abstrata que representa um canal.
 */
class Canal {
public:
    /**
     * @enum Tipo
     * @brief Enumeração dos tipos de canais.
     */
    enum class Tipo { TEXTO, VOZ };

    /**
     * @brief Construtor da classe Canal.
     * @param nome O nome do canal.
     */
    Canal(const std::string& nome);

    /**
     * @brief Destrutor virtual da classe Canal.
     */
    virtual ~Canal();

    /**
     * @brief Obtém o nome do canal.
     * @return O nome do canal.
     */
    std::string getNome() const;

    /**
     * @brief Obtém o tipo do canal.
     * 
     * Este método é puramente virtual e deve ser implementado pelas classes derivadas.
     * 
     * @return O tipo do canal (TEXTO ou VOZ).
     */
    virtual Tipo getTipo() const = 0;

protected:
    std::string nome; /**< Nome do canal. */
};

#endif // CANAL_H