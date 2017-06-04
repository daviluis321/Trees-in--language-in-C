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

Arv* cria();
No* insere(No *r,int V);
void insereRaiz(Arv*a,int v);
void imprimir_pre_ordem(No *r);
void imprime_arv(Arv* a);
No* excluir(No* r,int V);
No* retira(No* r ,int V);
int buscaUm(No *r);
void buscaUmArv(Arv *a);
int pares(No *r);
void paresArv(Arv *a);
int grau(No *r,int v);
void grauArv(Arv *a,int v);
int maior(No *r);
void maiorArv(Arv *a);

int main(){
	int valor;
	Arv *a = cria();
    /*int continua = 1;
    while(continua == 1){
    	printf("Digite o valor:");
		scanf("%d",&valor);
    	if(valor == -1){
			break;
		}else{
			insereRaiz(a,valor);
		}
	}*/
	insereRaiz(a,41);
	insereRaiz(a,3);
	insereRaiz(a,42);
	insereRaiz(a,8);
	insereRaiz(a,4);
	insereRaiz(a,2);
	
	buscaUmArv(a);//primeira questão
	paresArv(a);//segunda questão
	grauArv(a,8);//terceira questão
	maiorArv(a);//quarta questao
}

Arv* cria(){
	Arv* a = (Arv*)malloc(sizeof(Arv));
	a->raiz = NULL;
	return a;
}

No* insere(No *r,int V){
	if(r == NULL){
		r=(No*)malloc(sizeof(No));
		r->info = V;
		r->esq = NULL;
		r->dir=NULL;
	}else{
		if(r->info==V){
			return r;
		}else{
			if( r->info > V){
				r->esq = insere(r->esq,V);
			}else{
				r->dir = insere(r->dir,V);
			}
		}
	} 
	return r;
}

void insereRaiz(Arv*a,int V){
	a->raiz= insere(a->raiz,V);
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

No* excluir(No *r,int V){
	if(r->esq ==  NULL && r->dir == NULL){
		free(r);
		r=NULL;
	}else if(r->esq == NULL){
		No* t = r;
		r=r->dir;
		free(t);
	}else if(r->dir==NULL){
		No* t = r;
		r= r->esq;
		free(t);
	}
	else{
		No* t = r->esq;
		while(t->dir != NULL){
			t=t->dir;
		}
		r->info = t->info;
		t->info = V;
		r->esq = retira(r->esq,V);
	}
}

No* retira(No* r ,int V){
	if(r==NULL){
		return NULL;
	}
	else if(r->info>V){
		r->esq = retira(r->esq,V);
	}else if(r->info < V){
		r->dir = retira(r->dir,V);
	}else{
	}
}


int buscaUm(No *r){//primeira questão
	if(r == NULL){
		return;
	}
	int alt_esq = buscaUm(r->esq);
	int alt_dir = buscaUm(r->dir);
	int quant = 0;
	if(r->esq == NULL && r->dir!=NULL){
		quant = 1;
	}else if(r->esq != NULL && r->dir==NULL){
		quant = 1;
	}
	return(alt_esq + alt_dir+quant);
}

void buscaUmArv(Arv *a){//primeira questão
	printf("A quantidade de nos que possui apenas um filho:%d\n",buscaUm(a->raiz));
}

int pares(No *r){//segunda questão
	if(r == NULL){
		return;
	}
	int alt_esq = pares(r->esq);
	int alt_dir = pares(r->dir);
	int quant = 0;
	if(r->info % 2 == 0){
		quant = 1;
    }
	return(alt_esq + alt_dir+quant);
}

void paresArv(Arv *a){//segunda questão
	printf("A quantidade de nos que armazennam numeros pares:%d\n",pares(a->raiz));
}

int grau(No *r,int v){//terceira questão
	if(r == NULL){
		return 0;
	}else{
		 if(r->info > v){
		 	grau(r->esq,v);
		 }
    	 else if(r->info < v){
    	 	grau(r->dir,v);
    	 }else{
    	 	if(r->esq == NULL && r->dir == NULL){
    	 		return 0;
    	 	}else if(r->esq != NULL && r->dir == NULL){
    	 		return 1;
    	 	}else if(r->esq == NULL && r->dir != NULL){
    	 		return 1;
    	 	}else if(r->esq != NULL && r->dir != NULL){
    	 		return 2;
    	 	}
    	 }
	}
}

void grauArv(Arv *a,int v){//terceira questão
	printf("O grau do no escolhido:%d\n",grau(a->raiz,v));
}


int maior(No *r){
	if(r == NULL){
		return ;
    }else{
    	if(r->dir->dir !=NULL){
   			maior(r->dir);
    	}else{
    		return r->dir->info;
    	}
    }
}

void maiorArv(Arv *a){
	printf("O maior valor:%d",maior(a->raiz));
}
