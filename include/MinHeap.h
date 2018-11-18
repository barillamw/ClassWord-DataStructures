#ifndef MINHEAP_H
#define MINHEAP_H

class MinHeap {
private:
  int *heapArray;    // this is the minheap
  int heapArraySize; // size of the array
  int nextIndex;     // location of next free array entry

protected:
  void percolate_up(int);
  void percolate_down(int, int);

public:
  MinHeap(int size = 100) : heapArraySize(size) {
    heapArray = new int[size];
    for (int i = 0; i < size; i++)
      heapArray[i] = 0;
    nextIndex = 0;
  }

  void print() {
    for (int i = 0; i < nextIndex; i++) {
      printf("%d ", heapArray[i]);
    }
    printf("\n");
  }

  bool insert(int);
  bool remove(int &); // remove the min value
  int getSize() {return heapArraySize;}

private:
  MinHeap(int *array, int size, int length = 0)
      : heapArray(array), heapArraySize(size), nextIndex(length) {
    int m = nextIndex / 2 - 1; // last internal BTNode
    while (m >= 0) {
      percolate_down(m, length);
      m--;
    }
  }

public:
  static void sort(int *array, int size);
};

#endif //MINHEAP_H
