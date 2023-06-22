#include <iostream>
#include <vector>
#include <algorithm>

class User {
private:
    int id;
    std::string name;
    std::string email;
    std::string password;

public:
    User(int id, const std::string& name, const std::string& email, const std::string& password)
        : id(id), name(name), email(email), password(password) {}

    int getId() const {
        return id;
    }

    std::string getName() const {
        return name;
    }

    std::string getEmail() const {
        return email;
    }

    std::string getPassword() const {
        return password;
    }
};

class Message {
private:
    std::string dateTime;
    int sentBy;
    std::string content;

public:
    Message() {}

    Message(const std::string& dateTime, int sentBy, const std::string& content)
        : dateTime(dateTime), sentBy(sentBy), content(content) {}

    std::string getDateTime() const {
        return dateTime;
    }

    int getSentBy() const {
        return sentBy;
    }

    std::string getContent() const {
        return content;
    }
};

class Channel {
protected:
    std::string name;

public:
    Channel(const std::string& name) : name(name) {}

    std::string getName() const {
        return name;
    }
};

class TextChannel : public Channel {
private:
    std::vector<Message> messages;

public:
    TextChannel(const std::string& name) : Channel(name) {}

    void addMessage(const Message& message) {
        messages.push_back(message);
    }

    std::vector<Message> getMessages() const {
        return messages;
    }
};

class VoiceChannel : public Channel {
private:
    Message lastMessage;

public:
    VoiceChannel(const std::string& name) : Channel(name) {}

    void setLastMessage(const Message& message) {
        lastMessage = message;
    }

    Message getLastMessage() const {
        return lastMessage;
    }
};

class Server {
private:
    int id;
    int ownerUserId;
    std::string name;
    std::string description;
    std::string inviteCode;
    std::vector<int> participantIds;
    std::vector<Channel*> channels;

public:
    Server(int id, int ownerUserId, const std::string& name, const std::string& description)
        : id(id), ownerUserId(ownerUserId), name(name), description(description) {}

    int getId() const {
        return id;
    }

    int getOwnerUserId() const {
        return ownerUserId;
    }

    std::string getName() const {
        return name;
    }

    std::string getDescription() const {
        return description;
    }

    void setDescription(const std::string& description) {
        this->description = description;
    }

    std::string getInviteCode() const {
        return inviteCode;
    }

    void setInviteCode(const std::string& inviteCode) {
        this->inviteCode = inviteCode;
    }

    std::vector<int> getParticipantIds() const {
        return participantIds;
    }

    void addParticipant(int participantId) {
        participantIds.push_back(participantId);
    }

    std::vector<Channel*> getChannels() const {
        return channels;
    }

    void addChannel(Channel* channel) {
        channels.push_back(channel);
    }
};

class System {
private:
    std::vector<User> users;
    std::vector<Server> servers;
    User* loggedInUser;
    Server* viewedServer;
    Channel* viewedChannel;
    bool loggedIn; // Novo membro para controlar o estado de login
public:
    System() : loggedInUser(nullptr), viewedServer(nullptr), viewedChannel(nullptr), loggedIn(false) {}

    void saveDataToFile() {
        std::cout << "Data saved to file." << std::endl;
    }

    void loadDataFromFile() {
        std::cout << "Data loaded from file." << std::endl;
    }

    void quit() {
        saveDataToFile();
        std::cout << "Quitting the system. Goodbye!" << std::endl;
    }

    void createUser(const std::string& name, const std::string& email, const std::string& password) {
        int newId = users.empty() ? 1 : users.back().getId() + 1;
        User newUser(newId, name, email, password);
        users.push_back(newUser);
        std::cout << "User created with ID: " << newId << std::endl;
    }

    void login(const std::string& email, const std::string& password) {
        auto it = std::find_if(users.begin(), users.end(), [&email, &password](const User& user) {
            return user.getEmail() == email && user.getPassword() == password;
        });

        if (it != users.end()) {
            loggedInUser = &(*it);
            loggedIn = true; // Atualiza o estado de login
            std::cout << "User logged in successfully." << std::endl;
        } else {
            loggedInUser = nullptr;
            loggedIn = false; // Atualiza o estado de login
            std::cout << "Invalid email or password. Login failed." << std::endl;
        }
    }

    bool isLoggedIn() const {
        return loggedIn;
    }
    void disconnect() {
        if (loggedInUser != nullptr) {
            std::cout << "Desconectando usuário " << loggedInUser->getEmail() << std::endl;
            loggedInUser = nullptr;
            loggedIn = false;
        } else {
            std::cout << "Não está conectado" << std::endl;
        }
    }

    void createServer(const std::string& name, const std::string& description) {
        if (loggedInUser != nullptr) {
            int ownerUserId = loggedInUser->getId();
            int newServerId = servers.empty() ? 1 : servers.back().getId() + 1;
            Server newServer(newServerId, ownerUserId, name, description);
            servers.push_back(newServer);
            std::cout << "Server created with ID: " << newServerId << std::endl;
        } else {
            std::cout << "You must be logged in to create a server." << std::endl;
        }
    }

    void setServerDescription(const std::string& description) {
        if (viewedServer != nullptr) {
            viewedServer->setDescription(description);
            std::cout << "Server description updated." << std::endl;
        } else {
            std::cout << "No server is currently viewed." << std::endl;
        }
    }

    void setServerInviteCode(const std::string& inviteCode) {
        if (viewedServer != nullptr) {
            viewedServer->setInviteCode(inviteCode);
            std::cout << "Server invite code set." << std::endl;
        } else {
            std::cout << "No server is currently viewed." << std::endl;
        }
    }

    void listServers() {
        if (!servers.empty()) {
            std::cout << "List of servers:" << std::endl;
            for (const Server& server : servers) {
                std::cout << "ID: " << server.getId() << ", Name: " << server.getName() << std::endl;
            }
        } else {
            std::cout << "No servers found." << std::endl;
        }
    }

    void removeServer(int serverId) {
        auto it = std::find_if(servers.begin(), servers.end(), [&serverId](const Server& server) {
            return server.getId() == serverId;
        });

        if (it != servers.end()) {
            servers.erase(it);
            std::cout << "Server removed." << std::endl;
        } else {
            std::cout << "Server not found." << std::endl;
        }
    }

    void enterServer(int serverId) {
        auto it = std::find_if(servers.begin(), servers.end(), [&serverId](const Server& server) {
            return server.getId() == serverId;
        });

        if (it != servers.end()) {
            viewedServer = &(*it);
            std::cout << "Entered server: " << viewedServer->getName() << std::endl;
        } else {
            std::cout << "Server not found." << std::endl;
        }
    }

    void leaveServer() {
        viewedServer = nullptr;
        viewedChannel = nullptr;
        std::cout << "Left the current server." << std::endl;
    }

    void listParticipants() {
        if (viewedServer != nullptr) {
            std::cout << "Participants in the server:" << std::endl;
            for (int participantId : viewedServer->getParticipantIds()) {
                auto it = std::find_if(users.begin(), users.end(), [&participantId](const User& user) {
                    return user.getId() == participantId;
                });

                if (it != users.end()) {
                    std::cout << "ID: " << it->getId() << ", Name: " << it->getName() << std::endl;
                }
            }
        } else {
            std::cout << "No server is currently viewed." << std::endl;
        }
    }

    void addParticipant(int participantId) {
        if (viewedServer != nullptr) {
            viewedServer->addParticipant(participantId);
            std::cout << "Participant added to the server." << std::endl;
        } else {
            std::cout << "No server is currently viewed." << std::endl;
        }
    }
};

int main() {
    System system;
    std::string command;

    std::cout << "Concordo - Sistema de Mensagens" << std::endl;

    while (true) {
        std::cout << "\nDigite um comando (ou 'help' para ver a lista de comandos): ";
        std::cin >> command;

        if (command == "quit") {
            system.quit();
            break;
        }
        else if (command == "create-user") {
            std::string name, email, password;
            std::cout << "Nome: ";
            std::cin >> name;
            std::cout << "Email: ";
            std::cin >> email;
            std::cout << "Senha: ";
            std::cin >> password;
            system.createUser(name, email, password);
        }
        else if (command == "login") {
            std::string email, password;
            std::cout << "Email: ";
            std::cin >> email;
            std::cout << "Senha: ";
            std::cin >> password;
            system.login(email, password);
        }
        else if (command == "disconnect") {
            system.disconnect();
        }
        else if (command == "create-server") {
            if (system.isLoggedIn()) {
                std::string name, description;
                std::cout << "Nome do servidor: ";
                std::cin >> name;
                std::cout << "Descrição do servidor: ";
                std::cin >> description;
                system.createServer(name, description);
            } else {
                std::cout << "Você precisa estar logado para criar um servidor." << std::endl;
            }
        }
        else if (command == "set-server-desc") {
            std::string description;
            std::cout << "Nova descrição: ";
            std::cin >> description;
            system.setServerDescription(description);
        }
        else if (command == "set-server-invitecode") {
            std::string inviteCode;
            std::cout << "Novo código de convite: ";
            std::cin >> inviteCode;
            system.setServerInviteCode(inviteCode);
        }
        else if (command == "list-servers") {
            system.listServers();
        }
        else if (command == "remove-server") {
            int serverId;
            std::cout << "ID do servidor: ";
            std::cin >> serverId;
            system.removeServer(serverId);
        }
        else if (command == "enter-server") {
            int serverId;
            std::cout << "ID do servidor: ";
            std::cin >> serverId;
            system.enterServer(serverId);
        }
        else if (command == "leave-server") {
            system.leaveServer();
        }
        else if (command == "list-participants") {
            system.listParticipants();
        }
        else if (command == "help") {
            std::cout << "Lista de comandos disponíveis:" << std::endl;
            std::cout << "quit - Sair do sistema" << std::endl;
            std::cout << "create-user - Criar um novo usuário" << std::endl;
            std::cout << "login - Fazer login em um usuário" << std::endl;
            std::cout << "disconnect - Desconectar do atual usuário" << std::endl;
            std::cout << "create-server - Criar um novo servidor" << std::endl;
            std::cout << "set-server-desc - Definir a descrição de um servidor" << std::endl;
            std::cout << "set-server-invitecode - Definir o código de convite de um servidor" << std::endl;
            std::cout << "list-servers - Listar os servidores disponíveis" << std::endl;
            std::cout << "remove-server - Remover um servidor" << std::endl;
            std::cout << "enter-server - Entrar em um servidor" << std::endl;
            std::cout << "leave-server - Sair do servidor atual" << std::endl;
            std::cout << "list-participants - Listar os participantes do servidor atual" << std::endl;
        }
        else {
            std::cout << "Comando inválido. Digite 'help' para ver a lista de comandos disponíveis." << std::endl;
        }
    }

    return 0;
}
