#include<stdio.h>

#include<stdlib.h>

#include<time.h>

int SelectionSort(int arr[], int n) {
  int i, j, c = 0, t, m;
  for (i = 0; i < n - 1; i++) {
    c++;
    m = i;
    c++;
    for (j = i + 1; j < n; j++) {
      c++;
      if (arr[j] < arr[m]) {
        m = j;
        c++;
      }
      c++;
    }
    if (m != i) {
      t = arr[m];
      c++;
      arr[m] = arr[i];
      c++;
      arr[i] = t;
      c++;
    }
    c++;
  }
  return c + 2;
}
int main() {
  int * arr, n, i, c, count;
  clock_t start_t, end_t, total_t;
  printf("Enter the size of the array: ");
  scanf("%d", & n);
  printf("Enter 1 for best case scenario\t2 for average case scenario\t3 for worst case scenario: ");
  scanf("%d", & c);
  arr = (int * ) malloc(n * sizeof(int));
  switch (c) {
  case 1:
    for (i = 0; i < n; i++) {
      arr[i] = i + 1;
    }
    break;
  case 2:
    srand(time(0));
    for (i = 0; i < n; i++) {
      arr[i] = rand() % n + 1;
    }
    break;
  case 3:
    for (i = 0; i < n; i++) {
      arr[i] = n - i;
    }
    break;
  default:
    printf("Incorrect Input");
    break;
  }
  count = SelectionSort(arr, n);
  printf("Step Count : %d steps\n", count);
}


// Sample Output:
// Enter the size of the array: 15
// Enter 1 for best case scenario 2 for average case scenario 3 
// for worst case scenario: 1
// Step Count: 315 steps
// Time Complexity Analysis:
// Best Case Time Complexity = O(n2)
// Average Case Time Complexity = O(n2)
// Worst Case Time Complexity = O(n2)