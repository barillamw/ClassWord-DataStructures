#include <stdio.h>
#include "MinHeap.h"

void ece309::MinHeap::percolate_up(int index) {
  while (index > 0) {
    int parent_index = (index - 1) / 2;
    if (heapArray[index] < heapArray[parent_index]) {
      int tmp = heapArray[index];
      heapArray[index] = heapArray[parent_index];
      heapArray[parent_index] = tmp;
      index = parent_index;
    } else
      return;
  }
}

void ece309::MinHeap::percolate_down(int index, int size) {
  int child_index = index * 2 + 1;
  int val = heapArray[index];
  while (child_index < size) {
    int min_val = val;
    int min_index = -1;
    for (int i = child_index; i < child_index + 2 && i < size; i++) {
      if (heapArray[i] < min_val) {
        min_val = heapArray[i];
        min_index = i;
      }
    }
    if (min_val == val)
      return;
    heapArray[index] = min_val;
    heapArray[min_index] = val;
    index = min_index;
    child_index = index * 2 + 1;
  }
}

bool ece309::MinHeap::insert(int data) {
  if (nextIndex < heapArraySize) {
    heapArray[nextIndex] = data;
    percolate_up(nextIndex);
    nextIndex++;
    return true;
  } else {
    return false;
  }
}

bool ece309::MinHeap::remove(int &val) {
  if (nextIndex > 0) {
    val = heapArray[0];
    heapArray[0] = heapArray[nextIndex - 1];
    nextIndex -= 1;
    percolate_down(0, nextIndex);
    return true;
  }
  return false;
}

void ece309::MinHeap::sort(int *array, int size) {
  MinHeap heap(array, size, size);

  printf("\nheapify: ");
  for (int i = 0; i < 10; i++) {
    printf("%d ", array[i]);
  }

  for (int i = size - 1; i > 0; i--) {
    int ref;
    heap.remove(ref);
    array[i] = ref;
  }

  // return, and the array passed in is sorted
}
