//
// Created by ibandeir on 05/04/2022.
//


#include <iostream>
#include "menus/Controller/MenuOpcoes/MenuOpcoes.cpp"
#include "menus/Controller/MenuPrincipal/MenuPrincipal.cpp"

int main() {
    char op;
    MenuDefault::menuPrincipal();
    op = MenuPrincipal::opcoes();
    cout <<"Você selecionou Opção de FIM DO SISTEMA %c: ", op;
    return 0;
}


