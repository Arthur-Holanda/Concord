#ifndef CANAL_H
#define CANAL_H

#include <string>

class Canal {
private:
    std::string nome;

public:
    Canal(const std::string& nome);
    virtual ~Canal();
    std::string getNome() const;
};

#endif