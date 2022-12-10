#include <iostream>
#include <vector>

#include "TipoPokemon.h"

using namespace std;

vector<TipoPokemon *> Pokedex;
string nome, descricao, regiao, tipo;
int ataque, defesa;

void instancia(string nome, string descricao, string regiao, int ataque, int defesa, string tipo){

    TipoPokemon *Pokemons = new TipoPokemon(ataque, defesa, tipo, regiao, nome, descricao);
    Pokedex.push_back(Pokemons);

    system("cls");
    cout << "Os dados do Pokemon foram cadastrados com sucesso!" << endl;
    cout << "Pokemons catalogados: " << Pokedex.size() << endl;
}

void catalogar(){

    cout << "[Registre seu Pokemon]" << endl;
    cout << "Nome do pokemon: " << endl;
    cin.ignore();
    getline(cin, nome);
    cout << "Descricao do pokemon: " << endl;
    cin.ignore();
    getline(cin, descricao);
    cout << "Regiao do pokemon: " << endl;
    cin.ignore();
    getline(cin, regiao);
    cout << "Tipo do pokemon:" << endl;
    cin.ignore();
    getline(cin, tipo);

    cout << "Ataque do Pokemon: " << endl;
    cin >> ataque;
    cout << "Defesa do Pokemon: " << endl;
    cin >> defesa;

    instancia(nome, descricao, regiao, ataque, defesa, tipo);

}

void visualizar(){

    system("cls");

    int op = -1;
    cout << "Filtrar por\n[1] Nome\n[2] Tipos\n[3] Regiao\n[4] Lendarios" << endl;
    cin >> op;

    if(op == 1){
        string nome;
        cout << "Digite o nome do Pokemon que você deseja vizualizar: " << endl;
        cin >> nome;
        for (int i = 0; i < Pokedex.size(); i++){
            if(nome == Pokedex[i]->getNome()){
                cout << "[Resultado]" << endl;
                cout << "Nome: " << Pokedex[i]->getNome() << endl;
                cout << "Descricao: " << Pokedex[i]->getDescricao() << endl;
            }
        }
    }else if(op == 2){
        string tipo;
        cout << "Digite o tipo que será filtrado: " << endl;
        cin >> tipo;
        cout << "[Resultado]" << endl;
        cout << "Estes são os Pokemon do tipo escolhido:" << endl;
        for (int i = 0; i < Pokedex.size(); i++){
            if(tipo == Pokedex[i]->getTipo()){
                cout << "Nome: " << Pokedex[i]->getNome() << endl;
            }
        }

    }else if(op == 3){
        string regiao;
        cout << "Digite a regiao desejada: " << endl;
        cin >> regiao;
        cout << "[Resultado]" << endl;
        cout << "Estes são os Pokemon da Regiao escolhida:" << endl;
        for (int i = 0; i < Pokedex.size(); i++){
            if(regiao == Pokedex[i]->getRegiao()){
                cout << "Nome: " << Pokedex[i]->getRegiao() << endl;
            }
        }
    }else if(op == 4){
        /*int escolha;
        cout << "Voce deseja vizualizar:\n[1] Lendários\n[2]Não-Lendários\n" << endl;
        cin >> escolha;
        for (int i = 0; i < Pokedex.size(); i++){
            if(Pokedex[i]->getLendario()){
                cout << "[Resultado]" << endl;
                cout << "Nome: " << Pokedex[i]->getNome() << endl; */
    }
            
}


void atualizar(){

    cout << "Pesquisar por Pokemon: " << endl;
    cin >> nome;
    for(int i = 0; i < Pokedex.size(); i++){
        if(Pokedex[i]->getNome() == nome){

            //system("cls");
            cout << "[Digite abaixo os novos dados para: " << Pokedex[i]->getNome() << "]" << endl;
            cout << "Nome: " << endl;
            cin >> nome;
            Pokedex[i]->setNome(nome);

            system("cls");
            cout << "Dados atualizados!" << endl;
        }
    }
}

void excluir(){

    cout << "Pesquisar por Pokemon: " << endl;
    cin >> nome;
    for(int i = 0; i < Pokedex.size(); i++){
        if(nome == Pokedex[i]->getNome()){

            Pokedex[i]->~TipoPokemon();
            cout << "Total atual de Pokemons: " << Pokedex.size() << endl;
        }
    }
}

int main(){

    int op = -1;
    while(op == -1){
        cout << "[Pokedex]\n 1 - Catalogar\n 2 - Visualizar\n 3 - Atualizar\n 4 - Excluir\n 0 - Sair" << endl;
        cout << "Digite o numero da opcao: " << endl;
        cin >> op;
    }
    if(op == 1){
        system("cls");
        catalogar();
        main();
    }else if(op == 2){
        system("cls");
        visualizar();
        main();
    }else if(op == 3){
        system("cls");
        atualizar();
        main();
    }else if(op == 4){
        system("cls");
        excluir();
        main();
    }else if(op == 0){
        system("cls");
        cout << "[Programa encerrado!]" << endl;
    }else {
        system("cls");
        cout << "[Funcao Invalida] Tente novamente!" << endl;
        
    }

    return 0;
}
