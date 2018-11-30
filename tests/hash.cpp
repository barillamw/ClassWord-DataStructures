#include "Hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int collision = 0;
int fails = 0;

// can only hold positive integers
ece309::IntegerSetHT::IntegerSetHT(int htsize)
:IntegerSet(htsize)
{
  collision = 0;
  fails = 0;
  probeDistance = 20;
   table = new int[size];
   for(int i=0; i<size; i++)
      table[i] = empty_since_start;  // -1 means empty
}

bool ece309::IntegerSetHT::insert(int data)
{
  //printf("insert started\n");
  int index = hash(data);
  int bucketsProbed = 0;
  while( bucketsProbed++ < probeDistance )
  {
    //printf("bucketsProbed: %d     index: %d     data: %d\n", bucketsProbed,index, data);
   if ( table[index] < 0 )
   {
     // if the entry is not being used, put the
    // data there
    //printf("success!\n");
     table[ index ] = data;

     return true;
   }
   if ( bucketsProbed == 1){
          //printf("collision\n");
          collision++;
   }
   index = (index+1) % size;
  }

  // otherwise give up
  //printf("fail\n");
  fails++;
   return false;
}

bool ece309::IntegerSetHT::search(int data) const
{
  int index = hash(data);
  int bucketsProbed = 0;
  while( table[index] != empty_since_start &&
         bucketsProbed++ < probeDistance )
  {
   if ( table[index] == data )
   {
     return true;
   }
   index = (index+1) % size;
  }

  // data can only be in one location, check it
  return false;
}

void ece309::IntegerSetHT::remove(int data)
{
  int index = hash(data);
  int bucketsProbed = 0;
  while( table[index] != empty_since_start &&
         bucketsProbed++ < probeDistance )
  {
   if ( table[index] == data )
   {
     table[index] = empty_after_removal;
     //return;
   }
   index = (index+1) % size;
  }
}

ece309::IntegerSetHTChain::IntegerSetHTChain(int htsize)
:IntegerSet(htsize)
{
  table = new List[size];
}

bool ece309::IntegerSetHTChain::insert(int data)
{
  List::iterator it;
  table[hash(data)].insertAfter(it,data);
  return true;
}

bool ece309::IntegerSetHTChain::search(int data) const
{
   List::iterator it = table[hash(data)].begin();
   while(!it.end())
   {
     if(it.getItem() == data)
        return true;
     it.increment();
   }
   return false;
}

void ece309::IntegerSetHTChain::remove(int data)
{
   List::iterator prev,it = table[hash(data)].begin();
   while(!it.end())
   {
     if(it.getItem() == data) {
        table[hash(data)].removeAfter(prev);
        return;
     }
     prev = it;
     it.increment();
   }
}


int main()
{
  ece309::IntegerSetHT set(1000);
  int r;
  int i;
  srand(time(NULL));

  ece309::IntegerSetHT set2;
  set2.insert(5);
  set2.insert(99);
  set2.insert(0);


  for (i=0; i<500; i++){
    r = rand();
    set.insert(r);
  }




  printf("Collisions: %d\nFails: %d\n",collision, fails);

  ece309::IntegerSetHT::iterator sit = set2.begin();
while(!sit.end())
{
   printf("%d\n", sit.getInt());
   sit.increment();
}

  return 0;
}
