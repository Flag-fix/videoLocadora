//
// Created by ibandeir on 17/04/2022.
//

#include "MenuPrincipal.h"
#include <iostream>
#include "MenuOpcoes.h"
#include "Cliente.h"
#include "Filme.h"
#include "Locado.h"

char MenuPrincipal::opcoes() {
    char opcao;
    while (true){
        scanf(" %c", &opcao);
        fflush(stdin);
        switch (opcao) {
            case '1':
                system("cls");
                MenuDefault::menuGenericOpcoes("Clientes");
                opcao = Cliente::opcoesMenuCliente();
                break;
            case '2':
                system("cls");
                MenuDefault::menuGenericOpcoes("Filmes");
                opcao = Filme::opcoesMenuFilme();
                break;
            case '3':
                system("cls");
                MenuDefault::menuLocado();
                opcao = Locado::opcoesMenuLocado();
                break;
            case '4':
                return opcao;
            default:
                cout << "Opcao Invalida !!!! \n\n";
                MenuDefault::menuPrincipal();
        }
    }
}