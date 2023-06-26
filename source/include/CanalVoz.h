#ifndef CANALVOZ_H
#define CANALVOZ_H

#include "Canal.h"
#include "Mensagem.h"

class CanalVoz : public Canal {
private:
    Mensagem ultimaMensagem;

public:
    // Construtor com parâmetros
    CanalVoz(const std::string& nome);
    void setUltimaMensagem(const Mensagem& mensagem);
    Mensagem getUltimaMensagem() const;
};

#endif