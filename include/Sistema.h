#ifndef SISTEMA_H
#define SISTEMA_H

#include <vector>
#include <string>
#include <iostream>

class Usuario {
    // defina a classe Usuario aqui
};

class Servidor {
    // defina a classe Servidor aqui
};

class Canal {
    // defina a classe Canal aqui
};

class Sistema {
private:
    std::vector<Usuario> usuarios;
    std::vector<Servidor> servidores;
    Usuario* usuarioLogado;
    Servidor* servidorAtual;
    Canal* canalAtual;

public:
    Sistema();

    void iniciar();
    bool lerComando();
    void quit();
    void criarUsuario(const std::string& email, const std::string& senha, const std::string& nome);
    void login(const std::string& email, const std::string& senha);
    void desconectar();
    void criarServidor(const std::string& nome);
    void mudarDescricaoServidor(const std::string& nome, const std::string& descricao);
    void mudarCodigoConviteServidor(const std::string& nome, const std::string& codigoConvite = "");
    void listarServidores();
    void removerServidor(const std::string& nome);
    void entrarServidor(const std::string& nome, const std::string& codigoConvite = "");
    void sairServidor();
    void listarParticipantes();
    void listarCanais();
    void criarCanal(const std::string& nome, const std::string& tipo);
    void entrarCanal(const std::string& nome);
    void sairCanal();
};

#endif  // SISTEMA_H