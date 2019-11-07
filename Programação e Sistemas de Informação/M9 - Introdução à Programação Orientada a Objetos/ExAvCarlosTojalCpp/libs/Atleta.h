
//
// Carlos Tojal 07-11-2019
// ExAvCarlosTojalCpp
// Atleta.h
//

#include <iostream>
#include <string>
#include "../libs/DadosFisicos.h"

class Atleta {
    private:
        string nome;
        long contacto;
        string nacionalidade;
        int numeroCamisa;
        string posicao;
        bool status;
        DadosFisicos dadosFisicos;
    public:
        Atleta();
        Atleta(string nome, long contacto, string nacionalidade);
        Atleta(string nome, long contacto, string nacionalidade, int numeroCamisa, string posicao);
        string getNome();
        void setNome(string nome);
        long getContacto();
        void setContacto(long contacto);
        string getNacionalidade();
        void setNacionalidade(string nacionalidade);
        int getNumeroCamisa();
        void setNumeroCamisa(int numeroCamisa);
        string getPosicao();
        void setPosicao(string posicao);
        bool getStatus();
        void setStatus(bool status);
        DadosFisicos getDadosFisicos();
        void setDadosFisicos(DadosFisicos dadosFisicos);
}