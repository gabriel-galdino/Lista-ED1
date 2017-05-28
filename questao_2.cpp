#include <bits/stdc++.h>

// Problema de Josephus

using namespace std;

struct Node{
    string nome;
    Node *next;
    Node(Node *head, string nome){
        this->nome = nome;
        this->next = head;
    }
    Node(){
        this->next = NULL;
    }
};

Node* criar(){
    Node *head = new Node();
    head->next = head;
    return head;
}

void inserir(Node *head, string nome, int pos){
    Node *aux;
    int i = 0;
    for(aux = head; aux->next != head and i < pos; aux = aux->next){
        i++;
	}	
    if(aux->next == head){
        aux->next = new Node(head, nome);
    }
	else{
        Node *k = new Node(head, nome);
        k->next = aux->next;
        aux->next = k;
    }
}

Node remover(Node *head, int pos){
    Node *aux;
    int i = 0;
    for(aux = head; aux->next != head and i < pos; aux = aux->next){
        i++;
	}	
    Node *k = aux->next; 
	Node r = *k;
    aux->next = aux->next->next;
    delete(k);
    return r;
}

void deletar(Node *head){
    Node *aux1 = head->next;
	Node *aux2 = head->next;
    while(aux1 != head){
        aux1 = aux1->next; 
		delete(aux2); 
		aux2 = aux1;
    }
	delete(aux2);
}

string josephus(Node *head, int n, int m)
{
    int c = 0, i;
    Node *aux = head;
    while(n != 1)
    {
        if(aux == head)
        {
            i = -1;
            aux = aux->next;
        }       
        else
        {
            i++, c++;
            if(c == m)
            {
                Node r = remover(head, i);
                n--;
                i--;
                c = 0;
                aux = r.next;
            }else
                aux = aux->next;
        }
    }
    return head->next->nome;
}

int main(){
    Node *head = criar();
    inserir(head, "Mu de Aries", 0);
    inserir(head, "Aiolia de Leão", 1);
    inserir(head, "Milo de Escorpiao", 2);
    inserir(head, "Saga de Gemeos", 3);
    inserir(head, "Shura de Capricornio", 4);
	inserir(head, "Camus de Aquario", 5);
	cout << josephus(head, 6, 2) << '\n';
	deletar(head);

    return 0;
}