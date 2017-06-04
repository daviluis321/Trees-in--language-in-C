#include<stdio.h>
#include<stdlib.h>

struct no{
	int info;
	struct no *esq;
	struct no *dir;
};

typedef struct no No;
typedef struct arv Arv;

struct arv{
	No *raiz;
};

No*cria_no(int n,No* esq,No* dir);
Arv* cria_Arvore(No* r);
void libera_nos(No* r);
void libera_arv(Arv* a);
void imprimir_pre_ordem(No *r);
void imprime_arv(Arv* a);
int altura_no(No*a);
void altura_arv(Arv *a);
int folhas(No*a);
void folhas_arv(Arv *a);
int pares(No *a);
void pares_arv(Arv *a);
int impares(No *a);
void imparespares_arv(Arv *a);
No* bus_num_arv(Arv *a,int num);


int main(){
	Arv* a = cria_Arvore(
		cria_no(1,
			cria_no(2,
			    cria_no(7,NULL,NULL),
				cria_no(4,NULL,NULL)),
			cria_no(3,
				cria_no(5,NULL,NULL),
				cria_no(6,NULL,
						cria_no(8,NULL,NULL)
				)
			)	
		)
	);
	
	//imprime_arv(a);
	altura_arv(a);
	folhas_arv(a);//questao 2
	pares_arv(a);// questao 3
	imparespares_arv(a);//questao4
	bus_num_arv(a,3);//questao
	
//	printf("\n%d\n",folhas(No*a))
}


No*cria_no(int n,No* esq,No* dir){
	No* p = (No*)malloc(sizeof(No));
	p->info=n;
	p->esq=esq;
	p->dir=dir;
	return p;
}

Arv* cria_Arvore(No* r){
	Arv* a = (Arv*) malloc(sizeof(Arv));
	a->raiz=r;
	return a;
}

void libera_nos(No* r){
	if(r != NULL){
		libera_nos(r->esq);
		libera_nos(r->dir);
		free(r);
	}
}

void libera_arv(Arv* a){
	libera_nos(a->raiz);
	free(a);
}

void imprimir_pre_ordem(No *r){
	if(r == NULL){
		return;
	}
	printf("%d",r->info);
	imprimir_pre_ordem(r->esq);
	imprimir_pre_ordem(r->dir);
}
void imprime_arv(Arv* a){
	imprimir_pre_ordem(a->raiz);
}

int altura_no(No*a){
	if(a == NULL){
		return -1;
	}
	int alt_esq = altura_no(a->esq);
	int alt_dir = altura_no(a->dir);
	if(alt_esq > alt_dir){
		return(alt_esq +1);
	}else{
		return(alt_dir +1);
	}
}
void altura_arv(Arv *a){
	printf("\nAltura : %d\n",altura_no(a->raiz));
}

int folhas(No*a){//questao 3
	if(a == NULL){
		return 0 ;
	}
	int alt_esq = folhas(a->esq);
	int alt_dir = folhas(a->dir);
	int aux = 0;
	if(a->esq == NULL && a->dir == NULL ){
		aux = 1;
	}
	return(alt_esq + alt_dir + aux);
}

void folhas_arv(Arv *a){//questao 3
	printf("\nQuantidade de folhas : %d\n",folhas(a->raiz));
}

int pares(No *a){//questao 4
	if(a == NULL){
		return ;
	}
	int  alt_esq = pares(a->esq);
	int  alt_dir = pares(a->dir);
    int	aux = 0;
	if(a->info % 2 == 0){
		aux = 1;
	}
	return(alt_esq+alt_dir+aux);
}

void pares_arv(Arv *a){//questao4
	printf("\n Os pares da arvores sao:%d\n",pares(a->raiz));
}

int impares(No *a){//questao 4
	if(a == NULL){
		return ;
	}
	int  alt_esq = impares(a->esq);
	int  alt_dir = impares(a->dir);
	int aux = 0;
	if(a->info % 2 != 0){
	   aux = a->info;
	}
	return(alt_esq+alt_dir+aux);
}

void imparespares_arv(Arv *a){//questao4
	printf("\n A soma dos impares das arvores sao:%d\n",impares(a->raiz));
}

No * bus_num(No* a,int num){//questao 1
	if(a == NULL){
		return NULL;
	}
	No *p = bus_num(a->esq,num);
	if(p != NULL){
		return p;
	}else{
		return(bus_num(a->dir,num));
	}
}

No* bus_num_arv(Arv *a,int num){//questao 1
    return  bus_num(a->raiz,num);
}
