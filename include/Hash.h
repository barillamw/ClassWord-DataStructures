#ifndef HASH_H
#define HASH_H

#include "List.h"

// IntegerSet abstract base class to demonstrate hash table concepts
class IntegerSet {
protected:
   int size;
   int hash(int key) const {
     int r = (key * 997) % size;
      if (r<0) return -r;
      return r;
    }
public:
   IntegerSet(int htsize):size(htsize) {}
   virtual bool insert(int) = 0;
   virtual bool search(int) const = 0;
   virtual void remove(int) = 0;
};

// Hash Table with Linear Probing
class IntegerSetHT : public IntegerSet {
protected:
  int *table;
  int probeDistance;
  const int empty_since_start = -2;
  const int empty_after_removal = -1;
public:

  class iterator {
  private:
    int *tbl;
    int sze;
    int indx;

  public:
    iterator(int *t, int s){
      tbl = t;
      sze = s;
      indx = 0;
    }
    int getInt() { return tbl[indx]; }
    void increment() {
      indx++;
      while(tbl[indx] == -2 ||  tbl[indx] == -1){
        indx++;
      }
    }
    bool end() {  return indx==sze; }

    friend class IntegersetHT;
  };
public:
   IntegerSetHT(int htsize = 100);
   virtual bool insert(int) override;
   virtual bool search(int) const override;
   virtual void remove(int) override;
   iterator begin() {return iterator(table, size); }
};

// Hash Table with Chaining
class IntegerSetHTChain : public IntegerSet {
protected:
  List *table;
public:
   IntegerSetHTChain(int htsize);
   virtual bool insert(int) override;
   virtual bool search(int) const override;
   virtual void remove(int) override;
};


/*int IntegerSet::hash(int key) const {
  // Squaring the key.
key = key * key;
// Extracting required number of digits ( here, 8 ).
if (key < 1000000000000000) {
  key = key / 10000;
  key = key % 100000000;
}
else {
  key = key / 10000;
  key = key % 100000000;
}
// Returning the key value.
return key%size;
}*/
#endif //HASH_H
