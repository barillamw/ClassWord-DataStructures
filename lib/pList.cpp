#include <stdio.h>
#include <pList.h>

//declarations of the virtual functions
ece309::StrItem::StrItem(const char *s) {str = s;}
void ece309::StrItem::print(){printf("Item: %s\n", str);}
ece309::IntItem::IntItem(int n) {num = n;}
void ece309::IntItem::print(){printf("Item: %d\n", num);}
ece309::DblItem::DblItem(double d) {dbl = d;}
void ece309::DblItem::print(){printf("Item: %f\n",dbl);}

ece309::ListNode::ListNode(Object* a, ListNode *n){
  item = a;
  next = n;
}
ece309::ListNode* ece309::ListNode::getNext(){return next;}
void ece309::ListNode::setNext(ListNode *n){next = n;}
ece309::Object* ece309::ListNode::getItem(){return item;}

ece309::iterator::iterator(ListNode* n) { node = n; }
ece309::Object* ece309::iterator::getItem() { return node->getItem(); }
void ece309::iterator::increment() { node = node->next; }
bool ece309::iterator::end() {  return node==NULL; }


ece309::iterator ece309::pList::begin() { return iterator(head); }

ece309::pList::pList(){
  // start with an empty list
  head = NULL;
  tail = NULL;
}

void ece309::pList::append(Object* a){
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

bool ece309::pList::remove(Object* copy){
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

bool ece309::pList::empty(){
  return head==NULL;
}

void ece309::pList::insertAfter(iterator it, Object* item){ // pseudocode in zyBook 2.3
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

void ece309::pList::removeAfter(iterator it){ // pseudocode in zyBook 2.4
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
