#include <stdio.h>
#include <stdlib.h>
#include "grafos.h"

void bfs(struct Graph* graph, int startVertex) {
  struct queue* q = createQueue();

  graph->visited[startVertex] = 1;
  enqueue(q, startVertex);

  while (!isEmpty(q)) {
    printf("Valores em fila: ");
    printQueue(q);
    int currentVertex = dequeue(q);
    printf("marcando o vertice %d como visitado\n\n", currentVertex);

    struct node* temp = graph->adjLists[currentVertex];
    printf("Vertices adjacentes não visitados de %d: ",currentVertex);
    while (temp) {
      int adjVertex = temp->vertex;
      

      if (graph->visited[adjVertex] == 0) {

        graph->visited[adjVertex] = 1;
        printf(" %d ",adjVertex);
        enqueue(q, adjVertex);
      }
      
      temp = temp->next;
    }
    printf("\n");
  }
}

// Creating a node
struct node* createNode(int v) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}


struct Graph* createGraph(int vertices) {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->numVertices = vertices;
  graph->values = (float**)malloc(graph->numVertices * sizeof(float*));
  graph->adjLists = malloc(vertices * sizeof(struct node*));
  graph->visited = malloc(vertices * sizeof(int));


  int i;
  for (i = 0; i < vertices; i++) {

    
    graph->values[i]= (float*)malloc(graph->numVertices * sizeof(float));
    graph->adjLists[i] = NULL;
    graph->visited[i] = 0;
  }

  return graph;
}


void addEdge(struct Graph* graph, int src, int dest, float value) {

  struct node* newNode = createNode(dest);
  newNode->next = graph->adjLists[src];
  graph->adjLists[src] = newNode;
  graph->values[dest][src] = graph->values[src][dest] = value;


  newNode = createNode(src);
  newNode->next = graph->adjLists[dest];
  graph->adjLists[dest] = newNode;
}

struct queue* createQueue() {
  struct queue* q = malloc(sizeof(struct queue));
  q->front = -1;
  q->rear = -1;
  return q;
}


int isEmpty(struct queue* q) {
  if (q->rear == -1)
    return 1;
  else
    return 0;
}


void enqueue(struct queue* q, int value) {
  if (q->rear == SIZE - 1)
    printf("\nQueue está cheia!!");
  else {
    if (q->front == -1)
      q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
  }
}


int dequeue(struct queue* q) {
  int item;
  if (isEmpty(q)) {
    printf("Queue está vazia");
    item = -1;
  } else {
    item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
      printf("A fila ficou vazia ");
      q->front = q->rear = -1;
    }
  }
  return item;
}


void printQueue(struct queue* q) {
  int i = q->front;

  if (isEmpty(q)) {
    printf("Queue está vazia");
  } else {

    for (i = q->front; i < q->rear + 1; i++) {
      
      printf("%d ", q->items[i]);
    }
    printf("\n");
  }
}

struct Graph* readGraphByFile(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }

    int numVertices, numArestas;
    fscanf(arquivo, "%d %d", &numVertices, &numArestas);

    struct Graph* graph = createGraph(numVertices);

    int v1, v2;
    float value;
    for (int i = 0; i < numArestas; i++) {
        fscanf(arquivo, "%d %d %f", &v1, &v2,&value);
        addEdge(graph, v1, v2,value);
    }

    fclose(arquivo);
    return graph;
}

void printGraph(struct Graph* graph) {
  for (int i = 0; i < graph->numVertices; i++) {
    printf("Vertex %d: ", i);
    struct node* temp = graph->adjLists[i];
    while (temp) {
      printf("vertice %d valor %f-> ", temp->vertex,graph->values[i][temp->vertex]);
      temp = temp->next;
    }
    printf("\n");
  }
}

void removeEdge(struct Graph* graph, int src, int dest) {


    if (!isEdge(graph, src, dest)) {
        printf("Aresta (%d, %d) não existe.\n", src, dest);
        return;
    }


    struct node* temp = graph->adjLists[src];
    struct node* prev = NULL;
    while (temp != NULL && temp->vertex != dest) {
        prev = temp;
        temp = temp->next;
    }

    if (temp != NULL) {
        if (prev == NULL) {
            graph->adjLists[src] = temp->next;
        } else {
            prev->next = temp->next;
        }
        free(temp);
    }


    temp = graph->adjLists[dest];
    prev = NULL;
    while (temp != NULL && temp->vertex != src) {
        prev = temp;
        temp = temp->next;
    }

    if (temp != NULL) {
        if (prev == NULL) {
            graph->adjLists[dest] = temp->next;
        } else {
            prev->next = temp->next;
        }
        free(temp);
    }
}


int isEdge(struct Graph* graph, int src, int dest) {
    struct node* temp = graph->adjLists[src];
    while (temp != NULL) {
        if (temp->vertex == dest) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void edgeLess100(struct Graph* graph, int city,int adjacents[]){
    struct node* temp = graph->adjLists[city];
    int i =0;
    printf("[ ");
    while (temp != NULL)
    {
      if (graph->values[city][temp->vertex] <= 100)
      {
        adjacents[i]=temp->vertex;
        printf(" vertex: %d valor: %f ",adjacents[i],graph->values[city][temp->vertex]);
        i++;
        
      }
      temp = temp->next;
    }
    printf(" ]\n");
    

}




