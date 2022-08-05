Aqui serão citados todos os detalhes utilizados para a implementação de cada função desta biblioteca

grafo le_grafo(void); void destroi_grafo(grafo g); grafo escreve_grafo(grafo g); int n_vertices(grafo g); int n_arestas(grafo g) e int grau(vertice v, grafo g): foram implementados com funções diretas da biblioteca cgraph

int grau_maximo(grafo g): itera por todos os vértices e retorna o maior grau encontrado

int grau_minimo(grafo g): itera por todos os vértices e retorna o menor grau encontrado

int grau_medio(grafo g): itera por todos os vértices e retorna o somatório dos graus dividido pelo número de vértices

int regular(grafo g): checa se todos os vértices tem o mesmo grau

int completo(grafo g): checa se todos os vértices tem grau |V(G)|-1

int conexo(grafo g): executa uma busca em largura sobre a matriz de adjacência do grafo e verifica se foi capaz de chegar em todos os vértices

int bipartido(grafo g): executa em busca em profundida, colorindo alternadamente os vértices, isto é, separando-os em 2 partições. Se um vértice tem de pertencer a ambas as partições, retorna que não é bipartido, caso contrário retorna que é bipartido

int n_triangulos(grafo g): eleva a matriz de adjacência ao cubo, soma sua diagonal principal e retorna esse somatório dividido por 6. A primeira multiplicação gera uma matriz M tal que m[i][j] é o número de vizinhos em comum entre os vértices i e j. A segunda gera uma matriz tal que m[i][j] é igual ao número de caminhos com início no vértice i e final no vértice j. Logo, o somatório da diagonal principal dessa matriz é equivalente a 6*n_triangulos, visto que é contado uma vez para cada vértice e para cada vértice uma vez em cada sentido.

int **matriz_adjacencia(grafo g): gera uma matriz de tamanho |V(G)|*|V(G)| e a preenche com 0. Após isso, para cada par de vértices i, j, se possuem uma aresta os conectando, m[i][j] = 1

grafo complemento(grafo g): cria um grafo H tal que V(H) = V(G) e para cada vértice v1 de H, adiciona as arestas {v1, v2} se não existe {v1, v2} em E(G)

