#include <iostream>
#include <math.h>
#include <string>
#include "Baldes.h"
using namespace std;

Baldes::Baldes(int tamanho, int dLocal){
    this->tamanho=tamanho;
    this->dLocal=dLocal;
    balde = new string[tamanho];
    this->ocupados=0;
}

Baldes::~Baldes(){
    delete [] balde;
}

void Baldes::insere(string pseudo){
    this->balde[this->ocupados]=pseudo;
    this->ocupados++;
}

bool Baldes::busca(string pseudo){
    for(int i=0;i<ocupados;i++){
        if(balde[i]==pseudo){
            return true;
        }
    }
    return false;
}

bool Baldes::cheio(){
    if(ocupados==tamanho){
        return true;
    }
    return false;
}

string Baldes::info(int i){
    return balde[i];
}

void Baldes::imprime(){
    for(int i=0;i<tamanho;i++){
        cout<< balde[i] << " >>> " ;
    }
}

int Baldes::jaExiste(string pseudo){
    for(int i=0;i<ocupados;i++){
        if(balde[i]==pseudo)
            return 1;
    }
    return 0;
}



