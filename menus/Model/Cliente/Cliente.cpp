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
#include <algorithm>

extern std::map<std::string, std::unique_ptr<Cliente>> batata;

char Cliente::opcoesMenuCliente() {
    std::list<Cliente> Listaclientes;
    char opcao;
    int valido = 0;
    while (valido == 0){
        scanf(" %c", &opcao);
        fflush(stdin);
        switch (opcao) {
            case '1':{
                Cliente cli = cadastrarCliente();
                Listaclientes.push_back(cli);
                std::cout << "Cliente Cadastrado"<<std::endl;
                system("cls");
                MenuDefault::menuGenericOpcoes("Clientes");
                break;
            }
            case '2':{
                alterarCliente(Listaclientes);
                std::cout << "Cliente Alterado"<<std::endl;
                system("cls");
                MenuDefault::menuGenericOpcoes("Clientes");
                break;
            }
            case '3':{
                deletarCliente(Listaclientes);
                std::cout << "Cliente Apagado"<<std::endl;
                system("cls");
                MenuDefault::menuGenericOpcoes("Clientes");
                break;
            }
            case '4':{
                std::cout << "Saindo ..."<<std::endl;
                return opcao;
            }
            default:{
                cout << "Opcao Invalida !!!! \n\n";
                MenuDefault::menuPrincipal();
            }
        }
    }
}

Cliente Cliente::cadastrarCliente() {
    SYSTEMTIME str_t;
    GetSystemTime(&str_t);
    Cliente cli = Cliente(1);
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

void Cliente::deletarCliente(std::list<Cliente>& list) {
    visualizarCliente(list);
    int id;
    std::cout << "Informe o Nome do Cliente que deseja Apagar"<<std::endl;
    std::cin>>id;
    list.erase(std::remove(list.begin(),list.end(), Cliente(id)));
}

void Cliente::alterarCliente(const std::list<Cliente>& list) {
    visualizarCliente(list);
    std::string nomeCLiente;
    std::cout << "Informe o Nome do Cliente que deseja alterar"<<std::endl;
    for (const auto & itemLista : list)
    {
        if(itemLista.nome == nomeCLiente){
            Cliente cli;
                std::cout << "Digite Nome do Cliente"<<std::endl;
                std::cin>>itemLista.nome;
                std::cout << "Digite dia Nascimento"<<std::endl;
                std::cin>>itemLista.diaNascimento;
                std::cout << "Digite mês Nascimento"<<std::endl;
                std::cin>>itemLista.mesNascimento;
                std::cout << "Digite ano Nascimento"<<std::endl;
                std::cin>>itemLista.anoNascimento;
                std::cout << "Digite o Sexo - F ou M"<<std::endl;
                std::cin>>itemLista.sexo;
        }
    }
}

