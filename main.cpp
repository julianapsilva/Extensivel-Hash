#include <iostream>
#include <math.h>
#include "Diretorio.h"
#include "Baldes.h"

using namespace std;

void insere(int n, int b, int m, int padrao){
    Diretorio *diretorio = new Diretorio(b,m);
    int j=0, k=0;
    for(int i=0;i<n && n<1000;i++){ // ate 1000 tentativas de insercao de chaves diferentes
        if(diretorio->insere(rand() % 1000, padrao)){  // a insercao ocorreu com sucesso
                j++;
        }
        else{
             n++;
             k++; // incrementa quantidade de chaves repetidas
        }
    }
    cout<<j << " valores diferentes inseridos com sucesso!" << endl;
    if(n==1000)
       cout<<"Nao foi possivel inserir todas as chaves, por favor, tente aumentar o numero de bits!"<<endl;
    cout<< "RESULTADO" << endl;
    diretorio->imprime();
    diretorio->fatorDeCarga();
    cout<< "Chaves repetidas geradas nao inseridas: " << k<< endl;
}

int main(){
    int m,b,n, resposta;
    cout<< "Digite o tamanho a ser usado para os baldes" << endl;
    cin>> m;
    cout << "Digite o numero de bits a ser usado para as pseudochaves"<< endl;
    cin>> b;

    n=20;
    cout<< "1) Digite 1 para inserir " << n << " valores aleatorios" << endl;
    cout<< "2) Digite 2 para inserir " << n << " valores com mesmo padrao" << endl;
    cin >> resposta;

    insere(20,b,m,resposta);

    return 0;
}
