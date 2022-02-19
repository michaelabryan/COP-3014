/*Name: Michael Bryan
Date: 9/25/2017
Section: 5
Assignment: Assignment #2
Due Date: 9/26/2017
About this project: This program will allow a user to determine the number of days in a month.
Assumptions: User may enter an invalid month, but must enter a valid year.

All work below was performed by Michael Bryan */

#include <iostream>
using namespace std;

int main()
{
	int month, year, days;
	
	//This block of code allows the user to input only a integer value for the month/year without aborting the program immediately.
	cout << "Enter a month (1-12): ";
	cin >> month;
	cout << "Enter a year: ";
	cin >> year;

	//The next block of code checks the month to determine validity, number of days, and if that month falls during a leap year.
	if (month < 1 || month > 12 || month%1 != 0) //Will cause program to abort if month does not enter a month 1-12 or whole integer.
	{
		cout << "Invalid Month entered. Aborting Program\n";
	}
	else
	{
		if (month == 2) //Specifically checks if user input is for the month Febuary.
		{
			if (year % 100 == 0 && year % 400 == 00 || year % 100 != 0 && year % 4 == 0) //An 'if' statement to check leap year status.
				days = 29;
			else
				days = 28;
		}
		else //The code for this 'else' falls under correct inputs and finds number of days based on the pattern of 31 days for odd months before/at 7 and even months at/after 8.
		{
			if (month <= 7 && month % 2 != 0)
				days = 31;
			else if (month >= 8 && month % 2 == 0)
				days = 31;
			else
				days = 30;
		}
		cout << "Number of days: " << days << endl; //After program determines correct number of days, it puts a simple output here.
	}

	return 0;
}