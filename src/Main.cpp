#include <iostream>
#include <string>
#include <stdlib.h>


#include "Ordenacao.hpp"
using namespace std;

void print(int *v,int tamanho)
{ 
    for (int i = 0; i < tamanho; i++)  
        cout << "\t "<< v[i] ;  
    cout << endl; 
}

void printObjeto(User *v,int tamanho)
{ 
    for (int i = 0; i < tamanho; i++) 
    {
        v[i].imprimirUser();  
    } 
        
    cout << endl; 
}
int main()
{
    Ordenacao o;
    User *u;
    string n,n1,n2;
     
    int t = 0;
    int t1 = 0,t2=0;
    int escolha;
    Lista<User> user,user3;
    Lista<User> user2;
    Pilha<User> pUser;
    Fila<User> fUser,fUser2;
    Arquivo a;
    cout<<"Carregando o arquivo..."<<endl;
    string nome = "netflix.csv";
    string idUser,idNota;
    user = a.carregaArquivo(nome);
    t=user.tamanho();

    do{
        cout<<"Digite [1] para mostrar todo arquivo:"<<endl;
        cout<<"Digite [2] para identificação de usuários semelhantes:"<<endl;
        cout<<"Digite [0] para sair:"<<endl;
        cout<<"Escolha:";
        cin>>escolha;

        switch (escolha)
        {
        case 1:
            system("clear");
            cout<<"Id\t"<<"cod\t"<<"nota"<<endl;
            user.imprimirObjeto();
            break;
        case 2:
            getchar();
            cout<<"Escolha um dos números abaixo  para identificação do usuário :"<<endl;
            cout<<" [2]   [5]    [7]    [8]    [10]     :  ";
            getline(cin,idUser);
            user2 = user.returnPilhaUser(idUser);
            
            cout<<"Usuário escolhido "<<endl;
            user2.imprimirObjeto();
            t1=user2.tamanho();

            for(int i = 0 ; i < t1; i++)
            {
                for(int j=0;j < t;j++)
                {    
                    /*if(stoi(n) > (stoi(idNota) - 2))
                    {
                        fUser.Add(user2.returnVetor(i));
                    }  */

                    if(user2.returnVetor(i).getFilm() == user.returnVetor(j).getFilm() && user2.returnVetor(i).getUser() != user.returnVetor(j).getUser() )
                    {
                        user3.Add(user.returnVetor(j));
                    }
                }
            }
            
            
            cout<<"Usuários próximos:"<<endl;

           // user3.imprimirObjeto();
            t2=user3.tamanho();
            u= new User[t2];

            for(int i =0;i<t2;i++)
            {
                u[i]=user3.returnVetor(i);
            }

            printObjeto(u,t2);
            o.BubbleSort(u,t2);
            printObjeto(u,t2);

            break;
        case 3:
            
            break;
         case 0:
            system("clear");
            cout<<"Saindo !"<<endl;
            break;
        
        default:
            system("clear");
            cout<<"Opção inválida"<<endl;
            break;
        }
    }while(escolha != 0);    

    return 0;
}

