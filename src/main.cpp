#include <iostream>
#include <vector>
#include <string>

class Usuario {
private:
    int id;
    std::string nome;
    std::string email;
    std::string senha;

public:
    // Construtor padrão
    Usuario() {}

    // Construtor com parâmetros
    Usuario(int id, const std::string& nome, const std::string& email, const std::string& senha)
        : id(id), nome(nome), email(email), senha(senha) {}

    // Getters
    int getId() const {
        return id;
    }

    std::string getNome() const {
        return nome;
    }

    std::string getEmail() const {
        return email;
    }

    std::string getSenha() const {
        return senha;
    }
};

class Mensagem {
private:
    std::string dataHora;
    int enviadaPor;
    std::string conteudo;

public:
    // Construtor padrão
    Mensagem() {}

    // Construtor com parâmetros
    Mensagem(const std::string& dataHora, int enviadaPor, const std::string& conteudo)
        : dataHora(dataHora), enviadaPor(enviadaPor), conteudo(conteudo) {}

    // Getters
    std::string getDataHora() const {
        return dataHora;
    }

    int getEnviadaPor() const {
        return enviadaPor;
    }

    std::string getConteudo() const {
        return conteudo;
    }
};

class Canal {
private:
    std::string nome;

public:
    Canal(const std::string& nome) : nome(nome) {}

    virtual ~Canal() {}

    std::string getNome() const {
        return nome;
    }
};

class CanalTexto : public Canal {
private:
    std::vector<Mensagem> mensagens;

public:
    // Construtor com parâmetros
    CanalTexto(const std::string& nome) : Canal(nome) {}
};

class CanalVoz : public Canal {
private:
    Mensagem ultimaMensagem;

public:
    // Construtor com parâmetros
    CanalVoz(const std::string& nome) : Canal(nome) {}
};

class Servidor {
private:
    int usuarioDonoId;
    std::string nome;
    std::string descricao;
    std::string codigoConvite;
    std::vector<Canal*> canais;
    std::vector<int> participantesIDs;

public:
    // Construtor com parâmetros
    Servidor(int usuarioDonoId, const std::string& nome, const std::string& descricao, const std::string& codigoConvite)
        : usuarioDonoId(usuarioDonoId), nome(nome), descricao(descricao), codigoConvite(codigoConvite) {}

    // Destrutor
    ~Servidor() {
        for (auto canal : canais) {
            delete canal;
        }
    }
    void adicionarParticipante(int id) {
        participantesIDs.push_back(id);
    }
    void adicionarCanal(Canal* canal) {
        canais.push_back(canal);
    }
        // Getters
    int getUsuarioDonoId() const {
        return usuarioDonoId;
    }

    std::string getNome() const {
        return nome;
    }

    std::string getDescricao() const {
        return descricao;
    }

    std::string getCodigoConvite() const {
        return codigoConvite;
    }

    std::vector<Canal*> getCanais() const {
        return canais;
    }

    std::vector<int> getParticipantesIDs() const {
        return participantesIDs;
    }

    // Setters
    void setUsuarioDonoId(int id) {
        usuarioDonoId = id;
    }

    void setNome(const std::string& novoNome) {
        nome = novoNome;
    }

    void setDescricao(const std::string& novaDescricao) {
        descricao = novaDescricao;
    }

    void setCodigoConvite(const std::string& novoCodigoConvite) {
        codigoConvite = novoCodigoConvite;
    }

    void setCanais(const std::vector<Canal*>& novosCanais) {
        canais = novosCanais;
    }

    void setParticipantesIDs(const std::vector<int>& novosParticipantesIDs) {
        participantesIDs = novosParticipantesIDs;
    }
};

class Sistema {
private:
    std::vector<Usuario> usuarios;
    std::vector<Servidor> servidores;
    Usuario* usuarioLogado;
    Servidor* servidorAtual;
    Canal* canalAtual;

public:
    Sistema() : usuarioLogado(nullptr), servidorAtual(nullptr), canalAtual(nullptr) {}

    void iniciar() {
        std::cout << "Concordo - Sistema de Mensagens" << std::endl;
        while (lerComando()) {}
    }

bool lerComando() {
        std::string command;
        std::cout << "\nDigite um comando (ou 'help' para ver a lista de comandos): ";
        std::getline(std::cin, command);

        size_t pos = command.find(' ');
        std::string cmd = command.substr(0, pos);

        if (cmd == "quit") {
            //quit();
            std::cout << "Saindo do Concordo" << std::endl;
            return false;
        }
        else if (cmd == "create-user") {
            std::string email, password, name;
            std::cout << "Email, senha e nome (separados por espaço): ";
            std::cin >> email >> password >> name;
            std::cin.ignore(); // Ignorar o caractere de nova linha residual
            criarUsuario(name, email, password);
        }
        else if (cmd == "login") {
            std::string email, password;
            std::cout << "Email, senha (separados por espaço): ";
            std::cin >> email >> password;
            login(email, password);
            std::cin.ignore(); // Ignorar o caractere de nova linha residual
        }                                                //não logado 
        else if (cmd == "disconnect") {
            desconectar();
        }
        else if (cmd == "create-server") {
            std::string serverName = command.substr(pos + 1);
            criarServidor(serverName);
        }
        else if (cmd == "set-server-desc"){
            size_t pos2 = command.find(' ', pos + 1);
            std::string serverName = command.substr(pos + 1, pos2 - pos - 1);
            std::string description = command.substr(pos2 + 1);
            mudarDescricaoServidor(serverName, description);
        }
        else if (cmd == "set-server-invite-code") {
            size_t pos2 = command.find(' ', pos + 1);
            std::string serverName = command.substr(pos + 1, pos2 - pos - 1);
            std::string inviteCode = command.substr(pos2 + 1);
            mudarCodigoConviteServidor(serverName, inviteCode);
        }
        else if (cmd == "list-servers") {
            listarServidores();
        }
        else if (cmd == "remove-server") {
            std::string serverName = command.substr(pos + 1);
            removerServidor(serverName);
        }
        else if (cmd == "enter-server") {
            size_t pos2 = command.find(' ', pos + 1);
            std::string serverName = command.substr(pos + 1, pos2 - pos - 1);
            std::string inviteCode = command.substr(pos2 + 1);
            entrarServidor(serverName, inviteCode);
        }
        else if (cmd == "leave-server") {
            sairServidor();
        }
        else if (cmd == "list-participants") {
            listarParticipantes();
        }
        else if (cmd == "list-channels") {
            listarCanais();
        }
        else if (cmd == "create-channel") {
            size_t pos2 = command.find(' ', pos + 1);
            std::string channelName = command.substr(pos + 1, pos2 - pos - 1);
            std::string channelType = command.substr(pos2 + 1);
            criarCanal(channelName, channelType);
        }
        else if (cmd == "enter-channel") {
            std::string channelName = command.substr(pos + 1);
            entrarCanal(channelName);
        }
        else if (cmd == "leave-channel") {
            sairCanal();
        }
        else if (cmd == "help") {
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
            std::cout << "enter-server [nome] - Entrar em um servidor" << std::endl;
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
    // Comando para sair do sistema
    void quit()
    {
        std::cout << "Quitting the system. Goodbye!" << std::endl;
    }

    // Comando para criar um usuário
    void criarUsuario(const std::string& email, const std::string& senha, const std::string& nome)
    {
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
    void login(const std::string& email, const std::string& senha)
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

    void desconectar()
    {
        if (usuarioLogado == nullptr) {
            std::cout << "Erro: Nenhum usuário está logado." << std::endl;
            return;
        }

        std::cout << "Desconectando usuário " << usuarioLogado->getEmail() << std::endl;
        usuarioLogado = nullptr;
    }

    void criarServidor(const std::string& nome)
    {
        if (usuarioLogado == nullptr) {
            std::cout << "Erro: É necessário estar logado para criar um servidor." << std::endl;
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

    void mudarDescricaoServidor(const std::string& nome, const std::string& descricao)
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

    void mudarCodigoConviteServidor(const std::string& nome, const std::string& codigoConvite = "")
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

    void listarServidores()
    {
        for (const auto& servidor : servidores) {
            std::cout << servidor.getNome() << std::endl;
        }
    }
    
    void removerServidor(const std::string& nome)
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

    void entrarServidor(const std::string& nome, const std::string& codigoConvite = "")
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
                    std::cout << "Entrou no servidor com sucesso" << std::endl;
                } else {
                    std::cout << "Erro: Servidor requer código de convite" << std::endl;
                }
                return;
            }
        }

        std::cout << "Erro: Servidor '" << nome << "' não encontrado." << std::endl;
    }

    void sairServidor()
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

    void listarParticipantes()
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

    void listarCanais()
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

    void criarCanal(const std::string& nome, const std::string& tipo)
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

    void entrarCanal(const std::string& nome)
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

    void sairCanal() 
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


};

int main()
{
    Sistema sistema;
    sistema.iniciar();


    /*
    Sistema system;
    std::string command;

    std::cout << "Concordo - Sistema de Mensagens" << std::endl;


    while(true)
    {
        std::cout << "\nDigite um comando (ou 'help' para ver a lista de comandos): ";
        std::getline(std::cin, command);

        size_t pos = command.find(' ');
        std::string cmd = command.substr(0, pos);
                                                        //não logado
        if (cmd == "quit") {
            system.quit();
            break;
        }
        else if (cmd == "create-user") {
            std::string email, password, name;
            std::cout << "Email, senha e nome (separados por espaço): ";
            std::cin >> email >> password >> name;
            std::cin.ignore(); // Ignorar o caractere de nova linha residual
            system.criarUsuario(name, email, password);
        }
        else if (cmd == "login") {
            std::string email, password;
            std::cout << "Email, senha (separados por espaço): ";
            std::cin >> email >> password;
            system.login(email, password);
            std::cin.ignore(); // Ignorar o caractere de nova linha residual
        }                                                //não logado 
        else if (cmd == "disconnect") {
            system.desconectar();
        }
        else if (cmd == "create-server") {
            std::string serverName = command.substr(pos + 1);
            system.criarServidor(serverName);
        }
        else if (cmd == "set-server-desc"){
            size_t pos2 = command.find(' ', pos + 1);
            std::string serverName = command.substr(pos + 1, pos2 - pos - 1);
            std::string description = command.substr(pos2 + 1);
            system.mudarDescricaoServidor(serverName, description);
        }
        else if (cmd == "set-server-invite-code") {
            size_t pos2 = command.find(' ', pos + 1);
            std::string serverName = command.substr(pos + 1, pos2 - pos - 1);
            std::string inviteCode = command.substr(pos2 + 1);
            system.mudarCodigoConviteServidor(serverName, inviteCode);
        }
        else if (cmd == "list-servers") {
            system.listarServidores();
        }
        else if (cmd == "remove-server") {
            std::string serverName = command.substr(pos + 1);
            system.removerServidor(serverName);
        }
        else if (cmd == "enter-server") {
            size_t pos2 = command.find(' ', pos + 1);
            std::string serverName = command.substr(pos + 1, pos2 - pos - 1);
            std::string inviteCode = command.substr(pos2 + 1);
            system.entrarServidor(serverName, inviteCode);
        }
        else if (cmd == "leave-server") {
            system.sairServidor();
        }
        else if (cmd == "list-participants") {
            system.listarParticipantes();
        }
        else if (cmd == "list-channels") {
            system.listarCanais();
        }
        else if (cmd == "create-channel") {
            size_t pos2 = command.find(' ', pos + 1);
            std::string channelName = command.substr(pos + 1, pos2 - pos - 1);
            std::string channelType = command.substr(pos2 + 1);
            system.criarCanal(channelName, channelType);
        }
        else if (cmd == "enter-channel") {
            std::string channelName = command.substr(pos + 1);
            system.entrarCanal(channelName);
        }
        else if (cmd == "leave-channel") {
            system.sairCanal();
        }
        else if (cmd == "help") {
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
            std::cout << "enter-server [nome] - Entrar em um servidor" << std::endl;
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
        
    }*/
    return 0;
}