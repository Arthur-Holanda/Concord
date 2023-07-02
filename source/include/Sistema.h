/**
 * @file Sistema.h
 * @brief Definição da classe Sistema.
 */

#ifndef SISTEMA_H
#define SISTEMA_H

#include <vector>
#include <string>
#include "Servidor.h"
#include "Usuario.h"
#include "Mensagem.h"

/**
 * @class Sistema
 * @brief Classe que representa o sistema de mensagens.
 */
class Sistema {
private:
    std::vector<Usuario> usuarios; /**< Vetor de usuários cadastrados no sistema. */
    std::vector<Servidor> servidores; /**< Vetor de servidores disponíveis no sistema. */
    Usuario* usuarioLogado; /**< Usuário logado no sistema. */
    Servidor* servidorAtual; /**< Servidor atualmente selecionado pelo usuário. */
    Canal* canalAtual; /**< Canal atualmente selecionado pelo usuário. */

public:
    /**
     * @brief Construtor da classe Sistema.
     */
    Sistema();

    /**
     * @brief Inicia o sistema.
     */
    void iniciar();

    /**
     * @brief Lê um comando do usuário.
     * @return True se o comando foi lido com sucesso, False caso contrário.
     */
    bool lerComando();


    /**
     * @brief Cria um novo usuário.
     * @param email O email do usuário.
     * @param senha A senha do usuário.
     * @param nome O nome do usuário.
     */
    void criarUsuario(const std::string& email, const std::string& senha, const std::string& nome);

    /**
     * @brief Realiza o login do usuário.
     * @param email O email do usuário.
     * @param senha A senha do usuário.
     */
    void login(const std::string& email, const std::string& senha);

    /**
     * @brief Desconecta o usuário logado.
     */
    void desconectar();

    /**
     * @brief Cria um novo servidor.
     * @param nome O nome do servidor.
     */
    void criarServidor(const std::string& nome);

    /**
     * @brief Altera a descrição de um servidor.
     * @param nome O nome do servidor.
     * @param descricao A nova descrição do servidor.
     */
    void mudarDescricaoServidor(const std::string& nome, const std::string& descricao);

    /**
     * @brief Altera o código de convite de um servidor.
     * @param nome O nome do servidor.
     * @param codigoConvite O novo código de convite do servidor.
     */
    void mudarCodigoConviteServidor(const std::string& nome, const std::string& codigoConvite = "");

    /**
     * @brief Lista todos os servidores disponíveis.
     */
    void listarServidores();

    /**
     * @brief Remove um servidor.
     * @param nome O nome do servidor a ser removido.
     */
    void removerServidor(const std::string& nome);

    /**
     * @brief Entra em um servidor.
     * @param nome O nome do servidor a ser entrado.
     * @param codigoConvite O código de convite do servidor (opcional).
     */
    void entrarServidor(const std::string& nome, const std::string& codigoConvite = "");

    /**
     * @brief Sai do servidor atual.
     */
    void sairServidor();

    /**
     * @brief Lista os participantes do servidor atual.
     */
    void listarParticipantes();

    /**
     * @brief Lista os canais do servidor atual.
     */
    void listarCanais();

    /**
     * @brief Cria um novo canal.
     * @param nome O nome do canal.
     * @param tipo O tipo do canal.
     */
    void criarCanal(const std::string& nome, const std::string& tipo);

    /**
     * @brief Entra em um canal.
     * @param nome O nome do canal a ser entrado.
     */
    void entrarCanal(const std::string& nome);

    /**
     * @brief Sai do canal atual.
     */
    void sairCanal();

    /**
     * @brief Envia uma mensagem no canal atual.
     * @param mensagem O conteúdo da mensagem a ser enviada.
     */
    void enviarMensagem(const std::string& mensagem);

    /**
     * @brief Obtém o nome de um usuário pelo ID.
     * @param idUsuario O ID do usuário.
     * @return O nome do usuário correspondente ao ID.
     */
    std::string getNomeUsuario(int idUsuario) const;

    /**
     * @brief Visualiza as mensagens do canal atual.
     */
    void visualizarMensagens();
    
};

#endif // SISTEMA_H
