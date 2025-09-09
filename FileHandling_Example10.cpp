#include <iostream>
#include <fstream>


using namespace std;

//1. Create a student class with functions getData() & showdata() for output
class student {
protected:
	char st_name[80];
	short age;

public:
	void getdata() //is used to take input from user
	{
		cout << "Enter name = ";
		cin.getline(st_name, 80);
		cout << "Enter Age = ";
		cin >> age;
	}
	void showdata()
	{
		cout << "\nName = " << st_name;
		cout << "\nAge = " << age << endl;
	}

	void DiskOut(); //writes one record to file
	void DiskIn(int); //Reads one record at a time
	static int DiskCount(); //Counts the number of student records in the file.
};

void student::DiskIn(int st_no) { //Reads one record at time
	ifstream infile;
	infile.open("STUDENT_FILE.dat", ios::binary);
	//takes the get pointer to the record that we are going to read
	infile.seekg(st_no * sizeof(student));
	//Read the record using read statement
	infile.read((char*)this, sizeof(*this)); //Reads record
}

void student::DiskOut() {

	ofstream outfile;
	outfile.open("STUDENT_File.dat", ios::app | ios::binary);
	outfile.write((char*)this, sizeof(*this));

}

int student::DiskCount() {
	ifstream infile;
	infile.open("STUDENT_FILE.dat", ios::binary);
	infile.seekg(0, ios::end);
	
	cout << "tellg() = " << infile.tellg() << endl;

	return (int)infile.tellg() / sizeof(student);
}




int main() {

	//2. Create a class object and call getdata to take input
	student st1;

	//3. Open file student.dat for writing in file


	char ch;
	do {
		cout << "\nEnter student data\n";
		st1.getdata();
		//4. Write data entered by user to the file using write function
		st1.DiskOut();//write one record to the file at a time
		cout << "Enter Another Student's Record (y/n) ?";
		cin >> ch;
		cin.ignore();
		cin.get();
	} while (ch == 'y');
	
	//Counts the number of students in the file.
	int n = student::DiskCount(); //n contains no of students in the file.
	cout << "\nThere are " << n << " students in the file\n";

	//6. NPW GOING TO READ FILE & PRINT ALL RECORDS
	//ifstream infile;
	//infile.open("STUDENT_FILE.dat", ios::binary);
	//7. read student record

	for(int j = 0; j < n;j++) { //Used to read all the records one by one in the file.
		st1.DiskIn(j);
		st1.showdata();
		cout << "\n\n=================================================";
	}

	//8. print record on the ouput screen
	//st1.showdata();
	//9. close file
	//infile.close();

	system("pause");
	return 0;
}