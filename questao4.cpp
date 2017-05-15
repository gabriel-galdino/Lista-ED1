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
    cliente aux = lista[0];
    for(int i = 0; i < tam - 1; i++){
        lista[i] = lista[i + 1];
	}	
    return aux;
}

void deletar(cliente *lista){
    free(lista);
}

int main(){
    cliente *lista = criar();
    cliente c1, c2, c3, c4;
    c1.Nome = "Aldebaran", c1.cpf = "741852963";
    inserir(lista, c1);
    c2.Nome = "Shaka", c2.cpf = "6248931759";
    inserir(lista, c2);
    c3 = remover(lista);
    cout << c3.Nome << '\n';
    c4.Nome = "Máscara da Morte", c4.cpf = "123654789";
    inserir(lista, c4);
    c3 = remover(lista);
    cout << c3.Nome << '\n';
    deletar(lista);
    
    return 0;
}