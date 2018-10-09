#include <stdio.h>

class IntegerSet {
protected:
   int size;
   int hash(int key) { return (key * 997) % size; }
public:
   IntegerSet(int htsize):size(htsize) {}
   virtual bool insert(int) = 0;
   virtual bool search(int) const = 0;
   virtual void remove(int) = 0;
};

class IntergerSetArray: public IntergerSet {
private:
  int* setArray;

public:
  IntergerSetArray(int size);
  bool Insert(int x);
  bool search(int x);
  void remove(int x);
}

IntegerSetArray::IntegerSetArray(int s){
  int array[s];
  int i;
  int empty = -1011; // initalize all values to negative 1011 assuming that value will not be stored by the user

  setArray = *array;
  size = s;
  for(i=0; i<size; i++){
    array[i] = -empty;
  }
}

bool IntergerSetArray::Insert(int x){
  int i;
  for (i=0; i<size;i++){
    if(setArray[i] == empty ){
      setArray[i] = x;
      return true;
    }
  }
  return false;
}

bool IntegerSetArray::Search(int x){
  int i;
  for (i=0; i<size; i++){
    if(setArray[i] == x){
      return true;
    }
  }
  return false;
}

void IntegerSetArray::remove(int x){
  int i;

  for (i=0; i<size; i++){
    if(setArray[i] == x){
      setArray[i] = empty;
    }
  }
}
