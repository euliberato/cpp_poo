#include "Pokemon.h"

class RegiaoPokemon : public Pokemon {
protected:
    string regiao;
    //vector<TipoFogo *> PokeFogo;
public:

    RegiaoPokemon(string regiao, string nome, string descricao) : Pokemon(nome, descricao){
        cout << "Atribuindo Regiao..." << endl;
        this->regiao = regiao;
    }

    ~RegiaoPokemon(){
        
    }

    //GETTERS
    string getRegiao(){
        return this->regiao;
    }

    //SETTERS
    void setRegiao(string novaregiao){
        this->regiao = novaregiao;
    }

};