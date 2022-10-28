// Source(s) of logic assistance:  
// Gaddis, T. (2018). Starting out with C++: From control structures through objects. Pearson. 
// Getline in loops
// https://stackoverflow.com/questions/2039918/stdgetline-does-not-work-inside-a-for-loop

#include <iostream> // To use cin/cout
#include <string>   // To implement to_string function
using namespace std;

// Global Constant Initialization
const string TITLE = "Name String Manipulator Program";
const string AUTHOR_LINE = "By Forrest Moulin";

// Function prototypes to notify compiler
string convertName(string input);
int anotherName();

int main()
{
	cout << TITLE << endl
		<< AUTHOR_LINE << endl;

	// Dynamic Variable Initialization
	string nameInput;
	char continueChar; // 'Y' or 'N'
	bool keepLooping = true;

	do
	{
		nameInput = "";
		// Program Logic
		cout << endl << "Please enter a name in the following format:"
			<< endl << "Forrest A Gump" << endl << endl
			<< "Note: Enter N/A for the middle initial "
			<< "if there is no middle name." 
			<< endl << endl;
		// Read in the entire line
		getline(cin, nameInput);
		cout << endl << "Converting name entry..." << endl 
			<< convertName(nameInput) << endl << endl;
		keepLooping = anotherName();
		// Clear '\n' from cin at end of iteration,
		// allowing getline to work properly
		cin.get();
	} while (keepLooping == true);

	cout << endl << "Exiting the program... Until next time!" << endl;
}

// Receives user input string arg and prints manipulated str
string convertName(string input)
{
	string firstName = "", middleInitial = "", lastName = "";
	string concatenation;
	int nameDividerCount = 0, spaceCount = 0;
	int foundIndex = 0;
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] == ' ')
		{
			spaceCount++;
			if (nameDividerCount < 2)
			{
				nameDividerCount++;
			}
		}

		if (nameDividerCount == 0 && input[i] != ' ')
		{
			firstName += input[i];
		}
		else if (nameDividerCount == 1 && input[i] != ' ')
		{
			middleInitial += input[i];
		}
		else if (nameDividerCount == 2)
		{
			lastName += input[i];
		}
	}

	// Ensure names are capitalized
	// In case there are multiple letters in middle initial,
	// capitalize all letters
	for (int i = 0; i < middleInitial.length(); i++)
	{
		middleInitial[i] = toupper(middleInitial[i]);
	}

	// Concatenate string and return it to main()
	input = lastName + ", " + firstName + " " + middleInitial;
	input[0] = toupper(input[0]);

	while (spaceCount >= 0)
	{
		// Capitalize any chars that follow a space
		// This will also capitalize last name, since
		// a space was intentionally added before it.
		foundIndex = input.find(' ', foundIndex) + 1;
		input[foundIndex] = toupper(input[foundIndex]);
		spaceCount--;
	}

	// Remove intentional space once concatenation is complete
	input = input.substr(1, input.length());
	return input;
}

// Returns 0 to exit (false), 1 to keep looping (true)
int anotherName()
{
	static string inputStr;
	static char continueChar;
	static bool keepLooping = true;

	while (keepLooping == true)
	{
		continueChar;
		inputStr = "";
		cout << "Would you like to enter another name?"
			<< endl << "(Y for yes, N for no)"
			<< endl << endl;

		cin >> inputStr;
		// Data validation (only read 1st char at index 0)
		continueChar = inputStr[0];

		if (continueChar == 'y' || continueChar == toupper('y'))
		{
			break;
		}
		else if (continueChar == 'n' || continueChar == toupper('n'))
		{
			keepLooping = false;
		}
		else
		{
			cout << endl << "Invalid entry." << endl;
		}
	}
	return keepLooping;
}

/*
* CONSOLE OUTPUT
* Name String Manipulator Program
* By Forrest Moulin
*
* Please enter a name in the following format:
* Forrest A Gump
*
* Note: Enter N/A for the middle initial if there is no middle name.
*
* nikola n/a tesla
*
* Converting name entry...
* Tesla, Nikola N/A
*
* Would you like to enter another name?
* (Y for yes, N for no)
*
* y
*
* Please enter a name in the following format:
* Forrest A Gump
*
* Note: Enter N/A for the middle initial if there is no middle name.
*
* alexandre m de souza
*
* Converting name entry...
* De Souza, Alexandre M
*
* Would you like to enter another name?
* (Y for yes, N for no)
*
* n
*
* Exiting the program... Until next time!
*/
