
// Created by felip on 19/10/2018.
//

#include "AudioBook.h"
#include <iostream>
#include <ios>

using namespace std;

AudioBook::AudioBook(vector <string> Escritores, string Titulo, vector <string> Capitulos, int Ano, string Idioma, vector <string> Keywords, float Duracao, string Formato):
        Livro(Escritores, Titulo, Capitulos, Ano, Idioma, Keywords){

    setDuracao(Duracao);
    setFormato(Formato);

}
AudioBook::AudioBook(){
    setTitulo("");
    setAno(0);
    setIdioma("");
    setDuracao(0.0);
    setFormato("");

}
AudioBook::~AudioBook(){}

//Duracao
void AudioBook::setDuracao(float Duracao){
    this -> Duracao = Duracao;
}
float AudioBook::getDuracao() const{
    return Duracao;
}

//Formato
void AudioBook::setFormato(string Fomrato){
    this -> Formato = Fomrato;
}
string AudioBook::getFormato(){
    return Formato;
}

void AudioBook::imprimirAudioBook(){

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
    cout << "\nDuracao: " << getDuracao();
    cout << "\nFormato de Audio: "  << getFormato();
}
//----------------------------------------------------------------------
ostream&operator<<(ostream& out, const AudioBook& book){

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
        << setw(9) << fixed << setprecision(2) << book.getDuracao() << "|";

    return out;

}

//----------------------------------------------------------------------------------------------------------------------
bool AudioBook::verificaSeContemEscritor(list <Livro*> Livros, string nomeEscritor){

    for(auto livro: Livros){
        if (typeid(AudioBook).name() == typeid(*livro).name()){
            for (auto escritor: livro->getEscritores()){
                if (escritor == nomeEscritor){
                    return true;
                }
            }
        }
    }
    return false;
}
//----------------------------------------------------------------------------------------------------------------------