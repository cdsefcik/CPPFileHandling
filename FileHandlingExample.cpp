#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include <fstream> //Needed this for the input stream.

using namespace std;

/*
*These are the examples of IO operations from chapter 10 Input and Output Streams, Programming Principles and Practice using C++/
*
*/

inline void keep_window_open() {
	char ch; cin >> ch;
}

void error(string value, string name) {
	cerr << value << "With the name " << name<<endl;
}

void fill_vector(istream& ist, vector<int>& v, char terminator) {
	int i = 0;
	while (ist >> i) v.push_back(i);
	if (ist.eof()) return; //Fine: we found the end of file. 

	//Not good() and not bad() and not eof(), ist must be fail().
	ist.clear();  //Clear stream state.
	char c;
	ist >> c;

	if (c != terminator) {             //Ouch, not the terminator, so we must fail
		ist.unget();                   //Maybe my caller can use that character.
		ist.clear(ios_base::failbit);  //Set the state to fail.
	}

}

int main() {

	//Input Stream Example
	cout << "Please enter the name of the file: \n";
	string name;
	cin >> name;
	ifstream ist(name.c_str());
	if (!ist) error("Can't open input file: ", name);

	//Output Stream Example
	cout << "Please enter a name of output file: \n";
	string oname;
	cin >> oname;
	ofstream ost(oname.c_str()); //Ost is an output stream for a file named onmame
	if (!ost)error("Can't open output file ", oname);

	//Close Streams
	ist.close();
	ost.close();


	vector<int> v;
	char terminator = '*';
	string name2 = "Example2.txt";
	ifstream ist2(name2.c_str());

	fill_vector(ist2, v, terminator);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	keep_window_open();

};