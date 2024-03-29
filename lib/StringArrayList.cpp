#include <stdio.h>
#include <string.h>
namespace ece309
{
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
		const char ** arr;

	public:
		Array(int n = 1);
		~Array();
		void push_back(char* string);
		const char * get(int n);
		int length();
		const char * remove_front();

};
}

ece309::Array::Array(int n) {
  // build an array of size n
  arraySize = n;
  arr = new const char *[arraySize];
  int i = 0;
  const char * itemNll = NULL;

  //initialize array a to NULL
  for (i=0;i<n;i++){
	  arr[n] = itemNll;
  }
}
ece309::Array ::~Array(){
	delete arr; //frees the array
}
int ece309::Array::length(){
	int i = 0;
	int count = 0;
	const char * empty = "";

	for (i=0; i<arraySize; i++){
		if(strcmp(get(i),empty) != 0){ //
			count++;
		}
	}

	return count;
}
const char * ece309::Array::get(int n){
	return arr[n];
}
void ece309::Array::push_back(char* string){
	int i = 0;
	const char ** newArray;


	if(strcmp(get(arraySize-1),"") != 0){
		newArray = new const char *[arraySize+1];
		for(i=0; i<arraySize; i++){
			arr[i] = newArray[i];
			arraySize = length();
		}
		newArray[arraySize] = string;
		arr = newArray;
	}
	else{
		for(i=0; i<arraySize; i++){
			if(strcmp(get(i),"") == 0){
				break;
			}
		}

		arr[i] = string;
	}
	return;
}
const char * ece309::Array::remove_front(){
	int i=0;
	const char * tmp = "";

	for(i=0; i<arraySize; i++){
		if(strcmp(arr[i],"") != 0){
			tmp = arr[i];
			arr[i] = "";
			return tmp;
		}
	}
	return NULL;
}
