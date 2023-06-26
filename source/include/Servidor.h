#ifndef SERVIDOR_H
#define SERVIDOR_H

#include <string>
#include <vector>
#include "Canal.h"
#include "CanalTexto.h"
#include "CanalVoz.h"

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
    Servidor(int usuarioDonoId, const std::string& nome, const std::string& descricao, const std::string& codigoConvite);

    // Destrutor
    ~Servidor();

    void adicionarParticipante(int id);
    void adicionarCanal(Canal* canal);

    // Getters
    int getUsuarioDonoId() const;
    std::string getNome() const;
    std::string getDescricao() const;
    std::string getCodigoConvite() const;
    std::vector<Canal*> getCanais() const;
    std::vector<int> getParticipantesIDs() const;

    // Setters
    void setUsuarioDonoId(int id);
    void setNome(const std::string& novoNome);
    void setDescricao(const std::string& novaDescricao);
    void setCodigoConvite(const std::string& novoCodigoConvite);
    void setCanais(const std::vector<Canal*>& novosCanais);
    void setParticipantesIDs(const std::vector<int>& novosParticipantesIDs);
};

#endif