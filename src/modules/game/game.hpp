#ifndef GAME
#define GAME

#include "../controller/controller.hpp"
#include "../character/character.hpp"
#include "../world/world.hpp"
#include "../../utilities/utilities.hpp"
#include "../player/player.hpp"

using namespace Print;

class Game : public Controller
{
private:
	bool gameOver = false;
	World world = World();
	Player &player = Player::getInstance();

	void quitGame()
	{
		gameOver = true;
	}

	void resetGame()
	{
		system("clear");
		cout << rich("Game over!", Color::red) << endl;
		player.resetPlayer();
		world.generateWorld();
	}

public:
	Game() : Controller("Game")
	{
		world.generateWorld();

		createAction(
			"w", [this]()
			{ world.enterWorld(); },
			"Enter world");

		createAction("q", bind(&Game::quitGame, this), "Quit game");

		createGlobalAction(
			"ip", [this]()
			{ player.inspect(); },
			"Inspect player");

		createSystemAction("GAME_OVER", bind(&Game::resetGame, this));
		createSystemAction("QUIT_GAME", bind(&Game::quitGame, this));
	}

	void startGame()
	{
		system("clear");
		cout << "C Where You Go" << endl;
		while (!gameOver)
		{
			string input = getInput("Main menu", true);
			manualTrigger(input);
		}
	}
};

#endif
