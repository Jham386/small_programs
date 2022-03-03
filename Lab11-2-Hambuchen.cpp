//Julia Hambuchen
//Lab 11, Assign. 2, calculates quarterbacks' average of completed passes

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int SIZE = 7;
struct QuarterbackInfo
{
	string name;
	int completions;
	int attempts;
	double avg;
};

//declares function prototypes
void get_info(QuarterbackInfo players[]);
void get_avg(QuarterbackInfo players[]);
void get_totals(QuarterbackInfo players[], int&, int&, double&);
void get_winner(QuarterbackInfo players[], double&, string&);
void display_info(QuarterbackInfo players[], string, int, int, double);

int main()
{
	//declares needed variables in main
	QuarterbackInfo players[SIZE];
	int completions = 0, attempts = 0;
	double winner_avg, average;
	string winner;

	//calls functions
	get_info(players);
	get_avg(players);
	get_totals(players, completions, attempts, average);
	get_winner(players, winner_avg, winner);
	display_info(players, winner, completions, attempts, average);

	return 0;
}

//gets info from user
void get_info(QuarterbackInfo players[])
{
	cout << "Please enter the information for the " << SIZE << " players: " << endl;
	for (int a = 0; a < SIZE; a++)
	{
		cout << "Quarterback " << a + 1 << ": " << endl;
		cout << "Name: ";
		getline(cin, players[a].name);
		cout << "Number of completions: ";
		cin >> players[a].completions;
		cout << "Number of attempts: ";
		cin >> players[a].attempts;
		cin.ignore();
		cout << "\n";
	}

	return;
}

//gets players AVE 
void get_avg(QuarterbackInfo players[])
{
	for (int b = 0; b < SIZE; b++)
	{
		players[b].avg = (double)players[b].completions / players[b].attempts;
	}

	return;
}

//gets total numbers for attempts, completions, and the average average
void get_totals(QuarterbackInfo players[], int& completions, int& attempts, double& average)
{
	for (int d = 0; d < SIZE; d++)
	{
		completions += players[d].completions;
		attempts += players[d].attempts;
		average = (double)completions / attempts;
	}

}

//sees who has the highest AVE
void get_winner(QuarterbackInfo players[], double& winner_avg, string& winner)
{
	winner_avg = -1.0;
	winner;

	for (int c = 0; c < SIZE; c++)
	{
		if (players[c].avg > winner_avg)
		{
			winner_avg = players[c].avg;
		}
		if (winner_avg == players[c].avg)
		{
			winner = players[c].name;
		}
	}
	return;
}

//displays Info
void display_info(QuarterbackInfo players[], string winner, int completions, int attempts, double average)
{
	cout << "Quarterback  ";
	cout << setw(7) << "Completions  ";
	cout << setw(10) << "Attempts ";
	cout << setw(10) << "AVE";
	cout << endl;

	for (int e = 0; e < SIZE; e++)
	{
		cout << players[e].name;
		cout << setw(9) << players[e].completions;
		cout << setw(12) << players[e].attempts;
		cout << setw(15) << setprecision(3) << fixed << players[e].avg;
		cout << "\n";
	}

	cout << "\n";
	cout << "Totals";
	cout << setw(9) << completions;
	cout << setw(12) << attempts;
	cout << setw(15) << setprecision(3) << fixed << average;

	cout << "\n\n";
	cout << winner << " wins the ESPY award for the highest average of completed passes.";

	return;
}
