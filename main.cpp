//
// Created by ibandeir on 05/04/2022.
//


#include <iostream>
#include <list>
#include "menus/Model/Cliente/Cliente.cpp"
#include "menus/Controller/MenuOpcoes/MenuOpcoes.cpp"
#include "menus/Controller/MenuPrincipal/MenuPrincipal.cpp"

void print(std::list<Cliente> list)
{
    for (const auto & itemLista : list)
    {
        std::cout << itemLista.nome << " :: " << itemLista.sexo << std::endl;
    }

}


int main() {
    char op;
    MenuDefault::menuPrincipal();
    op = MenuPrincipal::opcoes();
    cout <<"Você selecionou Opção de FIM DO SISTEMA %c: ", op;
    return 0;
}


