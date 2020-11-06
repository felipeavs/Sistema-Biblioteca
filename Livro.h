//
// Created by felip on 14/10/2018.
//

#ifndef TP1_POO_LIVRO_H
#define TP1_POO_LIVRO_H

#include <string>
#include <vector>
#include <list>
#include <iomanip>
#include <set>
#include <algorithm>
#include <iterator>
#include <functional>
#include <iostream>
#include <map>
#include <utility>


using namespace std;

class Livro {

protected:

    vector <string> Escritores; //Coleção
    string Titulo;
    vector <string> Capitulos;  //Coleção
    int Ano;
    string Idioma;
    vector <string> Keywords;    //Coleção

public:

    Livro(vector <string>, string, vector <string>, int, string, vector <string>);
    Livro();
    virtual~Livro();

    //Escritor
    void setEscritores(vector <string> Escritores);
    vector <string> getEscritores()const;

    //Titulo
    void setTitulo(string Titulo);
    string getTitulo()const;

    //Capitulo
    void setCapitulos(vector <string> Capitulo);
    vector <string> getCapitulos()const;

    //Ano de publicação
    void setAno(int Ano);
    int getAno()const;

    //Idioma
    void setIdioma(string Idioma);
    string getIdioma()const;

    //Keywords;
    void setKeywords(vector <string> Keywords);
    vector <string> getKeywords()const;
    friend ostream&operator<<(ostream& out, const Livro& );

    //Funçoes do TP
    list <Livro*> retornaColecaoIdioma(list <Livro*>, string);
    list <Livro*> retornaColecaoLivrosMesmoNome(list<Livro*>, string);
    set <string> retornaColecaoKeyWords(list<Livro*>);
    int retornaQuantidadeDeLivrosKeywords(list<Livro*> ,string);
    list<Livro*> retornaPesquisaPorCapitulo(list<Livro*>, int);


};

#endif //TP1_POO_LIVRO_H
