#include <stdio.h>
#include <stdlib.h>
#include "grafos.c"

int main() {
  int a1;
  int a2;
  int opcaoMenu = 0;
  struct Graph* graph = readGraphByFile("grafo_teste.txt");
  float v1;
	
  while(opcaoMenu != 7){
	  
	  printf("Menu:");
	  printf("1- Imprimir grafo completo");
	  printf("2- Inserir nova aresta");
	  printf("3- Remover uma aresta");
	  printf("4- Verificar existência rodovia");
	  printf("5- Listar cidades que possuam ligação direta até 100km");
	  printf("6- Verificar se gráfo é acíclico");
	  printf("7- Saindo");
	  
	  
	
	  scanf("%d", &opcaoMenu);
	  switch(opcaoMenu){
		  case 1:
			printGraph(graph);
			break;
		  case 2:
			scanf("Vértice: \n %d", &a1);
			scanf("Vértice: \n %d", &a2);
			scanf("Vértice: \n %f", &v1);
			addEdge(graph, a1, a2, v1);
			break;
		  case 3:
			scanf("Vértice: \n %d", &a1);
			scanf("Vértice: \n %d", &a2);
			removeEdge(graph, a1, a2);
			break;
		  case 4:
			scanf("Vértice: \n %d", &a1);
			scanf("Vértice: \n %d", &a2);
			int isedge = isEdge(graph, a1, a2);
			if (isedge == 1) {
				printf("Existe rodovia(s) entre %d e %d", a1, a2);
			}
			else {
				printf("Não existe rodovia(s) entre %d e %d", a1, a2);
			}
			break;
		  case 5:
			scanf("Vértice: \n %d", &a1);
			edgeLess100(graph, a1);
			break;
		  case 6:
			break;
		  case 7:
			printf("Saindo");
			break;
		  default:
			printf("Saindo");
	  }
	  
	  
  }

  
  
  bfs(graph,0);

  

  return 0;
}