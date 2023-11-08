#ifndef GRAFO_H
#define GRAFO_H

// Estruturas
typedef struct adjacencia ADJACENCIA; // Estrutura para representar uma adjacência em um grafo
typedef struct vertice VERTICE; // Estrutura para representar um vértice em um grafo
typedef struct grafo GRAFO; // Estrutura para representar um grafo
typedef int TIPOPESO; // Tipo de dado para representar o peso de uma aresta
typedef int bool; // Tipo de dado para representar um valor booleano

// Funções
GRAFO *criaGrafo(int v); // Função para criar um grafo com v vértices
ADJACENCIA *criadAdj(int v, int peso); // Função para criar uma adjacência com um vértice v e um peso
bool criaAresta(GRAFO *gr, int vi, int vf, TIPOPESO p); // Função para criar uma aresta de vi a vf com peso p em um grafo gr
void imprime(GRAFO *gr); // Função para imprimir um grafo
void Matriz(GRAFO *gr); // Função para imprimir a matriz de adjacência de um grafo
bool DFS(GRAFO *gr, int origem, int destino, int *total, int *visitados); // Função de Busca em Profundidade (DFS)
int valorTotalCaminho(GRAFO *gr, int origem, int destino); // Função para calcular o valor total do caminho entre dois vértices em um grafo


#endif