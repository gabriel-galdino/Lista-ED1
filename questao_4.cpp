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
	cliente *c = new cliente(nome, cpf);
    while(aux->next != NULL){
        aux = aux->next;
	}	
    aux->next = c;
}

cliente remover(cliente *head){
    cliente *aux = head->next;
	cliente	r = *aux;
    if(aux->next == NULL){
        head->next = NULL;
	}	
    else{
        head->next = aux->next;
	}	
    delete(aux);
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
    inserir(head, "Ikki", "741258963");
    inserir(head, "Shun", "123987456");
    cout << remover(head).nome << '\n';
    cout << remover(head).nome << '\n';
    deletar(head);
	return 0;
}