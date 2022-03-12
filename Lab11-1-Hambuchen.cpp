//Julia Hambuchen
//Lab 11, assgn. 1, calculates student grade for course

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


//declare SIZE of and StudentRecord type
const int SIZE = 50;
struct StudentRecord
{
	string name;
	int exam_points;
	int lab_points;
	double avg;
	char letter;
};

//declare function prototypes
void get_info(int&, int&, int&);
void get_stud_info(int, StudentRecord student[]);
void get_avg(int, int, int, StudentRecord student[]);
void get_max_min(int, StudentRecord student[], double&, double&);
void display(int, StudentRecord student[], double, double);


//using main as driver function
int main()
{
	int exam_total, lab_total, student_num;
	double max, min;
	StudentRecord student[SIZE];

	get_info(exam_total, lab_total, student_num);
	get_stud_info(student_num, student);
	get_avg(exam_total, lab_total, student_num, student);
	get_max_min(student_num, student, max, min);
	display(student_num, student, max, min);

	return 0;
}

//gets general info - total points for exams/labs, student number
void get_info(int& exam_total, int& lab_total, int& student_num)
{
	cout << "Please enter the number of students in the course: ";
	cin >> student_num;
	cout << "Please enter the total number of exam points: ";
	cin >> exam_total;
	cout << "Please enter the total number of lab points: ";
	cin >> lab_total;
	cin.ignore();

	return;
}

//gets info for each student
void get_stud_info(int student_num, StudentRecord student[])
{
	for (int a = 0; a < student_num; a++)
	{
		cout << "Student " << a + 1 << "'s Information: " << endl;
		cout << "Name: ";
		getline(cin, student[a].name);
		cout << "Exam Points: ";
		cin >> student[a].exam_points;
		cout << "Lab Points: ";
		cin >> student[a].lab_points;
		cin.ignore();
		cout << "\n";
	}

	return;
}

//gets average for all students and their letter grade
void get_avg(int exam_total, int lab_total, int student_num, StudentRecord student[])
{
	for (int b = 0; b < student_num; b++)
	{
		student[b].avg = (((student[b].exam_points / (double)exam_total) * .60) + ((student[b].lab_points / (double)lab_total) * .40)) * 100;

		if (student[b].avg >= 90)
		{
			student[b].letter = 'A';
		}
		else if (student[b].avg <= 89 && student[b].avg >= 80)
		{
			student[b].letter = 'B';
		}
		else if (student[b].avg <= 79 && student[b].avg >= 70)
		{
			student[b].letter = 'C';
		}
		else if (student[b].avg <= 69 && student[b].avg >= 60)
		{
			student[b].letter = 'D';
		}
		else
		{
			student[b].letter = 'F';
		}
	}

	return;
}

//finds highest average and lowest average
void get_max_min(int student_num, StudentRecord student[], double& max, double& min)
{
	max = -1;
	min = 200;
	for (int c = 0; c < student_num; c++)	 //haha c++...
	{
		if (student[c].avg > max)
		{
			max = student[c].avg;
		}
		if (student[c].avg < min)
		{
			min = student[c].avg;
		}
	}
	return;
}

//displays StudentRecord and max/min
void display(int student_num, StudentRecord student[], double max, double min)
{
	cout << "Name   ";
	cout << setw(10) << "Exam Points";
	cout << setw(15) << "Lab Points";
	cout << setw(17) << "Average";
	cout << setw(20) << "Letter Grade";
	cout << "\n";

	for (int d = 0; d < student_num; d++)
	{
		cout << student[d].name;
		cout << setw(10) << student[d].exam_points;
		cout << setw(15) << student[d].lab_points;
		cout << setw(17) << setprecision(1) << fixed << student[d].avg << "%";
		cout << setw(20) << student[d].letter;
		cout << "\n";
	}

	cout << "Highest Average: " << setprecision(1) << fixed << max << endl;
	cout << "Lowest Average: " << setprecision(1) << fixed << min << endl;


	return;
}
