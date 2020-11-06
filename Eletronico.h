//
// Created by felip on 18/10/2018.
//

#ifndef TP1_POO_ELETRONICO_H
#define TP1_POO_ELETRONICO_H

#include "Livro.h"
#include <typeinfo>
#include <algorithm>
#include <vector>


class Eletronico: public Livro {

private:
    string url;
    string FormatoArq;

public:
    Eletronico(vector <string>, string, vector <string>, int, string, vector <string>, string, string);
    Eletronico();
    virtual ~Eletronico();

    //URL
    void setUrl(string);
    string getUrl()const;

    //Formato do Arquivo
    void setFormatoArq(string);
    string getFormatoArq()const;

    //
    void imprimirLivroEletronico();
    friend ostream&operator<<(ostream&, const Eletronico&);

    list <Eletronico*> retornaColecaoFormato(list <Livro*>, string);


};


#endif //TP1_POO_ELETRONICO_H
