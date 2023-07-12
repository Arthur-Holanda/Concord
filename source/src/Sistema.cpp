/**
 * @file Sistema.cpp
 * @brief Implementação da classe Sistema.
 */
#include "../include/Sistema.h"

    Sistema::Sistema() : usuarioLogado(nullptr), servidorAtual(nullptr), canalAtual(nullptr) {}



    void Sistema::iniciar() {
        carregar();
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
            std::istringstream iss(args);
            std::getline(iss, email, ' ');
            std::getline(iss, senha, ' ');
            std::getline(iss, nome);
            criarUsuario(email, senha, nome);
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
        else if (command == "send-message") {
            std::string mensagem;

            std::istringstream iss(args);
            std::getline(iss, mensagem);
            enviarMensagem(mensagem);
        }
        else if (command == "list-messages") {
            visualizarMensagens();
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
            std::cout << "send-message [mensagem] - Envia uma mensagem para o canal de Texto" << std::endl;
            std::cout << "list-messages - Lista todas as mensagens do canal" << std::endl;
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
        salvar();
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
        if (servidorAtual != nullptr) {
            sairServidor();
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
        novoServidor.adicionarParticipante(usuarioLogado->getId());
        servidores.push_back(novoServidor);
        std::cout << "Servidor criado" << std::endl;
        salvar();
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
                salvar();
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
                salvar();
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
                salvar();
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

        if (canalAtual != nullptr) {
            sairCanal();
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
        salvar();
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

    void Sistema::enviarMensagem(const std::string& mensagem) {
        if (usuarioLogado == nullptr) {
            std::cout << "Erro: É necessário estar logado para enviar uma mensagem." << std::endl;
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
        CanalTexto* canalTexto = dynamic_cast<CanalTexto*>(canalAtual);
        if (canalTexto == nullptr) {
            std::cout << "Erro: Mensagens só podem ser enviadas para canais de texto." << std::endl;
            return;
        }

        Mensagem novaMensagem;
        novaMensagem.setConteudo(mensagem);
        novaMensagem.setDataHora(std::time(nullptr));
        novaMensagem.setEnviadaPor(usuarioLogado->getId());

        canalTexto->adicionarMensagem(novaMensagem);
        salvar();
    }

    std::string Sistema::getNomeUsuario(int idUsuario) const {
        for (const Usuario& usuario : usuarios) {
            if (usuario.getId() == idUsuario) {
                return usuario.getNome();
            }
        }
        return "";
    }

    void Sistema::visualizarMensagens() {
        if (usuarioLogado == nullptr) {
            std::cout << "Erro: É necessário estar logado para visualizar mensagens." << std::endl;
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

        CanalTexto* canalTexto = dynamic_cast<CanalTexto*>(canalAtual);
        if (canalTexto == nullptr) {
            std::cout << "Erro: Mensagens só podem ser visualizadas em canais de texto." << std::endl;
            return;
        }

        const std::vector<Mensagem>& mensagens = canalTexto->getMensagens();
        if (mensagens.empty()) {
            std::cout << "Sem mensagens para exibir" << std::endl;
            return;
        }

        for (const Mensagem& mensagem : mensagens) {
            // Obtém o nome do usuário que enviou a mensagem
            std::string nomeUsuario = getNomeUsuario(mensagem.getEnviadaPor());

            // Formata a data e a hora da mensagem
            time_t dataHora = mensagem.getDataHora();
            char bufferDataHora[20];
            std::strftime(bufferDataHora, sizeof(bufferDataHora), "%d/%m/%Y - %H:%M", std::localtime(&dataHora));

            // Imprime a mensagem formatada
            std::cout << nomeUsuario << "<" << bufferDataHora << ">: " << mensagem.getConteudo() << std::endl;
        }
    }

    void Sistema::salvarUsuarios() {
        std::ofstream arquivo("usuarios.txt");
        if (arquivo.is_open()) {
            arquivo << usuarios.size() << "\n";
            for (const Usuario& usuario : usuarios) {
                arquivo << usuario.getId() << "\n";
                arquivo << usuario.getNome() << "\n";
                arquivo << usuario.getEmail() << "\n";
                arquivo << usuario.getSenha() << "\n";
            }
            arquivo.close();
        } else {
            std::cerr << "Não foi possível abrir o arquivo para escrita.\n";
        }
    }

    void Sistema::salvarServidores() {
        std::ofstream arquivo("servidores.txt");
        if (arquivo.is_open()) {
            arquivo << servidores.size() << "\n";
            for (const Servidor& servidor : servidores) {
                arquivo << servidor.getUsuarioDonoId() << "\n";
                arquivo << servidor.getNome() << "\n";
                arquivo << servidor.getDescricao() << "\n";
                arquivo << servidor.getCodigoConvite() << "\n";
                const std::vector<int>& participantes = servidor.getParticipantesIDs();
                arquivo << participantes.size() << "\n";
                for (int idParticipante : participantes) {
                    arquivo << idParticipante << "\n";
                }
                const std::vector<Canal*>& canais = servidor.getCanais();
                arquivo << canais.size() << "\n";
                for (const Canal* canal : canais) {
                    arquivo << canal->getNome() << "\n";
                    if (canal->getTipo() == Canal::Tipo::TEXTO) {
                        arquivo << "TEXTO\n";
                        const std::vector<Mensagem>& mensagens = dynamic_cast<const CanalTexto*>(canal)->getMensagens();
                        arquivo << mensagens.size() << "\n";
                        for (const Mensagem& mensagem : mensagens) {
                            arquivo << mensagem.getEnviadaPor() << "\n";

                            // Converte o valor de tempo em uma estrutura tm
                            std::time_t dataHora = mensagem.getDataHora();
                            std::tm* dataHoraTm = std::localtime(&dataHora);

                            // Formata a data/hora como uma string no formato "dia/mês/ano"
                            char buffer[11];
                            std::strftime(buffer, sizeof(buffer), "%d/%m/%Y", dataHoraTm);

                            // Escreve a data/hora formatada no arquivo
                            arquivo << buffer << "\n";

                            arquivo << mensagem.getConteudo() << "\n";
                        }
                    } else if (canal->getTipo() == Canal::Tipo::VOZ) {
                        arquivo << "VOZ\n";
                        const Mensagem& ultimaMensagem = dynamic_cast<const CanalVoz*>(canal)->getUltimaMensagem();
                        if (ultimaMensagem.getEnviadaPor() != -1) {
                            arquivo << "1\n";
                            arquivo << ultimaMensagem.getEnviadaPor() << "\n";

                            // Converte o valor de tempo em uma estrutura tm
                            std::time_t dataHora = ultimaMensagem.getDataHora();
                            std::tm* dataHoraTm = std::localtime(&dataHora);

                            // Formata a data/hora como uma string no formato "dia/mês/ano"
                            char buffer[11];
                            std::strftime(buffer, sizeof(buffer), "%d/%m/%Y", dataHoraTm);

                            // Escreve a data/hora formatada no arquivo
                            arquivo << buffer << "\n";

                            arquivo << ultimaMensagem.getConteudo() << "\n";
                        } else {
                            arquivo << "0\n";
                        }
                    }
                }
            }
            arquivo.close();
        } else {
            std::cerr << "Não foi possível abrir o arquivo para escrita.\n";
        }
    }

    void Sistema::salvar() {
        salvarUsuarios();
        salvarServidores();
    }

    void Sistema::carregarUsuarios() {
        std::ifstream arquivo("usuarios.txt");
        if (arquivo.is_open()) {
            int numUsuarios;
            arquivo >> numUsuarios;
            std::string lixo;
            std::getline(arquivo, lixo);
            for (int i = 0; i < numUsuarios; i++) {
                int id;
                std::string nome, email, senha;
                arquivo >> id;
                std::getline(arquivo, lixo);
                std::getline(arquivo, nome);
                std::getline(arquivo, email);
                std::getline(arquivo, senha);
                usuarios.push_back(Usuario(id, nome, email, senha));
            }
            arquivo.close();
        } else {
            std::cerr << "Não foi possível abrir o arquivo para leitura.\n";
        }
    }

    void Sistema::carregarServidores() {
        std::ifstream arquivo("servidores.txt");
        if (arquivo.is_open()) {
            int numServidores;
            arquivo >> numServidores;
            std::string lixo;
            std::getline(arquivo, lixo);
            for (int i = 0; i < numServidores; i++) {
                int donoId, numParticipantes, numCanais;
                std::string nome, descricao, codigoConvite;
                arquivo >> donoId;
                std::getline(arquivo, lixo);
                std::getline(arquivo, nome);
                std::getline(arquivo, descricao);
                std::getline(arquivo, codigoConvite);
                Servidor servidor(donoId, nome, descricao, codigoConvite);
                arquivo >> numParticipantes;
                for (int j = 0; j < numParticipantes; j++) {
                    int idParticipante;
                    arquivo >> idParticipante;
                    servidor.adicionarParticipante(idParticipante);
                }
                arquivo >> numCanais;
                for (int j = 0; j < numCanais; j++) {
                    std::string nomeCanal, tipoCanal;
                    int numMensagens;
                    std::getline(arquivo, nomeCanal);
                    std::getline(arquivo, tipoCanal);
                    Canal* canal;
                    if (tipoCanal == "TEXTO") {
                        canal = new CanalTexto(nomeCanal);
                        arquivo >> numMensagens;
                        for (int k = 0; k < numMensagens; k++) {
                            int enviadaPor;
                            time_t dataHora;
                            std::string conteudo;
                            arquivo >> enviadaPor >> dataHora;
                            std::getline(arquivo, conteudo);
                            Mensagem mensagem(enviadaPor, dataHora, conteudo);
                            dynamic_cast<CanalTexto*>(canal)->adicionarMensagem(mensagem);
                        }
                    } else if (tipoCanal == "VOZ") {
                        canal = new CanalVoz(nomeCanal);
                        arquivo >> numMensagens;
                        if (numMensagens > 0) {
                            int enviadaPor;
                            time_t dataHora;
                            std::string conteudo;
                            arquivo >> enviadaPor >> dataHora;
                            std::getline(arquivo, conteudo);
                            Mensagem mensagem(enviadaPor, dataHora, conteudo);
                            dynamic_cast<CanalVoz*>(canal)->setUltimaMensagem(mensagem);
                        }
                    }
                    servidor.adicionarCanal(canal);
                }
                servidores.push_back(servidor);
            }
            arquivo.close();
        } else {
            std::cerr << "Não foi possível abrir o arquivo para leitura.\n";
        }
    }

    void Sistema::carregar() {
        carregarUsuarios();
        carregarServidores();
    }

