#ifndef GAME
#define GAME

#include "../controller/controller.hpp"
#include "../character/character.hpp"
#include "../world/world.hpp"
#include "../../utilities/utilities.hpp"

class Game : public Controller
{
private:
	bool gameOver = false;
	Character player = Character();
	World world = World();

	void quitGame()
	{
		gameOver = true;
	}

public:
	Game() : Controller("Game")
	{
		player.createPlayer();
		world.generateDefaultWorld();

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
		while (!gameOver)
		{
			string input = getInput("Please provide some input - h for help", true);
			triggerAction(input);
		}
	}
};

#endif
