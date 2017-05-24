#include <bits/stdc++.h>

using namespace std;

struct cliente{
    string nome;
	string cpf;
    cliente *next;
    cliente(string nome, string cpf){
		this->nome = nome;
		this->cpf = cpf; 
		next = NULL;
	}
    cliente(){
		next = NULL;
	}
};

cliente* criar(){
    cliente *head = new cliente();
    return head;
}

void inserir(cliente *head, string nome, string cpf){
    cliente *aux = head;
	cliente	*c = new cliente(nome, cpf);
    while(aux->next != NULL){
        aux = aux->next;
	}	
    aux->next = c;
}

cliente remover(cliente *head){
    cliente *aux = head, r;
    while(aux->next->next != NULL){
        aux = aux->next;
	}
    r = *aux->next;
	delete(aux->next);
	aux->next = NULL;
    return r;
}

void deletar(cliente *head){
	cliente *aux = head;
    while(aux->next != NULL){
        aux = aux->next;
		delete(head);
		head = aux->next;
	}	
}

int main(){
    cliente *head = criar();
    inserir(head, "Seiya", "741822963");
    inserir(head, "Hyoga", "789654123");
    cout << remover(head).nome << '\n';
    cout << remover(head).nome << '\n';
	deletar(head);
    return 0;
}