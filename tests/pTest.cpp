#include <stdio.h>
#include <pList.h>
//test file for HW 4

int main()
{
  //declaration of variables and formation of the list
  ece309::pList l;
  ece309::IntItem *one = new ece309::IntItem(7);
  l.append(one);
  ece309::Object *two = new ece309::StrItem("This is a string");
  l.append(two);
  ece309::Object *three = new ece309::DblItem(2.0);
  l.append(three);

  ece309::iterator it = l.begin();
  while(!it.end())
    {
      ece309::Object* copy = it.getItem();

      copy ->print();

      it.increment();
    }
}
