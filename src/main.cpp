#include "modules/modules.hpp"
#include "utilities/utilities.hpp"
#include "errors/errors.hpp"

#include <iostream>
#include <string>

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