#include <iostream>
#include <cstring>			// for string functions
using namespace std;

// A class to define strings
// contents of strings terminate with a null character '\0'
class String{
	 int size;					// length of a string
	 char *contents;
	 int char_num;
 public:
	 String(const char *);   // Constructor
	 ~String();              // Destructor
	 void print();           // A member function
};

// Constructor
// copies the input character array that terminates with null character
// to the contents of the string
String::String(const char *in_data): char_num(0)
{
	 cout<< "Constructor has been invoked " << endl;
	 size = strlen(in_data);
	 contents = new char[size +1];   // +1 for null character
	 strcpy(contents, in_data);		// input_data is copied to the contents
	 for(int i = 0; i < size; i++){ // counting char_num copied string
		if(contents[i] != ' '){
			char_num++;
		}
	}
}

void String::print()
{
	cout<< "Contents: " << contents << " / " << "Size: " << size << " / Number of characters: " << char_num << endl;
	int j = 0;
	for(int i = 0; i < size; i++){
		cout << contents[i];
		if(contents[i] == ' '){
			cout << endl;
		}
	}
	cout << endl;
}

// Destructor
// Memory pointed by contents is given back to the heap
String::~String()
{
	 cout << "Destructor has been invoked" << endl;
	 delete[] contents;
}

//------- Main Function -------
int main()
{
	String string1("Lorem Ipsum Dolar sit amet");
	string1.print();
	
	return 0;
}









