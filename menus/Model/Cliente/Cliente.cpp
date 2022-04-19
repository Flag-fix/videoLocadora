//
// Created by ibandeir on 17/04/2022.
//

#include "Cliente.h"
#include "menus/Controller/MenuOpcoes/MenuOpcoes.h"
#include <iostream>
#include <list>
#include <map>
#include <windows.h>
#include <memory>

extern std::map<std::string, std::unique_ptr<Cliente>> batata;

Cliente Cliente::cadastrarCliente() {
    SYSTEMTIME str_t;
    GetSystemTime(&str_t);
    Cliente cli;
    do {
        std::cout << "Digite Nome do Cliente"<<std::endl;
        std::cin>>cli.nome;
    }while(cli.nome.length() <= 3);
    do{
        std::cout << "Digite dia Nascimento"<<std::endl;
        std::cin>>cli.diaNascimento;
    }while(cli.diaNascimento <= 0 || cli.diaNascimento > 31);
    do{
        std::cout << "Digite mês Nascimento"<<std::endl;
        std::cin>>cli.mesNascimento;
    }while(cli.mesNascimento <= 0 || cli.mesNascimento > 12);
    do{
        std::cout << "Digite ano Nascimento"<<std::endl;
        std::cin>>cli.anoNascimento;
    } while (cli.anoNascimento < 1900 || cli.anoNascimento > str_t.wYear);
    do{
        std::cout << "Digite o Sexo - F ou M"<<std::endl;
        std::cin>>cli.sexo;
    }while(cli.sexo.length() >= 2);

    return cli;
}

void Cliente::visualizarCliente(const std::list<Cliente>& list) {
    std::cout << "Lista de Clientes\n"<<std::endl;
    for (const auto & itemLista : list)
    {
        std::cout << "Nome: "<<itemLista.nome << std::endl;
        std::cout << "Data de Nascimento: "<<itemLista.diaNascimento <<"/"<<itemLista.mesNascimento <<"/"<<itemLista.anoNascimento<< std::endl;
        std::cout << "Sexo: "<<itemLista.sexo << std::endl;
    }
}

char Cliente::opcoesMenuCliente() {
    std::list<Cliente> Listaclientes;
    char opcao;
    int valido = 0;
    while (valido == 0){
        scanf(" %c", &opcao);
        fflush(stdin);
        switch (opcao) {
            case '1':
                system("cls");
                Cliente cli = cadastrarCliente();
                Listaclientes.push_back(cli);
                break;
//            case '2':
//                system("cls");
//                break;
//            case '3':
//                system("cls");
//                break;
//            case '4':
//                return opcao;
//            default:
//                cout << "Opcao Invalida !!!! \n\n";
//                MenuDefault::menuPrincipal();
        }
    }
}

