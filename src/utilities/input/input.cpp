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
