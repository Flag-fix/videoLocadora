//
// Created by ibandeir on 05/04/2022.
//

#include <iostream>
#include <list>
#include "Cliente.h"
#include "Filme.h"
#include "MenuPrincipal.h"
#include "MenuOpcoes.h"

std::list<Cliente> listaClientes;
std::list<Filme> listaFilmes;
int idCount = 1;

int main() {
    char op;
    MenuDefault::menuPrincipal();
    op = MenuPrincipal::opcoes();
    cout <<"Você selecionou Opção de FIM DO SISTEMA %c: ", op;
    return 0;
}


