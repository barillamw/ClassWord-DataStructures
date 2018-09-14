#include <stdio.h>
#include <string.h>
#include <iostream.h>

class Array {
	private:
		int arraySize;
		int * array;

	public:
		//push_back(char* string;
		//get(int n);
		//length();
		//remove_front();
		~Array();
		Array(int n = 1);
		
};

void Array::Array(int n) {
  // build an array of size n
  arraySize = n;
  array = new string[arraySize];
  int i = 0;
  
  //initialize array a to NULL
  for (i=0;i<n;i++){
	  a[n] = NULL;
  }
}

List::~List() {
	// Free all of the ListNodes in the listItem t;
	Item t(NULL);
	while(!empty()) {//while not empty
		remove(t); //remove the next node
	}
}
