#include <stdio.h>
#include "grafo.h"

//------------------------------------------------------------------------------
grafo le_grafo(void) {

  return agread(stdin, NULL); 
}
//------------------------------------------------------------------------------
void destroi_grafo(grafo g) {
  agclose(g);
  return 1;
}
//------------------------------------------------------------------------------
grafo escreve_grafo(grafo g) {
  
  return agwrite(g, stdout);
}

// -----------------------------------------------------------------------------
int n_vertices(grafo g) {
  
  return agnnodes(g);
}

// -----------------------------------------------------------------------------
int n_arestas(grafo g) {
  
  return agnedges(g);
}

// -----------------------------------------------------------------------------
int grau(vertice v, grafo g) {

  return agdegree(g, v, TRUE, TRUE);
}

// -----------------------------------------------------------------------------
int grau_maximo(grafo g)  {
  
  vertice v = agfstnode(g);
  int grau_max = 0;

  while (v != NILnode) {
    if (grau(v, g) > grau_max)
      grau_max = grau(v, g);
    v = agnxtnode(g, v);
  }


  return grau_max;
}

// -----------------------------------------------------------------------------
int grau_minimo(grafo g)  {

  vertice v = agfstnode(g);
  int grau_min = n_vertices(g);

  while (v != NILnode) {
    if (grau(v, g) < grau_min)
      grau_min = grau(v, g);
    v = agnxtnode(g, v);
  }
  
  return grau_min;
}

// -----------------------------------------------------------------------------
int grau_medio(grafo g) {
  
  return 0;
}

// -----------------------------------------------------------------------------
int regular(grafo g) {
  
  return 0;
}

// -----------------------------------------------------------------------------
int completo(grafo g) {
  
  return 0;
}

// -----------------------------------------------------------------------------
int conexo(grafo g) {
  
  return 0;
}

// -----------------------------------------------------------------------------
int bipartido(grafo g) {
  
  return 0;
}

// -----------------------------------------------------------------------------
int n_triangulos(grafo g) {
  
  return 0;
}

// -----------------------------------------------------------------------------
int **matriz_adjacencia(grafo g) {
  
  return NULL;
}

// -----------------------------------------------------------------------------
grafo complemento(grafo g) {
  
  return NULL;
}

