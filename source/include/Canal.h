/**
 * @file Canal.h
 * @brief Definição da classe Canal.
 */

#ifndef CANAL_H
#define CANAL_H

#include <string>

/**
 * @class Canal
 * @brief Classe que representa um canal.
 */
class Canal {
private:
    std::string nome; /**< Nome do canal. */

public:
    /**
     * @brief Construtor da classe Canal.
     * @param nome O nome do canal.
     */
    Canal(const std::string& nome);

    /**
     * @brief Destrutor da classe Canal.
     */
    virtual ~Canal();

    /**
     * @brief Obtém o nome do canal.
     * @return O nome do canal.
     */
    std::string getNome() const;
};

#endif // CANAL_H