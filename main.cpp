//
// Created by ibandeir on 05/04/2022.
//

#include "menus/Cadastro/Cadastrar.h"
#include "menus/MenuPrincipal/MenuPrincipal.h"
extern list<string> filmes;
extern list<string> pessoa;
extern list<string> movimentacao;

int main() {
    char op;
    MenuPrincipal::menuPrincipal();
    op = MenuPrincipal::opcoes();
    cout <<"Você selecionou Opção de FIM DO SISTEMA %c: ", op;
    return 0;
}
