//
// Created by ibandeir on 17/04/2022.
//

#include <iostream>
#include <windows.h>
#include <memory>
#include <algorithm>
#include "Cliente.h"
#include "MenuOpcoes.h"

char Cliente::opcoesMenuCliente() {
    char opcao;
    while (true) {
        scanf(" %c", &opcao);
        fflush(stdin);
        switch (opcao) {
            case '1': {
                Cliente cli = cadastrarCliente();
                listaClientes.push_back(cli);
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
                std::cout << "Voltando ..." << std::endl;
                MenuDefault::menuPrincipal();
                return opcao;
            }
            default: {
                std::cout << "Opcao Invalida !!!! \n\n";
                MenuDefault::menuGenericOpcoes("Clientes");
            }
        }
    }
}

Cliente Cliente::cadastrarCliente() {
    SYSTEMTIME str_t;
    GetSystemTime(&str_t);
    Cliente cliente(idCount);
    do {
        std::cout << "Digite Nome do Cliente" << std::endl;
        std::cin >> cliente.nome;
    } while (cliente.nome.length() <= 3);
    do {
        std::cout << "Digite Idade do Cliente" << std::endl;
        std::cin >> cliente.idade;
    } while (cliente.nome.length() <= 0);
    do {
        std::cout << "Digite dia Nascimento" << std::endl;
        std::cin >> cliente.diaNascimento;
    } while (cliente.diaNascimento <= 0 || cliente.diaNascimento > 31);
    do {
        std::cout << "Digite mes Nascimento" << std::endl;
        std::cin >> cliente.mesNascimento;
    } while (cliente.mesNascimento <= 0 || cliente.mesNascimento > 12);
    do {
        std::cout << "Digite ano Nascimento" << std::endl;
        std::cin >> cliente.anoNascimento;
    } while (cliente.anoNascimento < 1900 || cliente.anoNascimento > str_t.wYear);
    do {
        std::cout << "Digite o Sexo - F ou M" << std::endl;
        std::cin >> cliente.sexo;
    } while (cliente.sexo.length() >= 2);

    idCount++;

    return cliente;
}

void Cliente::visualizarCliente() {
    std::cout << "Lista de Clientes\n" << std::endl;
    for (auto &itemLista: listaClientes) {
        std::cout << "Id: " << itemLista.id << std::endl;
        std::cout << "Nome: " << itemLista.nome << std::endl;
        std::cout << "Idade: " << itemLista.idade << std::endl;
        std::cout << "Data de Nascimento: " << itemLista.diaNascimento << "/" << itemLista.mesNascimento << "/"
                  << itemLista.anoNascimento << std::endl;
        std::cout << "Sexo: " << itemLista.sexo << "\n" << std::endl;
    }
}

void Cliente::deletarCliente() {
    visualizarCliente();
    int id;
    std::cout << "Informe o id do Cliente que deseja Apagar" << std::endl;
    std::cin >> id;
    listaClientes.erase(std::remove(listaClientes.begin(), listaClientes.end(), Cliente(id)));
}

void Cliente::alterarCliente() {
    visualizarCliente();
    int id;

    std::cout << "Informe o Id do Cliente que deseja alterar" << std::endl;
    cin >> id;

    for (auto &itemLista: listaClientes) {
        if (itemLista.id == id) {
            std::cout << "Digite Nome do Cliente" << std::endl;
            std::cin >> itemLista.nome;
            std::cout << "Digite Idade do Cliente" << std::endl;
            std::cin >> itemLista.idade;
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

Cliente *Cliente::getClienteById() {
    int id;
    std::cout << "Selecione o Id do Cliente: " << std::endl;
    std::cin >> id;

    return getClienteById(id);
}

Cliente *Cliente::getClienteById(int id) {
    std::list<Cliente>::iterator it;
    it = std::find(listaClientes.begin(), listaClientes.end(), Cliente(id));
    if (it != listaClientes.end())
        return &*it;
    else
        throw std::invalid_argument( "Cliente não encontrado." );
}

std::string Cliente::getNomeCliente() {
    return nome;
}

