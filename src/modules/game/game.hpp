#ifndef GAME
#define GAME

#include "../controller/controller.hpp"
#include "../character/character.hpp"
#include "../world/world.hpp"
#include "../../utilities/utilities.hpp"
#include "../player/player.hpp"

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

public:
	Game() : Controller("Game")
	{
		player.createPlayer();
		world.generateWorld();

		createAction(
			"w", [this]()
			{ world.enterWorld(); },
			"Enter world");

		createGlobalAction(
			"ip", [this]()
			{ player.inspect(); },
			"Inspect player");

		createAction("q", bind(&Game::quitGame, this), "Quit game");
	}

	void startGame()
	{
		system("clear");
		cout << "C Where You Go" << endl;
		while (!gameOver)
		{
			string input = getInput("Game input - h for help", true);
			manTrigger(input);
		}
	}
};

#endif
