#ifndef _USER_HPP
#define _USER_HPP
#include <string>
#include <iostream>
using namespace std;

class User
{
private:
    string user;
    string film;
    string nota;
public:
    User();
    User(string user,string film,string nota);

    void setUser(string user);
    string getUser();
    
    void setFilm(string film);
    string getFilm();

    void setNota(string nota);
    string getNota();

    void imprimirUser();
};
#endif

User::User()
{

}

User::User(string user,string film,string nota)
{
    this->user = user;
    this->film = film;
    this->nota = nota;
}

void User::setUser(string user)
{
    this->user = user;
}

string User::getUser()
{
    return user;
}

void User::setFilm(string film)
{
    this->film = film;
}

string User::getFilm()
{
    return film;
}

void User::setNota(string nota)
{
    this->nota = nota;
}

string User::getNota()
{
    return nota;
}

void User::imprimirUser()
{
    
    cout<<getUser()<<"\t"<<getFilm()<<"\t"<<getNota()<<endl;
}