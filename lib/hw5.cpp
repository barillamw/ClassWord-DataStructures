#include <stdio.h>
#define EMPTY -1011

class IntegerSet {
protected:
   int size;
   int hash(int key) { return (key * 997) % size; }
public:
   IntegerSet(int htsize):size(htsize) {}
   virtual bool insert(int x) = 0;
   virtual bool search(int x) const = 0;
   virtual void remove(int x) = 0;
};

class IntegerSetArray: public IntegerSet {
private:
  int* setArray;
  //int empty = -1011; // initalize all values to negative 1011 assuming that value will not be stored by the user

public:
  IntegerSetArray(int size);
  bool insert(int x);
  bool search(int x) const;
  void remove(int x);
}

IntegerSetArray(int s){
  int i;


  setArray = new int[s] ;
  size = s;
  for(i=0; i<size; i++){
    array[i] = EMPTY;
  }
}

bool IntegerSetArray::insert(int x){
  int i;
  for (i=0; i<size;i++){
    if(setArray[i] == EMPTY ){
      setArray[i] = x;
      return true;
    }
  }
  return false;
}

bool IntegerSetArray::search(int x) const {
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
      setArray[i] = EMPTY;
    }
  }
}
