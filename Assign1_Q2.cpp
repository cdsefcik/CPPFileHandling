#include<iostream>
#include<fstream>

using namespace std;  
int main()
{
	ifstream fin;
	fin.open("FileData.txt");
	char ch;
	int count=0;
	while(!fin.eof())
	{
		fin.get(ch);
		if(ch==' ')
			count++;
	}
	cout<<"Number of blank spaces in file are "<<count<<endl;
	fin.close();
	system("pause");
	return 0;
}
