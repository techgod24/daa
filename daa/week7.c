#include<stdio.h>

#include<conio.h>

int a[10][10], reach[20], n;
void dfs(int v) {
  int i;
  reach[v] = 1;
  for (i = 1; i <= n; i++)
    if (a[v][i] && !reach[i]) {
      printf("\n%d->%d", v, i);
      dfs(i);
    }
}
int main() {
  int i, j, count = 0;
  printf("Enter no of vertices : ");
  scanf("%d", & n);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++) {
      reach[i] = 0;
      a[i][j] = 0;
    }
  printf("Enter adjacency matrix : ");
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++)
      scanf("%d", & a[i][j]);
  dfs(1);
  for (i = 1; i <= n; i++)
    if (reach[i])
      count++;
  if (count == n)
    printf("\nGraph is connected.");
  else
    printf("\nGraph is disconnected.");
  getch();
  return (0);
}
// 1.Enter no of vertices : 3
//  Enter adjacency matrix : [ 1 1 0
//  1 0 0
//  0 0 0 ]
//  1->2
//  Graph is disconnected.
// 2.Enter no of vertices : 3
//  Enter adjacency matrix : [ 0 1 0
//  1 0 1
//  0 1 0 ]
//  1->2
//  2->3
//  Graph is connected