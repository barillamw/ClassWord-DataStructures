<<<<<<< HEAD
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
=======
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
>>>>>>> 6ff87dd704aa03430c0c78af99004cd7c4f28560
