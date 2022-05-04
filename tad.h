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

void enqueue(Huffman *H, Fila **F){
    Fila *aux = *F;
    if(isEmpty(aux)){
        aux->info = H;
        aux->prox = NULL;
    }else{
        while(H->freq > aux->info->freq){
            aux = aux->prox;
        }
    }
}