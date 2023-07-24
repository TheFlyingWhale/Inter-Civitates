#include "richPrint.hpp"

#include <string>
#include <iostream>

using namespace std;

namespace Print
{
	void newLine()
	{
		cout << endl;
	}

	void hardClear()
	{
		printf("\033[2J\033c");
	}

	void error(string message)
	{
		cout << rich("Error: ", Color::red, Decoration::bold) << message << endl;
	};

	void success(string message)
	{
		cout << rich("Success: ", Color::green, Decoration::bold) << message << endl;
	}

	// Only color
	string rich(string text, Color color)
	{
		return "\033[" + getColorCode(color) + "m" + text + "\033[0m";
	}

	// Only decoration
	string rich(string text, Decoration decoration)
	{
		return "\033[" + to_string(decoration) + "m" + text + "\033[0m";
	}

	// Color and decoration
	string rich(string text, Color color, Decoration decoration)
	{
		return "\033[" + getColorCode(color) + ";" + to_string(color) + "m" + text + "\033[0m";
	}

	string getColorCode(Color color)
	{
		switch (color)
		{
		case Color::black:
			return "30";
		case Color::red:
			return "31";
		case Color::green:
			return "32";
		case Color::yellow:
			return "33";
		case Color::blue:
			return "34";
		case Color::magenta:
			return "35";
		case Color::cyan:
			return "36";
		case Color::orange:
			return "38;2;255;165;";
		default:
			return "37";
		}
	}
};
