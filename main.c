#include "tad.h"

int main(){
    Huffman *h1, *h2, *h3, *h4, *hAux1, *hAux2, *Tree;
    Fila *F = NULL;

    h1 = (Huffman *) malloc (sizeof(Huffman));
    h2 = (Huffman *) malloc (sizeof(Huffman));
    h3 = (Huffman *) malloc (sizeof(Huffman));
    h4 = (Huffman *) malloc (sizeof(Huffman));

    criaCaixaHuffman(&h1, 1, 3);
    criaCaixaHuffman(&h2, 2, 2);
    criaCaixaHuffman(&h3, 3, 1);
    criaCaixaHuffman(&h4, 4, 1);

    enqueue(h1, &F);
    enqueue(h2, &F);
    enqueue(h3, &F);
    enqueue(h4, &F);

    dequeue(&F, &hAux1, &hAux2);

    Tree = CriaArvore(hAux1, hAux2);
    enqueue(Tree, &F);

    dequeue(&F, &hAux1, &hAux2);
    Tree = CriaArvore(hAux1, hAux2);
    enqueue(Tree, &F);

    dequeue(&F, &hAux1, &hAux2);
    Tree = CriaArvore(hAux1, hAux2);
    enqueue(Tree, &F);
    exibeFila(F);

}