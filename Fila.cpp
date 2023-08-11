#include <iostream>
#include "Fila.h"


Fila* Fila::inserir_pref(Fila *fimPref, std::string nome, int idade){
    Fila *aux = new Fila();
    aux->nome = nome;
    aux->idade = idade;
    aux->tipo_cliente = 0;
    aux->elo = NULL;
    if(fimPref != NULL)
        fimPref->elo = aux;
    fimPref = aux;
    return fimPref;
}

Fila* Fila::inserir_comun(Fila *fimComun, std::string nome, int idade){
    Fila *aux = new Fila();
    aux->nome = nome;
    aux->idade = idade;
    aux->tipo_cliente = 1;
    aux->elo = NULL;
    if(fimComun != NULL)
        fimComun->elo = aux;
    fimComun = aux;
    return fimComun;
}

Fila* Fila::excluir_cliente(Fila *inicio){
    Fila *aux = inicio;
    inicio = inicio->elo;
    delete aux;
    return inicio;
}

void Fila::listar(Fila *inicio){
    Fila *aux = inicio;
    if(inicio->tipo_cliente == 0){
        std::cout << "Listando todos os cliente preferenciais: \n";
    }else{
        std::cout << "Listando todos os cliente comuns: \n";
    }
    while(aux != NULL){
        std::cout << aux->nome << "\t" << aux->idade << std::endl;
        aux = aux->elo;
    }
}

int Fila::qtd(Fila *inicio){
    int qtd=0;
    Fila *aux = inicio;
    while(aux != NULL){
        qtd++;
        aux = aux->elo;
    }
    return qtd;
}


