/*
 Name: Michael Bryan
 Date: December 2, 2017
 Section: 5
 Assignment: HW #7
 Due Date: December 6, 2017
 About this project: This project aims to open and read a specifically formated text file, store its information, and then close it.
 Once that is done, the information is stored in developer made data types (called structures) for use within the
 program. Dynamic arrays will be constructed so the information can be manipulated for the program's main intent.
 Assumptions: Team names will hold no more than 40 characters (so c-strings of 41). User must be forced to enter correct file name.
 First line of file is always an int. User entry for menu is an int.
 
 All work below was performed by Michael Bryan */

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

struct teamInfo
{
    char teamName[41];
    int teamWins;
    int teamLosses;
    bool goPlayoffs;
    int win_lossDiff;
};

void printMenu(); //Reduces size of main()
void atLeastWins(teamInfo *, int, const int); //teamInfo pointer for the array
void playoffChecker(teamInfo *, const int); //Prints teams that go to playoff
void bubbleSort(teamInfo[], const int); //Book example, Ch 8.3 //Pointers can direct to an array param.
void swapStructArray(teamInfo &, teamInfo &); //Book example, Ch 8.3

int main()
{
    const int SIZE = 21; //Can be adjusted in code if filename needs to be increased
    char filename[SIZE]; //User inputed filename
    int userMenuSelection = NULL; //Set to NULL as to not immediately end program
    bool invalidMenuChoice = false, skipBeginning = false; //Assists in switch menu
    ifstream inFile; //Stream object that will read file
    int firstNum, numWins; //firstNum reads first int from file. numWins reads user inputed minimum wins
    
    teamInfo * NFLteams = nullptr; //Pointer for a dynamic array after reading in first int
    
    //*********************************************************
    //*                                                       *
    //*             This block of code is for loading         *
    //*              the text file from the source            *
    //*             location per user document input          *
    //*                                                       *
    //*********************************************************
    
    
    inFile.clear(); //Clears anything that may be in the stream for inFile
    do //Loop to ensure user entered a correct file name
    {
        cout << "Please enter the name of the input file.\nFilename: ";
        cin >> filename;
        inFile.open(filename);
        
        if (!inFile)
        {
            cout << "That is not a valid file. Try again!\n";
        }
        else
        {
            cout << "The file loaded!\n";
        }
        
    } while (!inFile);
    
    
    inFile >> firstNum; //Number of lines/teams the text file holds
    inFile.ignore(1); //ignores newline after the first int
    
    NFLteams = new teamInfo[firstNum]; //Dynamically allocates memory based on text file
    
    for (int i = 0; i < firstNum; i++) //Reads data from text file to write to array
    {
        inFile.clear();
        inFile.getline((NFLteams + i)->teamName, 41, ','); //Accepts team name and removes first comma
        inFile >> (NFLteams + i)->teamWins; //Accepts win numbers
        inFile.ignore(1); //ignores comma
        inFile >> (NFLteams + i)->teamLosses; //Accepts number of losses
        inFile.ignore(1); //ignores comma
        inFile >> (NFLteams + i)->goPlayoffs; //Boolean for whether or not team goes to playoff
        if (!inFile.eof()) //if statement to ignore newline
            inFile.ignore(1);
        (NFLteams + i)->win_lossDiff = (NFLteams + i)->teamWins - (NFLteams + i)->teamLosses; //Win differential input
    }
    
    inFile.close(); //Can close file stream now to use again later if desired
    
    //*********************************************************
    //*                                                       *
    //*             Begins to use the data for user           *
    //*                        purposes.                      *
    //*                                                       *
    //*********************************************************
    
    do
    {
        if (skipBeginning == false) //Prints the menu only if the user has already gone through an option
        {
            printMenu();
            cout << "Choice: ";
            cin >> userMenuSelection;
        }
        switch (userMenuSelection) //My switch code used in previous homeworks
        {
            case 1: //Prints all teams' W/L record
            {
                cout << "\nTeam W-L:\n";
                for (int i = 0; i < firstNum; i++)
                {
                    cout << (NFLteams + i)->teamName << ' ' << (NFLteams + i)->teamWins << '-';
                    cout << (NFLteams + i)->teamLosses << '\n';
                }
                cout << '\n';
                skipBeginning = false;
                
                break;
            }
            case 2: //Teams that have a minimum win number
            {
                cout << "\nShow teams with how many wins? --> ";
                cin >> numWins;
                atLeastWins(NFLteams, numWins, firstNum);
                skipBeginning = false;
                
                break;
            }
            case 3: //Teams that go to playoffs printed
            {
                cout << "\nPlayoff Teams:";
                playoffChecker(NFLteams, firstNum);
                skipBeginning = false;
                
                break;
            }
            case 4: // W/L differential is printed
            {
                cout << '\n';
                for (int i = 0; i < firstNum; i++)
                {
                    cout << showpos;
                    cout << (NFLteams + i)->teamName << ' ' << (NFLteams + i)->win_lossDiff << '\n';
                    cout << noshowpos;
                }
                cout << '\n';
                skipBeginning = false;
                
                break;
            }
            case 5: //Sorts teams via ascending W/L differential
            {
                bubbleSort(NFLteams, firstNum);
                cout << '\n';
                skipBeginning = false;
                
                break;
            }
            case 0: //Exits program with a funny* quote (* hiliarity value may vary per user)
            {
                cout << "\nHasta la Vista.......... Baby.\n";    //Arnold will be baaaahck.
                
                break;
            }
            default: //Switch statement defaults if user inputs int that is either less than 0 or greater than 5 (without decimal points)
            {
                do
                {
                    cout << "\nInvalid Choice.\nYou can try Again: ";
                    invalidMenuChoice = true;
                    cin >> userMenuSelection;
                    
                    if (userMenuSelection == 0 || userMenuSelection == 1 || userMenuSelection == 2 || userMenuSelection == 3 || userMenuSelection == 4 || userMenuSelection == 5)
                    {
                        invalidMenuChoice = false;
                        
                        break;
                    }
                } while (invalidMenuChoice == true);
                skipBeginning = true;
                invalidMenuChoice = false;
            }
        }
        
        if (userMenuSelection == 0)
        {
            break;
        }
        invalidMenuChoice = false;
        
    } while (userMenuSelection == 1 || userMenuSelection == 2 || userMenuSelection == 3 || userMenuSelection == 4
             || userMenuSelection == 5);
    
    delete[] NFLteams; //No memory leaks
    NFLteams = nullptr; //Reset to nullptr if code is added to main() after this point
    
    return 0;
}

void printMenu() //Simple print function
{
    cout << "Select one of the following choices:\n";
    cout << "\t1 - View team Win / Loss records\n";
    cout << "\t2 - Show teams with at least x wins\n";
    cout << "\t3 - List teams that made the playoffs\n";
    cout << "\t4 - Print teams and their Win Loss Differentials\n";
    cout << "\t5 - Sort teams by their Win Loss Differentials\n";
    cout << "\t0 - Exit program\n";
    
    return;
}

void atLeastWins(teamInfo * ptr, int wins, const int SIZE) //Option 2
{
    for (int i = 0; i < SIZE; i++)
    {
        if ((ptr + i)->teamWins >= wins)
            cout << (ptr + i)->teamName << '\n';
    }
    cout << '\n';
    
    return;
}

void playoffChecker(teamInfo * ptr, const int SIZE) //Option 3
{
    bool initialCOUT = false;
    
    cout << '\n';
    for (int i = 0; i < SIZE; i++)
    {
        if ((ptr + i)->goPlayoffs == true && initialCOUT == false)
        {
            cout << (ptr + i)->teamName;
            initialCOUT = true;
        }
        else if ((ptr + i)->goPlayoffs == true)
            cout << ", " << (ptr + i)->teamName;
    }
    cout << "\n\n";
    
    
    return;
}

void bubbleSort(teamInfo ptr[], const int SIZE) //Code from book, Ch 8.3
{
    int count = 1;
    for (int maxElement = SIZE - 1; maxElement > 0; maxElement--)
    {
        for (int i = 0; i < maxElement; i++)
        {
            if ((ptr + i)->win_lossDiff >(ptr + (i + 1))->win_lossDiff)
            {
                swapStructArray(*(ptr + i), *(ptr + (i + 1)));
                count++;
            }
        }
    }
    return;
}

void swapStructArray(teamInfo & uno, teamInfo & dos) //Code from book, Ch 8.3
{
    teamInfo temp = uno;
    uno = dos;
    dos = temp;
    
    return;
}

