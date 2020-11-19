#ifndef _ARQUIVO_HPP
#define _ARQUIVO_HPP
#include "Lista.hpp"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
using namespace std;


class Arquivo 
{
    private:
        string nome;
    public:
        Arquivo();
        Lista<User> carregaArquivo(string nome);  
        void escreverArquivo(string nome,string escrever);   
};
#endif


Arquivo::Arquivo()
{

}
Lista<User> Arquivo::carregaArquivo(string nome)
{    
    string linha;
    Lista<User> l;
    string idUser,idFilm,idNota;
    ifstream arquivo;
    arquivo.open(nome);
    if(arquivo.is_open())
    {
        while(getline(arquivo,linha))
        {
        stringstream ss(linha);
        getline(ss,idUser,',');  
        getline(ss,idFilm,',');
        getline(ss,idNota,',');
        User users(idUser,idFilm,idNota);

        l.Add(users);
        }
    }
    else
    {
        cout<<"Não foi possível abrir o arquivo"<<endl;
    }
    arquivo.close();
   
    return l;
}

void Arquivo::escreverArquivo(string nome,string escrita)
{
    ofstream arquivo;
    arquivo.open(nome+".txt",ios::app);
    arquivo<<escrita<<endl;
    arquivo.close();
}

