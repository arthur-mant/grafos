#include <stdio.h>
#include "grafo.h"

//------------------------------------------------------------------------------

int main(void) {

  grafo g = le_grafo();

  escreve_grafo(g);

  printf("vertices: %d\narestas: %d\n", n_vertices(g), n_arestas(g));
  
  printf("grau maximo: %d\n", grau_maximo(g));
  printf("grau minimo: %d\n", grau_minimo(g));

  printf("grau medio: %d\n", grau_medio(g));

  printf("o grafo ");
  if (!regular(g))
    printf("não ");
  printf("eh regular\n");

  printf("o grafo ");
  if (!completo(g))
    printf("não ");
  printf("eh completo\n");

  int **m = matriz_adjacencia(g);
  for (int i=0; i<n_vertices(g); i++) {
    for (int j=0; j<n_vertices(g); j++)
      printf("%d ", m[i][j]);
    printf("\n");
  }

  printf("\n");

  m = matriz_adjacencia(complemento(g));
  for (int i=0; i<n_vertices(g); i++) {
    for (int j=0; j<n_vertices(g); j++)
      printf("%d ", m[i][j]);
    printf("\n");
  }

  printf("possui %d triangulos\n", n_triangulos(g));

  printf("g ");
  if (!conexo(g))
    printf("nao ");
  printf("eh conexo\n");

  printf("g ");
  if (!bipartido(g))
    printf("nao ");
  printf("eh bipartido\n");


  destroi_grafo(g);

  return 0;
}
