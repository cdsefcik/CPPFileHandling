// content from source file to
// destination file

#include<fstream>
#include<iostream>
using namespace std;
  
// driver code
int main()
{
    fstream file;
  
    // Input stream class to
    // operate on files.
    ifstream ifile("fileone.txt", ios::in);
  
    // Output stream class to
    // operate on files.
    ofstream ofile("filetwo.txt", ios::out | ios::app);
  
    // check if file exists
    if (!ifile.is_open()) {
  
        // file not found (i.e, not opened).
        // Print an error message.
        cout << "file not found";
    }
    else {
        // then add more lines to
        // the file if need be
        ofile << ifile.rdbuf();
    }
    string word;
  
    // opening file
    file.open("file2.txt");
  
    // extracting words form the file
    while (file >> word) {
  
        // displaying content of
        // destination file
        cout << word << " ";
    }
    cout<<"\nFileone data is appended to Filetwo data\n";
    system("pause");
    return 0;
    
}


