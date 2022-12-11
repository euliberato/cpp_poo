#include <iostream>
#include <vector>

#include "TipoPokemon.h"

using namespace std;

vector<TipoPokemon *> Pokedex;
string nome, descricao, regiao, tipo;
int ataque, defesa;
bool raridade;

void instancia(bool raridade, string nome, string descricao, string regiao, int ataque, int defesa, string tipo){

    TipoPokemon *Pokemons = new TipoPokemon(raridade, ataque, defesa, tipo, regiao, nome, descricao);
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
    cout << "Esse Pokemon e Lendario:\n0 - Para Nao\n1 - Para Sim" << endl;
    cin >> raridade;

    cout << "Ataque do Pokemon: " << endl;
    cin >> ataque;
    cout << "Defesa do Pokemon: " << endl;
    cin >> defesa;

    instancia(raridade, nome, descricao, regiao, ataque, defesa, tipo);

}

void visualizar(){

    system("cls");

    int op = -1;
    cout << "Filtrar por\n[1] Nome\n[2] Tipos\n[3] Regiao\n[4] Lendarios" << endl;
    cin >> op;

    if(op == 1){
        string nome;
        cout << "Digite o nome do Pokemon que voce deseja visualizar: " << endl;
        cin >> nome;
        for (int i = 0; i < Pokedex.size(); i++){
            if(nome == Pokedex[i]->getNome()){
                cout << "Nome: " << Pokedex[i]->getNome() << endl;
                cout << "Descricao: " << Pokedex[i]->getDescricao() << endl;
                cout << "Regiao: " << Pokedex[i]->getRegiao() << endl;
                cout << "Tipo: " << Pokedex[i]->getTipo() << endl;
                cout << "Lendario: " << Pokedex[i]->getRaridade() << endl;
                cout << "Ataque: " << Pokedex[i]->getAtaque() << endl;
                cout << "Defesa: " << Pokedex[i]->getDefesa() << endl;
            }
        }
    }else if(op == 2){
        string tipo;
        cout << "Digite o tipo que sera filtrado: " << endl;
        cin >> tipo;
        cout << "[Resultado]" << endl;
        cout << "Estes sao os Pokemons do tipo: " << tipo << endl;
        for (int i = 0; i < Pokedex.size(); i++){
            if(tipo == Pokedex[i]->getTipo()){
                cout << "Nome: " << Pokedex[i]->getNome() << endl;
            }
        }

    }else if(op == 3){
        system("cls");
        string regiao;
        cout << "Digite a regiao desejada: " << endl;
        cin >> regiao;
        cout << "[Resultado]" << endl;
        cout << "Estes sao os Pokemons da regiao: "<< regiao << endl;
        for (int i = 0; i < Pokedex.size(); i++){
            if(regiao == Pokedex[i]->getRegiao()){
                cout << "Nome: " << Pokedex[i]->getNome() << endl;
            }
        }
    }else if(op == 4){
        system("cls");
        int op = -1;
        cout << "Listar Lendarios ou Comuns:\n[1] Lendarios\n[2] Comuns" << endl;
        cin >> op;
        if(op == 1){
            for (int i = 0; i < Pokedex.size(); i++){
                if(Pokedex[i]->getRaridade() == false){
                    cout << "Nome: " << Pokedex[i]->getNome() << endl;
                }
            }
        }else if(op == 2){
            for (int i = 0; i < Pokedex.size(); i++){
                if(Pokedex[i]->getRaridade() == true){
                    cout << "Nome: " << Pokedex[i]->getNome() << endl;
                }
            }
        }
    }
            
}


void atualizar(){

    cout << "Pesquisar por Pokemon: " << endl;
    cin >> nome;

    int at = -1;
    cout << "Selecione a informacao para atualizar de " << nome << ":\n[1] Nome\n[2] Descricao\n[3] Regiao\n[4] Ataque\n[5] Defesa" << endl;
    cin >> at;

    if(at == 1){
        for(int i = 0; i < Pokedex.size(); i++){
            if(Pokedex[i]->getNome() == nome){
                cout << "Digite o novo nome: " << endl;
                cin >> nome;
                Pokedex[i]->setNome(nome);
            }
        }
    }else if(at == 2){
        for(int i = 0; i < Pokedex.size(); i++){
            if(Pokedex[i]->getNome() == nome){
                cout << "Digite a nova descricao: " << endl;
                cin >> descricao;
                Pokedex[i]->setDescricao(descricao);
            }
        }
    }else if(at == 3){
        for(int i = 0; i < Pokedex.size(); i++){
            if(Pokedex[i]->getNome() == nome){
                cout << "Digite a nova regiao: " << endl;
                cin >> descricao;
                Pokedex[i]->setRegiao(regiao);
            }
        }
    }else if(at == 4){
        for(int i = 0; i < Pokedex.size(); i++){
            if(Pokedex[i]->getNome() == nome){
                cout << "Digite a nova quantidade de ataque: " << endl;
                cin >> ataque;
                Pokedex[i]->setAtaque(ataque);
            }
        }
    }else if(at == 5){
        for(int i = 0; i < Pokedex.size(); i++){
            if(Pokedex[i]->getNome() == nome){
                cout << "Digite a nova quantidade de defesa: " << endl;
                cin >> defesa;
                Pokedex[i]->setDefesa(defesa);
            }
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
        main();
    }

    return 0;
}
