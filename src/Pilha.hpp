#ifndef _PILHA_HPP
#define _PILHA_HPP
#include<iostream>
#include "Fila.hpp"

using namespace std;
template<class T>
struct Node
{
    T dado;
    struct Node<T> *proximo;
};
template <class T>
class Pilha
{
private:
    Node<T>*topo;
public :
    Pilha();
    void push(T item);
    void pop();
    void print();
    void printObject();
    ~Pilha();
};
#endif

template <class T>
Pilha<T>::Pilha()
{ 
    topo=NULL;
}

template <class T>
void Pilha<T>::push(T item)
{
    Node<T> *temp;
    temp=new Node<T>;
    temp->dado = item;
    temp->proximo=topo;
    topo=temp;
}

template <class T>    
void Pilha<T>::pop()
{
    if(topo != NULL)
    {
         Node<T> *temp=topo;
         topo=topo->proximo;
            
        delete temp;
    }
    else
        cout<<"Pilha cheia\n";
}

template <class T>
void Pilha<T>::print()
{
    Node<T> *temp=topo;
    while(temp!=NULL)
    {
        cout<<temp->dado<<" | ";
        temp=temp->proximo;
    }
    cout<<endl;
}

template <class T>
void Pilha<T>::printObject()
{
    Node<T> *temp=topo;
    while(temp!=NULL)
    {
        temp->dado.imprimirUser();
        temp=temp->proximo;
    }
    cout<<endl;
}

template <class T>
Pilha<T>::~Pilha()
{
    while(topo!=NULL)
    {
        Node<T> *temp=topo;
        topo=topo->proximo;
        delete temp;
    }
}

