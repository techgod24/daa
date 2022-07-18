
#include<stdio.h>

#include<stdlib.h>

#include<time.h>

int InsertionSort(int arr[], int n) {
  int i, j, t, c = 1;
  for (i = 1; i < n; i++, c++) {
    t = arr[i];
    c++;
    for (j = i; j > 0 && t < arr[j - 1]; j--, c++) {
      arr[j] = arr[j - 1];
      c++;
    }
    arr[j] = t;
    c++;
  }
  return c + 2;
}
int main() {
  int * arr, n, i, c, count;
  clock_t start_t, end_t, total_t;
  printf("Enter the size of the array: ");
  scanf("%d", & n);
  printf("Enter 1 for best case scenario\t2 for average case scenario\t3for worst case scenario: ");
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

  count = InsertionSort(arr, n);

  printf("Step Count: %d steps\n", count);
}





// Enter the size of the array: 12
// Enter 1 for best case scenario 2 for average case scenario 3 for worst
// case scenario: 1
// Step Count: 36 steps

// Time Complexity Analysis:
// Best Case Time Complexity = O(n)
// Average Case Time Complexity = O(n2)
// Worst Case Time Complexity = O(n2)
