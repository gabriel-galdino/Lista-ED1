#include <bits/stdc++.h>

using namespace std;

struct Cliente{
	string cpf;
	string nome;
	Cliente *next;
	Cliente(string cpf, string nome){
		this->cpf = cpf;
		this->nome = nome;
		next = NULL;
	}
	Cliente(){
		next = NULL;
	}
};

Cliente* criar(){
	Cliente *head;
	head = new Cliente();
	return head;
}

void inserir(Cliente *head, string cpf, string nome, int pos){
	int index = pos - 1;
	Cliente *aux = head;
	Cliente *cav = new Cliente(cpf, nome);
	for(int i = 0; i < index and aux->next != NULL; i++){
		aux = aux->next;
	}
	if(aux->next == NULL){
		aux->next = cav;
	}
	else{
		cav->next = aux->next;
		aux->next = cav;
	}
}

Cliente remover(Cliente *head, int pos){
	Cliente *aux = head, r;
	Cliente *aux2;
	int index = pos - 1;
	for(int i = 0; i < index and aux->next != NULL; i++){
		aux = aux->next;
	}
	r = *(aux->next);
	if(aux->next->next == NULL){
		aux->next = NULL;
		delete(aux->next);
	}
	else{
		aux2 = aux->next->next;
		delete(aux->next);
		aux->next = aux2;
	}
	return r;
}

int buscar(Cliente *head, string cpf, string nome){
	Cliente *aux = head->next;
	int i = 0;
	for(i = 0; aux->cpf == cpf and aux->nome == nome; i++){
		aux = aux->next;
	}
	return i;
}

void listar(Cliente *head){
	Cliente *aux = head->next;
	while(aux != NULL){
		cout << aux->cpf << ' ' << aux->nome << '\n';
		aux = aux->next;
	}
}

void deletar(Cliente *head){
	Cliente *aux = head;
	while(aux->next != NULL){
		aux = aux->next;
		delete(head);
		head = aux->next;
	}
}



int main(){
	Cliente *head = criar();
	inserir(head, "123456789", "Mu de Aries", 1);
	inserir(head, "213456789", "Aldebaran de Touro", 2);
	inserir(head, "312456789", "Saga de Gemeos", 3);
	inserir(head, "931245678", "Afrodite de Peixes", 4);
	listar(head);
	remover(head, 4);
	listar(head);
	inserir(head, "412356789", "Mascara da Morte de Cancer", 4);
	listar(head);
	inserir(head, "741852963", "Shura de Capricornio", 10);
	inserir(head, "931245678", "Afrodite de Peixes", 12);
	listar(head);
	return 0;
}



