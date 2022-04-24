//
// Created by ibandeir on 17/04/2022.
//

#include "Locado.h"
#include "MenuOpcoes.h"
#include <algorithm>

char Locado::opcoesMenuLocado() {
    char opcao;
    while (true) {
        scanf(" %c", &opcao);
        fflush(stdin);
        switch (opcao) {
            case '1': {
                cadastrarLocado();
                system("cls");
                MenuDefault::menuLocado();
                break;
            }
            case '2': {
                devolverLocado();
                system("cls");
                MenuDefault::menuLocado();
                break;
            }
            case '3': {
                visualizarNaoLocados();
                system("cls");
                MenuDefault::menuLocado();
                break;
            }
            case '4': {
                visualizarLocados();
                system("cls");
                MenuDefault::menuLocado();
                break;
            }
            case '5': {
                std::cout << "Faturamento: R$" << faturamento << std::endl;
                system("cls");
                MenuDefault::menuLocado();
                break;
            }
            case '6': {
                std::cout << "Voltando ..." << std::endl;
                MenuDefault::menuPrincipal();
                return opcao;
            }
            default: {
                std::cout << "Opcao Invalida !!!! \n\n";
                MenuDefault::menuLocado();
            }
        }
    }
}

void Locado::cadastrarLocado() {
    try {
        Cliente *cliente;
        Filme *filme;

        Cliente::visualizarCliente();
        cliente =  Cliente::getClienteById();

        // TODO: criar metodo para buscar apenas filmes com atributo filmeLocado = false
        Filme::visualizarFilme();
        filme =  Filme::getFilmeById();

        Locado loc = Locado(filme, cliente);
        listaLocados.push_back(loc);
        std::cout << "Locacao Cadastrada" << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Erro ao cadastrar Locacao: " << e.what() << std::endl;
    }
}

void Locado::devolverLocado() {
    try {
        Cliente *cliente;
        Filme *filme;

        Cliente::visualizarCliente();
        cliente =  Cliente::getClienteById();

        Filme::visualizarFilme();
        filme =  Filme::getFilmeById();

        Locado loc = getLocadoByClienteIdFilmeId(cliente, filme);

        faturamento += loc.valor;
        filme->changeLocadoStatus();
        listaLocados.erase(std::remove(listaLocados.begin(), listaLocados.end(), loc));
        std::cout << "Locacao Devolvida" << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Erro ao devolver Locacao: " << e.what() << std::endl;
    }
}

// TODO: criar metodo para buscar apenas filmes com atributo filmeLocado = false
void Locado::visualizarNaoLocados() {

}

void Locado::visualizarLocados() {
    std::cout << "Lista de Locacoes\n" << std::endl;
    for (auto &itemLista: listaLocados) {
        char* dt = ctime(&itemLista.dataHoraLocacao);

        std::cout << "Cliente: " << itemLista.cliente->getNomeCliente() << std::endl;
        std::cout << "Filme: " << itemLista.filme->getTitulo() << std::endl;
        std::cout << "Data e Hora: " << dt << std::endl;
    }
}

Locado Locado::getLocadoByClienteIdFilmeId(Cliente *cliente, Filme *filme) {
    Locado locado = Locado();
    locado.cliente = cliente;
    locado.filme = filme;

    std::list<Locado>::iterator it;
    it = std::find(listaLocados.begin(), listaLocados.end(), locado);
    if (it != listaLocados.end())
        return *it;
    else
        throw std::invalid_argument( "Locacao não encontrada." );
}
