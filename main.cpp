#define __USE_MINGW_ANSI_STDIO 0 
#include <iostream>
#include "Livro.h"
#include "Impresso.h"
#include "Eletronico.h"
#include "AudioBook.h"
#include <string>
#include <list>
#include <vector>
#include <typeinfo>
#include <fstream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <set>
#include <functional>
#include <map>
#include <utility>
#include <cctype>



using namespace std;

typedef map<string, Livro*> mapType;
typedef multimap<string,Livro*> MultiMapTaype;

MultiMapTaype mapeamentoPorIdioma(list<Livro*> Livros);

vector<string> split(const string& str, char delim = ';'){


    vector<string> vetor;
    stringstream ss(str);
    string token;
    while(getline(ss,token,delim))
        vetor.push_back(token);

    return vetor;
}

int main() {


    int flag;
    Impresso *bookImpresso;
    Eletronico *bookEletronico;
    AudioBook *bookAudio;

    //Atributos de Livros
    vector <string> Escritores;
    string titulo;
    vector <string> Capitulos;
    int Ano;
    string Idioma;
    vector <string> keywords;

    //Atributos de Impresso
    vector <string> Livrarias;
    int Colunas;

    //Atributors de Eletronico
    string url;
    string formato;

    //Atributos de Audio Book
    float duracao;
    string formatoAudio;

    list <Livro*> Biblioteca;



    //------------------------------------------------------------------------------------------------------------------
    //LEITURA DOS DADOS DOS ARQUIVOS

    string FLAG;
    string TITULO;
    string ESCRITOR;
    string ANO;
    string IDIOMA;
    string KEYWORD;
    string CAPITULO;

    string LIVRARIA, COLUNA;
    string URL, FORMATO_ARQUIVO;
    string DURACAO, FORMATO_AUDIO;

    ifstream arquivo;
    string nameFile;
    string Diretorio;
    Diretorio = "Livros/";

    for(int i = 1; i <=16; i++){

        nameFile = Diretorio + to_string(i) + ".txt";

        arquivo.open(nameFile, ios::in);

        if(!arquivo){
            cout << "\nErro ao abrir o arquivo" << endl;
            exit(1);
        }

        getline(arquivo,FLAG);
        flag = stoi(FLAG);

        getline(arquivo,TITULO);
        getline(arquivo,ESCRITOR);
        getline(arquivo,ANO);
        getline(arquivo,IDIOMA);
        getline(arquivo,KEYWORD);
        getline(arquivo,CAPITULO);

        titulo = TITULO;//............................RECEBE NOME DO LIVRO
        Escritores = split(ESCRITOR, ';');//...........RECEBE VETOR DE ESCRITORES
        Ano = stoi(ANO);//............................RECEBE ANO DE PUBLICACAO
        Idioma = IDIOMA;//............................RECEBE IDIOMA
        keywords = split(KEYWORD, ';');//..............RECEBE VETOR DE KEYWORDS
        Capitulos = split(CAPITULO,';');//..............RECEBE VETOR DE CAPITULOS

        if(flag == 1){
            getline(arquivo, LIVRARIA);
            Livrarias = split(LIVRARIA, ';');//........RECEBE VETOR DE LIVRARIAS
            getline(arquivo,COLUNA);
            Colunas = stoi(COLUNA);//.................RECEBE NUMERO DE COLUNAS

            bookImpresso = new Impresso(Escritores,titulo, Capitulos, Ano, Idioma, keywords, Livrarias,Colunas);
            Biblioteca.push_back(bookImpresso);
        }
        else if(flag == 2){
            getline(arquivo, URL);
            url = URL;//..............................RECEBE URL
            getline(arquivo,FORMATO_ARQUIVO);
            formato = FORMATO_ARQUIVO;//..............RECEBE FORMATO DE ARQUIVO

            bookEletronico = new Eletronico(Escritores, titulo, Capitulos, Ano, Idioma, keywords, url, formato);
            Biblioteca.push_back(bookEletronico);
        }
        else if(flag == 3){
            getline(arquivo, DURACAO);
            duracao = stof(DURACAO);//................RECEBE DURACAO
            getline(arquivo,FORMATO_AUDIO);
            formatoAudio = FORMATO_AUDIO;//...........RECEBE FORMATO DE AUDIO

            bookAudio = new AudioBook(Escritores, titulo, Capitulos, Ano, Idioma, keywords, duracao, formatoAudio);
            Biblioteca.push_back(bookAudio);
        }

        arquivo.close();


    }

    cout << "\nLivros Carregados!" << endl;

    //------------------------------------------------------------------------------------------------------------------

    //PROGRAMA

    int menu;
    list <Livro*> colecaoLivros;
    list <Eletronico*> colecaoEletronico;
    list <Impresso*> colecaoImpresso;
    set <string> colecaoKeywords;

    mapType mapCapitulo;

    //Variaveis Auxiliares;
    Livro aux;
    Eletronico auxEletronico;
    Impresso auxImpresso;
    AudioBook auxAudioBook;
    string idiomaAux;
    string formatoAux;
    string escritorAux;
    string tituloAux;
    string auxKeyword;
    string auxIdioma;
    int nCapitulos;
    int nLivrarias;


    do {
        cout << "\nSistema de Biblioteca" << endl;
        cout << "MENU" << endl;
        cout << "(1)  Imprimir todos os livros do vetor " << endl;
        cout << "(2)  Pesquisar por Idioma" << endl;
        cout << "(3)  Pesquisar Livros eletronico de mesmo formato de arquivo" << endl;
        cout << "(4)  Pesquisar por Numero de Livrarias" << endl;
        cout << "(5)  Verificar se contem Escritor em Audio Book" << endl;
        cout << "(6)  Pesquisar por Titulo do livro" << endl;
        cout << "(7)  Mostrar todas Keywords" << endl;
        cout << "(8)  Pesquisa por numero de Capitulos" << endl;

        cout << "(10) Mostrar na tela ou salvar em um arquivo" << endl;
        cout << "(11) Mostrar quantidade de livros inserindo uma keyWord" << endl;
        cout << "(12) Mapear Livros de acordo com o idioma" << endl;
        cout << "(0) Finalizar Programa" << endl;
        cout << "Escolha: ";
        cin  >> menu;

        switch (menu){

            case 1:{
                cout << "\n------------------------------------------------------------------------------------------------------" << endl;
                cout << "Titulo                        |             Primeiro Escritor|Idioma    |N de Capitulos|N de KeyWords |" << endl;
                cout << "------------------------------------------------------------------------------------------------------" << endl;
                for(auto livro: Biblioteca){
                    cout << *livro << endl;
                }
            }break;

            case 2:{

                cout << "Digite o idioma de escolha: ";
                cin  >> idiomaAux;

                colecaoLivros = aux.retornaColecaoIdioma(Biblioteca, idiomaAux);

                cout << "\n------------------------------------------------------------------------------------------------------" << endl;
                cout << "Titulo                        |             Primeiro Escritor|Idioma    |N de Capitulos|N de KeyWords |" << endl;
                cout << "------------------------------------------------------------------------------------------------------" << endl;
                for(auto livro: colecaoLivros){
                    cout << *livro << endl;
                }

            }break;

            case 3:{
                cout << "Digite o formato de arquivo de escolha: ";
                cin  >>  formatoAux;

                colecaoEletronico = auxEletronico.retornaColecaoFormato(Biblioteca, formatoAux);

                cout << "\n------------------------------------------------------------------------------------------------------" << endl;
                cout << "Titulo                        |             Primeiro Escritor|Idioma    |N de Capitulos|N de KeyWords |" << endl;
                cout << "------------------------------------------------------------------------------------------------------" << endl;
                for(auto livro: colecaoEletronico){
                    cout << *livro << "  " << livro->getAno() << endl;
                }

            }break;

            case 4:{

                cout << "Digite o numero de Livrarias desejado: ";
                cin  >>  nLivrarias;

                colecaoImpresso = auxImpresso.retornaColecaoPorLivraria(Biblioteca,nLivrarias);

                if(colecaoImpresso.size() == 0){
                    cout << "Nao encontrado" << endl;

                }else {
                    cout << "\n-------------------------------------------" << endl;
                    for (auto livro: colecaoImpresso) {

                        cout << "Nome do Livro: " << livro->getTitulo() << "  /Numero de Livrarias: " << livro->getLivrarias().size() << endl;
                    }
                }

            }break;

            case 5:{

                bool verifica;
                cout << "Digite o nome do Escritor: ";
                cin.ignore();
                getline(cin,escritorAux);
                verifica = auxAudioBook.verificaSeContemEscritor(Biblioteca,escritorAux);

                if(verifica){
                    cout << "\nEscritor encontrado em AudioBook" << endl;
                }
                else{
                    cout << "\nEscritor NAO encontrado em AudioBook" << endl;
                }


            }break;

            case 6:{

                cout << "Digite o Nome do Livro: ";
                cin.ignore();
                getline(cin,tituloAux);

                colecaoLivros = aux.retornaColecaoLivrosMesmoNome(Biblioteca,tituloAux);

                cout << "\n------------------------------------------------------------------------------------------------------" << endl;
                cout << "Titulo                        |             Primeiro Escritor|Idioma    |N de Capitulos|N de KeyWords |" << endl;
                cout << "------------------------------------------------------------------------------------------------------" << endl;
                for(auto livro: colecaoLivros){
                    cout << *livro << endl;
                }
            }break;

            case 7:{

                cout << "\n------------------------------------------------------------------------------------------------" << endl;
                cout << "KeyWords: "  << endl;
                colecaoKeywords = aux.retornaColecaoKeyWords(Biblioteca);
                for(auto elem: colecaoKeywords){
                    cout << elem << ", ";
                }
                cout << "\n-------------------------------------------------------------------------------------------------" << endl;

            }break;

            case 8:{
                cout << "\nDigite o numero de capitulos: ";
                cin  >> nCapitulos;

                colecaoLivros = aux.retornaPesquisaPorCapitulo(Biblioteca,nCapitulos);


                cout << "\n------------------------------------------------------------------------------------------------------" << endl;
                cout << "Titulo                        |             Primeiro Escritor|Idioma    |N de Capitulos|N de KeyWords |" << endl;
                cout << "------------------------------------------------------------------------------------------------------" << endl;
                for(auto elem: colecaoLivros){
                    cout << *elem << endl;
                }

            }break;

            case 10:{

                int i;

                cout << "(1) - Mostrar na Tela" << endl;
                cout << "(2) - Salvar em um arquivo txt" << endl;
                cout << "Escolha: ";
                cin.ignore();
                cin  >> i;

                if(i == 1){
                    cout << "\n------------------------------------------------------------------------------------------------------" << endl;
                    cout << "Titulo                        |             Primeiro Escritor|Idioma    |N de Capitulos|N de KeyWords |" << endl;
                    cout << "------------------------------------------------------------------------------------------------------" << endl;
                    for(auto elem: Biblioteca){
                        if (typeid(Impresso).name() == typeid(*elem).name()) {
                            Impresso *aux = (Impresso *) elem;
                            cout << *aux << endl;
                        }
                        else if (typeid(Eletronico).name() == typeid(*elem).name()) {
                            Eletronico *aux = (Eletronico *) elem;
                            cout << *aux << endl;
                        }
                        else if (typeid(AudioBook).name() == typeid(*elem).name()) {
                            AudioBook *aux = (AudioBook *) elem;
                            cout << *aux << endl;
                        }
                    }
                }
                else{
                    fstream arquivoSaida;
                    arquivoSaida.open("Biblioteca.txt",ios::out);
                    if(!arquivoSaida){
                        cout << "\nArquivo nao pode ser aberto" << endl;
                        exit(1);
                    }

                    arquivoSaida << "\n------------------------------------------------------------------------------------------------------" << endl;
                    arquivoSaida << "Titulo                        |             Primeiro Escritor|Idioma    |N de Capitulos|N de KeyWords |" << endl;
                    arquivoSaida << "------------------------------------------------------------------------------------------------------" << endl;
                    for(auto elem: Biblioteca){
                        if (typeid(Impresso).name() == typeid(*elem).name()) {
                            Impresso *aux = (Impresso *) elem;
                            arquivoSaida << *aux << endl;
                        }
                        else if (typeid(Eletronico).name() == typeid(*elem).name()) {
                            Eletronico *aux = (Eletronico *) elem;
                            arquivoSaida << *aux << endl;
                        }
                        else if (typeid(AudioBook).name() == typeid(*elem).name()) {
                            AudioBook *aux = (AudioBook *) elem;
                            arquivoSaida << *aux << endl;
                        }
                    }
                    arquivoSaida.close();

                    cout << "\nBiblioteca salva em arquivo" << endl;
                }

            }break;

            case 11:{

                int quant;
                cout << "Digite a Keyword para busca: ";
                cin.ignore();
                getline(cin,auxKeyword);


                quant = aux.retornaQuantidadeDeLivrosKeywords(Biblioteca,auxKeyword);
                cout << "Keyword: pertence " << quant << " livros" << endl;
            }break;

            case 12:{


                MultiMapTaype mult = mapeamentoPorIdioma(Biblioteca);
                cout << "(ING) - Mostrar livros em ingles via Map " << endl;
                cout << "(ESP) - Mostrar livros em espanhol via Map" << endl;
                cout << "(FRS) - Mostrar livros em frances via Map" << endl;
                cout << "(POT) - Mostrar livros em portugues via Map" << endl;
                cout << "Escolha: ";
                cin  >> auxIdioma;


                cout << "\n------------------------------------------------------------------------------------------------------" << endl;
                cout << "Titulo                        |             Primeiro Escritor|Idioma    |N de Capitulos|N de KeyWords |" << endl;
                cout << "------------------------------------------------------------------------------------------------------" << endl;

                for(MultiMapTaype::const_iterator iter = mult.begin(); iter != mult.end(); ++iter){
                    if(iter->first == auxIdioma){
                        cout << *iter->second << endl;
                    }
                }




            }break;

            case 0:{
                cout << "\nPrograma finalizado" << endl;
            }break;

            default:{

                cout << "\nOpcao invalida " << endl;
            }break;

        }

    } while(menu != 0);

    return 0;
}
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
MultiMapTaype mapeamentoPorIdioma(list<Livro*> Livros){

    MultiMapTaype aux;

    for(auto *elem: Livros){

        if(elem->getIdioma() == "Ingles"){
            aux.insert(MultiMapTaype::value_type("ING",elem));
        }
        else if(elem->getIdioma() == "Espanhol"){
            aux.insert(MultiMapTaype::value_type("ESP",elem));
        }
        else if(elem->getIdioma() == "Frances"){
            aux.insert(MultiMapTaype::value_type("FRS",elem));
        }
        else if(elem->getIdioma() == "Portugues"){
            aux.insert(MultiMapTaype::value_type("POT",elem));
        }
    }
    return aux;
}
