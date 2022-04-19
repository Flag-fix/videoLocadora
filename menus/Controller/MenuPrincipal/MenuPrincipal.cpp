//
// Created by ibandeir on 17/04/2022.
//

#include "MenuPrincipal.h"
#include <iostream>
#include "menus/Controller/MenuOpcoes/MenuOpcoes.h"
#include "menus/Model/Cliente/Cliente.cpp"


char MenuPrincipal::opcoes() {
    char opcao;
    int valido = 0;
    while (valido == 0){
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
                break;
            case '3':
                system("cls");
                MenuDefault::menuGenericOpcoes("Locados");
                break;
            case '4':
                return opcao;
            default:
                cout << "Opcao Invalida !!!! \n\n";
                MenuDefault::menuPrincipal();
        }
    }
}