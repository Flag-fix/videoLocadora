//
// Created by ibandeir on 05/04/2022.
//

#ifndef VIDEOLOCADORA_MENUPRINCIPAL_H
#define VIDEOLOCADORA_MENUPRINCIPAL_H
using namespace std;
#include <iostream>
#include <cstdlib>
#include <list>
#include "menus/Alterar/Alterar.h"
#include "menus/Deletar/Deletar.h"
#include "menus/Visualizar/Visualizar.h"
#include "/main.cpp"


class MenuPrincipal {


public:

    static void menuPrincipal() {
        cout <<"\n\t************************************** \n ";
        cout <<"\t***  Selecionar uma Opcao do Menu: ***\n";
        cout <<"\t--------------------------------------\n";
        cout <<"\t*********    1 - Cadastrar    ********\n";
        cout <<"\t*********    2 - Alterar      ********\n";
        cout <<"\t*********    3 - Deletar      ********\n";
        cout <<"\t*********    4 - Visualizar   ********\n";
        cout <<"\t*********    5 - Sair         ********\n";
        cout <<"\t--------------------------------------\n";
        cout <<"\t**************************************\n";
    }

    static char opcoes() {
        char opcao;
        int valido = 0;
        while (valido == 0){
            scanf(" %c", &opcao);
            switch (opcao) {
                case '1':
                    system("cls");
                    Cadastrar::menuCadastro();
                    break;
                case '2':
                    system("cls");
                    Alterar::menuAlterar();
                    break;
                case '3':
                    system("cls");
                    Deletar::menuDeletar();
                    break;
                case '4':
                    system("cls");
                    Visualizar::menuVisualizar();
                    break;
                case '5':
                    return opcao;
                default:
                    cout << "Opcao Invalida !!!! \n\n";
                    MenuPrincipal::menuPrincipal();
            }
        }
    }
};


#endif //VIDEOLOCADORA_MENUPRINCIPAL_H
