#include <iostream>
#include <fstream>

using namespace std;


int main() {

	fstream F; //Open a file for both reading and writing

	F.open("file1.txt",ios::in | ios::out);

	cout << "\nfile1.txt is opened" << endl;

	cout << "\n\ncurrent location = " << F.tellg() << endl; //Get the current location

	F.seekg(8, ios::beg); //Move the character b bytes from the beginning.

	char ch = F.get(); //Extracting one character from the current location using the get() function

	cout << "The extracted character pointed by get pointer = " << ch << endl;

	F.seekg(10, ios::beg); //Now move the get pointer 10 more bytes/characters from the beginning using seekg function.

	cout << "\n\nAftger F.seekg(10,ios::beg) now current location of get ptr = " << F.tellg() << endl;

	ch = F.get(); //Get another character

	cout << "\n\nExtracted character from current location = " << ch << endl;

	F.seekp(7, ios::beg);

	F.put('Z');

	F.seekg(-8, ios::end); //Move the pointer 8 bytes from the end of the file.

	cout << "\n\ncurrent position of get ptr after F.seekg(-8,ios:end) = " <<F.tellg()<< endl; //Exctracting one character from current locaiton using get() function

	ch = F.get(); 
	
	//Printing the character

	cout << "\n\nExtracted character from current location = " << ch << endl;
	
	system("pause");
	return 0;
}