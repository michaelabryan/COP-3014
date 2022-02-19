/* Name: Michael Bryan
Date: September 25, 2017
Section: 5
Assignment: HW 2
Due Date: September 26, 2017
About this project: This program will allow the user to play a game to match the value of dollars that they input.
Assumptions: User will provide letters for 

All work below was performed by Michael Bryan */

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	const double HALFDOLLAR = .50, QUARTER = .25, DIME = .10, NICKLE = .05, PENNY = .01;
	int num_halfdollar, num_quarter, num_dime, num_nickle, num_penny;
	double total_amount, total_guess;
	char play_ans;
	cout << fixed << showpoint << setprecision(2);

	cout << "Welcome to the coin game!\nWould you like to play? (y or n) --> ";
	cin >> play_ans;
	

	if (play_ans == 'y' || play_ans == 'Y') //Program being used as intended.
	{
		cout << "What amount of $ would you like to match? --> ";
		cin >> total_amount;
		cout << "Okay! You need to match the value of $" << total_amount << '\n' << "Enter the number of:\n";
		cout << "\tHalf Dollars: ";
		cin >> num_halfdollar;
		cout << "\tQuarters: ";
		cin >> num_quarter;
		cout << "\tDimes: ";
		cin >> num_dime;
		cout << "\tNickles: ";
		cin >> num_nickle;
		cout << "\tPennies: ";
		cin >> num_penny;

		//total_guess simplifies the formula into a single variable.
		total_guess = num_halfdollar*HALFDOLLAR + num_quarter*QUARTER + num_dime*DIME + num_nickle*NICKLE + num_penny*PENNY;

		if (num_halfdollar < 0 || num_quarter < 0 || num_dime < 0 || num_nickle < 0 || num_penny < 0) //Verify no negative numbers.
			cout << "You can't enter a negative amount of coins. Aborting game.\n";
		else //Once all numbers are checked, able to play game correctly. This "else" forks into three end statments based on value of "total_guess".
		{
			if (total_guess == total_amount)
				cout << "You WIN!\nThanks for playing!\n";
			else if (total_guess < total_amount)
				cout << "You LOST! You were under by: $" << total_amount - total_guess << "\nThanks for Playing!\n";
			else
				cout << "You LOST! You were over by: $" << total_guess - total_amount << "\nThanks for Playing!\n";
		}
	}
	else if (play_ans == 'n' || play_ans == 'N') //Game will skip to a taunt and end program if "n" or "N" is inputed.
		cout << "Guess you're scared! Come back when you're ready to play!\n";
	else //Anything besides "y", "Y", "n", or "N" will result in an invalid entry and will end the program.
		cout << "\aInvalid entry, aborting program.\n";

	return 0;
}