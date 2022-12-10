#include "RegiaoPokemon.h"

class TipoPokemon : public RegiaoPokemon {
private:
    string tipo;
    int ataque, defesa;
public:

    TipoPokemon(int ataque, int defesa, string tipo ,string regiao, string nome, string descricao) : RegiaoPokemon(regiao, nome, descricao){
        cout << "Atribuindo caracteristicas do Pokemon..." << endl;
        this->ataque = ataque;
        this->defesa = defesa;
        this->tipo = tipo;
    }

    ~TipoPokemon(){
        
    }

    //GETTERS
    int getAtaque(){
        return this->ataque;
    }
    int getDefesa(){
        return this->defesa;
    }
    string getTipo(){
        return this->tipo;
    }

    //SETTERS
    void setAtaque(int novoataque){
        this->ataque = novoataque;
    }
    void setDefesa(int novadefesa){
        this->defesa = novadefesa;
    }
    void setTipo(string novotipo){
        this->tipo = novotipo;
    }
};