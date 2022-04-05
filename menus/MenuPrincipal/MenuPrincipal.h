//
// Created by ibandeir on 05/04/2022.
//

#ifndef VIDEOLOCADORA_MENUPRINCIPAL_H
#define VIDEOLOCADORA_MENUPRINCIPAL_H
using namespace std;
#include <iostream>
#include <cstdlib>
#include "menus/Alterar/Alterar.h"
#include "menus/Deletar/Deletar.h"
#include "menus/Visualizar/Visualizar.h"


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
                    Cadastrar::menuCadastro();
                case '2':
                    Alterar::menuAlterar();
                case '3':
                    Deletar::menuDeletar();
                case '4':
                    Visualizar::menuVisualizar();
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
