//
// Created by ibandeir on 17/04/2022.
//

#ifndef VIDEOLOCADORA_LOCADO_H
#define VIDEOLOCADORA_LOCADO_H
#include <ctime>
#include "Cliente.h"
#include "Filme.h"

class Locado {
private:
    Filme *filme;
    Cliente *cliente;
    double valor;
    time_t dataHoraLocacao;

public:
    explicit Locado(Filme *filme, Cliente *cliente) {
        this->cliente = cliente;
        this->filme = filme;
        if (filme->getLocadoStatus())
            throw std::invalid_argument( "Filme já se encontra Locado." );
        filme->changeLocadoStatus();
        this->valor = filme->getValorLocacao();
        this->dataHoraLocacao = time(0);
    };

    explicit Locado() {};

    inline bool operator==(const Locado &outro) const
    {
        return outro.filme == this->filme && outro.cliente == this->cliente;
    }

    static char opcoesMenuLocado();
    static void cadastrarLocado();
    static void devolverLocado();
    static void visualizarNaoLocados();
    static void visualizarLocados();
    static Locado getLocadoByClienteIdFilmeId(Cliente *cliente, Filme *filme);
};

extern std::list<Locado> listaLocados;
extern double faturamento;

#endif //VIDEOLOCADORA_LOCADO_H