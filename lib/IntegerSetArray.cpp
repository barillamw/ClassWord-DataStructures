#include <stdio.h>
#include "IntegerSetArray.h"
#define EMPTY -1011 //random number that is used to signify empty space in array



ece309::IntegerSetArray::IntegerSetArray(int s){
  int i;

  setArray = new int[s] ;
  size = s;
  for(i=0; i<size; i++){
    setArray[i] = EMPTY;
  }
}

bool ece309::IntegerSetArray::insert(int x){
  int i;
  for (i=0; i<size;i++){
    if(setArray[i] == EMPTY ){
      setArray[i] = x;
      return true;
    }
  }
  return false;
}

bool ece309::IntegerSetArray::search(int x) const {
  int i;
  for (i=0; i<size; i++){
    if(setArray[i] == x){
      return true;
    }
  }
  return false;
}

void ece309::IntegerSetArray::remove(int x){
  int i;

  for (i=0; i<size; i++){
    if(setArray[i] == x){
      setArray[i] = EMPTY;
    }
  }
}
