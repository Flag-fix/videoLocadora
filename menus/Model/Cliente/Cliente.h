//
// Created by ibandeir on 17/04/2022.
//

#ifndef VIDEOLOCADORA_CLIENTE_H
#define VIDEOLOCADORA_CLIENTE_H
#include <iostream>
#include <time.h>

class Cliente{
public:
    std::string nome{};
    int diaNascimento{};
    int mesNascimento{};
    int anoNascimento{};
    std::string sexo{};


    static char opcoesMenuCliente();
    static Cliente cadastrarCliente();
    static void visualizarCliente(const std::list<Cliente>& list);
};


#endif //VIDEOLOCADORA_CLIENTE_H
