/**
 * @file Servidor.h
 * @brief Definição da classe Servidor.
 */

#ifndef SERVIDOR_H
#define SERVIDOR_H

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "Canal.h"
#include "CanalTexto.h"
#include "CanalVoz.h"

/**
 * @class Servidor
 * @brief Classe que representa um servidor.
 */
class Servidor {
private:
    int usuarioDonoId; /**< Identificador do usuário dono do servidor. */
    std::string nome; /**< Nome do servidor. */
    std::string descricao; /**< Descrição do servidor. */
    std::string codigoConvite; /**< Código de convite do servidor. */
    std::vector<Canal*> canais; /**< Vetor de canais do servidor. */
    std::vector<int> participantesIDs; /**< Vetor de identificadores dos participantes do servidor. */

public:
    /**
     * @brief Construtor da classe Servidor.
     * @param usuarioDonoId O identificador do usuário dono do servidor.
     * @param nome O nome do servidor.
     * @param descricao A descrição do servidor.
     * @param codigoConvite O código de convite do servidor.
     */
    Servidor(int usuarioDonoId, const std::string& nome, const std::string& descricao, const std::string& codigoConvite);

    /**
     * @brief Destrutor da classe Servidor.
     */
    ~Servidor();

    /**
     * @brief Adiciona um participante ao servidor.
     * @param id O identificador do participante a ser adicionado.
     */
    void adicionarParticipante(int id);

    /**
     * @brief Adiciona um canal ao servidor.
     * @param canal O canal a ser adicionado.
     */
    void adicionarCanal(Canal* canal);

    /**
     * @brief Obtém o identificador do usuário dono do servidor.
     * @return O identificador do usuário dono do servidor.
     */
    int getUsuarioDonoId() const;

    /**
     * @brief Obtém o nome do servidor.
     * @return O nome do servidor.
     */
    std::string getNome() const;

    /**
     * @brief Obtém a descrição do servidor.
     * @return A descrição do servidor.
     */
    std::string getDescricao() const;

    /**
     * @brief Obtém o código de convite do servidor.
     * @return O código de convite do servidor.
     */
    std::string getCodigoConvite() const;

    /**
     * @brief Obtém os canais do servidor.
     * @return Vetor de ponteiros para os canais do servidor.
     */
    std::vector<Canal*> getCanais() const;

    /**
     * @brief Obtém os identificadores dos participantes do servidor.
     * @return Vetor de identificadores dos participantes do servidor.
     */
    std::vector<int> getParticipantesIDs() const;

    /**
     * @brief Define o identificador do usuário dono do servidor.
     * @param id O identificador do usuário dono do servidor.
     */
    void setUsuarioDonoId(int id);

    /**
     * @brief Define o nome do servidor.
     * @param novoNome O novo nome do servidor.
     */
    void setNome(const std::string& novoNome);

    /**
     * @brief Define a descrição do servidor.
     * @param novaDescricao A nova descrição do servidor.
     */
    void setDescricao(const std::string& novaDescricao);

    /**
     * @brief Define o código de convite do servidor.
     * @param novoCodigoConvite O novo código de convite do servidor.
     */
    void setCodigoConvite(const std::string& novoCodigoConvite);

    /**
     * @brief Define os canais do servidor.
     * @param novosCanais Vetor de ponteiros para os novos canais do servidor.
     */
    void setCanais(const std::vector<Canal*>& novosCanais);

    /**
     * @brief Define os identificadores dos participantes do servidor.
     * @param novosParticipantesIDs Vetor de identificadores dos novos participantes do servidor.
     */
    void setParticipantesIDs(const std::vector<int>& novosParticipantesIDs);
};

#endif // SERVIDOR_H
