#include <stdio.h>
#include "IntegerSetArray.h"
#define EMPTY -1011 //random number that is used to signify empty space in array



IntegerSetArray::IntegerSetArray(int s){
  int i;

  setArray = new int[s] ;
  size = s;
  for(i=0; i<size; i++){
    setArray[i] = EMPTY;
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
