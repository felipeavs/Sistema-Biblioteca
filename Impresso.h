//
// Created by felip on 17/10/2018.
//

#ifndef TP1_POO_IMPRESSO_H
#define TP1_POO_IMPRESSO_H

#include "Livro.h"
#include <typeinfo>


class Impresso: public Livro {

private:
    vector <string> Livrarias;
    int colunas;

public:

    Impresso(vector <string>, string, vector <string>, int, string, vector <string>, vector <string>, int );
    Impresso();
    virtual~Impresso();

    //Livrarias
    void setLivrarias(vector <string> Livrarias);
    vector <string> getLivrarias()const ;

    //Colunas
    void setColunas(int Colunas);
    int getColunas()const ;

    void imprimirLivroImpresso();
    friend ostream&operator<<(ostream& out, const Impresso&);

    list <Impresso*> retornaColecaoPorLivraria(list <Livro*>, int);


};


#endif //TP1_POO_IMPRESSO_H
