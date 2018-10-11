#include <stdio.h>
#include <string.h>
#include "IntArray.h"

IntArray::IntArray(const char* str){
  int count;
  int i;
  for (i=0;str[i]!='\0'; i++){
    count++;
  }

  array = new int[count];

  for(i=0; i<count;i++){
    array[i] = (int)str[i];
  }
}

IntArray::IntArray(int size, int val){
  int i;

  array = new int[size];

  for(i=0; i<size; i++){
    array[i] = val;
  }

}

int& IntArray::operator[] (int index){
  return array[index];
}

IntArray& IntArray::operator +=(const IntArray &rhs){
  IntArray result(size);
  int i = 0;

  for(i=0; i<size; i++){
    result.array[i] += array[i] + rhs.array[i];
  }

  return *this;
}

IntArray IntArray::operator+(const IntArray &rhs) const
{
  IntArray result(size); // make object to hold return value,
  	                       // make long enough to hold this object’s data
    int i=0;
    for(i=0; i<size && i<rhs.size; i++)
       result.array[i] = array[i] + rhs.array[i];
    for(;i<size;i++) // if rhs.length is shorter, copy rest of array
       result.array[i] = array[i];
    return result;
}

IntArray IntArray::operator- (const IntArray &rhs) const
{
  IntArray result(size);

  int i=0;
  for(i=0; i<size && i<rhs.size;i++)
    result.array[i] = array[i] - rhs.array[i];
  for(;i<size;i++)
    result.array[i] = array[i];
  return result;
}

IntArray IntArray::operator*(int x) const
{
  IntArray result(size);

  int i=0;
  for(i=0; i<size; i++)
    result.array[i] = array[i] * x;

  return result;
}

IntArray IntArray::operator/(int x) const
{
  IntArray result(size);

  int i=0;
  for(i=0; i<size; i++)
    result.array[i] = array[i] / x;

  return result;
}

IntArray IntArray::operator<<(int count) const
{
  IntArray result(size);

  int i=0;
  for(i=1; i<size; i++)
    result.array[i+1] = array[i];
  result.array[i] = '\0';

  return result;

}

IntArray::operator char*() const
{
  char* string = new char[size+1];
  int i = 0;

  for(i=0; i<size; i++)
    string[i] = array[i];

  string[size] = '\0';

  return string;
}

IntArray::operator int() const
{
  int sum = 0;
  int i = 0;
  int average = 0;

  for (i=0; i<size; i++)
    sum += array[i];

  average = sum/size;

  return average;
}
