#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Pokemon {
protected:
    string nome, descricao;
    //Criar um vetor 
public:

    Pokemon(string nome, string descricao){
        cout << "Catalogando..." << endl;
        this->nome = nome;
        this->descricao = descricao;
        
        //Alocar dados no vetor
        
    };

    ~Pokemon(){
        //Delete p/ o vetor - delete [] nomeDoVetor
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

