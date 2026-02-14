#include<iostream>
#include<fstream>
using namespace std;

int main() {
    
   ifstream in_file("student.dat", ios::binary);
   in_file.seekg(0, ios::end);
   int file_size = in_file.tellg();
   cout<<"Size of the file is"<<" "<< file_size<<" "<<"bytes";
   system("pause");
   return 0;
   
}
