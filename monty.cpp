/* Name: Michael Bryan
Date: October 20, 2017
Section: 5
Assignment: HW #4
Due Date: October 20, 2017
About this project: This project focuses on demonstrating functions, loops, conditionals, and a random number generator in a program. With these tools,
Monty Hall's "Let's Make a Deal" gameshow can be emulated.
Assumptions: User can choose an incorrect value within the menu that isn't 1-4.

All work below was performed by Michael Bryan */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

void printDoors();
void printCar1();
void printCar2();
void printCar3();
void menuSelection();
void timeDelay(); //Adds..... SUSPENSE!!
void timeDelay1fourth(); //Adds a little suspense o_o
int doorChooser(int, int, int&);
double winPercent(int, double);
double lossPercent(int, double);

//Your function declarations go here:

int main()
{
	int winDoor, randoNum, userMenuSelection, userDoorSelection, otherDoor, goatDoor;
	unsigned int userWins = 0, userLosses = 0, invalidDoorCounter = 0, invalidMenuCounter = 0;
	double totalGames = 0.0;

	cout << "Welcome to the Monty Hall Let's Make a Deal Simulator!\n";

	//begin a loop that presents the user with the menu and determines their choice 1,2,3,or 4.
	do
	{
		if (invalidMenuCounter == 0)
		{
			menuSelection();
		}
		cin >> userMenuSelection;
		switch (userMenuSelection)
		{
			case 1: //Let's Make a Deal!! CPU winning door initialized once case 1 begins.
			{	srand(time(0));
				randoNum = rand() % 3 + 1;
				winDoor = randoNum;

				//Game Begins for User
				cout << "\nPick a door: 1, 2, or 3!\n\n";
				printDoors();
				cout << "User Choice > ";
				cin >> userDoorSelection;
				goatDoor = doorChooser(userDoorSelection, winDoor, otherDoor = 1); //The "random" door that has a goat needs to be initialized after the user picks the door.
				switch (userDoorSelection) //Ensures user picks a door between 1-3
				{
					case 1:
					case 2:
					case 3:
						break;
					default:
						do
						{
							cout << "Please Choose a Door > ";
							cin >> userDoorSelection;
						} while (userDoorSelection < 1 || userDoorSelection > 3);
				}
				cout << "You chose door #" << userDoorSelection << "!\n";
				cout << "I'll now open a door for you randomly that you didn't choose!\n";
				cout << "Opening door #" << goatDoor << " and it's a ";
				timeDelay1fourth();
				timeDelay1fourth();
				cout << "GOAT!\n";
				timeDelay1fourth();
				cout << "Now, I'll be a kind host and give you the chance to switch your door!\n";
				cout << "Would you like door #";
				if (userDoorSelection < winDoor) //This if/else block organizes remaining door numbers numerically.
					cout << userDoorSelection << " or #" << winDoor << "? > ";
				else if (winDoor < userDoorSelection)
					cout << winDoor << " or #" << userDoorSelection << "? > ";
				else if (userDoorSelection == winDoor)
				{
					if (userDoorSelection < otherDoor)
						cout << userDoorSelection << " or #" << otherDoor << "? > ";
					else if (otherDoor < userDoorSelection)
						cout << otherDoor << " or #" << userDoorSelection << "? > ";
				}
				cin >> userDoorSelection;
				while (userDoorSelection == goatDoor) //User will not be able to choose the opened door.
				{
					cout << "Please select your original door or the remaining door: ";
					cin >> userDoorSelection;
				}
				cout << "Opening door #" << userDoorSelection << ".......";
				timeDelay(); //OOOOOoooooOOoh, what's gonna be the outcome?? The suspense is killing me!!
				if (userDoorSelection == winDoor)
				{
					cout << "\nIT'S A BRAND NEW CAR!! YOU WIN!!\n";
					userWins++;
					totalGames++;
					printCar1();
					printCar2();
					printCar3();
				}
				else if (userDoorSelection != winDoor)
				{
					cout << "\nbaaaaaaaaaaaaaaaaa... it's a GOAT!!! YOU LOSE!\n";
					userLosses++;
					totalGames++;
				}

				invalidMenuCounter = 0;
				break;
			}
			case 2: //Game Statistics
			{
				if (totalGames == 0)
				{
					cout << fixed << setprecision(0);
					cout << "\nNo stats to display, " << totalGames << " games played.\n\n";
				}
				else
				{
					cout << fixed << setprecision(0);
					cout << "\nResults after " << totalGames << " games:\n";
					cout << "Wins: " << userWins << "\tLosses: " << userLosses << '\n';
					cout << "Win %: " << winPercent(userWins, totalGames) << "\tLoss %: " << lossPercent(userLosses, totalGames) << "\n\n";
				}
				invalidMenuCounter = 0;
				break;
			}
			case 3 : //Resets Statistics
			{
				cout << "\nResetting Statistics.";
				userWins = 0;
				userLosses = 0;
				totalGames = 0;
				timeDelay();
				cout << "\n....Statistics Reset!\n\n";
				invalidMenuCounter = 0;
				break;
			}
			case 4 : //Exits Game.
			{
				cout << "\nGoodbye!\n";
				break;
			}
			default:
			{
				cout << "Invalid option, please retry > ";
				invalidMenuCounter++;
				continue;
			}
		}
		if (userMenuSelection == 4)
			break;
	} while (userMenuSelection >= 1 && userMenuSelection <= 3 || invalidMenuCounter >= 1);
	



	return 0;
}

/*ASCII Art doors*/
/*THIS FUNCTION PRINTDOORS IS PROVIDED (graciously by ascii artist Melina) by the student wherever needed.*/
void printDoors()
{
	cout << "---------    ---------    ---------- \n";
	cout << "|       |    |  ____ |    |  _____ | \n";
	cout << "|  /|   |    |     | |    |      | | \n";
	cout << "|   |   |    |  ___| |    |   ___| | \n";
	cout << "|   |   |    | |     |    |      | | \n";
	cout << "| __|__ |    | |____ |    |  ____| | \n";
	cout << "---------    ---------    ---------- \n\n";

	return;
}

void menuSelection()
{
	cout << "\nChoose one of the following:\n";
	cout << "1 Play Game\n";
	cout << "2 See Stats\n";
	cout << "3 Reset Stats\n";
	cout << "4 Quit Game\n";
	cout << "> ";
}

void printCar1()
{
	cout << "                  *               *                       *                   \n";
	cout << "           *            +    *              *           *                  \n";
	cout << "                  *          _______________________         *        * \n";
	cout << "                        +   (            |           )                    \n";
	cout << "   *        *  +   *       /             |     *     \\      *               \n";

	return;
}
	
void printCar2()
	{
		cout << "                          /     *        |            \\               *         \n";
		cout << "                  +      /               |             \\   *       ____          \n";
		cout << "       *O*              /        *       |       *      \\         / ___/        \n";
		cout << "       _|______________/_________________|_______________\\ ______/ /_       \n";
		cout << "      ( xx )        |        +       |                   /        ( xx\\        ";

		return;
	}
void printCar3()
{
	cout << "      ( xx )         \\          < >  |             < >  /   *     ( xx \\    *    \n";
	cout << "  *   3        ______  \\             |       *         / ______        |        |\n";
	cout << "      3      / \\  //\\  |       *    |  *             // \\  //\\       |         \n";
	cout << "      3     ( == X == ) |            |               |( == X == )     |   *    *    \n";
	cout << "      (      \\ //  \\ / |             |      *        | \\ //  \\ /  __/         \n";
	cout << "      (-------\\______/--|------------|---------------'--\\______/--'        \n";

	return;
}

void timeDelay()
{
	for (int i = 0; i < 1000000000; i++);
}

void timeDelay1fourth()
{
	for (int i = 0; i < 250000000; i++);
}

double winPercent(int winSum, double gameCount)
{
	cout << fixed << showpoint << setprecision(1);
	double winningPercentage = (winSum/gameCount)*100;

	return winningPercentage;
}

double lossPercent(int loseSum, double gameCount)
{
	cout << fixed << showpoint << setprecision(1);
	double losingPercentage = (loseSum / gameCount) * 100;

	return losingPercentage;
}

int doorChooser(int user, int cpuDoor, int& choose1Door)
{
	int autoGoatDoor;

	if (user != cpuDoor)
	{
		autoGoatDoor = user - cpuDoor;
		if (autoGoatDoor < 0)
			autoGoatDoor = autoGoatDoor*(-1);
		if (autoGoatDoor == user || autoGoatDoor == cpuDoor)
			autoGoatDoor = 3; 
	}
	else
	{
		if (user == 1)
		{
			autoGoatDoor = rand() % 2 + 2;
			if (autoGoatDoor == 2)
				choose1Door = 3;
			else
				choose1Door = 2;
		}
		else if (user == 2)
		{
			autoGoatDoor = rand() % 2;
			if (autoGoatDoor == 0)
				autoGoatDoor++;
			else
				autoGoatDoor += 2;
			if (autoGoatDoor == 1)
				choose1Door = 3;
		}
		else
			autoGoatDoor = rand() % 2 + 1;
		
	}

	if (autoGoatDoor == user)
		autoGoatDoor = autoGoatDoor + 1;

	return autoGoatDoor;
}