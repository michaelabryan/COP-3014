/* Name: Michael Bryan
Date: October 24, 2017
Section: 5
Assignment: HW #5
Due Date: November 6, 2017
About this project: Using what has already been learned in previous sections, data will be entered into an array
					so that the stored information can be manipulated how the user wishes.
Assumptions: Main menu will have options for (P) Print, (F) Fill array, (I) Insert, (D) Delete, (R) Reverse, (X) Max odd value,
			 (M) Print Menu, and (Q) Quit. Menu prints first time automatically for user. User will use "Fill Array" first, will give
			 legitimate Max/Min values. Array will be filled with INTEGERS, (i.e. no decimal points).

All work below was performed by Michael Bryan (except for the starter file text). */

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <cctype>
using namespace std;

/*Starter function*/
void PrintArray(const int[], const int);

/*functions below do not have cin/cout statements*/
void fillArray(int[],const int,int,int);
void Insert(int[],const int,int,int); //four parameters
void Delete(int[], const int, int); //three parameters
void Reverse(int[], const int); //two parameters
int MaxOdd(int[], const int);//two parameters

/*My own functions*/
int MaxEven(int[], const int); //Complement to Max Odd
void printMenu(); //Prints the menu to the screen
void timeDelay(); //Time delays allow user to read the current line at a reasonable pace
void timeDelay1fourth();

int main()
{
	const int SIZE = 16;
	char userMenuSelection, Yes_No_Ans;
	int userMinVal=-50, userMaxVal=100;
	int userNewVal, userElementPick;
	bool invalidMenuChoice = false, skipBeginningLoop=false;

	/* Declare your array of size SIZE*/
	int arrMatey[SIZE];


	/*Loop that presents user with menu options and calls appropriate Array functions*/
	/*Note: you can assume the user will call Fill Array function first so that the array has data in it to begin*/
	fillArray(arrMatey, SIZE, userMinVal, userMaxVal);
	printMenu();

	do
	{
		if (skipBeginningLoop == false)
		{
			cout << "What is your menu selection: ";
			cin >> userMenuSelection;
		}
		userMenuSelection = toupper(userMenuSelection); //toupper reduces lines of code to account for upper/lowercase
		switch (userMenuSelection)
		{
		case 'P': //Only need 'P' because of toupper
		{
			PrintArray(arrMatey, SIZE);
			cout << '\n';
			skipBeginningLoop = false;

			break;
		}
		case 'F':
		{
			cout << "What is the minimum random value? ";
			cin >> userMinVal;
			cout << "What is the maxiumum random value? ";
			cin >> userMaxVal;
			if (userMaxVal <= userMinVal) //Error checking
			{
				cout << "Please understand that a maximum value must be greater than a minimum value before trying again. Aborting.";
				break;
			}
			else
			{
				fillArray(arrMatey, SIZE, userMinVal, userMaxVal);
				cout << '\n';
				PrintArray(arrMatey, SIZE);
				timeDelay();
			}
			skipBeginningLoop = false;

			break;
		}
		case 'I':
		{
			cout << "Please pick an array element between 0 and " << SIZE - 1 << " : ";
			cin >> userElementPick;
			if (userElementPick < 0 || userElementPick >= SIZE) //Error checking ensure user has a value between 0 and array size -1
			{
				cout << "Element selection is not within the array bounds.\nAborting Insert. You may try again by reselecting \"I\"";
				break;
			}
			else
			{
				cout << "Please enter a new value to be inserted: ";
				cin >> userNewVal;
				Insert(arrMatey, SIZE, userNewVal, userElementPick);
				cout << '\n';
				PrintArray(arrMatey, SIZE);
				timeDelay();
			}
			skipBeginningLoop = false;

			break;
		}
		case 'D':
		{
			cout << "Please pick an array element between 0 and " << SIZE - 1 << " : ";
			cin >> userElementPick;

			if (userElementPick < 0 || userElementPick >= SIZE) //Error checking
			{
				cout << "Element selection is not within the array bounds.\nAborting Insert. You may try again by reselecting \"D\"";
				break;
			}
			else
			{
				//Ensures user is fully aware of which number is being deleted
				cout << "Are you sure you want " << userElementPick << " holding the value " << arrMatey[userElementPick] << " to be deleted? (Y/N): ";
				cin >> Yes_No_Ans;
				switch (toupper(Yes_No_Ans))
				{
				case 'Y':
				{
					cout << "Deleting.";
					timeDelay1fourth();
					cout << ".";
					timeDelay1fourth();
					cout << ".";
					timeDelay1fourth();
					cout << ".";
					Delete(arrMatey, SIZE, userElementPick);
					timeDelay1fourth();
					cout << " Deleted!\n";
					PrintArray(arrMatey, SIZE);

					break;
				}
				case 'N': //Allows user to not delete a number if mistake is made
				{
					cout << "Nothing deleted. Returning to Main Menu.";
					timeDelay1fourth();

					break;
				}
				}
			}
			skipBeginningLoop = false;

			break;
		}
		case 'R':
		{
			cout << "\n---Before Function Operation---\n";
			PrintArray(arrMatey, SIZE);
			Reverse(arrMatey, SIZE);
			cout << "\n---After Function Operation---\n";
			PrintArray(arrMatey, SIZE);
			cout << '\n';
			skipBeginningLoop = false;

			break;
		}
		case 'X':
		{
			cout << "The maximum odd value is " << MaxOdd(arrMatey, SIZE) << ".\n";
			timeDelay();
			skipBeginningLoop = false;

			break;
		}
		case 'M':
		{
			printMenu();
			skipBeginningLoop = false;

			break;
		}
		case 'Q':
		{
			PrintArray(arrMatey, SIZE);
			skipBeginningLoop = false;

			break;
		}
		case 'Y':
		{
			cout << "The maximum even value is " << MaxEven(arrMatey, SIZE) << ".\n";
			timeDelay();
			skipBeginningLoop = false;

			break;
		}
		default:
		{
			do
			{
				cout << "Invalid option, please retry > ";
				invalidMenuChoice = true;
				cin >> userMenuSelection;
				userMenuSelection = toupper(userMenuSelection);

				if (userMenuSelection == 'P' || userMenuSelection == 'F' || userMenuSelection == 'I'|| userMenuSelection == 'D'
					|| userMenuSelection == 'R' || userMenuSelection == 'X' || userMenuSelection == 'M' || userMenuSelection == 'Y')
				{
					invalidMenuChoice = false;
					skipBeginningLoop = true;

					break;
				}
			} while (invalidMenuChoice == true);

			break;
		}
		}
		if (userMenuSelection == 'Q')
		{
			break;
		}
		invalidMenuChoice = false;

	} while (userMenuSelection == 'P' || userMenuSelection == 'F' || userMenuSelection == 'I'|| userMenuSelection == 'D'
		|| userMenuSelection == 'R' || userMenuSelection == 'X' || userMenuSelection == 'M' || userMenuSelection == 'Y');

	return 0;
}


/* Add in the definitions of your own 5 functions HERE */

void fillArray(int arr[], const int SIZE, int Min, int Max)
{
	srand((unsigned int)(time(0)));
	
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % (Max - Min) + Min;
	}

	return;
}

void Insert(int arr[], const int ARRSIZE, int userPickVal, int arrElement)
{
	int temp = 0;
	for (int i = ARRSIZE-1; i >= arrElement; i--)
	{
		if (arr[i] == arr[arrElement])
			arr[i] = userPickVal;
		else if (arr[i] != arr[arrElement])
		{
			arr[i - 1] = temp;
			temp = arr[i];
		}
	}

	return;
}

void Delete(int arr[], const int ARRSIZE, int arrElement)
{
	for (int i = arrElement; i < ARRSIZE; i++)
	{
		if (i != ARRSIZE-1)
			arr[i] = arr[i + 1];
		else
			arr[i] = 0;
	}
	return;
}

void Reverse(int arr[], const int ARRSIZE)
{
	int temp=0;
	for (int i = 0; i <= (ARRSIZE / 2); i++)
	{
		temp = arr[i];
		arr[i] = arr[ARRSIZE - (i + 1)];
		arr[ARRSIZE - (i + 1)] = temp;
	}

	return;
}

int MaxOdd(int arr[], const int ARRSIZE)
{
	int maxOddNum=0, tempHighestOdd;
	for (int i = 0; i < ARRSIZE; i++)
	{
		for (int j = 0; j < ARRSIZE; j++) //Second for loop finds a maxOddNum to compare
		{
			if (arr[j] % 2 != 0)
			{
				tempHighestOdd = arr[j];
				maxOddNum = tempHighestOdd;
			}
			if (maxOddNum != NULL)
				break;
		}
		if (arr[i] % 2 != 0) //Once inner for loop is ran, this if statement will take over
		{
			tempHighestOdd = arr[i];
			if (tempHighestOdd > maxOddNum)
				maxOddNum = tempHighestOdd;
		}
	}

	return maxOddNum;
}

/* Definition of PrintArray below DO NOT CHANGE!*/

//PrintArray Function
//This function prints the contents of any interger array of any size seperated by commas
void PrintArray(const int arr[], const int size)
{
	cout << "\nThe array:\n { ";
	for (int i = 0; i < size - 1; i++)	// for loop, prints each item (not last due to comma handling)
		cout << arr[i] << ", ";

	cout << arr[size - 1] << " }\n";	// prints last item , sans comma
}

//Developer functions below
void printMenu()
{
	cout << "\n\t** Given Features **\n";
	cout << "P\tPrint the array contents\n\n";
	cout << "\t** Function Tests **\n";
	cout << "F\tFill the array with random values\n";
	cout << "I\tInsert\n";
	cout << "D\tDelete\n";
	cout << "R\tReverse\n";
	cout << "X\tMax Odd Value\n\n\n";
	cout << "M\tPrint this Menu\n";
	cout << "Q\tQuit this Program\n\n";
	cout << "\t** Extra Feature **\n";
	cout << "Y\tMax Even Value\n\n";

	return;
}

int MaxEven(int arr[], const int ARRSIZE)
{
	int maxEvenNum = 0, tempHighestEven = 0;

	for (int i = 0; i < ARRSIZE; i++)
	{
		int newValue = arr[i];

		if (newValue % 2 == 0)  //Check for even numbers
		{
			if (tempHighestEven == NULL)  //Need to initially set the tempHighestEven value (first time through)
				tempHighestEven = newValue;
			else 
			{
				if (newValue> tempHighestEven)  //If value has been set, do comparison to find the next highest even number
					tempHighestEven = newValue;
			}
		}
		maxEvenNum = tempHighestEven;
	}

	return maxEvenNum;
}

void timeDelay()
{
	for (int i = 0; i < 1000000000; i++);
}

void timeDelay1fourth()
{
	for (int i = 0; i < 250000000; i++);
}