#include <stdio.h>
#include <stdlib.h>

struct registro{
    int simbolo;
    char palavra[20];
    int freq;
    char cod_huffman[20];
};

typedef struct registro Registro;

struct lista{
    Registro reg;
    struct lista *prox;
};

typedef struct lista Lista;

struct huffman{
    int freq;
    int simbolo;
    struct huffman *esq, *dir;
};

typedef struct huffman Huffman;

struct fila{
    Huffman *info;
    struct fila *prox;
};

typedef struct fila Fila;

char isEmpty(Fila *F){
    return F == NULL;
}

void criaCaixaHuffman(Huffman **H, int simbolo, int freq){
    (*H)->freq = freq;
    (*H)->simbolo = simbolo;
    (*H)->esq = (*H)->dir = NULL;
}

Fila *criaCaixaFila(Huffman *H){
    Fila *nova = (Fila *) malloc (sizeof(Fila));
    nova->info = H;
    nova->prox = NULL;

    return nova;
}

void enqueue(Huffman *H, Fila **F){
    Fila *nova = criaCaixaFila(H);
    Fila *aux, *ant;
    if(isEmpty(*F)){
        *F = criaCaixaFila(H);
    }else if(H->freq < (*F)->info->freq){ // insere no inicio
        nova->prox = *F;
        *F = nova;
    }else{
        ant = *F;
        aux = ant->prox;

        while(aux != NULL && H->freq >= aux->info->freq){
            ant = aux;
            aux = aux->prox;
        }

        ant->prox = nova;
        nova->prox = aux;
    }
}

void dequeue(Fila **F, Huffman **h1, Huffman **h2){
    Fila *aux1, *aux2;
    *h1 = (*F)->info;
    *h2 = (*F)->prox->info;

    aux1 = *F;
    aux2 = (*F)->prox;

    *F = (*F)->prox->prox;

    free(aux1);
    free(aux2);
}

Huffman *CriaArvore(Huffman *h1, Huffman *h2){
    Huffman *nova = (Huffman *) malloc (sizeof(Huffman));

    nova->freq = h1->freq + h2->freq;
    nova->simbolo = -1;
    nova->esq = h1;
    nova->dir = h2;

    return nova;
}

void exibeFila(Fila *F){
    while(F != NULL){
        printf("%d\n", F->info->freq);
        F = F->prox;
    }
}