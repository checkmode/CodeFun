
#include "sortfunctions.h"

void quickSort(int arr[], int left, int right);

void sort_quick(int* arr, int len) {
  quickSort(arr, 0, len - 1);
}

void quickSort(int arr[], int left, int right) {
  if (left >= right)
    return;
  int i, j, base, temp;
  i = left, j = right;
  base = arr[left];
  while (i < j) {
    while (arr[j] >= base && i < j)
      j--;
    while (arr[i] <= base && i < j)
      i++;
    if (i < j) {
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }

  arr[left] = arr[i];
  arr[i] = base;
  quickSort(arr, left, i - 1);
  quickSort(arr, i + 1, right);
}
