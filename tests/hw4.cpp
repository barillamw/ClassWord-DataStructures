#include <stdio.h>
#include <poly.h>
//test file for HW 4

int main()
{
  //declaration of variables and formation of the list
  pList l;
  IntItem *one = new IntItem(7);
  l.append(one);
  Object *two = new StrItem("This is a string");
  l.append(two);
  Object *three = new DblItem(2.0);
  l.append(three);

  iterator it = l.begin();
  while(!it.end())
    {
      Object* copy = it.getItem();

      copy ->print();

      it.increment();
    }







  return 0;
}
