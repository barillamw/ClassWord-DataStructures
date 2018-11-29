#include "Queue.h"

void ece309::Queue::push(Item item)
{
  list.append(item);
}

void ece309::Queue::pop()
{
  List::iterator it; // NULL iterator
  // remove from the head of the queue using NULL iterator
  list.removeAfter(it);
}

Item& ece309::Queue::peek()
{
  List::iterator it = list.begin();
  return it.getItem();
}

bool ece309::Queue::empty()
{
  return list.empty();
}
