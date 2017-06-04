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
int altura(No *r);
int impares(No *r);
int impares2(No *r);
int folhas(No *r);
void folhaArv(Arv *a);
int umFilho(No*r);
int umFilhoArv(Arv *a);
void busca_e_remove (int y,No *a);
//int maiorNo(No*r);
int mairNo(No*r);
int mairNoArv(Arv *a);
void menor(No*r,int valor);
No* buscar(No*r,int valor);
void buscarMenorArv(Arv *a,int valor);
No* pai(No* a, int no);
void imprime_pai(No* pai);


int main(){

	No* a = criaNo(1);
	No* b = criaNo(22);
	No* c = criaNo(3);
	No* d = criaNo(60);
	No* e = criaNo(5);

    insere(a,b);
    insere(a,c);
    insere(a,d);
    insere(b,e);


    Arv* arvore = criaArv(a);
   	mairNoArv(arvore);//primeira questao
   	buscarMenorArv(arvore,22);//segunda questao
    folhaArv(arvore);//terceira questao
    No *aux;//quarta questao
    aux =pai(a,5);//quarta questao
    imprime_pai(aux);//quarta questao
	return 0;
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

int impares(No *r){
	if(r==NULL){
		return 0;
    }
	int var = 0;
	if(r->info % 2 != 0){
		var = 1;
	}
	return impares(r->prim) + impares(r->prox)+var;
}

int impares2(No *r){
    No *p;
    int h = 0;
    if(r->info % 2 != 0){
        h = 1;
    }
    for(p = r->prim; p != NULL; p = p->prox){
        h = h + impares2(p);
    }
    return h;
}


int folhas(No *r){
    No *p;
    int h = 0;
    if(r->prim == NULL){
        h = 1;
    }
    for(p = r->prim; p != NULL; p = p->prox){
        h = h + folhas(p);
    }
    return h;
}
void folhaArv(Arv *a){
    printf("A quantidade de folhas na arvore:%d",folhas(a->raiz));
}

int umFilho(No*r){
    No *p;
    int h = 0;
    if(r->prim != NULL && r->prim->prox == NULL){
        h = 1;
    }
    for(p = r->prim; p != NULL; p = p->prox){
        h = h + umFilho(p);
    }
    return h;
}

int umFilhoArv(Arv *a){
     printf("\n No com apenas um filho:%d",umFilho(a->raiz));
}

int verifica_igualdade(No* a,No* b){
    if(a == NULL && b == NULL)
        return 1;
    if(a == NULL || b == NULL)
        return 0;
    return ((a->info == b->info) && verifica_igualdade(a->prox, b->prox) && verifica_igualdade(a->prim, b->prim));
}

void busca_e_remove (int y,No *a)
{
   No *p, *q;
   p = a;
   q = a->prox;
   while(q != NULL && q->info != y) {
      p = q;
      q = q->prox;
   }
   if (q != NULL) {
      p->prox = q->prox;
      free(q);
   }
}

int maiorGalho(No*r){
	int i,j;
    if(r==NULL){
    	return 0;
    }
	if((r->prox==NULL)&&(r->prim==NULL)){
    	return 1;
    }

    i = maiorGalho(r->prim);
    j = maiorGalho(r->prox);
    if(j>i){
    	return j+1;
    }else{
    	return i+1;
    }
}

/*No *p = (No*)malloc(sizeof(No));;
    //printf("sssss");
    if(r->info > maior ){
        maior = r->info;
    }
    for(p = r->prim; p != NULL; p = p->prox){
    	maiorNo(r,maior);
    }
    return maior;*/

/*int altura(No *r){
	No *p;
    int h = 0;
    for(p = r->prim; p != NULL; p = p->prox)
    }
    return h;
}*/

int mairNo(No*r){//primeira questão
	int i,j;

	if((r->prox==NULL)&&(r->prim==NULL)){//se a raiz for um nó folha retorna o proprio valor
    	return r->info;
    }
	if(r->prox==NULL){//se o no não possuir irmoes
		j=mairNo(r->prim);//chama recursivamente todos os filhos desse no
		if(r->info>j){
			return (r->info);
		}else{
			return j;
		}
	}else if(r->prim==NULL){
		i = mairNo(r->prox);
		if(r->info>i){
			return (r->info);
		}else{
			return i;
		}
	}else{
		j = mairNo(r->prim);
		i = mairNo(r->prox);
		if(i>j){
				if(r->info>i){
					return (r->info);
				}else{
					return i;
				}
		}else{
			if(r->info>j){
				return (r->info);
			}else{
				return j;
			}
		}
	}
}

int mairNoArv(Arv *a){//primeira questao
	printf("\nO maior no da arvore:%d\n",mairNo(a->raiz));
}

void menor(No*r,int valor){
	if(r->info < valor){
		printf("Os menores associados ao valor escolhido:%d\n",r->info);
	}
	No* p = (No*)malloc(sizeof(No));
	for(p = r->prim;p !=NULL;p=p->prox){
		menor(p,valor);
	}
}

No* buscar(No*r,int valor){
	if(r->info == valor){
		menor(r,valor);
		return;
	}
	No *p;
	for(p = r->prim; p != NULL; p = p->prox){
       buscar(p,valor);
	}
}
void buscarMenorArv(Arv *a,int valor){
    menor(a->raiz,valor);
}

No* pai(No* a, int no){//quarta questao
    No *p;
    No *pai2 = NULL;
    if(a->prim == NULL && a->prox == NULL){
        return ;
    }
    for(p = a->prim; p != NULL; p = p->prox){
        if(p->info == no){
            return a;
        }
        pai2 = pai(p, no);
    }
    return pai2;
}
void imprime_pai(No* pai){//quarta questao
    printf("\nPai do no: %d\n", pai->info);
}
 

