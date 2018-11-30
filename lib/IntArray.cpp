#include <stdio.h>
#include <string.h>
#include "IntArray.h"

ece309::IntArray::IntArray(const char* str)
{
  int count = 0;
  int i;
  for (i=0;str[i]!='\0'; i++){
    count++;
  }
  size = count;
  array = new int[count];

  for(i=0; i<count;i++){
    array[i] = (int)str[i];
  }

}

ece309::IntArray::IntArray(int s, int val)
{
  int i;
  size = s;
  array = new int[size];

  for(i=0; i<size; i++){
    array[i] = val;
  }

}

int& ece309::IntArray::operator[] (int index)
{
  return array[index];
}

ece309::IntArray& ece309::IntArray::operator+=(const IntArray &rhs)
{
  int i = 0;


  for(i=0; i<3; i++){
    this->array[i] = this->array[i] + rhs.array[i];
  }


  return *this;
}

ece309::IntArray ece309::IntArray::operator+(const IntArray &rhs) const
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

ece309::IntArray ece309::IntArray::operator- (const IntArray &rhs) const
{
  IntArray result(size);

  int i=0;
  for(i=0; i<size && i<rhs.size;i++)
    result.array[i] = array[i] - rhs.array[i];
  for(;i<size;i++)
    result.array[i] = array[i];
  return result;
}

ece309::IntArray ece309::IntArray::operator*(int x) const
{
  IntArray result(size);

  int i=0;
  for(i=0; i<size; i++)
    result.array[i] = array[i] * x;

  return result;
}

ece309::IntArray ece309::IntArray::operator/(int x) const
{
  IntArray result(size);

  int i=0;
  for(i=0; i<size; i++)
    result.array[i] = array[i] / x;

  return result;
}

ece309::IntArray ece309::IntArray::operator<<(int count) const
{
  IntArray result(size);

  int i=0;
  for(i=1; i<size; i++)
    result.array[i] = array[i-1];
  result.array[0] = array[i-1];

  return result;

}

ece309::IntArray::operator char*() const
{
  char* s = new char[size];
  int i = 0;

  for(i=0; i<size; i++){
    s[i] = (unsigned)array[i];}

  s[1] = 32;
  s[i] = '\0';
  //printf("%s\n",s);
  return s;
}

ece309::IntArray::operator int() const
{
  int sum = 0;
  int i = 0;
  int average = 0;

  for (i=0; i<size; i++)
    sum += array[i];

  average = sum/size;

  return average;
}
