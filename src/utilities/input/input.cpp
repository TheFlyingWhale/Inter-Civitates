#include "input.hpp"

#include <iostream>
#include <string>

using namespace std;

string getInput(string prompt, bool clear)
{
	cout << prompt + " - H for help" << endl;
	string input;
	cin >> input;
	if (clear)
		system("clear");
	return input;
}

int getPositiveInt(string prompt, bool clear)
{
	string input;
	int intInput;
	bool validInputProvided = false;
	while (!validInputProvided)
	{
		try
		{
			cout << prompt << endl;
			cin >> input;
			intInput = stoi(input);

			if (intInput < 0)
			{
				throw "Provided input is not a positive number";
			}

			validInputProvided = true;
		}
		catch (invalid_argument const &ex)
		{
			cout << "That was not a valid number, try again" << endl;
		}
		catch (out_of_range const &ex)
		{
			cout << "Provided input was to large" << endl;
		}
		catch (const char *message)
		{
			cout << message << endl;
		}
	}
	return intInput;
}
