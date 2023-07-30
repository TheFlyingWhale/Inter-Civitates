#include "modules/modules.hpp"
#include "utilities/utilities.hpp"
#include "errors/errors.hpp"

#include <iostream>
#include <string>
#include <ncurses.h>

using namespace std;

int main()
{
	Game game = Game();
	try
	{
		game.startGame();
	}
	catch (const exception &ex)
	{
		handleEx(ex);
	}
}