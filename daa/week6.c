#include<stdio.h>

#include<stdlib.h>

#include<time.h>

void swap(int * a, int * b) {
  int t = * a;
  * a = * b;
  * b = t;
}
int partition(int array[], int low, int high) {
  int pivot = array[high];
  int i = (low - 1);
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap( & array[i], & array[j]);
    }
  }
  swap( & array[i + 1], & array[high]);
  return (i + 1);
}
void quickSort(int array[], int low, int high) {
  if (low < high) {
    int pi = partition(array, low, high);
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}
int main() {
  int * arr, n, i, c, count;
  clock_t start_t, end_t;
  double total_t;
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

  start_t = clock();
  quickSort(arr, 0, n - 1);
  end_t = clock();
  total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;

  printf("\nThe time taken is %lf seconds", total_t);

}

// OUTPUT:
// Enter the size of the array: 1000
// Enter 1 for best case scenario 2 for average case scenario 3 for worst
// case scenario: 1
// The time taken is 0.002982 seconds