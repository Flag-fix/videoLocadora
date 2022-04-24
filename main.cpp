//
// Created by ibandeir on 05/04/2022.
//

#include <iostream>
#include <list>
#include "Cliente.h"
#include "Filme.h"
#include "MenuPrincipal.h"
#include "MenuOpcoes.h"
#include "Locado.h"

std::list<Cliente> listaClientes;
std::list<Filme> listaFilmes;
std::list<Locado> listaLocados;
double faturamento = 0.0;
int idCount = 1;

int main() {
    char op;
    MenuDefault::menuPrincipal();
    op = MenuPrincipal::opcoes();
    cout <<"Você selecionou Opção de FIM DO SISTEMA : " << op;
    return 0;
}


