#include <iostream>


class Fila
{
    public:
        std::string nome;
        int idade;
        int tipo_cliente;
        Fila *elo;
        Fila* inserir_pref(Fila*, std::string, int);
        Fila* inserir_comun(Fila*, std::string, int);
        Fila* excluir_cliente(Fila*);
        void listar(Fila*);
        int qtd(Fila*);

    protected:

    private:
};
