#include <stdio.h>

class Item {
	public:
		const char * str;
		Item(const char *as = "") 
	{ 
		str = as; 
	}
};


class List {
	private:

		// ListNode represents each node of the list
		class ListNode {
		private:
			Item item; // data in the list
			ListNode *next;	
		public:
			ListNode(Item a) { 
				item = a; 
				next=NULL; // automatically serves as a list tail
			}
			ListNode* getNext() { 
			  return next; 
			}
			void setNext(ListNode *n) { 
				next = n; 
			}
			Item getItem() { 
			  return item; 
			}
		};

		// add head and tail pointer
		ListNode *head;
		ListNode *tail;


  
	public:
		List();
		bool remove(Item &a);
		void append(Item a);
		bool empty();
		void push_back(char* string);
		Item get(int n);
		int length();
		bool remove_front();
		~List();
		
};

List::List() {
  // start with an empty list
  head = NULL;
  tail = NULL;
}

bool List::remove(Item &copy) {
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

void List::append(Item a) {
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

bool List::empty() {
  return head==NULL;
}

/*void List::push_back(char * string) {
	//Add a string to the tail of a list
	Item new (string);
	append(new);
}

Item List::get(int n){
	//Return a copy of the n-th item in the list.
	int i = 0;
	ListNode tmp = head;
	for(i=0, i<n, i++) {
		ListNode = tmp ->getNext();
	}
	
	return tmp->getItem();
	
}

int List::length(){
	//Get the number of items in the list.
	int i = 0;
	ListNode tmp = head;
	
	while(tmp != NULL){
		i++;
	}
	
	return i;
}

Item List::remove_front(){
	//Remove the head of the list and return a copy of the data that was removed.
	ListNode copy = NULL;
	remove(head)
	return copy->getitem();
}

List::~List() {
	int t = 0;
	// Free all of the ListNodes in the listItem t;
	while(!empty()) {//while not empty
		remove(t); //remove the next node
		t++;
	}
}*/
