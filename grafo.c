#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int **matrix_multiplication(int **m1, int **m2, int tam) {

  int **m = (int **)malloc(tam*sizeof(int *));

  for (int i=0; i<tam; i++)
    m[i] = (int *)malloc(tam*sizeof(int));

  for (int i=0; i<tam; i++)
    for (int j=0; j<tam; j++) {
      m[i][j] = 0;
    }

  for (int i=0; i<tam; i++)
    for (int j=0; j<tam; j++)
      for (int k=0; k<tam; k++)
        m[i][j] += m1[i][k]*m2[k][j];

  return m;
}

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

  vertice v = agfstnode(g);
  int sum = 0;

  while (v != NILnode) {
    sum += grau(v, g);
    v = agnxtnode(g, v);
  }
  
  return sum/n_vertices(g);

}

// -----------------------------------------------------------------------------
int regular(grafo g) {
 
  vertice v = agfstnode(g);
  int k = grau(v, g);

  while (v != NILnode) {
    if (k != grau(v, g)) 
      return FALSE;;
    v = agnxtnode(g, v);
  }

  return TRUE;
}

// -----------------------------------------------------------------------------
int completo(grafo g) {

  vertice v = agfstnode(g);
  int k = n_vertices(g) - 1;

  while (v != NILnode) {
    if (k != grau(v, g)) 
      return FALSE;;
    v = agnxtnode(g, v);
  }

  return TRUE;
  
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

  int sum = 0;
  int **m = matriz_adjacencia(g);

  m = matrix_multiplication(m, matrix_multiplication(m, m, n_vertices(g)), n_vertices(g));

  //m = matrix_multiplication(m, m, n_vertices(g));

  for (int i=0; i<n_vertices(g); i++) {
    sum += m[i][i];
  }

  return sum/6;
}

// -----------------------------------------------------------------------------
int **matriz_adjacencia(grafo g) {
  
  int **m = (int **)malloc(n_vertices(g)*sizeof(int *));
  vertice v1, v2;


  for (int i=0; i<n_vertices(g); i++)
    m[i] = (int *)malloc(n_vertices(g)*sizeof(int));

  v1 = agfstnode(g);

  for (int i=0; i<n_vertices(g); i++) {

    int j = 0;
    v2 = agfstnode(g);

    while (v2 != NILnode) {
      if (agedge(g, v1, v2, NULL, FALSE))
        m[i][j] = 1;
      else
        m[i][j] = 0;
      v2 = agnxtnode(g, v2);
      j++;
    }
    v1 = agnxtnode(g, v1);
  }
  return m;
      
}

// -----------------------------------------------------------------------------
grafo complemento(grafo g) {


  grafo g_;
  vertice v, v_, v_aux, v_aux_;

  g_ = agopen(NULL, Agundirected, NULL);
  v = agfstnode(g);


  while (v != NILnode) {

    //printf("%s\n", agnameof(v));
    v_ = agnode(g_, agnameof(v), TRUE);
    v = agnxtnode(g, v);
    //printf("%d\n", n_vertices(g_));

  }

  //printf("vertices criados\n");
  v = agfstnode(g);
  v_ = agfstnode(g_);
  while (v != NILnode) {

    v_aux = agfstnode(g);
    v_aux_ = agfstnode(g_);

    //printf("%s %s\n", agnameof(v), agnameof(v_aux));

    while (v_aux != NILnode) {
      //printf("in loop\n");
      if ((v != v_aux) && (!agedge(g, v, v_aux, NULL, FALSE))) {
        //printf("creating edge between %s and %s\n", agnameof(v), agnameof(v_aux));
        agedge(g_,v_, v_aux_, NULL, TRUE);
      } //else
        //printf("NOT creating edge between %s and %s\n", agnameof(v), agnameof(v_aux));
      v_aux = agnxtnode(g, v_aux);
      v_aux_ = agnxtnode(g_, v_aux_);
    }
    //printf("out of loop\n");
    v = agnxtnode(g, v);
    v_ = agnxtnode(g_, v_);
  }
  //printf("finished graph\n");
  return g_;
}

