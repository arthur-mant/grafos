#include <stdio.h>
#include "grafo.h"

//------------------------------------------------------------------------------

int main(void) {

  grafo g = le_grafo();

  escreve_grafo(g);

  printf("vertices: %d\narestas: %d\n", n_vertices(g), n_arestas(g));
  
  printf("grau maximo: %d\n", grau_maximo(g));
  printf("grau minimo: %d\n", grau_minimo(g));

  destroi_grafo(g);

  return 0;
}
