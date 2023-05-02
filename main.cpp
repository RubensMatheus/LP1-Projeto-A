#include <iostream>
#include "funcoes.hpp"

using namespace std;

int main(){

    carregarValoresOnibus();

    int acesso, funcao;
    string senha;

    cout << "Digite a forma de acesso ao sistema:" << endl;
    cout << "1 - Cliente" << endl;
    cout << "2 - Administrador" << endl;

    cin >> acesso;
    if (acesso == 2){
        cout << "Informe a senha para acessar o sistema:" << endl;
        cin >> senha;
        if (senha == "admin"){
            cout << "\nSenha correta, pode proseguir\n";
        }else{
            cout << "Infelizmente a senha incorreta!\nPrograma encerrado";
        }
    }

    while (acesso == 1)
    {
        cout << "\nO que deseja fazer?\n" << endl;
        cout << "1 - Listar os ônibus cadastrados (nome da linha e bairro)\n";
        cout << "2 - Buscar um ônibus por seu bairro (terminal)\n";
        cout << "3 - Ver o itinerário de um ônibus (buscando pelo nome da linha)\n";
        cout << "4 - Fazer uma reclamação (anônima)\n";
        cout << "0 - Encerrar o sistema\n";

        cin >> funcao;
        cout << "\n";

        switch (funcao)
        {
        case 1:
            listar();
            break;
        case 2:
            buscarPorBairro();
            break;
        case 3:
            verItinerario();
            break;
        case 4:
            adicionaReclamacao();
            break;
        case 0:
            acesso = 3;
            break;
        default:
            break;
        }
    }

    while (acesso == 2)
    {
        cout << "\nO que deseja fazer?\n" << endl;
        cout << "1 - Listar todos os ônibus cadastrados\n";
        cout << "2 - Buscar um ônibus por seu nome\n";
        cout << "3 - Buscar um ônibus por seu bairro (terminal)\n";
        cout << "4 - Atualizar o bairro (terminal) de um determinado ônibus\n";
        cout << "5 - Atualizar o itinerário de um determinado ônibus\n";
        cout << "6 - Excluir um ônibus (buscando pelo nome)\n";
        cout << "7 - Listar reclamações (data e reclamação)\n";
        cout << "0 - Encerrar o sistema\n";

        cin >> funcao;
        cout << "\n";

        switch (funcao)
        {
        case 1:
            listar();
            break;
        case 2:
            buscarPorNome();
            break;
        case 3:
            buscarPorBairro();
            break;
        case 4:
            atualizaBairro();
            break;
        case 5:
            atualizaItinerario();
            break;
        case 6:
            excluirLinha();
            break;
        case 7:
            listarReclamacoes();
            break;
        case 0:
            acesso = 3;
            break;
        default:
            break;
        }
    }

    atualizaValoresOnibus();

    return 0;
}