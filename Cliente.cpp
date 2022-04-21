//
// Created by ibandeir on 17/04/2022.
//

#include <iostream>
#include <list>
#include <windows.h>
#include <memory>
#include <algorithm>
#include "Cliente.h"
#include "MenuOpcoes.h"

char Cliente::opcoesMenuCliente() {
    std::list<Cliente> Listaclientes;
    char opcao;
    while (true) {
        scanf(" %c", &opcao);
        fflush(stdin);
        switch (opcao) {
            case '1': {
                Cliente cli = cadastrarCliente();
                Listaclientes.push_back(cli);
                std::cout << "Cliente Cadastrado" << std::endl;
                system("cls");
                MenuDefault::menuGenericOpcoes("Clientes");
                break;
            }
            case '2': {
                alterarCliente();
                std::cout << "Cliente Alterado" << std::endl;
                system("cls");
                MenuDefault::menuGenericOpcoes("Clientes");
                break;
            }
            case '3': {
                deletarCliente();
                std::cout << "Cliente Apagado" << std::endl;
                system("cls");
                MenuDefault::menuGenericOpcoes("Clientes");
                break;
            }
            case '4': {
                visualizarCliente();
                system("cls");
                MenuDefault::menuGenericOpcoes("Clientes");
                break;
            }
            case '5': {
                std::cout << "Saindo ..." << std::endl;
                return opcao;
            }
            default: {
                cout << "Opcao Invalida !!!! \n\n";
                MenuDefault::menuPrincipal();
            }
        }
    }
}

Cliente Cliente::cadastrarCliente() {
    SYSTEMTIME str_t;
    GetSystemTime(&str_t);
    Cliente cli1 = Cliente(1);
    Cliente cli(1);
    do {
        std::cout << "Digite Nome do Cliente" << std::endl;
        std::cin >> cli.nome;
    } while (cli.nome.length() <= 3);
    do {
        std::cout << "Digite dia Nascimento" << std::endl;
        std::cin >> cli.diaNascimento;
    } while (cli.diaNascimento <= 0 || cli.diaNascimento > 31);
    do {
        std::cout << "Digite mes Nascimento" << std::endl;
        std::cin >> cli.mesNascimento;
    } while (cli.mesNascimento <= 0 || cli.mesNascimento > 12);
    do {
        std::cout << "Digite ano Nascimento" << std::endl;
        std::cin >> cli.anoNascimento;
    } while (cli.anoNascimento < 1900 || cli.anoNascimento > str_t.wYear);
    do {
        std::cout << "Digite o Sexo - F ou M" << std::endl;
        std::cin >> cli.sexo;
    } while (cli.sexo.length() >= 2);

    return cli;
}

void Cliente::visualizarCliente() {
    std::cout << "Lista de Clientes\n" << std::endl;
    for (auto &itemLista: listaClientes) {
        std::cout << "Nome: " << itemLista.nome << std::endl;
        std::cout << "Data de Nascimento: " << itemLista.diaNascimento << "/" << itemLista.mesNascimento << "/"
                  << itemLista.anoNascimento << std::endl;
        std::cout << "Sexo: " << itemLista.sexo << std::endl;
    }
}

void Cliente::deletarCliente() {
    visualizarCliente();
    int id;
    std::cout << "Informe o Nome do Cliente que deseja Apagar" << std::endl;
    std::cin >> id;
    listaClientes.erase(std::remove(listaClientes.begin(), listaClientes.end(), Cliente(id)));
}

void Cliente::alterarCliente() {
    visualizarCliente();
    std::string nomeCLiente;
    std::cout << "Informe o Nome do Cliente que deseja alterar" << std::endl;
    for (auto &itemLista: listaClientes) {
        if (itemLista.nome == nomeCLiente) {
            std::cout << "Digite Nome do Cliente" << std::endl;
            std::cin >> itemLista.nome;
            std::cout << "Digite dia Nascimento" << std::endl;
            std::cin >> itemLista.diaNascimento;
            std::cout << "Digite mês Nascimento" << std::endl;
            std::cin >> itemLista.mesNascimento;
            std::cout << "Digite ano Nascimento" << std::endl;
            std::cin >> itemLista.anoNascimento;
            std::cout << "Digite o Sexo - F ou M" << std::endl;
            std::cin >> itemLista.sexo;
        }
    }
}

