//
// Created by Francielxyz on 21/04/2022.
//

#include <iostream>
#include <windows.h>
#include <memory>
#include <algorithm>
#include "Filme.h"
#include "MenuOpcoes.h"

char Filme::opcoesMenuFilme() {
    char opcao;
    while (true) {
        scanf(" %c", &opcao);
        fflush(stdin);
        switch (opcao) {
            case '1': {
                Filme filme = cadastrarFilme();
                listaFilmes.push_back(filme);
                std::cout << "Filme Cadastrado" << std::endl;
                system("cls");
                MenuDefault::menuGenericOpcoes("Filmes");
                break;
            }
            case '2': {
                alterarFilme();
                std::cout << "Filme Alterado" << std::endl;
                system("cls");
                MenuDefault::menuGenericOpcoes("Filmes");
                break;
            }
            case '3': {
                deletarFilme();
                std::cout << "Filme Apagado" << std::endl;
                system("cls");
                MenuDefault::menuGenericOpcoes("Filmes");
                break;
            }
            case '4': {
                visualizarFilme();
                system("cls");
                MenuDefault::menuGenericOpcoes("Filmes");
                break;
            }
            case '5': {
                std::cout << "Voltando ..." << std::endl;
                MenuDefault::menuPrincipal();
                return opcao;
            }
            default: {
                std::cout << "Opcao Invalida !!!! \n\n";
                MenuDefault::menuGenericOpcoes("Filmes");
            }
        }
    }
}

Filme Filme::cadastrarFilme() {
    SYSTEMTIME str_t;
    GetSystemTime(&str_t);
    Filme filme(idCount);
    do {
        std::cout << "Digite Titulo do Filme" << std::endl;
        std::cin >> filme.titulo;
    } while (filme.titulo.length() <= 3);
    do {
        std::cout << "Digite Genero do Filme" << std::endl;
        std::cin >> filme.genero;
    } while (filme.genero.length() <= 0);
    do {
        std::cout << "Digite Valor para Locacao" << std::endl;
        std::cin >> filme.valorLocacao;
    } while (filme.valorLocacao <= 0);

    idCount++;

    return filme;
}

void Filme::visualizarFilme() {
    std::cout << "Lista de Filmes\n" << std::endl;
    for (auto &itemLista: listaFilmes) {
        std::cout << "Id: " << itemLista.id << std::endl;
        std::cout << "Titulo: " << itemLista.titulo << std::endl;
        std::cout << "Genero: " << itemLista.genero << std::endl;
        std::cout << "Valor de Locacao R$ " << itemLista.valorLocacao << std::endl;
        std::cout << "Filme esta Locado? " << std::boolalpha << itemLista.filmeLocado << "\n" << std::endl;
    }
}

void Filme::deletarFilme() {
    visualizarFilme();
    int id;
    std::cout << "Informe o Id do Filme que deseja Apagar" << std::endl;
    std::cin >> id;
    listaFilmes.erase(std::remove(listaFilmes.begin(), listaFilmes.end(), Filme(id)));
}

void Filme::alterarFilme() {
    visualizarFilme();
    int id;

    std::cout << "Informe o Id do Filme que Deseja Alterar" << std::endl;
    std::cin >> id;

    for (auto &itemLista: listaFilmes) {
        if (itemLista.id == id) {
            std::cout << "Digite Titulo do Filme" << std::endl;
            std::cin >> itemLista.titulo;
            std::cout << "Digite Genero do Filme" << std::endl;
            std::cin >> itemLista.genero;
            std::cout << "Digite Valor de Locacao do Filme" << std::endl;
            std::cin >> itemLista.valorLocacao;
        }
    }
}

