#ifndef _ORDENACAO_HPP
#define _ORDENACA0_HPP

#include "Arquivo.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class Ordenacao
{
public:
    //void swap(int *a,int *b);

    /*void BubbleSort(int *v,int tamanho);

    void insertionSort(int *v, int tamanho);

    void mergeSort(int *v, int l, int r);
    void merge(int v[], int p, int q, int r);

    int partition (int *v, int n1, int n2);
    void quickSort(int *v, int n1, int n2);

    void heapify(int *v, int n, int i);
    void heapSort(int *v, int n);

    void radixSort(int *v, int n);
    void countSort(int *v, int n, int exp);
    int getMax(int *v, int n);*/
    
    void swap(User *a,User *b);
    void print(User *v,int tamanho);

    void BubbleSort(User *v,int tamanho);

   /* void insertionSort(User *v, int tamanho);

    void mergeSort(User *v, int l, int r);
    void merge(User *v, int p, int q, int r);

    int partition (User *v, int n1, int n2);
    void quickSort(User *v, int n1, int n2);

    void heapify(User *v, int n, int i);
    void heapSort(User *v, int n);

    void radixSort(User *v, int n);
    void countSort(User *v, int n, int exp);
    int getMax(User *v, int n);
    
    void print(User *v,int tamanho);*/
};
#endif

void Ordenacao::swap(User *a,User *b)
{
    User temp = *a;  
    *a = *b;  
    *b = temp;
}

//vetores de inteiros
/*void Ordenacao::BubbleSort(int *v,int tamanho)
{
    for (int i = 0; i < tamanho-1; i++)
    {
        for (int j = 0; j < tamanho-i-1; j++) 
        {
            if (v[j] > v[j+1]) 
            {
                swap(&v[j],&v[j+1]);
            }
        }       
    }      
}

void Ordenacao::print(int *v,int tamanho)
{ 
    for (int i = 0; i < tamanho; i++)  
        cout << "\t "<< v[i] ;  
    cout << endl; 
}

void Ordenacao::insertionSort(int *v, int n)  
{  
    int i, b, j,cont=0;;  
    for (i = 1; i < n; i++) 
    {  
        b = v[i];  
        j = i - 1;  
        while (j >= 0 && v[j] > b) 
        {  
            v[j + 1] = v[j];  
            j = j - 1;
            cont++;  
        }  
        v[j + 1] = b;  
    }  
    cout<<endl<<endl;
} 

void Ordenacao::merge(int *v, int p, int q, int r)
{
  int n1 = q - p + 1;
  int n2 = r - q;

  int *L = new int[n1];
  int *M = new int[n2];

  for (int i = 0; i < n1; i++)
    L[i] = v[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = v[q + 1 + j];

  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      v[k] = L[i];
      i++;
    } else {
      v[k] = M[j];
      j++;
    }
    k++;
  }
  while (i < n1) {
    v[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    v[k] = M[j];
    j++;
    k++;
  }
}

void Ordenacao::mergeSort(int *v, int l, int r)
{
    if (l < r) 
    {
        int m = l + (r - l) / 2;

        mergeSort(v, l, m);
        mergeSort(v, m + 1, r);
        merge(v, l, m, r);
    }
}

int Ordenacao::partition (int *v, int n1, int n2)  
{  
    int pivot = v[n2]; 
    int i = (n1 - 1);   
  
    for (int j = n1; j <= n2 - 1; j++)  
    {  
         
        if (v[j] < pivot)  
        {  
            i++; 
            swap(&v[i], &v[j]);  
        }  
    }  
    swap(&v[i + 1], &v[n2]);  
    return (i + 1);  
}  
  
void Ordenacao::quickSort(int *v, int n1, int n2)  
{  
    if (n1 < n2)  
    {  
        
        int pi = partition(v, n1, n2);  
    
        quickSort(v, n1, pi - 1);  
        quickSort(v, pi + 1, n2);  
    }  
}  

void Ordenacao::heapify(int *v, int n, int i)
{
    int j = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 
 
    
    if (l < n && v[l] > v[j])
        j = l;
 
   
    if (r < n && v[r] > v[j])
        j = r;
 
  
    if (j != i) {
        swap(&v[i], &v[j]);
 
       
        heapify(v, n, j);
    }
}
 

void Ordenacao::heapSort(int *v, int n)
{
    
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(v, n, i);
 
    
    for (int i = n - 1; i > 0; i--) {
        swap(&v[0], &v[i]);
        heapify(v, i, 0);
    }
}

int Ordenacao::getMax(int *v, int n) 
{ 
    int mx = v[0]; 
    for (int i = 1; i < n; i++) 
        if (v[i] > mx) 
            mx = v[i]; 
    return mx; 
} 
  
void Ordenacao::countSort(int *v, int n, int exp) 
{ 
    int *o = new int[n]; 
    int i, count[10] = { 0 }; 
  
    for (i = 0; i < n; i++) 
    { 
        count[(v[i] / exp) % 10]++; 
    }
       
  
    for (i = 1; i < 10; i++)
    {
        count[i] += count[i - 1]; 
    } 
        
    for (i = n - 1; i >= 0; i--)
    { 
        o[count[(v[i] / exp) % 10] - 1] = v[i]; 
        count[(v[i] / exp) % 10]--; 
    } 
  
    for (i = 0; i < n; i++) 
    {
        v[i] = o[i];
    }
         
} 
  

void Ordenacao::radixSort(int *v, int n) 
{ 

    int m = getMax(v, n); 
    for (int exp = 1; m / exp > 0; exp *= 10) 
    {
         countSort(v, n, exp); 
    }      
} */



void Ordenacao::print(User *v,int tamanho)
{
    for (int i = 0; i < tamanho; i++) 
    {
        v[i].imprimirUser();  
    } 
        
    cout << endl; 
}

void Ordenacao::BubbleSort(User *v,int tamanho)
{
    for (int i = 0; i < tamanho-1; i++)
    {
        for (int j = 0; j < tamanho-i-1; j++) 
        {
            if (stoi(v[j].getNota()) > stoi(v[j+1].getNota())) 
            {
                swap(&v[j],&v[j+1]);
            }
        }       
    }  

      
}


/*void Ordenacao::insertionSort(User *v, int n)  
{  
    int i, b, j,cont=0;;  
    for (i = 1; i < n; i++) 
    {  
        b = v[i];  
        j = i - 1;  
        while (j >= 0 && v[j] > b) 
        {  
            v[j + 1] = v[j];  
            j = j - 1;
            cont++;  
        }  
        v[j + 1] = b;  
    }  
    cout<<endl<<endl;
} 

void Ordenacao::merge(User *v, int p, int q, int r)
{
  int n1 = q - p + 1;
  int n2 = r - q;

  int *L = new int[n1];
  int *M = new int[n2];

  for (int i = 0; i < n1; i++)
    L[i] = v[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = v[q + 1 + j];

  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      v[k] = L[i];
      i++;
    } else {
      v[k] = M[j];
      j++;
    }
    k++;
  }
  while (i < n1) {
    v[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    v[k] = M[j];
    j++;
    k++;
  }
}

void Ordenacao::mergeSort(User *v, int l, int r)
{
    if (l < r) 
    {
        int m = l + (r - l) / 2;

        mergeSort(v, l, m);
        mergeSort(v, m + 1, r);
        merge(v, l, m, r);
    }
}

int Ordenacao::partition (User *v, int n1, int n2)  
{  
    int pivot = v[n2]; 
    int i = (n1 - 1);   
  
    for (int j = n1; j <= n2 - 1; j++)  
    {  
         
        if (v[j] < pivot)  
        {  
            i++; 
            swap(&v[i], &v[j]);  
        }  
    }  
    swap(&v[i + 1], &v[n2]);  
    return (i + 1);  
}  
  
void Ordenacao::quickSort(User *v, int n1, int n2)  
{  
    if (n1 < n2)  
    {  
        
        int pi = partition(v, n1, n2);  
    
        quickSort(v, n1, pi - 1);  
        quickSort(v, pi + 1, n2);  
    }  
}  

void Ordenacao::heapify(User *v, int n, int i)
{
    int j = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 
 
    
    if (l < n && v[l] > v[j])
        j = l;
 
   
    if (r < n && v[r] > v[j])
        j = r;
 
  
    if (j != i) {
        swap(&v[i], &v[j]);
 
       
        heapify(v, n, j);
    }
}
 

void Ordenacao::heapSort(User *v, int n)
{
    
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(v, n, i);
 
    
    for (int i = n - 1; i > 0; i--) {
        swap(&v[0], &v[i]);
        heapify(v, i, 0);
    }
}

int Ordenacao::getMax(User *v, int n) 
{ 
    int mx = v[0]; 
    for (int i = 1; i < n; i++) 
        if (v[i] > mx) 
            mx = v[i]; 
    return mx; 
} 
  
void Ordenacao::countSort(User *v, int n, int exp) 
{ 
    int *o = new int[n]; 
    int i, count[10] = { 0 }; 
  
    for (i = 0; i < n; i++) 
    { 
        count[(v[i] / exp) % 10]++; 
    }
       
  
    for (i = 1; i < 10; i++)
    {
        count[i] += count[i - 1]; 
    } 
        
    for (i = n - 1; i >= 0; i--)
    { 
        o[count[(v[i] / exp) % 10] - 1] = v[i]; 
        count[(v[i] / exp) % 10]--; 
    } 
  
    for (i = 0; i < n; i++) 
    {
        v[i] = o[i];
    }
         
} 
  

void Ordenacao::radixSort(User *v, int n) 
{ 

    int m = getMax(v, n); 
    for (int exp = 1; m / exp > 0; exp *= 10) 
    {
         countSort(v, n, exp); 
    }      
} */