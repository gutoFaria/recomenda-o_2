#ifndef _LISTA_HPP
#define _LISTA_HPP

#include "Pilha.hpp"

#include <iostream>

using namespace std;
template<class T>
struct No
{
    T dado;
    struct No<T> *proximo;
};


template<class T>
class Lista
{
private:
    No<T> *primeiro;
    No<T> *ultimo;
public:
    Lista();
    void Add(T valor);
    void imprimirLista();
    void firstLista(T valor);
    void posicaoLista(int pos,T valor);
    void imprimirObjeto();
    T removerPrimeiro();
    T removerPosQualquer(int n);
    T removeUltimo();
    int tamanho();
    T returnVetor(int pos);
    T returnLista(Lista<T> lista); 
    Lista<User> returnPilha(string idFilm);
    Lista<User> returnPilhaUser(string idUser);
};
#endif

template<class T>
Lista<T>::Lista()
{
    primeiro = NULL;
    ultimo = NULL;
}

template<class T>
void Lista<T>::Add(T valor)
{
    No<T> *temp = new No<T>;
    temp->dado = valor;
    temp->proximo = NULL;

    if(primeiro ==NULL)
    {
        primeiro = temp;
        ultimo = temp;
    }
    else
    {
        ultimo->proximo=temp;
        ultimo = temp;
    }      
}

template<class T>
void Lista<T>::imprimirLista()
{
    No<T> *current = primeiro;

    while(current != NULL)
    {
        cout<<current->dado<<" | ";
        current=current->proximo;
    }
    cout<<endl;
}

template<class T>
void Lista<T>::firstLista(T valor)
{
    No<T> * newNo;
    newNo = new No<T>;

    newNo->dado = valor;
    newNo->proximo = primeiro;

    primeiro = newNo;   
}

template<class T>
void Lista<T>::posicaoLista(int pos,T valor)
{
    No<T> *pre = new No<T>;
    No<T> *current = new No<T>;
    No<T> temp = new No<T>;
    current = primeiro;

    for(int i =0;i<pos;i++)
    {
        pre = current;
        current = current->proximo;
    }

    temp->dado = valor;
    pre->proximo = temp;
    temp->proximo = current;
}

template<class T>
T Lista<T>::removerPrimeiro()
{
    T item = NULL;
    No<T> * nextNo = NULL;

    nextNo = primeiro->proximo;
    item = primeiro->value;
    delete primeiro;
    primeiro = nextNo;

    return item;
}

template<class T>
T Lista<T>::removeUltimo()
{
    T item = NULL;
    
    if (primeiro->proximo == NULL)
    {
        item = primeiro->dado;
        delete primeiro;
        return item;
    }

    
    No<T> *current = primeiro;
    while (current->proximo->proximo != NULL) {
        current = current->primeiro;
    }

    
    item = current->proximo->dado;
    delete current->proximo;
    current->proximot = NULL;

    return item;
}

template<class T>
T Lista<T>::removerPosQualquer(int n)
{
    
    T pos = -1;
    No<T> * current = primeiro;
    No<T> * tempNo = NULL;

    if (n == 0) 
    {
        return removerPrimeiro(primeiro);
    }

    for (int i = 0; i < n-1; i++) 
    {
        if (current->proximo == NULL) {
            return -1;
        }
        current = current->proximo;
    }

    tempNo = current->proximo;
    pos = tempNo->dado;
    current->proximo = tempNo->proximo;
    delete tempNo;

    return pos;
}
template<class T>
int Lista<T>::tamanho()
{
    int t=0;
    No<T> *current = primeiro;

    while(current != NULL)
    {
        t++;
        current=current->proximo;
    }
    return t;
}

template<class T>
T Lista<T>::returnVetor(int pos)
{
    T item;
    int i=0;
    No<T> *current = primeiro;

    while(current != NULL)
    {
        if(i==pos)
        {
            item=current->dado;
            break;
        }
        current=current->proximo;
        i++;
    }

    return item;
}

template<class T>
void Lista<T>::imprimirObjeto()
{
    No<T> *current = primeiro;

    while(current != NULL)
    {
        current->dado.imprimirUser();
        current=current->proximo;
    }
    cout<<endl;
}

template<class T>
T Lista<T>::returnLista(Lista<T> lista)
{
    return lista;
}

template<class T>
Lista<User> Lista<T>::returnPilha(string idFilm)
{
    User user;
    No<T> *current = primeiro;
    Lista<User> p;
    while(current != NULL)
    {
        user = current->dado;
        if(user.getFilm()==idFilm)
        {
            p.Add(user);
        }
        current=current->proximo;
    }
    cout<<endl;
    
    return p;
}

template<class T>
Lista<User> Lista<T>::returnPilhaUser(string idUser)
{
    User user;
    No<T> *current = primeiro;
    Lista<User> p;
    while(current != NULL)
    {
        user = current->dado;
        if(user.getUser()==idUser)
        {
            p.Add(user);
        }
        current=current->proximo;
    }
    cout<<endl;
    
    return p;
}