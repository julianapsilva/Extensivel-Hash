#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include "Baldes.h"
#include "Diretorio.h"
using namespace std;

 Diretorio::Diretorio(int bits, int tamBaldes){
    this->tamBaldes=tamBaldes;
    dGlobal=2;
    this->bits=bits;
    Baldes *balde1 =  new Baldes (tamBaldes,1);
    Baldes *balde2 =  new Baldes (tamBaldes,2);
    Baldes *balde3 =  new Baldes (tamBaldes,2);
    diretorio.push_back(balde1);
    diretorio.push_back(balde1);
    diretorio.push_back(balde2);
    diretorio.push_back(balde3);

}

string Diretorio::hash(int k){
    double A= (sqrt(5)-1)/2;
    double mult=k*A;
    double kA= mult-int(mult);
    int result=floor(256* kA);
    return converteDecimal(result);
}

int Diretorio::indice(string pseudo){        // retorna o indice correspondente do diretorio
    int j=0, indice=0;
        for(int i=dGlobal-1;i>=0;i--){
            indice+= (pseudo[i]-'0') * pow(2,j);
            j++;
        }
    return indice;
}

void Diretorio::insere(int k){
    string pseudo= hash(k);
    int i= indice(pseudo);

    if(diretorio[i]->cheio()){

        if(dGlobal==diretorio[i]->getdLocal()){
        duplica();  //duplica o tamanho do diretorio
        int i= indice(pseudo);
        divideBalde(diretorio[i]);
        }
        else if(diretorio[i]->getdLocal() < dGlobal ) {
        divideBalde(diretorio[i]);   // realiza a divisao do balde e incrementa dLocal
    }
    }

    diretorio[i]->insere(pseudo);

}

bool Diretorio::busca(int k){
    string pseudo= hash(k);
    int i= indice(pseudo);
    return diretorio[i]->busca(pseudo);
}

void Diretorio::divideBalde(Baldes *adividir){
    Baldes *novo =  new Baldes (tamBaldes,1);
    Baldes *aux =  new Baldes (tamBaldes,1);
    string var1,var2;
    var2="";

    adividir->setdLocal(adividir->getdLocal()+1);
    novo->setdLocal(adividir->getdLocal());
    aux->setdLocal(adividir->getdLocal());

    var1=adividir->info(0).substr(0, adividir->getdLocal()); // recebe os d numeros da pseudo chave
    for(int i=1;i<tamBaldes;i++){
       if((adividir->info(i).substr(0, adividir->getdLocal())!=var1)){
           var2=adividir->info(i).substr(0, adividir->getdLocal());
       }}
       for(int i=0;i<tamBaldes;i++){
           if(adividir->info(i).substr(0, adividir->getdLocal())==var1){
               novo->insere(adividir->info(i));
           }
           else if(var2!="") {
               aux->insere(adividir->info(i));
           }
       }

       diretorio[indice(var1)]=novo;
       diretorio[indice(var2)]=aux;
}

void Diretorio::duplica(){
    dGlobal++;
    int p=pow(2,dGlobal);
    Baldes *duplicado[p];
    int j=0;
    for(int i=1;i<=p;i+=2){
        duplicado[i]=diretorio[j];
        duplicado[i-1]=diretorio[j];
        j++; }

    diretorio.clear();

    for(int i=0;i<pow(2,dGlobal);i++){
        diretorio.push_back(duplicado[i]);
}
    delete[] duplicado;
}

// funcao que converte a hash com decimal para binaria
string Diretorio::converteDecimal(int decimal){
    string pseudo=""; int vet[12], i=0;

    while(((decimal-(decimal%2))/2)!=0){        // enquanto o quociente for diferente de 0
        vet[i]= decimal%2;
        i++;
        decimal=decimal/2;
    }
    vet[i]=decimal;
    if(bits<i|| bits==i){     // i indica a quantidade de digitos que o binario tem
        for(int j=0;j<bits;j++){
            pseudo+= (std::to_string(vet[i]));
            i--;
        } }

        else {
            for(int j=i;j>=0;j--){
                pseudo+=(std::to_string(vet[i]));
                i--;;
            }
        pseudo.insert(pseudo.begin(), bits - pseudo.length(), '0'); // preenche com 0 a esquerda
        }
    return pseudo;

}

void Diretorio::imprime(){
    int p=pow(2,dGlobal);
    for(int i=0;i<p;i++){
        diretorio[i]->imprime();
        cout<<endl;
    }
}




