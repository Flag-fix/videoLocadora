//
// Created by ibandeir on 05/04/2022.
//

#ifndef VIDEOLOCADORA_CADASTRAR_H
#define VIDEOLOCADORA_CADASTRAR_H

using namespace std;
#include <iostream>

class Cadastrar{


public:
    static void menuCadastro() {
        cout <<"\n\t************************************** \n ";
        cout <<"\t*********    Menu Cadastrar:  *********\n";
        cout <<"\t--------------------------------------\n";
        cout <<"\t*********    1 - Cadastrar Filme ******\n";
        cout <<"\t*********    2 - Alterar Filme   ******\n";
        cout <<"\t*********    3 - Deletar  Filme  ******\n";
        cout <<"\t*********    4 - Visualizar Filme *****\n";
        cout <<"\t*********    5 - Sair            ******\n";
        cout <<"\t--------------------------------------\n";
        cout <<"\t**************************************\n ";
    }
};

#endif //VIDEOLOCADORA_CADASTRAR_H
