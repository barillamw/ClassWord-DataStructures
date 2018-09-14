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
		Item * arr;

	public:
		Array(int n = 1);
		~Array();
		void push_back(char* string);
		Item get(int n);
		int length();
		Item remove_front();

};

Array::Array(int n) {
  // build an array of size n
  arraySize = n;
  arr = new Item[arraySize];
  int i = 0;
  Item itemNll;

  //initialize array a to NULL
  for (i=0;i<n;i++){
	  arr[n] = itemNll;
  }
}
Array ::~Array(){
	delete arr; //frees the array
}
int Array::length(){
	int i = 0;
	int count = 0;
	Item empty = "";

	for (i=0; i<arraySize; i++){
		if(get(i) != empty){
			count++;
		}
	}

	return count;
}
Item Array::get(int n){
	return arr[n];
}
void Array::push_back(char* string){
	int i = 0;
	Item * newArray = new Item[arraySize+1];

	if(get(arraySize-1) != ""){
		for(i=0; i<arraySize; i++){
			arr[i] = newArray[i];
			arraySize = length();
		}
		newArray[arraySize] = string;
		arr = newArray;
	}
	else{
		for(i=0; i<arraySize; i++){
			if(get(i)==""){
				break;
			}
		}

		arr[i] = string;
		delete newArray[];
	}


}
Item Array::remove_front(){
	int i=0;
	Item tmp = "";

	for(i=0; i<arraySize; i++){
		if(arr[i] != ""){
			tmp = arr[i];
			arr[i] = "";
			return tmp;
		}
	}
}
