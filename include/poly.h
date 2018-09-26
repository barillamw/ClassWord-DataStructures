#include <stdio.h>

#ifndef poly_h
#define poly_h

class Object {
public:
  virtual void print()=0;
};

class StrItem : public Object {
public:
  const char * str;
  StrItem(const char *s = "");
  void print();
  };

class IntItem : public Object {
public:
  int num;
  IntItem(int n = 0);
  void print();
};

class DblItem : public Object {
public:
  double dbl;
  DblItem(const double d = 0);
  void print();
};

class ListNode {
  public:
    Object item;// data in the list
    ListNode *next;
  public:
    ListNode(const Object& a, ListNode *n=NULL);
    ListNode* getNext();
    void setNext(ListNode *n);
    Object& getItem();

    friend class List;
  };

  class iterator {
  private:
    ListNode *node;

  public:
    iterator(ListNode *n=NULL);
    Object &getItem();
    void increment();
    bool end();

    friend class List;
  };


class List {
  private:
    // ListNode represents each
    // node of the list


  // add head and tail pointer
  ListNode *head;
  ListNode *tail;


  public:
    List();
    void append(Object a);
    bool remove(Object &a);
    bool empty();

    iterator begin();

    void removeAfter(iterator it); // pseudocode in zyBook 2.4
    void insertAfter(iterator it, Object item);
  };



#endif
