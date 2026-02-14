#include<iostream>
#include<fstream>
using namespace std;

void alphabets()
{
	ifstream fin;
	fin.open("Data.txt");
	char ch;
	int count=0;
	while(!fin.eof())
	{
		fin.get(ch);
		if(isalpha(ch))
			count++;
	}
	cout<<"Number of alphabets in file are "<<count<<endl;
	fin.close();
}

int main()
{
    alphabets();
    system("pause");
    return 0;
}
