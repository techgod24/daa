// Using Iterative method:
#include<stdio.h>

int c = 0;
int fact(int n) {
  int fact = 1;
  while (n > 1) {
    fact = fact * n;
    c++;
    n--;
    c++;
    c++;
  }
  c++;
  c++;
  return fact;
}
int main() {
  int n1, n2;
  printf("Enter a positive integer: ");
  scanf("%d", & n1);
  printf("Factorial of %d is %d.", n1, fact(n1));
  printf("\nStep Count: %d", c);
  return 0;
}
// Enter a positive integer: 10
// Factorial of 10 is 3628800.
// Step Count: 29
// Enter a positive integer: 5
// Factorial of 5 is 120.
// Step Count: 14


