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
    int idade;
    int diaNascimento;
    int mesNascimento;
    int anoNascimento;
    std::string sexo;

public:
    explicit Cliente(int id)
    {
        this->id = id;
    }

    explicit Cliente() {};

    inline bool operator==(const Cliente &outro) const
    {
        return outro.id == this->id;
    }

    std::string getNomeCliente();
    static char opcoesMenuCliente();
    static Cliente cadastrarCliente();
    static void alterarCliente();
    static void deletarCliente();
    static void visualizarCliente();
    static Cliente *getClienteById();
    static Cliente *getClienteById(int id);
};

extern std::list<Cliente> listaClientes;
extern int idCount;

#endif //VIDEOLOCADORA_CLIENTE_H
