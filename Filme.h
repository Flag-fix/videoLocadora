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
    int clietneId;

public:
    explicit Filme(int id)
    {
        this->id = id;
    };

    inline bool operator==(const Filme &outro) const
    {
        return outro.id == this->id;
    }


    static char opcoesMenuFilme();
    static Filme cadastrarFilme();
    static void alterarFilme();
    static void deletarFilme();
    static void visualizarFilme();
};

extern std::list<Filme> listaFilmes;


#endif //VIDEOLOCADORA_FILME_H
