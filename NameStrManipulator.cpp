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
	int spaceCount = 0;
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] == ' ' && spaceCount < 2)
		{
			spaceCount++;
		}
		if (spaceCount == 0 && input[i] != ' ')
		{
			firstName += input[i];
		}
		else if (spaceCount == 1 && input[i] != ' ')
		{
			middleInitial += input[i];
		}
		else if (spaceCount == 2)
		{
			lastName += input[i];
		}
	}
	// Inclusive programming approach:
	// Remove 1st space in last name, but allow
	// subsequent spaces to be entered if last name
	// contains spaces. 
	lastName = lastName.substr(1, lastName.length());

	// Ensure names are capitalized
	firstName[0] = toupper(firstName[0]);
	lastName[0] = toupper(lastName[0]);
	// In case there are multiple letters in middle initial,
	// capitalize all letters
	for (int i = 0; i < middleInitial.length(); i++)
	{
		middleInitial[i] = toupper(middleInitial[i]);
	}

	// If last name has multiple names/spaces,
	// capitalize each name
	for (int i = 1; i < lastName.length(); i++)
	{
		// If the previous char was a space,
		// capitalize the current char
		if (lastName[i - 1] == ' ')
		{
			lastName[i] = toupper(lastName[i]);
		}
	}
	// Concatenate string and return it to main()
	input = lastName + ", " + firstName + " " + middleInitial;
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
