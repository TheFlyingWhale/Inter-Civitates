#include "initializer.hpp"
#include "modules/modules.hpp"
#include "utilities/utilities.hpp"
#include "errors/errors.hpp"

#include <curses.h>

#include <iostream>
using namespace std;

Model &mm = Model::GetInstance();
Controller &co = Controller::GetInstance();

void init()
{
	mm.generateDefaultWorld();
	connectEssentials();

	// Character player = Character("Player");
	// player.addWeapon(new UsableItem("Cool sword", 50, 25, 100));
	// player.addShield(new UsableItem("Super shield", 15, 50, 100));
	// player.inspect();

	// Chest che = Chest("Super chest");
	// che.addItem(new UsableItem("Dark sword", 20, 25, 50));
	// che.addItem(new UsableItem("Light sword", 10, 15, 25));
	// che.addItem(new UsableItem("King shield", 10, 15, 25));

	// che.inspect();
}

void startBattle()
{
	Character *player = new Character("player");
	player->addWeapon(new UsableItem("Sword", 100, 100, 100));

	Character *enemy = new Character("enemy");
	Arena ar = Arena();
	ar.mountPlayer(player);
	ar.mountEnemy(enemy);
	ar.startBattle();

	delete player;
	delete enemy;
}

void connectEssentials()
{
	createAction("q", quitGame, "Quit the game");
	createAction("d", goForwards, "Go forwards");
	createAction("s", printStage, "Take a look at your surroundings");
	createAction("a", goBackwards, "Go backwards");
	createAction("b", startBattle, "Test battleground");
}

void quitGame()
{
	mm.isGameOver = true;
}

void traverseForward()
{
	mm.traverseForward();
}

void goForwards()
{
	mm.forward();
	co.triggerAction("s");
}

void goBackwards()
{
	mm.backward();
	co.triggerAction("s");
}

void printStage()
{
	mm.printStage();
}
