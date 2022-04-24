//
// Created by Francielxyz on 21/04/2022.
//

#ifndef VIDEOLOCADORA_Filme_H
#define VIDEOLOCADORA_Filme_H
#include <iostream>
#include <list>

class Filme{
private:
    int id;
    std::string titulo;
    std::string genero;
    double valorLocacao;
    bool filmeLocado = false;

public:
    explicit Filme(int id)
    {
        this->id = id;
    }

    explicit Filme() {};

    inline bool operator==(const Filme &outro) const
    {
        return outro.id == this->id;
    }

    std::string getTitulo();
    double getValorLocacao();
    bool getLocadoStatus();
    void changeLocadoStatus();
    static char opcoesMenuFilme();
    static Filme cadastrarFilme();
    static void alterarFilme();
    static void deletarFilme();
    static void visualizarFilme();
    static Filme *getFilmeById();
    static Filme *getFilmeById(int id);
};

extern std::list<Filme> listaFilmes;
extern int idCount;

#endif //VIDEOLOCADORA_FILME_H