#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Pokemon {
protected:

    //Criar vetor...
    string nome, descricao;

    //Pokemon * Pokemons
    //RegiaoPokemon * regiao;

public:

    Pokemon(string nome, string descricao){
        cout << "Catalogando..." << endl;
        this->nome = nome;
        this->descricao = descricao;
        
        //regiao = new RegiaoPokemon[];
        
    };

    ~Pokemon(){
        //delete[] regiao;
    };

    //GETTERS
    string getNome(){
        return this->nome;
    }
    string getDescricao(){
        return this->descricao;
    }
    
    //SETTERS
    void setNome(string novonome){
        this->nome = novonome;
    }
    void setDescricao(string novadescricao){
        this->descricao = novadescricao;
    }

};

