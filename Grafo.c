#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"

#define true 1
#define false 0

typedef int bool;
typedef int TIPOPESO;

// Estrutura para representar uma adjacência em um grafo
typedef struct adjacencia{
    int vertice; // Vértice de destino
    TIPOPESO peso; // Peso associado à aresta que leva ao vértice
    struct adjacencia *prox; // Próximo elemento da lista de adjacências
}ADJACENCIA;

// Estrutura para representar um vértice em um grafo
typedef struct vertice{
    ADJACENCIA *cab; // Cabeça da lista de adjacências
}VERTICE;

// Estrutura para representar um grafo
typedef struct grafo{
    int vertices; // Número total de vértices
    int arestas; // Número total de arestas
    VERTICE *adj; // Arranjo de vértices da estrutura
}GRAFO;

// Função para criar um grafo com v vértices
GRAFO *criaGrafo (int v){
    int i;

    // Aloca memória para o grafo
    GRAFO *g = (GRAFO *)malloc(sizeof(GRAFO));
    g->vertices = v;
    g->arestas = 0;
    g->adj = (VERTICE *)malloc(v*sizeof(VERTICE));

    // Inicializa a lista de adjacências de cada vértice
    for(i=0; i<v; i++){
        g->adj[i].cab=NULL;
    }
    return (g);
}

// Função para criar uma adjacência com um vértice v e um peso
ADJACENCIA *criadAdj(int v, int peso){
    // Aloca espaço para a adjacência
    ADJACENCIA *temp = (ADJACENCIA *)malloc(sizeof(ADJACENCIA));
    temp->vertice =v; // Vértice alvo da adjacência
    temp->peso = peso; // Peso da aresta
    temp->prox = NULL; 
    return(temp); // Retorna o endereço da adjacência
}

// Função para criar uma aresta de vi a vf com peso p em um grafo gr
bool criaAresta(GRAFO *gr, int vi, int vf, TIPOPESO p){
    // Validações se o grafo existe e se os vértices são válidos
    if(!gr) return(false);
    if((vf<0)||(vf>=gr->vertices))return(false);
    if((vi<0)||(vf>=gr->vertices))return(false);

    // Cria a adjacência com o vértice final e o peso
    ADJACENCIA *novo = criadAdj(vf,p);

    // Coloca a adjacência na lista do vértice inicial
    novo->prox = gr->adj[vi].cab;
    gr->adj[vi].cab=novo;

    // Atualiza o número de arestas no grafo
    gr->arestas++;
    return (true);
}

// Função para imprimir um grafo
void imprime(GRAFO *gr){
    printf("Vertices..: %d. Arestas..: %d \n",gr->vertices,gr->arestas);
    int i;

    // Percorre cada vértice do grafo
    for(i = 0; i<gr->vertices; i++){
        printf("v%d:",i+1);

        // Percorre a lista de adjacências do vértice
        ADJACENCIA *ad = gr->adj[i].cab;
        while (ad){
            printf("v%d(%d) ",ad->vertice+1,ad->peso);
            ad=ad->prox;
        }
        printf("\n");
    }
}

// Função para imprimir a matriz de adjacência de um grafo
void Matriz(GRAFO *gr) {
    printf("\n\nMatriz de Adjacencia:\n");

    // Percorre cada vértice do grafo
    for (int i = 0; i < gr->vertices; i++) {
        for (int j = 0; j < gr->vertices; j++) {
            int adjacencia = 0;

            // Percorre a lista de adjacências do vértice
            ADJACENCIA *ad = gr->adj[i].cab;
            while (ad) {
                if (ad->vertice == j) {
                    adjacencia = ad->peso;
                }
                ad = ad->prox;
            }
            printf("%d\t", adjacencia);
        }
        printf("\n");
    }
}

// Função de Busca em Profundidade (DFS)
bool DFS(GRAFO *gr, int origem, int destino, int *total, int *visitados) {
    // Se o vértice de origem é igual ao vértice de destino, retorna verdadeiro
    if (origem == destino) {
        return true;
    }

    // Marca o vértice de origem como visitado
    visitados[origem] = 1;

    // Obtém a lista de adjacências do vértice de origem
    ADJACENCIA *ad = gr->adj[origem].cab;

    // Percorre a lista de adjacências
    while (ad) {
        // Se o vértice adjacente não foi visitado e existe um caminho do vértice adjacente ao destino
        if (!visitados[ad->vertice] && DFS(gr, ad->vertice, destino, total, visitados)) {
            // Adiciona o peso da aresta ao total
            *total += ad->peso;

            // Retorna verdadeiro pois encontrou um caminho
            return true;
        }

        // Passa para a próxima adjacência
        ad = ad->prox;
    }

    // Se não encontrou um caminho, retorna falso
    return false;
}

// Função para calcular o valor total do caminho entre dois vértices em um grafo
int valorTotalCaminho(GRAFO *gr, int origem, int destino) {
    int total = 0; // Variável para armazenar o valor total do caminho

    // Cria um vetor de visitados com o mesmo número de vértices do grafo
    // Inicialmente, todos os vértices são marcados como não visitados (0)
    int *visitados = (int*) calloc(gr->vertices, sizeof(int));

    // Se existe um caminho do vértice de origem ao vértice de destino
    if (DFS(gr, origem, destino, &total, visitados)) {
        // Libera a memória alocada para o vetor de visitados
        free(visitados);

        // Retorna o valor total do caminho
        return total;
    } else {
        // Libera a memória alocada para o vetor de visitados
        free(visitados);

        // Retorna -1 se não houver caminho
        return -1;
    }
}
