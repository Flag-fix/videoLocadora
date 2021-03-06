//
// Created by ibandeir on 05/04/2022.
//

#include "MenuOpcoes.h"

void MenuDefault::menuPrincipal() {
    cout <<"\n\t************************************** \n";
    cout <<"\t***  Selecionar uma Opcao do Menu: ***\n";
    cout <<"\t--------------------------------------\n";
    cout <<"\t*********    1 - Clientes     ********\n";
    cout <<"\t*********    2 - Filmes       ********\n";
    cout <<"\t*********    3 - Locados      ********\n";
    cout <<"\t*********    4 - Sair         ********\n";
    cout <<"\t--------------------------------------\n";
    cout <<"\t**************************************\n"<< std::endl;
}

void MenuDefault::menuGenericOpcoes(const string& nomeTipoMenu) {
    cout <<"\n\t************************************** \n ";
    cout <<"\t*********    Menu "+nomeTipoMenu+":  *********\n";
    cout <<"\t--------------------------------------\n";
    cout <<"\t*********    1 - Cadastrar "+nomeTipoMenu+" ******\n";
    cout <<"\t*********    2 - Alterar "+nomeTipoMenu+"   ******\n";
    cout <<"\t*********    3 - Deletar  "+nomeTipoMenu+"  ******\n";
    cout <<"\t*********    4 - Visualizar "+nomeTipoMenu+" *****\n";
    cout <<"\t*********    5 - Voltar             ******\n";
    cout <<"\t--------------------------------------\n";
    cout <<"\t**************************************\n "<< std::endl;
}

void MenuDefault::menuLocado() {
    cout <<"\n\t********************************************\n";
    cout <<"\t*********     Menu Locado:           *********\n";
    cout <<"\t----------------------------------------------\n";
    cout <<"\t*********    1 - Cadastrar Locado       ******\n";
    cout <<"\t*********    2 - Devolver Locado        ******\n";
    cout <<"\t*********    3 - Visualizar Nao Locado  ******\n";
    cout <<"\t*********    4 - Visualizar Locado      ******\n";
    cout <<"\t*********    5 - Mostrar Faturamento    ******\n";
    cout <<"\t*********    6 - Voltar                 ******\n";
    cout <<"\t----------------------------------------------\n";
    cout <<"\t**********************************************\n "<< std::endl;
}
