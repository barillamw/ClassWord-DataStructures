#include <stdio.h>

#ifndef INTSETARRAY_H
#define INTSETARRAY_H
class IntegerSet {
protected:
   int size;
   int hash(int key) { return (key * 997) % size; }
public:
   virtual bool insert(int x) = 0;
   virtual bool search(int x) const = 0;
   virtual void remove(int x) = 0;
};

class IntegerSetArray : public IntegerSet {
private:
  int* setArray;
  //int empty = -1011; // initalize all values to negative 1011 assuming that value will not be stored by the user

public:
  IntegerSetArray(int s);
  bool insert(int x);
  bool search(int x) const;
  void remove(int x);
};
#endif //INTSETARRAY_H
