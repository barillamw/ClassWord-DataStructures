#include <stdio.h>
#include <poly.h>


StrItem::StrItem(const char *s) {str = s;}
void StrItem::print(){printf("Item: %s\n", str);}
IntItem::IntItem(int n) {num = n;}
void IntItem::print(){printf("Item: %d\n", num);}
DblItem::DblItem(double d) {dbl = d;}
void DblItem::print(){printf("Item: %f\n",dbl);}

ListNode::ListNode(Object* a, ListNode *n){
  item = a;
  next = n;
}
ListNode* ListNode::getNext(){return next;}
void ListNode::setNext(ListNode *n){next = n;}
Object* ListNode::getItem(){return item;}

iterator::iterator(ListNode* n) { node = n; }
Object* iterator::getItem() { return node->getItem(); }
void iterator::increment() { node = node->next; }
bool iterator::end() {  return node==NULL; }


iterator pList::begin() { return iterator(head); }

pList::pList(){
  // start with an empty list
  head = NULL;
  tail = NULL;
}

void pList::append(Object* a){
  ListNode *node = new ListNode(a);
  if (head == NULL)
    {
      // list is empty
      head = node;
      tail = node;
    }
  else
    {
      tail->setNext(node);
      tail = node;
    }
}

bool pList::remove(Object* copy){
  if (!empty()) // if list is not empty
    {
      copy = head->getItem(); // return copy
      ListNode *tmp = head->getNext();
      delete head; // delete the node
      head = tmp;  // update the head
      if (tmp==NULL) // removed last element
	tail = NULL;
      return true;
    }
  return false; // nothing in list
}

bool pList::empty(){
  return head==NULL;
}

void pList::insertAfter(iterator it, Object* item){ // pseudocode in zyBook 2.3
    if (it.node==NULL)
      { // special case to insert at the head
	// point new node at current head of list
	ListNode *node = new ListNode(item,head);
	if (head==NULL) { // if head was NULL, tail was also NULL
	  tail = node;   // new node is now the tail
	  head = node;   // new node is now the head
	} else {
	  head = node;   // update head to new node
	}
      }
    else // insert after it
      {
	       ListNode *node = new ListNode(item,it.node->getNext());
	       it.node->setNext(node);
	       if (tail==it.node) tail = node;
      }
}

void pList::removeAfter(iterator it){ // pseudocode in zyBook 2.4
   if (it.node==NULL) // special case to remove head, it’s not after any node
     {
       ListNode *remove = head;               // will remove the head
       head = head->getNext();      // advance head
       if (head==NULL) tail = NULL; // if head is NULL now, list is empty
       delete remove;               // delete removed node
     }
   else // normal case, if not the head, then simply disconnect the node
     {
       ListNode *tmp = it.node;
       ListNode *remove = tmp->getNext(); // next node to be removed
       tmp->setNext(remove->getNext());   // point around node to be removed
       if (tail==remove) tail = tmp;      // if removing tail, update tail
       delete remove; // delete node      // delete the removed node
     }
}
