#include <stdio.h>
#include <stdlib.h>
#include "grafos.c"

int main() {

  
  
  struct Graph* graph = readGraphByFile("grafo_teste.txt");
  bfs(graph,0);

  

  return 0;
}