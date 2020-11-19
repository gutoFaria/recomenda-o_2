#ifndef _FILA_HPP
#define _FILA_HPP
#include "User.hpp"
#include <iostream>

using namespace std;

template<class T>
struct Nod
{
    T dado;
    struct Nod<T> *proximo;
};

template<class T>
class Fila
{
private:
    Nod<T> *primeiro;
    Nod<T> *ultimo;
public:
    Fila();
    void Add(T item);
    void remove();
    void print();
    void printObject();
    
    ~Fila();
};
#endif
template<class T>
Fila<T>::Fila()
{
    primeiro = NULL;
    ultimo = NULL;
}

template<class T>
void Fila<T>::Add(T item)
{
    Nod<T> *temp;
    temp = new Nod<T>;
    temp->dado = item;
    temp->proximo = NULL;
    if(ultimo == NULL)
    {
        ultimo = temp;
        primeiro = temp;
    }
    else
    {
        ultimo->proximo = temp;
        ultimo = temp;
    }
}

template<class T>
void Fila<T>::remove()
{
    if(primeiro != NULL)
    {
        Nod<T> *temp = primeiro;
        cout<<primeiro->dado << " removido \n";
        primeiro = primeiro->proximo;
        delete temp;
        if(primeiro == NULL)
        {
            primeiro = NULL;
        }
    }
    else
    {
        cout<<"Pilha vazia \n";
    }
        
}

template<class T>
void Fila<T>::print()
{
    Nod<T> *temp = primeiro;
    while(temp != NULL)
    {
        cout<<temp -> dado<<" | " ;
        temp =temp->proximo;
    }
    cout<<endl;
}

template<class T>
void Fila<T>::printObject()
{
    Nod<T> *temp = primeiro;
    while(temp != NULL)
    {
        temp -> dado.imprimirUser();
        temp =temp->proximo;
    }
    cout<<endl;
}

template<class T>   
Fila<T>::~Fila()
{
    while(primeiro != NULL)
    {
        while(primeiro != NULL)
        {
            Nod<T> *temp = primeiro;
            primeiro = primeiro->proximo;
            delete temp;
        }
    }
}