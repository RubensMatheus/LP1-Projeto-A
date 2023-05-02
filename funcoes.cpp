#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>
#include <list>
#include <iterator>

using namespace std;

struct onibus
{
    int linha;
    string terminal;
    vector<string> itinerario;
};

map<int, onibus> mapOnibus;

//Faz o carregamento do arquivo txt com os dados dos ônibus
void carregarValoresOnibus()
{   
    fstream arquivoCriar;

    // cria o arquivo onibus.txt caso não exista
    arquivoCriar.open("onibus.txt", ios::out | ios::app);
    arquivoCriar.close();

    // Abre o arquivo onibus.txt para leitura
    fstream arquivoler;
    arquivoler.open("onibus.txt", ios::in);
    string linha;
    vector<string> vetor;

    // Lê todas as linhas do arquivo e salva cada linha em um vector
    while (getline(arquivoler, linha))
    {
        vetor.push_back(linha);
    }
    arquivoler.close(); // fecha o arquivo lido.

    // Transfere as linhas do vector para dentro do map
    for (int i = 0; i < vetor.size(); i += 3)
    {
        // stoi convete uma string para inteiro
        int linhas = stoi(vetor[i]);
        mapOnibus[linhas].linha = linhas;
        mapOnibus[linhas].terminal = vetor[i + 1];
        // usando stringstream e gatline para separar a grande string em partes a partir do iterador '-'
        stringstream ss(vetor[i + 2]);
        string parte;
        while (getline(ss, parte, '-'))
        {
            mapOnibus[linhas].itinerario.push_back(parte);
        }
    }
}

//lista o ônibus por linha e bairro
void listar(){

    for (auto it : mapOnibus) {
        cout << it.first << " - " << it.second.terminal << "\n";
    }
}

//Buscar um ônibus por seu bairro (terminal); 
void buscarPorBairro(){
    string bairro;
    cout << "Digite o bairro do ônibus que deseja pesquisar: ";
    cin >> bairro;
    cout << "\n";
    int a = 0;
    for(auto i : mapOnibus){
        if (i.second.terminal == bairro){
            cout << "ônibus da linha " << i.first << " e bairro " << i.second.terminal << " encontrado com sucesso\n";
            a++;
        }
    }
    if (a == 0){
        cout << "Ônibus não encontrado\n";
    }
}

//Ver o itinerário de um ônibus (buscando pelo nome da linha)
void verItinerario(){
    int linhas;
    cout << "Digite nome do ônibus que deseja pesquisar: ";
    cin >> linhas;
    cout << "\n";
    if (mapOnibus.count(linhas) > 0) {
        auto i = mapOnibus.find(linhas);
        cout << "Onibus da linha" << i->first << " e birro " << i->second.terminal << " encontrado\n";
        cout << "Itinerario:\n" ;
            for(int x = 0; x < i->second.itinerario.size(); x++){
                cout << i->second.itinerario[x] << endl;
            }
    }else{
        cout << "Ônibus não encontrado\n";
    }
}

//Fazer uma reclamação (anônima) - Abertura do arquivo reclamacoes.txt adcionando no final a reclamação
void adicionaReclamacao(){
    string texto, data;
    cout << "Deixe suas reclamações e observações abaixo:\n";

    fstream arquivo;
    arquivo.open("reclamacoes.txt", ios::out | ios::app);
    //o ignore serve pr limpar o buff de entrada 
    cin.ignore(); 
    getline(cin, texto);
    arquivo << texto;
    cout << "\nAgora digite a data de envio no formato DD/MM/AAAA: ";
    getline(cin, data);
    cout << data;
    arquivo << " - " << data << endl;
    arquivo.close();
    cout << "Reclamação enviada com sucesso!\n";
}

void buscarPorNome(){
    int linhas;
    cout << "Digite nome do ônibus para pesquisar: ";
    cin >> linhas;
    cout << "\n";
    if (mapOnibus.count(linhas) > 0) {
        auto i = mapOnibus.find(linhas);
        cout << "Onibus da linha " << i->first << " e bairro " << i->second.terminal << " encontrado com sucesso\n";
        cout << "\n"; 
    }else{
        cout << "Ônibus não encontrado\n";
    }
}

//Atualizar o bairro (terminal) de um determinado ônibus
void atualizaBairro(){
    int linhas;
    cout << "Digite nome do ônibus que deseja atualizar o bairro: ";
    cin >> linhas;
    cout << "\n";
    string novoBairro;
    if (mapOnibus.count(linhas) > 0) {
        auto i = mapOnibus.find(linhas);
        cout << "Digite o novo bairro para a linha " << i->first << endl;
        cin.ignore();
        getline(cin, novoBairro);
        i->second.terminal = novoBairro;
        cout << "\n"; 
    }else{
        cout << "Ônibus não encontrado\n";
    }
}

//Atualizar o itinerário de um determinado ônibus
void atualizaItinerario(){
    int linhas;
    cout << "Digite nome do ônibus que deseja atualizar o itinerario: ";
    cin >> linhas;
    cout << "\n";
    string novoItinerario;
    if (mapOnibus.count(linhas) > 0) {
        auto it = mapOnibus.find(linhas);
        cout << "Digite o novo Itinerario para a linha " << it->first << "separado por '-':\n";
        cin.ignore();
        getline(cin, novoItinerario);
        stringstream ss(novoItinerario);
        string parte;
        mapOnibus[linhas].itinerario.clear();   
        while (getline(ss, parte, '-'))
        {
            mapOnibus[linhas].itinerario.push_back(parte);
        }
        cout << "\n"; 
    }else{
        cout << "Ônibus não encontrado\n";
    }
}

//Excluir um ônibus (buscando pelo nome).
void excluirLinha(){
    int linhas;
    cout << "Digite nome do ônibus que deseja excluir: ";
    cin >> linhas;
    cout << "\n";
    //checa se existe realmente um ônibus com o nome informado, se sim exclui
    if (mapOnibus.count(linhas) > 0) {
        mapOnibus.erase(linhas);
        cout << "Ônibus excluido com sucesso\n";  
    }else{
        cout << "Ônibus não encontrado\n";
    }
}

//Listar reclamações (data e reclamação)
void listarReclamacoes(){
    fstream arquivo;
    arquivo.open("reclamacoes.txt", ios::in);
    string temp;
    list<string> lista;
    while(getline(arquivo, temp)){
        lista.push_back(temp);
    }
    for(auto x : lista){
        cout << x << endl;
    }
}

void atualizaValoresOnibus(){
    fstream arquivo;

    // atualiza o arquivo onibus.txt
    arquivo.open("onibus.txt", ios::out);
    for (auto x : mapOnibus){
        arquivo << x.second.linha << endl;
        arquivo << x.second.terminal << endl;
        for (int i = 0; i < x.second.itinerario.size(); i++)
        {
            if (i == (x.second.itinerario.size()-1))
            {
                arquivo << x.second.itinerario[i] << endl;
            }else{
                arquivo << x.second.itinerario[i] << '-';
            }
        }
    }
    arquivo.close();
}