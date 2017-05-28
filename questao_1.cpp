#include <bits/stdc++.h>

// Representação de Grafos

using namespace std;

struct Node{
    int v;
    Node *next;
    Node(int v){
        this->v = v;
        this->next = NULL;
    }
    Node(){
        this->v = 0;
        this->next = NULL;
    }
};

struct Head{
    Node *adj;
    Node *end;
    bool flag;
};

Head* criar(int n){
    Head *head = new Head[n];
    for(int i = 0; i < n; i++){
        head[i].adj = new Node();
		head[i].flag = false; 
		head[i].end = head[i].adj;
	}	
    return head;
}
    
void inserir(Head *head, int v, int x){
    head[v].end->next = new Node(x);
    head[v].end = head[v].end->next;
    head[v].adj->v++;
    return;
}

void deletar(Head *head, int n){
    Node *aux, *k;
    for(int i = 0; i < n; i++){
        aux = head[i].adj;
        while(aux != NULL){
            k = aux->next;
			delete(aux); 
			aux = k;
		}
	}
    delete[] head;
}

void imprimir(Head *head, int n){
    for(int i = 0; i < n; i++)
    {
        cout << i << ": ";
        for(Node *aux = head[i].adj->next; aux != NULL; aux = aux->next){
            cout << aux->v << ' ';
		}	
        cout << '\n';
    }
}

int main(){
    Head *head = criar(3);
	inserir(head, 0, 2);
    inserir(head, 2, 0);
    inserir(head, 0, 1);
    inserir(head, 1, 0);
    inserir(head, 1, 2);
    inserir(head, 2, 1);
    imprimir(head, 3);
    cout << '\n'; 
    deletar(head, 3);
     
    return 0;
}