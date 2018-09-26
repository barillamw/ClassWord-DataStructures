#include <stdio.h>
#include <poly.h>

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

  one ->print();
  two ->print();
  three ->print();






  return 0;
}
