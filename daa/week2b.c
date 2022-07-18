//Using Recursive Method:
#include<stdio.h>

int c = 0;
int fact(int n) {
  if (n > 1) {
    c = c + 2;
    return n * fact(n - 1);
  } else {
    c = c + 3;
    return 1;
  }
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
// Step Count: 21
// Enter a positive integer: 5
// Factorial of 5 is 120.
// Step Count: 11