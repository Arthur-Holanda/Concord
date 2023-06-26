/**
 * @file Sistema.cpp
 * @brief Implementação da classe Sistema.
 */
#include "../include/Sistema.h"
#include <sstream>

    Sistema::Sistema() : usuarioLogado(nullptr), servidorAtual(nullptr), canalAtual(nullptr) {}



    void Sistema::iniciar() {
        std::cout << "Concordo - Sistema de Mensagens" << std::endl;
        while (lerComando()) {}
    }

bool Sistema::lerComando() {
    std::cout << "\nDigite um comando (ou 'help' para ver a lista de comandos): ";

    std::string line;
    std::getline(std::cin, line);

    std::string command;
    std::string args;

    std::istringstream iss(line);
    std::getline(iss, command, ' ');
    std::getline(iss, args);

    if (command == "quit") {
        std::cout << "Saindo do Concordo. Até mais!" << std::endl;
        return false;
    }
    else if (command == "create-user") {
        std::string email;
        std::string senha;
        std::string nome;
        std::string lixo;
        std::istringstream iss(args);
        std::getline(iss, email, ' ');
        std::getline(iss, senha, ' ');
        std::getline(iss, nome, ' ');
        criarUsuario(email, senha, nome);
        std::getline(iss, lixo, ' ');
        if(!(lixo.empty())){
            std::cout << "Aviso: Caracteres extras desconsiderados" << std::endl;
        }
    }
    else if (command == "login") {
        std::string email;
        std::string senha;
        std::string lixo;
        std::istringstream iss(args);
        std::getline(iss, email, ' ');
        std::getline(iss, senha, ' ');
        login(email, senha);
        std::getline(iss, lixo, ' ');
        if(!(lixo.empty())){
            std::cout << "Aviso: Caracteres extras desconsiderados" << std::endl;
        }
    }                                                //não logado 
    else if (command == "disconnect") {
        desconectar();
    }
    else if (command == "create-server") {
        std::string serverName;
        std::string lixo;
        std::istringstream iss(args);
        std::getline(iss, serverName, ' ');
        criarServidor(serverName);
        std::getline(iss, lixo, ' ');
        if(!(lixo.empty())){
            std::cout << "Aviso: Caracteres extras desconsiderados" << std::endl;
        }
    }
    else if (command == "set-server-desc"){
        std::string serverName;
        std::string description;
        std::string lixo;
        std::istringstream iss(args);
        std::getline(iss, serverName, ' ');
        iss.ignore();
        std::getline(iss, description, '"');
        mudarDescricaoServidor(serverName, description);
        std::getline(iss, lixo, ' ');
        if(!(lixo.empty())){
            std::cout << "Aviso: Caracteres extras desconsiderados" << std::endl;
        }
    }
    else if (command == "set-server-invite-code") {
        std::string serverName;
        std::string inviteCode;
        std::string lixo;
        std::istringstream iss(args);
        std::getline(iss, serverName, ' ');
        std::getline(iss, inviteCode, ' ');
        mudarCodigoConviteServidor(serverName, inviteCode);
        std::getline(iss, lixo, ' ');
        if(!(lixo.empty())){
            std::cout << "Aviso: Caracteres extras desconsiderados" << std::endl;
        }
    }
    else if (command == "list-servers") {
        listarServidores();
    }
    else if (command == "remove-server") {
        std::string serverName;
        std::string lixo;
        std::istringstream iss(args);
        std::getline(iss, serverName, ' ');
        removerServidor(serverName);
        std::getline(iss, lixo, ' ');
        if(!(lixo.empty())){
            std::cout << "Aviso: Caracteres extras desconsiderados" << std::endl;
        }        
    }
    else if (command == "enter-server") {
        std::string serverName;
        std::string inviteCode;
        std::string lixo;
        std::istringstream iss(args);
        std::getline(iss, serverName, ' ');
        std::getline(iss, inviteCode, ' ');
        entrarServidor(serverName, inviteCode);
        std::getline(iss, lixo, ' ');
        if(!(lixo.empty())){
            std::cout << "Aviso: Caracteres extras desconsiderados" << std::endl;
        }
    }
    else if (command == "leave-server") {
        sairServidor();
    }
    else if (command == "list-participants") {
        listarParticipantes();
    }
    else if (command == "list-channels") {
        listarCanais();
    }
    else if (command == "create-channel") {
        std::string channelName;
        std::string channelType;

        std::istringstream iss(args);
        std::getline(iss, channelName, ' ');
        std::getline(iss, channelType, ' ');
        criarCanal(channelName, channelType);
    }
    else if (command == "enter-channel") {
        std::string ChanelName;

        std::istringstream iss(args);
        std::getline(iss, ChanelName, ' ');
        entrarCanal(ChanelName);
    }
    else if (command == "leave-channel") {
        sairCanal();
    }
    else if (command == "help") {
        std::cout << "Comandos disponíveis:" << std::endl;
        std::cout << "quit - Sair do programa" << std::endl;
        std::cout << "create-user [email] [senha] [nome] - Criar um novo usuário" << std::endl;
        std::cout << "login [email] [senha] - Fazer login com um usuário existente" << std::endl;
        std::cout << "disconnect - Desconectar do usuário atual" << std::endl;
        std::cout << "create-server [nome] - Criar um novo servidor" << std::endl;
        std::cout << "set-server-desc [nome] [descrição] - Definir a descrição de um servidor" << std::endl;
        std::cout << "set-server-invite-code [nome] [código] - Definir o código de convite de um servidor" << std::endl;
        std::cout << "list-servers - Listar todos os servidores" << std::endl;
        std::cout << "remove-server [nome] - Remover um servidor" << std::endl;
        std::cout << "enter-server [nome] [código] (Código só quando necessario) - Entrar em um servidor" << std::endl;
        std::cout << "leave-server - Sair do servidor atual" << std::endl;
        std::cout << "list-participants - Listar os participantes do servidor atual" << std::endl;
        std::cout << "list-channels - Listar os canais do servidor atual" << std::endl;
        std::cout << "create-channel [nome] [tipo] - Criar um canal no servidor atual" << std::endl;
        std::cout << "enter-channel [nome] - Entrar em um canal do servidor atual" << std::endl;
        std::cout << "leave-channel - Sair do canal atual" << std::endl;
    }
    else {
        std::cout << "Comando inválido. Digite 'help' para ver a lista de comandos disponíveis." << std::endl;
    }
    return true;
    }

    // Comando para criar um usuário
    void Sistema::criarUsuario(const std::string& email, const std::string& senha, const std::string& nome)
    {      
        if (email.empty() || senha.empty() || nome.empty()) {
            std::cout << "Erro: informação insuficiente." << std::endl;
            return;
        }
        // Verificar se o email já existe no cadastro geral
        for (const auto& usuario : usuarios) {
            if (usuario.getEmail() == email) {
                std::cout << "Erro: O email fornecido já está em uso." << std::endl;
                return;
            }
        }

        // Gerar ID para o novo usuário
        int novoId = usuarios.size() + 1;

        // Criar o novo usuário e adicioná-lo ao cadastro geral
        Usuario novoUsuario(novoId, nome, email, senha);
        usuarios.push_back(novoUsuario);

        std::cout << "Usuário criado com sucesso." << std::endl;
        //std::cout << novoUsuario.getId() << std::endl;
    }


    // Comando para efetuar login
    void Sistema::login(const std::string& email, const std::string& senha)
    {
        // Verificar se o usuário já está logado
        if (usuarioLogado != nullptr) {
            std::cout << "Erro: Já existe um usuário logado." << std::endl;
            return;
        }
        // Procurar o usuário no cadastro geral
        for (auto& usuario : usuarios) {
            if (usuario.getEmail() == email && usuario.getSenha() == senha) {
                usuarioLogado = &usuario;
                std::cout << "Login efetuado com sucesso." << std::endl;
                return;
            }
        }

        std::cout << "Erro: Email ou senha inválidos." << std::endl;
    }

    void Sistema::desconectar()
    {
        if (usuarioLogado == nullptr) {
            std::cout << "Erro: Nenhum usuário está logado." << std::endl;
            return;
        }

        std::cout << "Desconectando usuário " << usuarioLogado->getNome() << std::endl;
        usuarioLogado = nullptr;
    }

    void Sistema::criarServidor(const std::string& nome)
    {
        if (usuarioLogado == nullptr) {
            std::cout << "Erro: É necessário estar logado para criar um servidor." << std::endl;
            return;
        }

        if (nome.empty()) {
            std::cout << "Erro: É necessario definir um nome para o servidor." << std::endl;
            return;
        }

        for (const auto& servidor : servidores) {
            if (servidor.getNome() == nome) {
                std::cout << "Erro: Já existe um servidor com esse nome." << std::endl;
                return;
            }
        }

        Servidor novoServidor(usuarioLogado->getId(), nome, "", "");
        servidores.push_back(novoServidor);
        std::cout << "Servidor criado" << std::endl;    
    }

    void Sistema::mudarDescricaoServidor(const std::string& nome, const std::string& descricao)
    {
        if (usuarioLogado == nullptr) {
            std::cout << "Erro: É necessário estar logado para mudar a descrição de um servidor." << std::endl;
            return;
        }

        for (auto& servidor : servidores) {
            if (servidor.getNome() == nome) {
                if (servidor.getUsuarioDonoId() == usuarioLogado->getId()) {
                    servidor.setDescricao(descricao);
                    std::cout << "Descrição do servidor '" << nome << "' modificada!" << std::endl;
                } else {
                    std::cout << "Erro: Você não pode alterar a descrição de um servidor que não foi criado por você." << std::endl;
                }
                return;
            }
        }

        std::cout << "Erro: Servidor '" << nome << "' não existe." << std::endl;
    }

    void Sistema::mudarCodigoConviteServidor(const std::string& nome, const std::string& codigoConvite)
    {
        if (usuarioLogado == nullptr) {
            std::cout << "Erro: É necessário estar logado para mudar o código de convite de um servidor." << std::endl;
            return;
        }

        for (auto& servidor : servidores) {
            if (servidor.getNome() == nome) {
                if (servidor.getUsuarioDonoId() == usuarioLogado->getId()) {
                    servidor.setCodigoConvite(codigoConvite);
                    if (codigoConvite.empty()) {
                        std::cout << "Código de convite do servidor '" << nome << "' removido!" << std::endl;
                    } else {
                        std::cout << "Código de convite do servidor '" << nome << "' modificado!" << std::endl;
                    }
                } else {
                    std::cout << "Erro: Você não pode alterar o código de convite de um servidor que não foi criado por você." << std::endl;
                }
                return;
            }
        }

        std::cout << "Erro: Servidor '" << nome << "' não existe." << std::endl;
    }

    void Sistema::listarServidores()
    {
        for (const auto& servidor : servidores) {
            std::cout << servidor.getNome() << std::endl;
        }
    }
    
    void Sistema::removerServidor(const std::string& nome)
    {
        if (usuarioLogado == nullptr) {
            std::cout << "Erro: É necessário estar logado para remover um servidor." << std::endl;
            return;
        }

        for (auto it = servidores.begin(); it != servidores.end(); ++it) {
            if (it->getNome() == nome) {
                if (it->getUsuarioDonoId() == usuarioLogado->getId()) {
                    servidores.erase(it);
                    std::cout << "Servidor '" << nome << "' removido" << std::endl;
                } else {
                    std::cout << "Erro: Você não pode remover um servidor que não foi criado por você." << std::endl;
                }
                return;
            }
        }

        std::cout << "Erro: Servidor '" << nome << "' não encontrado." << std::endl;
    }

    void Sistema::entrarServidor(const std::string& nome, const std::string& codigoConvite)
    {
        if (usuarioLogado == nullptr) {
            std::cout << "Erro: É necessário estar logado para entrar em um servidor." << std::endl;
            return;
        }

        for (auto& servidor : servidores) {
            if (servidor.getNome() == nome) {
                if (servidor.getCodigoConvite().empty() || servidor.getUsuarioDonoId() == usuarioLogado->getId() || servidor.getCodigoConvite() == codigoConvite) {
                    servidor.adicionarParticipante(usuarioLogado->getId());
                    servidorAtual = &servidor;
                    std::cout << "Entrou no servidor " << nome <<  " com sucesso" << std::endl;
                } else {
                    std::cout << "Erro: Servidor requer código de convite" << std::endl;
                }
                return;
            }
        }

        std::cout << "Erro: Servidor '" << nome << "' não encontrado." << std::endl;
    }

    void Sistema::sairServidor()
    {
        if (usuarioLogado == nullptr) {
            std::cout << "Erro: É necessário estar logado para sair de um servidor." << std::endl;
            return;
        }

        if (servidorAtual == nullptr) {
            std::cout << "Erro: Você não está visualizando nenhum servidor." << std::endl;
            return;
        }

        std::cout << "Saindo do servidor '" << servidorAtual->getNome() << "'" << std::endl;
        servidorAtual = nullptr;
    }

    void Sistema::listarParticipantes()
    {
        if (usuarioLogado == nullptr) {
            std::cout << "Erro: É necessário estar logado para listar os participantes de um servidor." << std::endl;
            return;
        }

        if (servidorAtual == nullptr) {
            std::cout << "Erro: Você não está visualizando nenhum servidor." << std::endl;
            return;
        }

        for (int id : servidorAtual->getParticipantesIDs()) {
            for (const auto& usuario : usuarios) {
                if (usuario.getId() == id) {
                    std::cout << usuario.getNome() << std::endl;
                    break;
                }
            }
        }
    }

    void Sistema::listarCanais()
    {
        if (usuarioLogado == nullptr) {
            std::cout << "Erro: É necessário estar logado para listar os canais de um servidor." << std::endl;
            return;
        }

        if (servidorAtual == nullptr) {
            std::cout << "Erro: Você não está visualizando nenhum servidor." << std::endl;
            return;
        }

        std::cout << "#canais de texto" << std::endl;
        for (const auto& canal : servidorAtual->getCanais()) {
            if (dynamic_cast<const CanalTexto*>(canal) != nullptr) {
                std::cout << canal->getNome() << std::endl;
            }
        }

        std::cout << "#canais de voz" << std::endl;
        for (const auto& canal : servidorAtual->getCanais()) {
            if (dynamic_cast<const CanalVoz*>(canal) != nullptr) {
                std::cout << canal->getNome() << std::endl;
            }
        }
    }

    void Sistema::criarCanal(const std::string& nome, const std::string& tipo)
    {
        if (usuarioLogado == nullptr) {
            std::cout << "Erro: É necessário estar logado para criar um canal." << std::endl;
            return;
        }

        if (servidorAtual == nullptr) {
            std::cout << "Erro: Você não está visualizando nenhum servidor." << std::endl;
            return;
        }

        for (const auto& canal : servidorAtual->getCanais()) {
            if (canal->getNome() == nome && ((tipo == "texto" && dynamic_cast<const CanalTexto*>(canal) != nullptr) || (tipo == "voz" && dynamic_cast<const CanalVoz*>(canal) != nullptr))) {
                std::cout << "Erro: Canal de " << tipo << " '" << nome << "' já existe!" << std::endl;
                return;
            }
        }

        if (tipo == "texto") {
            CanalTexto* novoCanal = new CanalTexto(nome);
            servidorAtual->adicionarCanal(novoCanal);
            std::cout << "Canal de texto '" << nome << "' criado" << std::endl;
        } else if (tipo == "voz") {
            CanalVoz* novoCanal = new CanalVoz(nome);
            servidorAtual->adicionarCanal(novoCanal);
            std::cout << "Canal de voz '" << nome << "' criado" << std::endl;
        } else {
            std::cout << "Erro: Tipo de canal inválido. Os tipos válidos são 'texto' e 'voz'." << std::endl;
        }
    }

    void Sistema::entrarCanal(const std::string& nome)
    {
    if (usuarioLogado == nullptr) {
        std::cout << "Erro: É necessário estar logado para entrar em um canal." << std::endl;
        return;
    }

    if (servidorAtual == nullptr) {
        std::cout << "Erro: Você não está visualizando nenhum servidor." << std::endl;
        return;
    }

    for (auto& canal : servidorAtual->getCanais()) {
        if (canal->getNome() == nome) {
            canalAtual = canal;
            std::cout << "Entrou no canal '" << nome << "'" << std::endl;
            return;
        }
    }

    std::cout << "Erro: Canal '" << nome << "' não existe." << std::endl;
    }

    void Sistema::sairCanal() 
    {
        if (usuarioLogado == nullptr) {
            std::cout << "Erro: É necessário estar logado para sair de um canal." << std::endl;
            return;
        }

        if (servidorAtual == nullptr) {
            std::cout << "Erro: Você não está visualizando nenhum servidor." << std::endl;
            return;
        }

        if (canalAtual == nullptr) {
            std::cout << "Erro: Você não está visualizando nenhum canal." << std::endl;
            return;
        }

        std::cout << "Saindo do canal" << std::endl;
        canalAtual = nullptr;
    }
