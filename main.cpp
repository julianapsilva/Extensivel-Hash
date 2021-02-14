#include <iostream>
#include <math.h>
#include "Diretorio.h"
#include "Baldes.h"

using namespace std;

void insereAleatorias(int n, int b, int m){
    Diretorio *diretorio = new Diretorio(b,m);

    for(int i=0;i<n;i++){
        diretorio->insere(rand() % 1000);
    }
    cout<< "RESULTADO" << endl;
    diretorio->imprime();
}

void insereMesmoPadrao(int n, int b, int m){
    Diretorio *diretorio = new Diretorio(b,m);

    for(int i=1;i<=n;i++){
        diretorio->insere(10*i);
    }
    cout<< "RESULTADO" << endl;
    diretorio->imprime();
}


int main(){
    // PARA OS VALORES TESTADOS, N=20, USE O TAMANHO DOS BALDES >= 6
    //PARA N ALEATORIAS, USE B >=4 E MESMO PADRAO DE BITS B>=6
    int m,b,n, resposta;
    cout<< "Digite o tamanho a ser usado para os baldes" << endl;
    cin>> m;
    cout << "Digite o numero de bits a ser usado para as pseudochaves"<< endl;
    cin>> b;

    n=20;
    cout<< "1) Digite 1 para inserir " << n << " valores aleatorios" << endl;
    cout<< "2) Digite 2 para inserir " << n << " valores com mesmo padrao" << endl;
    cin >> resposta;

    if(resposta==1){
        insereAleatorias(20,b,m);   // 20 valores aleatorios
    }
    else if(resposta==2){
        insereMesmoPadrao(20,b,m);    // 20 valores com padrao semelhante
    }

    return 0;
}
