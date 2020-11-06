//
// Created by felip on 17/10/2018.
//

#include "Impresso.h"
#include "Livro.h"
#include <iostream>

using  namespace std;

Impresso::Impresso(vector<string> Escritores, string Titulo, vector<string> Capitulos, int Ano, string Idioma, vector<string> Keywords, vector<string> Livrarias, int Colunas):
        Livro(Escritores, Titulo, Capitulos, Ano, Idioma, Keywords) {

    setLivrarias(Livrarias);
    setColunas(Colunas);

}

Impresso::Impresso():Livro() {
    setColunas(-1);
}

Impresso::~Impresso() {
    //dtor
}

//Livrarias---------------------------------------------------
void Impresso::setLivrarias(vector <string> Livrarias){
    this -> Livrarias = Livrarias;
}
vector <string> Impresso::getLivrarias() const {
    return Livrarias;
}
//Colunas-----------------------------------------------------
void Impresso::setColunas(int Colunas){
    this -> colunas = Colunas;
}
int Impresso::getColunas() const {
    return colunas;
}
//------------------------------------------------------------
void Impresso::imprimirLivroImpresso(){
    cout << "Dados do Livro" << endl;

    cout << "\nEscritores: ";
    for(int i = 0; i < Escritores.size(); i++){
        cout << Escritores[i] << "/";
    }
    cout << "\nTitulo: " << Titulo;
    cout << "\nCapitulos: ";
    for(int i = 0; i < Capitulos.size(); i++){
        cout << Capitulos[i] << "/";
    }
    cout << "\nAno: " << Ano;
    cout << "\nIdioma: " << Idioma;
    cout << "\nKeywords: ";
    for(int i = 0; i < Keywords.size(); i++){
        cout << Keywords[i] << "/";
    }
    cout << "\nLivraria: ";
    for(int i = 0; i < Livrarias.size(); i++){
        cout << Livrarias[i] << "/";
    }
    cout << "\nColunas: "  << colunas;

}
//----------------------------------------------------------------------------------------------------------------------
//SOBRECARCA DE OPERADORES PARA IMPRIMIR LIVROS IMPRESSOS COM SUAS CARACTERISTICAS ESPECIFICAS E FORMATADO
ostream&operator<<(ostream& out, const Impresso& book) {

    int aux = 0;

    for (auto v: book.getTitulo()) {
        if (aux == 30)
            break;

        out << v;
        aux++;
    }
    out << setw(31 - book.getTitulo().length()) << "|";

    string nome = book.getEscritores()[0];

    out << setw(31 - book.getEscritores()[0].length());

    aux = 0;
    for (auto u: nome) {
        if (aux == 30)
            break;

        out << u;
        aux++;
    }

    out << "|";

    aux = 0;
    for (auto v: book.getIdioma()) {
        if (aux == 10)
            break;

        out << v;
        aux++;
    }

    out << setw(11 - book.getIdioma().length()) << "|";

    if(book.getCapitulos().size() > 10) {
        out << setfill(' ') << setw(12) << "0" << book.getCapitulos().size() << "|";
    }
    else{
        out << setfill(' ') << setw(13);
        out << "00" << book.getCapitulos().size() << "|";
    }

    out << setw(13) << "0" << book.getKeywords().size() << "|" << setfill(' ')
        << setw(9)  << book.getLivrarias()[0] << "|";

    return out;
}
//----------------------------------------------------------------------------------------------------------------------
//FUNCAO QUE RETORNA UMA COLECAO DE LIVROS QUE POSSUEM O MESMO FORMATO
list <Impresso*> Impresso::retornaColecaoPorLivraria(list <Livro*> Livros, int numeroLivrarias){

    list <Impresso*> colecaoPorNumeroLivraria;

    for(auto livro: Livros){
        if (typeid(Impresso).name() == typeid(*livro).name()) {
            Impresso* aux = (Impresso*)livro;

            if (aux->getLivrarias().size() >= numeroLivrarias)
                colecaoPorNumeroLivraria.push_back(aux);
        }
    }

    return colecaoPorNumeroLivraria;
}
//----------------------------------------------------------------------------------------------------------------------
