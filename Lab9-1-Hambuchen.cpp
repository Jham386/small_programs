//Julia Hambuchen
//Lab 9, Assignment 1, calculates student grades using arrays

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//declare global constants
const int students = 12;


//Declare function prototypes
void get_info(string&, int[], int&);
void get_max_min(int[], int&, int&);
double calc_average(int[], int);
void get_pass_fail(int[], int&, int&);
void get_letter_grades(int[], int&, int&, int&, int&, int&);
void display_info(string, int[], int, int, double, int, int, int, int, int, int, int);


//call functions with main
int main()
{
	//declare varibales in main
	string exam_name;
	int scores[students];
	int max, min, passed, failed, a, b, c, d, f;
	double average;
	char choice;

	do {

		//initalizing/resetting accumulators
		int total = 0; passed = 0; failed = 0;
		
		//call functions
		get_info(exam_name, scores, total);
		get_max_min(scores, max, min);
		average = calc_average(scores, total);
		get_pass_fail(scores, passed, failed);
		get_letter_grades(scores, a, b, c, d, f);
		display_info(exam_name, scores, max, min, average, passed, failed, a, b, c, d, f);

		//ask for choice to repeat
		cout << "Would you like to calculate more exam scores?" << endl;
		cout << "Please enter Y/y for yes or N/n for no: ";
		cin >> choice;
		cin.ignore();

		cout << "\n\n";

	} while (choice == 'Y' || choice == 'y');

	return(0);
}

//Gets scores and the name of the exam
void get_info(string& exam_name, int scores[], int& total)
{

	cout << "Name of exam: ";
	getline(cin, exam_name);
	cout << "Please enter the scores for your " << students << " students: " << endl;
	for (int counter = 0; counter < students; counter++)
	{
		cout << "Score " << counter + 1 << " : ";
		cin >> scores[counter];

		//input validation
		if (scores[counter] < 0)
		{
			cout << "ERROR: Score cannot be negative." << endl;
			cout << "Please re-enter score " << counter + 1 << " here: ";
			cin >> scores[counter];
		}

		total += scores[counter];
	}

	return;
}

//finds and stores the maximum/minimum scores
void get_max_min(int scores[], int& max, int& min)
{
	//finding maximum value
	max = -1;
	for (int counter = 0; counter < students; counter++)
	{
		if (scores[counter] > max)
		{
			max = scores[counter];
		}
	}

	//finding minimum value
	min = 200;
	for (int counter = 0; counter < students; counter++)
	{
		if (scores[counter] < min)
		{
			min = scores[counter];
		}
	}
	return;
}

//calculates average
double calc_average(int scores[], int total)
{
	double average;

	average = total / students;

	return average;
}

//sorts student scores into passed, failed
void get_pass_fail(int scores[], int& passed, int& failed)
{
	for(int counter = 0; counter < students; counter++)
	{
		if (scores[counter] >= 60)
		{
			passed++;
		}
		else
		{
			failed++;
		}
	}
	return;
}

//gets number of students who got A, B, C, D, F's
void get_letter_grades(int scores[], int& a, int& b, int& c, int& d, int& f)
{
	a = 0; b = 0; c = 0; d = 0; f = 0;

	for (int counter = 0; counter < students; counter++)
	{
		if (scores[counter] >= 90)
		{
			a++;
		}
		else if (scores[counter] <= 89 && scores[counter] >= 80)
		{
			b++;
		}
		else if (scores[counter] <= 79 && scores[counter] >= 70)
		{
			c++;
		}
		else if (scores[counter] <= 69 && scores[counter] >= 60)
		{
			d++;
		}
		else
		{
			f++;
		}
	}
	return;
}

//displays information (exam name, max/min score, average score, passed/failed amounts, grade distribution)
void display_info(string exam_name, int scores[], int max, int min,
				  double average, int passed, int failed, int a, int b, int c, int d, int f)
{
	cout << "\n\nExam Name: " << exam_name << endl;

	//prints all scores
	cout << "Scores:" << endl;
	for(int counter = 0; counter < students; counter++)
	{
		cout << "Score " << counter + 1 << ": " << scores[counter] << endl;
	}

	cout << "\nHighest Score: " << max << endl;
	cout << "Average Score: " << setprecision(1) << fixed << average << endl;
	cout << "Lowest Score: " << min << endl;
	cout << "Amount of students who passed: " << passed << endl;
	cout << "Amount of students who failed: " << failed << endl;
	cout << "Amount of students with an A: " << a << endl;
	cout << "Amount of students with an B: " << b << endl;
	cout << "Amount of students with an C: " << c << endl;
	cout << "Amount of students with an D: " << d << endl;
	cout << "Amount of students with an F: " << f << endl;

	return;
}