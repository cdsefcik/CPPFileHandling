#include <iostream>
#include <fstream>


using namespace std;

    //1. Create a student class with functions getData() & showdata() for output
class student {
private:
	char st_name[80];
	short age;

public:
	void getdata() //is used to take input from user
	{
		cout << "Enter name = ";
		cin.getline(st_name,80);
		cout << "Enter Age = ";
		cin >> age;
	}
	void showdata()
	{
		cout << "\nName = " << st_name;
		cout << "\nAge = " << age<<endl;
	}

	};

int main() {

	//2. Create a class object and call getdata to take input
	student st1;

	//3. Open file student.dat for writing in file
	ofstream outfile("STUDENT_FILE.dat", ios::binary | ios::app);

	char ch;
	do {
		cout << "\nEnter student data\n";
		st1.getdata();

		//4. Write data entered by user to the file using write function
		outfile.write(reinterpret_cast<char*>(&st1), sizeof(student));
		cout << "Enter Another Student's Record (y/n) ?";
		cin >> ch;
		cin.ignore();
		cin.get();
	} while (ch == 'y');
	//5. Close file
	outfile.close();
	//6. NPW GOING TO READ FILE & PRINT ALL RECORDS
	ifstream infile;
	infile.open("STUDENT_FILE.dat", ios::binary);
	//7. read student record

	while (infile.read(reinterpret_cast<char*>(&st1), sizeof(student))) {
		st1.showdata();
		cout << "\n\n=================================================";
	}

	//8. print record on the ouput screen
	st1.showdata();
	//9. close file
	infile.close();

	system("pause");
	return 0;
}