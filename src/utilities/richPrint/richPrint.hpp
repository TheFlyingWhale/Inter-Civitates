#ifndef RICH_PRINT
#define RICH_PRINT

#include <string>

using namespace std;

namespace Print
{
	enum Color
	{
		black = 30,
		red = 31,
		green = 32,
		yellow = 33,
		blue = 34,
		magenta = 35,
		cyan = 36,
		white = 37
	};

	enum Decoration
	{
		reset = 0,
		bold = 1,
		faint = 2,
		italic = 3,
		underline = 4,
		blinking = 5,
		reversed = 7
	};

	void newLine();

	void error(string message);

	void success(string message);

	string rich(string text, Color color);

	string rich(string text, Decoration decoration);

	string rich(string text, Color color, Decoration decoration);
};

#endif
