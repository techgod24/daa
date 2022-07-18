#include <stdio.h>


int gcd(int n1, int n2) {
  int c = 0;
  if (n2 != 0) {
    c = c + 2;
    return gcd(n2, n1 % n2);
  } else {
    c = c + 3;
    return n1;
  }
}
int main() {
  int n1, n2,c;
  printf("Enter two positive integers: ");
  scanf("%d %d", & n1, & n2);
  printf("G.C.D of %d and %d is %d.", n1, n2, gcd(n1, n2));
  printf("\nStep Count: %d", c);
  return 0;
}

// Enter two positive integers: 19 17
// G.C.D of 19 and 17 is 1.
// Step Count: 9
// Enter two positive integers: 1547 1554
// G.C.D of 1547 and 1554 is 7.
// Step Count: 9