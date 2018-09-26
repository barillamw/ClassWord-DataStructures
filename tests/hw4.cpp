#include <stdio.h>
#include "poly.h"

int main()
{
  List l;

  l.append(StrItem("milk"));



  iterator it = l.begin();
  while(!it.end())
    {
      Object& copy = it.getItem();

      copy.print();

      it.increment();
    }

  return 0;
}
