#include<stdio.h>
#include<stdlib.h>

struct no{
	int info;
	struct no *prim;
	struct no *prox;
};

typedef struct no No;
struct arv{
	No* raiz;
};
typedef struct arv Arv;

No* criaNo(int valor);
Arv* criaArv(No* r);
void insere(No* a,No* b);
void imprime(No *r);

int main(){
	
	No* a = criaNo(1);
	No* b = criaNo(2); 	
	No* c = criaNo(3);
	No* d = criaNo(4);
    
    insere(a,b);
    insere(a,c);
    insere(a,d);
    
    Arv* arvore = criaArv(a);
    imprime(a);
}

No* criaNo(int valor){
	No* a = (No*)malloc(sizeof(No));
	a->info = valor;
	a->prim = NULL;
	a->prox = NULL;
	return a;
}

Arv* criaArv(No *r){
	Arv *a = (Arv*) malloc(sizeof(Arv));
	a->raiz = r;
	return a;
}

void insere(No* a,No* b){
	b->prox = a->prim;
	a->prim = b;
}

void imprime(No *r){
	printf("%d",r->info);
	No* p = (No*)malloc(sizeof(No));
	for(p = r->prim;p !=NULL;p=p->prox){
		imprime(p);
	}
}

int altura(No *r){
	No* p = (No*)malloc(sizeof(No));
	int alt = altura(r->prim);
	int alt2 = altura(r->prox);
	if()
}
