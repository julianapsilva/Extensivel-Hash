#ifndef DIRETORIO_H_INCLUDED
#define DIRETORIO_H_INCLUDED
#include <iostream>
#include <vector>
#include "Baldes.h"
#include "Diretorio.h"

class Diretorio{

private:
    int dGlobal;
    int bits;
    int tamBaldes;
    vector<Baldes*> diretorio;

public:
    Diretorio(int bits, int tamBaldes);
    string hash(int k);
    int indice(string pseudo);
    int insere(int k, int padrao);
    bool busca(int k);
    void divideBalde(Baldes *adividir);
    void duplica();
    string converteDecimal(int decimal);
    void imprime();
    void fatorDeCarga();
};




#endif // DIRETORIO_H_INCLUDED
