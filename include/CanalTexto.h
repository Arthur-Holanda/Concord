#ifndef CANALTEXTO_H
#define CANALTEXTO_H

#include "Canal.h"
#include <vector>
#include "Mensagem.h"

class CanalTexto : public Canal {
private:
    std::vector<Mensagem> mensagens;

public:
    // Construtor com parâmetros
    CanalTexto(const std::string& nome);

    // Outros métodos e funcionalidades podem ser adicionados aqui
};

#endif