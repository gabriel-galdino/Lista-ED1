#include <bits/stdc++.h>

using namespace std;

struct cliente{
    string nome; 
	string cpf;
    cliente *next; 
	cliente *prev;
    cliente(string nome, string cpf){
		this->nome = nome;
		this->cpf = cpf; 
		next = NULL; 
		prev = NULL;
	}
    cliente(){
		next = NULL; 
		prev = NULL;
	}
};

cliente* criar(){
    cliente *head = new cliente();
    return head;
}

void inserir(cliente *head, string nome, string cpf, int pos){
    cliente *aux = head;
	cliente	*c = new cliente(nome, cpf);
    int i = 1;
    while(i < pos and aux->next != NULL)
        aux = aux->next, i++;

    if(aux->next == NULL){
        aux->next = c;
		c->prev = aux; 
		c->next = NULL;
	}	
    else{
        c->next = aux->next; 
		c->next->prev = c; 
		aux->next = c; 
		c->prev = aux;
	}
}

cliente remover(cliente *head, int pos){
    cliente *aux = head->next;
	cliente	r;
    int i = 1;
    while(i < pos and aux->next != NULL){
        aux = aux->next;
		i++;
	}	
    r = *aux;
    if(aux->next == NULL){
        aux->prev->next = NULL;
	}	
    else{
        aux->prev->next = aux->next; 
		aux->next->prev = aux->prev;
	}	
    return r;
}

int buscar(cliente *head, cliente *c){
    cliente *aux = head->next;
    int i = 1;
    while(aux->cpf != c->cpf){
        aux = aux->next; 
		i++;
	}	
    return i;
}


void listar(cliente *head){
    cliente *aux = head->next;
    while(aux != NULL){
        cout << aux->nome << '\n'; 
		aux = aux->next;
	}	
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
	inserir(head, "Jabu", "741852963", 1);
	inserir(head, "Shiryu", "789654123", 1);
	cout << remover(head, 1).nome << '\n';
	cout << remover(head, 1).nome << '\n';
	deletar(head);
	return 0;
}