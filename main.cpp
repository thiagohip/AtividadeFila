#include <iostream>
#include "Fila.h"
#include <unistd.h>

using namespace std;

void menu(){
    cout << "\t=====================================" << endl;
    cout << "\t|                                   |" << endl;
    cout << "\t|     BEM VINDO AO BANCO CEFET      |" << endl;
    cout << "\t|                                   |" << endl;
    cout << "\t=====================================" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "[1]Inserir cliente;" << endl;
    cout << "[2]Remover cliente;" << endl;
    cout << "[3]Listar os clientes preferenciais;" << endl;
    cout << "[4]Listar os clientes comuns;" << endl;
    cout << "[5]Listar a quantidade de clientes preferenciais;" << endl;
    cout << "[6]Listar a quantidade de clientes comuns;" << endl;
    cout << "[7]Sair" << endl;
    cout << endl;
    cout << "Escolha uma opção: ";
}

int main()

{
    Fila *fimPref = NULL;
    Fila *inicioPref = NULL;
    Fila *fimComun = NULL;
    Fila *inicioComun = NULL;
    Fila F;
    int op;
    string nome;
    int idade;
    int cliente;

    do{
        system("clear");
        menu();
        cin >> op;
        switch(op){
            case 1:
                system("clear");
                cout << "Digite o nome: ";
                cin >> nome;
                cout << "Digite a idade: ";
                cin >> idade;
                if(idade >= 60){
                    fimPref = F.inserir_pref(fimPref, nome, idade);
                    if(inicioPref == NULL){
                        inicioPref = fimPref;
                    }
                }else{
                    fimComun = F.inserir_comun(fimComun, nome, idade);
                    if(inicioComun == NULL){
                        inicioComun = fimComun;
                    }
                }
                cout << endl << "Cliente inserido com sucesso!";
                sleep(1.5);
                break;
            case 2:
                system("clear");
                cout << "Escolha qual tipo de cliente deseja remover: " << endl;
                cout << "[1]Preferencial" << endl;
                cout << "[2]Comum" << endl;
                cin >> cliente;
                if(cliente == 1){
                    F.excluir_cliente(inicioPref);
                }else if(cliente == 2){
                    F.excluir_cliente(inicioComun);
                }
                cout << endl << "Cliente removido com sucesso!";
                sleep(1.5);
                break;
            case 3:
                system("clear");
                F.listar(inicioPref);
                cin.ignore().get();
                break;
            case 4:
                system("clear");
                F.listar(inicioComun);
                cin.ignore().get();
                break;
            case 5:
                system("clear");
                cout << "Temos cadastrados em nosso sitema " << F.qtd(inicioPref) << " clientes preferenciais.";
                cin.ignore().get();
                break;
            case 6:
                system("clear");
                cout << "Temos cadastrados em nosso sitema " << F.qtd(inicioComun) << " clientes comuns.";
                cin.ignore().get();
                break;
            case 7:
                system("clear");
                break;
        }

    }while(op != 7);


    return 0;
}
