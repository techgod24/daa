#include<stdio.h>

#include<string.h>

int min(int, int, int);
int main() {
  char s1[100], s2[100];
  int n1, n2, i, j, a[100][100];
  printf("enter string-1:");
  gets(s1);
  printf("enter string-2:");
  gets(s2);
  n1 = strlen(s1);
  n2 = strlen(s2);
  for (j = 0; j <= n2; j++) {
    a[0][j] = j;
  }
  for (i = 0; i <= n1; i++) {
    a[i][0] = i;
  }
  for (i = 1; i <= n1; i++) {
    for (j = 1; j <= n2; j++) {
      if (s1[i - 1] == s2[j - 1]) {
        a[i][j] = a[i - 1][j - 1];
      } else {
        a[i][j] = (min(a[i - 1][j - 1], a[i - 1][j], a[i][j - 1]) + 1);
      }
    }
  }
  printf("no.of string edits are: %d", a[n1][n2]);
}
int min(int a, int b, int c) {
  if (a < b && a < c) {
    return a;
  } else if (b < c) {
    return b;
  } else {
    return c;
  }
}