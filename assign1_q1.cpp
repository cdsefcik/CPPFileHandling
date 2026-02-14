#include<iostream>
#include<fstream>

using namespace std;  
int main()
{
	ofstream fout;
	fout.open("NUMBERS.TXT");
	for(int i=1;i<=100;i++)
		fout<<i<<endl;
	cout<<"\nData written to file\n";
	fout.close();
	system("pause");
	return 0;
}
