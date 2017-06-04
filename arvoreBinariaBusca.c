#include<stdio.h>
#include<stdlib.h>

struct arvore{
	int valor;
	struct arvore *esquerda;
	struct arvore *direita;
};

typedef struct arvore ArvBin;

//prototipos
ArvBin *criar();
ArvBin *inserir(int info, ArvBin* a);
void imprimir(ArvBin* a);
int pares(ArvBin* a);
int folhas(ArvBin* a);
int um_filho (ArvBin* a); 

int main(){
	
	ArvBin *a = inserir(2,NULL);
	ArvBin *b = inserir(1,a);
	ArvBin *c = inserir(5,a);
	imprimir(a);
}


ArvBin *inserir(int info, ArvBin* a){
	if(a == NULL){
		a = (ArvBin*) malloc(sizeof(ArvBin));
		a->valor = info;
		a->esquerda	= a->direita = NULL;
	}
	else if(a->valor > info){
		a->esquerda = inserir(info,a->esquerda);
	}else{
		a->direita = inserir(info,a->direita);
	}
	return a;
}

void imprimir(ArvBin *a){
	if(a == NULL){
		return;
	}
	imprimir(a->esquerda);
	imprimir(a->direita);
	printf("%d\n",a->valor);
}

int pares(ArvBin* a){
    if(a == NULL){
        return 0;
    }
	int auxDireita = pares(a->direita);
	int auxEsquerda = pares(a->esquerda);
	int aux = 0;
	if(a->valor % 2 == 0){
		aux = 1;
	}
	return(auxEsquerda + auxDireita + aux);
}

int folhas(ArvBin* a){
	if(a == NULL){
		return 0;
	}
	int auxDireita =folhas(a->direita);
	int auxEsquerda =folhas(a->esquerda);
	return(auxEsquerda+auxDireita+1);
}

int um_filho (ArvBin* a){
	folhas(a->direita);
	folhas(a->esquerda);
	
}
