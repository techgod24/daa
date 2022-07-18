#include<stdio.h>

void main() {
  int n, i, j, count = 0;
  printf("Enter number of weights\n");
  scanf("%d", & n);
  float w[n], p[n], r[n], m, max_pro = 0;
  printf("Enter weights\n");
  for (i = 0; i < n; i++) {
    scanf("%f", & w[i]);
  }
  printf("Enter profits to corresponding weights\n");
  for (i = 0; i < n; i++) {
    scanf("%f", & p[i]);
  }
  printf("Enter maximum weight\n");
  scanf("%f", & m);
  for (i = 0; i < n; i++)
    r[i] = p[i] / w[i];
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - 1; j++) {
      if (r[j + 1] > r[j]) {
        r[j + 1] = r[j + 1] + r[j];
        r[j] = r[j + 1] - r[j];
        r[j + 1] = r[j + 1] - r[j];
        w[j + 1] = w[j + 1] + w[j];
        w[j] = w[j + 1] - w[j];
        w[j + 1] = w[j + 1] - w[j];
        p[j + 1] = p[j + 1] + p[j];
        p[j] = p[j + 1] - p[j];
        p[j + 1] = p[j + 1] - p[j];
      }
    }
  }
  printf("Profit/weight array is\n");
  for (i = 0; i < n; i++) {
    printf("%f ", r[i]);
  }
  for (i = 0; i < n; i++) {
    if (m >= w[i]) {
      max_pro = max_pro + p[i];
      m = m - w[i];
    } else if (m < w[i] && count == 0) {
      max_pro = max_pro + (m * p[i]) / w[i];
      count = 1;
    }
  }
  printf("\nMaximum profit is %f", max_pro);
}
// Enter number of weights
// 4
// Enter weights
// 2 4 6 9
// Enter profits to corresponding weights
// 10 10 12 18
// Enter maximum weight
// 15
// Profit/weight array is
// 5.000000 2.500000 2.000000 2.000000
// Maximum profit is 38.000000


