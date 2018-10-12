#include <stdio.h>
#ifndef INTARRAY_H
#define INTARRAY_H

class IntArray  {
private:
  int* array;
  int size = 0;
public:
  IntArray(const char* str);
  IntArray(int size, int val = 0);
  int& operator[](int index);
  IntArray& operator+=(const IntArray &rhs);
  IntArray operator+(const IntArray &rhs) const;
  IntArray operator-(const IntArray &rhs) const;
  IntArray operator*(int x) const;
  IntArray operator/(int x) const;
  IntArray operator<<(int count) const;
  operator char*() const;
  operator int() const;
  ~IntArray() {
      delete [] array;
    }


IntArray& operator=(const IntArray &rhs) {
       if(this == &rhs) return *this;
       printf("Running operator=!\n");
       delete [] array;
       size = rhs.size;
      array = new int[size];
      for(int i=0; i<size; i++)
         array[i] = rhs.array[i];
      return *this; // reference to this object
    }

  void set(int index, int val) {
       array[index] = val;
     }

  int get(int index) {
         return array[index];
     }

  int getLength() { return size; }

};




#endif //INTARRAY_H
