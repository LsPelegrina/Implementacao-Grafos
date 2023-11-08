#include <stdio.h>
#include <stdlib.h>
#include "Grafo.c"

int main() {
    GRAFO *gr1 = criaGrafo(5); // Cria o primeiro grafo com 5 vértices

    // Adiciona as arestas conforme o grafo da imagem, porém sem estar orientado, logo as arestas são bidirecionais 
    criaAresta(gr1, 0, 0, 0);
    criaAresta(gr1, 0, 2, 0);
    criaAresta(gr1, 2, 0, 0);
    criaAresta(gr1, 2, 1, 0);
    criaAresta(gr1, 2, 3, 0);
    criaAresta(gr1, 3, 1, 0);
    criaAresta(gr1, 3, 4, 0);
    criaAresta(gr1, 3, 2, 0);
    criaAresta(gr1, 1, 2, 0);
    criaAresta(gr1, 1, 3, 0);
    criaAresta(gr1, 1, 4, 0);
    criaAresta(gr1, 4, 1, 0);
    criaAresta(gr1, 4, 3, 0);

    // Lista de adjacencia
    imprime(gr1);

    // Imprime a matriz de adjacência do primeiro grafo
    Matriz(gr1);

    // Calcula e imprime o valor total do caminho de 1 a 5 no primeiro grafo, cujo é igual da imagem, porém não é orientado e não possui pesos.
    int total1 = valorTotalCaminho(gr1, 0, 4);
    if (total1 != -1) {
        printf("\nO valor total do caminho de 1 a 5 no primeiro grafo e..: %d\n", total1);
    } else {
        printf("\nNao existe caminho de 1 a 5 no primeiro grafo\n");
    }

    printf("\n");
    printf("--------------------------------------------------------"); //Espacanento
    printf("\n\n");

    // Cria o segundo grafo com 5 vértices
    GRAFO *gr2 = criaGrafo(5);

    // Adiciona as arestas no segundo grafo, orientado e com pesos
    criaAresta(gr2, 0, 0, 2);
    criaAresta(gr2, 0, 2, 4);
    criaAresta(gr2, 2, 1, 16);
    criaAresta(gr2, 2, 3, 9);
    criaAresta(gr2, 3, 1, 8);
    criaAresta(gr2, 3, 4, 1);
    criaAresta(gr2, 4, 1, 5);

    // Lista de adjacencia
    imprime(gr2);

    // Imprime a matriz de adjacência do segundo grafo
    Matriz(gr2);

    // Calcula e imprime o valor total do caminho de 1 a 5 no segundo grafo, cujo é igual da imagem, porém orientado e possui pesos.
    int total2 = valorTotalCaminho(gr2, 0, 4);
    if (total2 != -1) {
        printf("\nO valor total do caminho de 1 a 5 no segundo grafo e..: %d\n", total2);
    } else {
        printf("\nNao existe caminho de 1 a 5 no segundo grafo\n");
    }

    return 0;
}