//Julia Hambuchen
//Lab 12, assign 1, stores student info for a college 

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//declare constants and structure formatting
const int SIZE = 50;

struct Address
{
	string street;
	string city_state;
	int zip;
};

struct StudentAddress
{
	string name;
	Address home;
	Address college;
};

//declare function prototypes
int get_size();
void get_info(int, StudentAddress stud_record[]);
void display_info(int, StudentAddress stud_record[]);

int main()
{
	//declare needed variables in main
	int actual_size;
	StudentAddress stud_record[SIZE];

	//call functions
	actual_size = get_size();
	get_info(actual_size, stud_record);
	display_info(actual_size, stud_record);

	return 0;
}

//gets actual size of student record from user and returns it to main
int get_size()
{
	int actual_size;
	cout << "Please enter the number of students (must be greater than 0 and less than or equal to 50):" << endl;
	cout << "Enter here: ";
	cin >> actual_size;

	//input validation
	while (actual_size < 0 || actual_size > 50)
	{
		cout << "ERROR: must be greater than 0 and less than or equal to 50." << endl;
		cout << "Please re-enter here: ";
		cin >> actual_size;
	}

	cin.ignore();

	return actual_size;
}

//gets student info from user and stores it in array record
void get_info(int actual_size, StudentAddress stud_record[])
{
	for (int a = 0; a < actual_size; a++)
	{
		cout << "Student " << a + 1 << ": " << endl;
		cout << "Name: ";
		getline(cin, stud_record[a].name);

		cout << "\nHome Address:" << endl;
		cout << "\tStreet: ";
		getline(cin, stud_record[a].home.street);
		cout << "\tCity, State: ";
		getline(cin, stud_record[a].home.city_state);
		cout << "\tZip Code: ";
		cin >> stud_record[a].home.zip;
		cin.ignore();

		cout << "\nCollege Address:" << endl;
		cout << "\tStreet: ";
		getline(cin, stud_record[a].college.street);
		cout << "\tCity, State: ";
		getline(cin, stud_record[a].college.city_state);
		cout << "\tZip Code: ";
		cin >> stud_record[a].college.zip;
		cin.ignore();

		cout << "\n";
	}

	return;
}

//Displays student record
void display_info(int actual_size, StudentAddress stud_record[])
{
	cout << "-----------------------------------" << endl;

	for (int b = 0; b < actual_size; b++)
	{
		cout << endl;
		cout << "Name: " << stud_record[b].name << endl;

		cout << "Home Address:" << endl;
		cout << "\tStreet: " << stud_record[b].home.street << endl;
		cout << "\tCity, State: " << stud_record[b].home.city_state << endl;
		cout << "\tZip Code: " << stud_record[b].home.zip << endl << endl;

		cout << "College Address:" << endl;
		cout << "\tStreet: " << stud_record[b].college.street << endl;
		cout << "\tCity, State: " << stud_record[b].college.city_state << endl;
		cout << "\tZip Code: " << stud_record[b].college.zip << endl;
	}

	return;
}