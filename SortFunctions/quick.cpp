
#include "sortfunctions.h"

void innerquicksort(int* arr, int startIndex, int endIndex);

void sort_quick(int* arr, int len) {
  innerquicksort(arr, 0, len);
}

int partition(int* arr, int startIndex, int endIndex) {
  int left = startIndex;
  int right = endIndex;
  int pivot = arr[startIndex];

  while (true) {
    // left -> right
    while (arr[left] <= pivot) {
      left++;
      if (left == right) {
        break;
      }
    }

    // right -> left
    while (pivot < arr[right]) {
      right--;
      if (left == right) {
        break;
      }
    }

    // meet
    if (left >= right) {
      break;
    }

    // exchange
    int temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
  }

  //
  int temp = arr[startIndex];
  arr[startIndex] = arr[right];
  arr[right] = temp;
  return right;
}

void innerquicksort(int arr[], int startIndex, int endIndex) {
  if (endIndex <= startIndex) {
    return;
  }

  int pivotIndex = partition(arr, startIndex, endIndex);
  innerquicksort(arr, startIndex, pivotIndex - 1);
  innerquicksort(arr, pivotIndex + 1, endIndex);
}
