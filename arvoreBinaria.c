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
ArvBin *inserir(int info, ArvBin* a,	ArvBin* b);
void imprimir(ArvBin* a);
int pares(ArvBin* a);
int folhas(ArvBin* a);
int um_filho (ArvBin* a); 

int main(){
	ArvBin* raiz = criar();
	ArvBin* a = criar();
	ArvBin* b = criar();
	ArvBin* c = criar();
	a = inserir(4,NULL,NULL);
	b = inserir(5,NULL,NULL);
	c = inserir(2,a,NULL);
	raiz = inserir(6,c,b);
	printf("Quantidade de arvores:%d\n",pares(raiz));
	printf("Quantidade de folhas:%d",folhas(raiz));
	//imprimir(raiz);
}

ArvBin *criar(){
	return NULL;
}

ArvBin *inserir(int info, ArvBin* a,	ArvBin* b){
	ArvBin* auxiliar = (ArvBin*)malloc(sizeof(ArvBin));
	auxiliar->valor = info;
	auxiliar->esquerda = a;
	auxiliar->direita = b;
	return auxiliar;
}

void imprimir(Binaria *raiz){
	Binaria *auxiliar = (Binaria*) malloc(sizeof(Binaria));
	auxiliar = raiz;
	printf("%d\n",auxiliar->info);
	imprimir(auxiliar->esquerda);
	imprimir(auxiliar->direita);
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
