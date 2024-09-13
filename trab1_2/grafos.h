#include <stdio.h>
#include <stdlib.h>
#define SIZE 40

struct queue {
  int items[SIZE];
  int front;
  int rear;
};



struct node {
  int vertex;
  struct node* next;
};

struct node* createNode(int);

struct Graph {
  int numVertices;
  struct node** adjLists;
  int* visited;
  float **values;
};

struct queue* createQueue();
void enqueue(struct queue* q, int);
int dequeue(struct queue* q);
void display(struct queue* q);
int isEmpty(struct queue* q);
void printQueue(struct queue* q);
void bfs(struct Graph* graph, int startVertex);
struct node* createNode(int v);
void addEdge(struct Graph* graph, int src, int dest,float values);
struct Graph* createGraph(int vertices);
struct Graph* readGraphByFile(const char *nomeArquivo);
void printGraph(struct Graph* graph);
void removeEdge(struct Graph* graph, int src, int dest);
int isEdge(struct Graph* graph, int src, int dest);
void edgeLess100(struct Graph* graph, int city,int adjacents[]);
