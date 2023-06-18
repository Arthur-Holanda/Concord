#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>

// Forward declarations
class Channel;
class Server;
class System;

// User class
class User {
private:
    int id;
    std::string name;
    std::string email;
    std::string password;

public:
    User(int userId, const std::string& userName, const std::string& userEmail, const std::string& userPassword)
        : id(userId), name(userName), email(userEmail), password(userPassword) {}

    // Getters
    int getId() const { return id; }
    std::string getName() const { return name; }
    std::string getEmail() const { return email; }
    std::string getPassword() const { return password; }
};

// Message class
class Message {
private:
    std::string dateTime;
    std::string sentBy;
    std::string content;

public:
    Message() {}  // Default constructor

    Message(const std::string& messageSentBy, const std::string& messageContent)
        : dateTime(getCurrentDateTime()), sentBy(messageSentBy), content(messageContent) {}

    // Getters
    std::string getDateTime() const { return dateTime; }
    std::string getSentBy() const { return sentBy; }
    std::string getContent() const { return content; }

private:
    // Utility function to get the current date and time as a string
    std::string getCurrentDateTime() {
        std::time_t now = std::time(nullptr);
        char buffer[20];
        std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
        return std::string(buffer);
    }
};

// Channel class
class Channel {
protected:
    std::string name;

public:
    Channel(const std::string& channelName) : name(channelName) {}

    // Getter
    std::string getName() const { return name; }
};

// TextChannel class
class TextChannel : public Channel {
private:
    std::vector<Message> messages;

public:
    TextChannel(const std::string& channelName) : Channel(channelName) {}

    // Message operations
    void addMessage(const Message& message) { messages.push_back(message); }
    std::vector<Message> getMessages() const { return messages; }
};

// VoiceChannel class
class VoiceChannel : public Channel {
private:
    Message lastMessage;

public:
    VoiceChannel(const std::string& channelName) : Channel(channelName) {}

    // Last message operations
    void setLastMessage(const Message& message) { lastMessage = message; }
    Message getLastMessage() const { return lastMessage; }
};

// Server class
class Server {
private:
    int ownerUserId;
    std::string name;
    std::string description;
    std::string inviteCode;
    std::vector<Channel*> channels;
    std::vector<int> participantIds;

public:
    Server(int serverOwnerUserId, const std::string& serverName, const std::string& serverDescription,
           const std::string& serverInviteCode)
        : ownerUserId(serverOwnerUserId), name(serverName), description(serverDescription), inviteCode(serverInviteCode) {}

    // Getters
    int getOwnerUserId() const { return ownerUserId; }
    std::string getName() const { return name; }
    std::string getDescription() const { return description; }
    std::string getInviteCode() const { return inviteCode; }
    std::vector<Channel*> getChannels() const { return channels; }
    std::vector<int> getParticipantIds() const { return participantIds; }

    // Channel operations
    void addChannel(Channel* channel) { channels.push_back(channel); }

    // Participant operations
    void addParticipant(int userId) { participantIds.push_back(userId); }
};

// System class
class System {
private:
    std::vector<User> users;
    std::vector<Server> servers;
    User* loggedInUser;
    Server* viewedServer;
    Channel* viewedChannel;

public:
    // Command implementations
    void quit() {
        saveDataToFile();  // Save data to file before quitting
        std::cout << "System has been quit." << std::endl;
        exit(0);  // Terminate the program
    }

    void createUser(const std::string& name, const std::string& email, const std::string& password) {
        int userId = users.size() + 1;
        User newUser(userId, name, email, password);
        users.push_back(newUser);
        std::cout << "User created successfully." << std::endl;
    }

    void login(const std::string& email, const std::string& password) {
        for (User& user : users) {
            if (user.getEmail() == email && user.getPassword() == password) {
                loggedInUser = &user;
                std::cout << "Logged in successfully." << std::endl;
                return;
            }
        }
        std::cout << "Invalid email or password." << std::endl;
    }

    // Utility function to save system data to a file
    void saveDataToFile() {
        std::ofstream file("system_data.txt");

        if (file.is_open()) {
            // Save users
            file << "Users:" << std::endl;
            for (const User& user : users) {
                file << user.getId() << "," << user.getName() << "," << user.getEmail() << "," << user.getPassword()
                     << std::endl;
            }
            file << std::endl;

            // Save servers
            file << "Servers:" << std::endl;
            for (const Server& server : servers) {
                file << server.getOwnerUserId() << "," << server.getName() << "," << server.getDescription() << ","
                     << server.getInviteCode() << std::endl;
            }

            file.close();
            std::cout << "Data saved to file." << std::endl;
        } else {
            std::cout << "Unable to open the file for saving data." << std::endl;
        }
    }
};

int main() {
    System system;
    std::string command;

    while (true) {
        std::cout << "Enter a command: ";
        std::cin >> command;

        if (command == "quit") {
            system.quit();
            break;
        } else if (command == "create-user") {
            std::string name, email, password;
            std::cout << "Enter name: ";
            std::cin >> name;
            std::cout << "Enter email: ";
            std::cin >> email;
            std::cout << "Enter password: ";
            std::cin >> password;
            system.createUser(name, email, password);
        } else if (command == "login") {
            std::string email, password;
            std::cout << "Enter email: ";
            std::cin >> email;
            std::cout << "Enter password: ";
            std::cin >> password;
            system.login(email, password);
        } else {
            std::cout << "Invalid command. Please try again." << std::endl;
        }
    }

    return 0;
}
