//
// Created by felip on 14/10/2018.
//

#include "Livro.h"
#include "iomanip"
#include <ios>
#include <iostream>



Livro::Livro(vector <string> Escritor, string Titulo, vector <string> Capitulos, int Ano, string Idioma, vector <string> Keywords){
    setEscritores(Escritor);
    setTitulo(Titulo);
    setCapitulos(Capitulos);
    setAno(Ano);
    setIdioma(Idioma);
    setKeywords(Keywords);
}
Livro::Livro(){
    setTitulo("");
    setAno(0);
    setIdioma("");

}
Livro::~Livro(){}

//Escritor----------------------------------------------------
void Livro::setEscritores(vector <string> Escritor){
    this -> Escritores = Escritor;
}
vector <string> Livro::getEscritores()const{
    return Escritores;
}

//Titulo------------------------------------------------------
void Livro::setTitulo(string Titulo) {
    this -> Titulo = Titulo;
}
string Livro::getTitulo()const{
    return  Titulo;
}

//Capitulo----------------------------------------------------
void Livro::setCapitulos(vector <string> Capitulos){
    this -> Capitulos = Capitulos;
}
vector <string> Livro::getCapitulos() const{
    return Capitulos;
}

//Ano de publicação-------------------------------------------
void Livro::setAno(int Ano){
    this -> Ano = Ano;
}
int Livro::getAno() const{
    return Ano;
}

//Idioma------------------------------------------------------
void Livro::setIdioma(string Idioma){
    this -> Idioma = Idioma;
}
string Livro::getIdioma() const{
    return Idioma;
}

//Keywords----------------------------------------------------
void Livro::setKeywords(vector <string> keywords){
    this -> Keywords = keywords;
}
vector <string> Livro::getKeywords() const {
    return Keywords;
}

//----------------------------------------------------------------------------------------------------------------------
ostream&operator<<(ostream& out, const Livro& book){

    int  aux = 0;

    for(auto v: book.getTitulo()){
        if(aux == 30)
            break;

        out << v;
        aux ++;
    }
    out << setw(31 - book.getTitulo().length())  << "|";

    string nome = book.getEscritores()[0];

    out << setw(31 - book.getEscritores()[0].length());

    aux = 0;
    for(auto u: nome){
        if(aux == 30)
            break;

        out << u;
        aux ++;
    }

    out << "|";

    aux = 0;
    for(auto v: book.getIdioma()){
        if(aux == 10)
            break;

        out << v;
        aux ++;
    }

    out << setw(11 - book.getIdioma().length()) << "|";

    if(book.getCapitulos().size() > 10) {
        out << setfill(' ') << setw(12) << "0" << book.getCapitulos().size() << "|";
    }
    else{
        out << setfill(' ') << setw(13);
        out << "00" << book.getCapitulos().size() << "|";
    }

    out << setw(13) << "0" << book.getKeywords().size() << "|" << setfill(' ');

    return out;

}
//----------------------------------------------------------------------------------------------------------------------
list <Livro*> Livro::retornaColecaoIdioma(list <Livro*> Livros, string idioma){

    list <Livro*> ColecaoPorIdioma;

    for(auto elem: Livros){
        if(elem->getIdioma() == idioma){
            ColecaoPorIdioma.push_back(elem);
        }
    }
    return ColecaoPorIdioma;
}
//----------------------------------------------------------------------------------------------------------------------
list <Livro*> Livro::retornaColecaoLivrosMesmoNome(list<Livro*> Livros, string Titulo){

    list<Livro*> ColecaoMesmoTitulo;
    for(auto elem: Livros){
        if(elem->getTitulo() == Titulo){
            ColecaoMesmoTitulo.push_back(elem);
        }
    }
    return  ColecaoMesmoTitulo;
}
//----------------------------------------------------------------------------------------------------------------------
set <string> Livro::retornaColecaoKeyWords(list<Livro*> Livro){

    set <string> colecao;
    for(auto elem: Livro){
        for(auto k: elem->getKeywords()){
            colecao.insert(k);
        }
    }

    return colecao;

}
//----------------------------------------------------------------------------------------------------------------------
int Livro::retornaQuantidadeDeLivrosKeywords(list<Livro*> Livro,string key){
    int i = 0;

    for(auto elem: Livro){
        for(auto elem2: elem->getKeywords()){
            if(elem2 == key){
                i++;
            }
        }
    }
    return  i;
}
//----------------------------------------------------------------------------------------------------------------------
bool menorString(Livro* e1, Livro* e2){

    unsigned int i = 0;
    while((i < e1->getEscritores()[i].length()) && (i < e2->getEscritores()[0].length())){
        if(tolower(e1->getEscritores()[0][i]) < tolower(e2->getEscritores()[0][i]))
            return  true;

        else if(tolower(e1->getEscritores()[0][i]) > tolower(e2->getEscritores()[0][i]))
            return false;

        i++;
    }

    return (e1->getEscritores()[i].length() < e2->getEscritores()[i].length());
}

list<Livro*> Livro::retornaPesquisaPorCapitulo(list<Livro*> Livros, int nCapitulo){

    list <Livro*> aux;
    for(auto *elem: Livros){
        if(elem->getCapitulos().size() <= nCapitulo){
            aux.push_back(elem);
        }
    }
    aux.sort(menorString);
    return aux;
}
