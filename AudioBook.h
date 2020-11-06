//
// Created by felip on 19/10/2018.
//

#ifndef TP1_POO_AUDIOBOOK_H
#define TP1_POO_AUDIOBOOK_H

#include "Livro.h"
#include <iostream>
#include <iomanip>
#include <typeinfo>

class AudioBook: public Livro {

public:
    float Duracao;
    string Formato;

public:
    AudioBook(vector <string>, string, vector <string>, int, string, vector <string>, float, string);
    AudioBook();
    virtual ~AudioBook();

    //Duracao
    void setDuracao(float);
    float getDuracao()const ;

    //Formato
    void setFormato(string);
    string getFormato();

    void imprimirAudioBook();
    friend ostream&operator<<(ostream&, const AudioBook&);

    bool verificaSeContemEscritor(list <Livro*>, string);
};


#endif //TP1_POO_AUDIOBOOK_H
