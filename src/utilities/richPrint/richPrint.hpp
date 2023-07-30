#ifndef RICH_PRINT
#define RICH_PRINT

#include <string>

using namespace std;

namespace Print
{
	enum Color
	{
		black,
		red,
		green,
		yellow,
		blue,
		magenta,
		cyan,
		white,
		orange
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

	void hardClear();

	void error(string message);

	void success(string message);

	Color colorStatus(int value);

	string rich(string text, Color color);

	string rich(string text, Decoration decoration);

	string rich(string text, Color color, Decoration decoration);

	string getColorCode(Color color);
};

#endif
