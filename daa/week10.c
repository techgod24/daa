#include <limits.h>

#include <stdbool.h>

#include <stdio.h>

#include <time.h>

int n;
int minkey(int key[], bool mstset[]) {
  int min_index, min = INT_MAX;
  for (size_t i = 0; i < n; i++) {
    if (mstset[i] == false && key[i] < min) {
      min = key[i];
      min_index = i;
    }
  }
  return min_index;
}
int printmst(int parent[], int graph[n][n]) {
  printf("Edge\t Weight\n");
  for (int i = 1; i < n; i++) {
    printf("%d - %d\t %d\n", parent[i], i, graph[i][parent[i]]);
  }
}
int prims(int graph[n][n]) {
  int parent[n], key[n];
  bool mstset[n];
  for (int i = 1; i < n; i++) {
    key[i] = INT_MAX, mstset[i] = false;
  }
  key[0] = 0;
  parent[0] = -1;
  for (int i = 0; i < n - 1; i++) {
    int u = minkey(key, mstset);
    mstset[u] = true;
    for (int j = 0; j < n; j++) {
      if (graph[u][j] && mstset[j] == false && graph[u][j] < key[j]) {
        parent[j] = u,
          key[j] = graph[u][j];
      }
    }
  }
  printmst(parent, graph);
}
int main() {
  printf("Enter the number of nodes = ");
  scanf("%d", & n);
  printf("Enter the Adjacency Matrix interms of costs: ");
  int graph[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", & graph[i][j]);
    }
  }
  clock_t start = clock();
  prims(graph);
  clock_t end = clock();
  double t = ((double)(end - start) / CLOCKS_PER_SEC);
  printf("Taken taken is %lf", t);
  return 0;
}

// Enter the number of nodes=5
// Enter the Adjacency Matrix interms of costs:
// 0 0 3 0 0
// 0 0 10 4 0
// 3 10 0 2 6
// 0 4 2 0 1
// 0 0 6 1 0
// Edge Weight
// 3 – 1 4
// 0 – 2 3
// 2 – 3 2
// 3 – 4 1
// Time taken is 0.004000
