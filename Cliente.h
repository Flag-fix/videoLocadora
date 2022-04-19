//
// Created by ibandeir on 17/04/2022.
//

#ifndef VIDEOLOCADORA_CLIENTE_H
#define VIDEOLOCADORA_CLIENTE_H
#include <iostream>
#include <list>

class Cliente{
private:
    int id;
    std::string nome;
    int diaNascimento;
    int mesNascimento;
    int anoNascimento;
    std::string sexo;

public:
    explicit Cliente(int id)
    {
        this->id = id;
    };

    inline bool operator==(const Cliente &outro) const
    {
        return outro.id == this->id;
    }


    static char opcoesMenuCliente();
    static Cliente cadastrarCliente();
    static void alterarCliente();
    static void deletarCliente();
    static void visualizarCliente();
};

extern std::list<Cliente> listaClientes;



#endif //VIDEOLOCADORA_CLIENTE_H
