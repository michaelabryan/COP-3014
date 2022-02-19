/* Name: Michael Bryan
Date: October 6, 2017
Section: 5
Assignment: HW #3, Part 1 - Temperature Converter and Averager 
Due Date: October 6, 2017
About this project: This assignment will convert individual temperatures from Fahrenheit to Celsius.
Assumptions: The user will enter at least one valid temperature.

All work below was performed by Michael Bryan */

#include <iostream>
#include <iomanip> //necessary for setting decimal point to two decimal places.
using namespace std;

int main()
{
	//Declaring, initilizing, and setting format for program to run
	char userResponse;
	int i = 0;
	double tempFahrenheit, tempCelsius;//Chose to include Fahrenheit as dbl for precise conversions.
	double sumCelsius = 0; 
	cout << fixed << showpoint << setprecision(2);

	//The main section of code that will be utilized
	do //Code is assumed to run at least once due to homework parameters.
	{
		cout << "Temperature to convert from F to C: ";
		cin >> tempFahrenheit;
		tempCelsius = (tempFahrenheit - 32) * (5.0 / 9);
		cout << tempFahrenheit << " F = " << tempCelsius << " C\n\n";
		sumCelsius += tempCelsius;
		cout << "Enter another temperature? (Y or N): ";
		cin >> userResponse;
		i++;
		cout << '\n';
	} while (userResponse == 'Y' || userResponse == 'y'); //Will exit loop if neither yes response is typed

	if (userResponse == 'n' || userResponse == 'N')
	{
		double avgCelsius = sumCelsius / i;
		cout << "Number of temperatures entered: " << i << "\nAverage Temperature: " << avgCelsius << " C\n";
	}
	else
		cout << "INVALID INVALID INVALID. EXTERMINATE... PROGRAM!!!"; //Voiced by our robot overloads, Daleks.

	return 0;
}