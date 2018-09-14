#include <stdio.h>
#include <string.h>

class Item {
	public:
		const char * str;
		Item(const char *as = "")
	{
		str = as;
	}
};
class Array {
	private:
		int arraySize;
		Item * array;

	public:
		Array(int n = 1);
		~Array();
		void push_back(char* string;
		Item get(int n);
		int length();
		Item remove_front();
				
};

Array::Array(int n) {
  // build an array of size n
  arraySize = n;
  array = new Item[arraySize];
  int i = 0;
  Item itemNll;

  //initialize array a to NULL
  for (i=0;i<n;i++){
	  array[n] = itemNll;
  }
}
Array ::~Array(){
	delete array; //frees the array
}
int Array::length(){
	int i = 0;
	int count = 0;
	for (i=0; i<arraySize; i++){
		if((get(i) != "")){
			count++;
		}
	}

	return count;
}
Item Array::get(int n){
	return array[n];
}
void push_back(char* string){
	int i = 0;
	newArray = new Item[arraySize+1];

	if(get(arraySize-1) != ""){
		for(i=0; i<arraySize; i++){
			array[i] = newArray[i];
			arraySize = length();
		}
		newArray[arraySize] = string;
		array = *newArray;
	}
	else{
		for(i=0; i<arraySize; i++){
			if(array[i]==""){
				break;
			}
		}

		array[i] = string;
		delete newArray;
	}


}
Item remove_front(){
	int i=0;
	Item tmp = "";

	for(i=0; i<arraySize; i++){
		if(array[i] != ""){
			tmp = array[i];
			array[i] = "";
			return tmp;
		}
	}
}
