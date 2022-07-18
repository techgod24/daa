#include<stdio.h>

int max(int a, int b) {
  return (a > b) ? a : b;
}
int knapSack(int W, int wt[], int val[], int n) {
  int i, w;
  int K[n + 1][W + 1];
  for (i = 0; i <= n; i++) {
    for (w = 0; w <= W; w++) {
      if (i == 0 || w == 0)
        K[i][w] = 0;
      else if (wt[i - 1] <= w)
        K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
      else
        K[i][w] = K[i - 1][w];
    }
  }
  return K[n][W];
}
int main() {
  int i, n, val[20], wt[20], W;
  printf("Enter number of items:");
  scanf("%d", & n);
  printf("Enter value of items:\n");
  for (i = 0; i < n; ++i) {
    scanf("%d", & val[i]);
  }
  printf("Enter weight of items:\n");
  for (i = 0; i < n; ++i) {
    scanf("%d", & wt[i]);
  }
  printf("Enter size of knapsack:");
  scanf("%d", & W);
  printf("Max value of knapsack is %d", knapSack(W, wt, val, n));
}


// Enter number of items:3
// Enter value of items:
// 100 50 150
// Enter weight of items:
// 20 10 30
// Enter size of knapsack:50
// Max value of knapsack is 250











