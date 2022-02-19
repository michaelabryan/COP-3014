/* Name: Michael Bryan
Date: September 5, 2017
Section: 5
Assignment: HW 1 - Area Calculator
Due Date: September 8, 2017
About this project: The goal of this program is to take a user's
numerical inputs to calculate the area of a
circle, square, and triangle, respectively.
Assumptions: Assumes correct user input (numbers).

All work below was performed by Michael Bryan */

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double circleradius, squarelength, tribase, triheight, PI = 3.14159; //Double variables all on one line to shorten code
	cout << fixed << showpoint << setprecision(2);

	cout << "Welcome to the COP3014 Area Calculator!\n" << "Please provide the following (all sizes in meters):\n";
	cout << '\t' << "Radius of Circle: "; //On a new line to improve readbility and grouping by cout/cin commands
	cin >> circleradius;
	cout << '\t' << "Side length of Square: ";
	cin >> squarelength;
	cout << '\t' << "Base length of Triangle: ";
	cin >> tribase;
	cout << '\t' << "Height length of Triangle: ";
	cin >> triheight;
	cout << "---------------------------------------------------------------------------------------------\n";

	cout << "Area of the Circle: " << PI*circleradius*circleradius << " m^2\n"; //Simplest way to square something is to multiply it twice
	cout << "Area of the Square: " << squarelength*squarelength << " m^2\n";
	cout << "Area of the Triangle: " << (1.0 / 2.0)*tribase*triheight << " m^2\n";
	cout << '\n' << "Thanks for using the COP 3014 Area Calculator!\n"; //Powered by BryTech USA!

	return 0;
}