#ifndef BALDES_H_INCLUDED
#define BALDES_H_INCLUDED
#include <iostream>
using namespace std;

class Baldes{
private:
    int dLocal;
    int ocupados;
    int tamanho;
    string* balde;
    //string balde[];

public:
    Baldes(int tamanho, int dLocal);
    ~Baldes();

    int ocupado(){ return ocupados;};
    void setOcupado(int valor){ ocupados=valor;};

    void insere(string pseudo);
    bool busca(string pseudo);
    bool cheio();
    void setdLocal(int valor){ dLocal=valor;};
    int getdLocal(){return dLocal;};
    string info(int i);
    void imprime();


};


#endif // BALDES_H_INCLUDED
