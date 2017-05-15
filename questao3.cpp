#include <bits/stdc++.h>

using namespace std;

const int MAX = 1 << 20;
int tam;
struct cliente{
	string Nome;
	string CPF;
};

cliente* criar(){
	cliente *lista;
	lista = (cliente*)(malloc(MAX));
	return lista;
}

void inserir(cliente *lista, cliente c){   
    lista[tam] = c;
    tam++;
}

cliente remover(cliente *lista){
    tam--;
    return lista[tam];
}

void deletar(cliente *lista){
    free(lista);
}

int main(){
    cliente *lista = criar();
    cliente c1, c2, c3, c4;
    c1.Nome = "Aiolia", c1.cpf = "123456789";
    inserir(lista, c1);
    c2.Nome = "Mu", c2.cpf = "987654321";
    inserir(lista, c2);
    c3 = remover(lista);
    cout << c3.Nome << '\n';
    c4.nome = "Milo", c4.cpf = "789513462";
    inserir(lista, c4);
    c3 = remover(lista);
    cout << c3.Nome << '\n';
    deletar(lista);
    
    return 0;
}