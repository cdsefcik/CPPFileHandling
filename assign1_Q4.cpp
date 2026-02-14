#include<iostream>
#include<fstream>
using namespace std;

void countlines()
{
	ifstream fin;
	fin.open("STORY.TXT");
	char str[80];
	int count=0;
	while(!fin.eof())
	{
		fin.getline(str,80);
		if(str[0]!='A')
			count++;
	}
	cout<<"Number of lines not starting with A are "<<count;
	fin.close();
}


int main()
{
    countlines();
    system("pause");
    return 0;
}

