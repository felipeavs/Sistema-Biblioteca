//
// Created by felip on 18/10/2018.
//

#include "Eletronico.h"
#include "Livro.h"
#include <iostream>
#include "cctype"

using namespace std;

Eletronico::Eletronico(vector <string> Escritores, string Titulo, vector <string> Capitulos, int Ano, string Idioma, vector <string> Keywords, string URL, string FormatoArq):
        Livro(Escritores, Titulo, Capitulos, Ano, Idioma, Keywords){

    setUrl(URL);
    setFormatoArq(FormatoArq);
}

Eletronico::Eletronico(){
    setUrl("");
    setFormatoArq("");
}
Eletronico::~Eletronico(){}

//URL
void Eletronico::setUrl(string URL){
    this -> url = URL;
}
string Eletronico::getUrl()const{
    return url;
}

//Formato do Arquivo
void Eletronico::setFormatoArq(string FormatoArq){
    this -> FormatoArq = FormatoArq;
}
string Eletronico::getFormatoArq()const{
    return FormatoArq;
}

void Eletronico::imprimirLivroEletronico(){

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
    cout << "\nUrl: " << getUrl();
    cout << "\nFormato de Arquivo: "  << getFormatoArq();


}
//----------------------------------------------------------------------------------------------------------------------
//SOBRECARCA DE OPERADORES PARA IMPRIMIR LIVROS ELETRONICOS COM SUAS CARACTERISTICAS ESPECIFICAS E FORMATADO
ostream&operator<<(ostream& out, const Eletronico& book){

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

    out << setw(13) << "0" << book.getKeywords().size() << "|" << setfill(' ')
        << setw(9) << book.getFormatoArq() << "|";

    return out;

}
//----------------------------------------------------------------------------------------------------------------------
//FUNCAO QUE RETORNA UMA COLECAO DE LIVROS QUE POSSUEM O MESMO FORMATO ORDENADA PELO ANO
bool menorAno(Eletronico* e1, Eletronico* e2){
    return (e1->getAno() < e2->getAno());
}

list <Eletronico*> Eletronico::retornaColecaoFormato(list <Livro*> Livros, string formato){

    list <Eletronico*> mesmoFormato;

    for(auto LivroEletronico: Livros){
        if (typeid(Eletronico).name() == typeid(*LivroEletronico).name()) {
            Eletronico* aux = (Eletronico* )LivroEletronico;

            if (aux->getFormatoArq() == formato)
                mesmoFormato.push_back(aux);
        }
    }

    mesmoFormato.sort(menorAno);

    return mesmoFormato;
}
//----------------------------------------------------------------------------------------------------------------------
