#ifndef ARENA
#define ARENA

#include "../../utilities/utilities.hpp"
#include "../character/character.hpp"
#include "../classController/classController.hpp"

#include <iostream>

using namespace std;
using namespace Print;

class Arena : public ClassController
{
private:
	Character *player;
	Character *enemy;
	bool go = false;

	void inspect()
	{
		if (player)
			player->inspect();
		if (enemy)
			enemy->inspect();
	}

	void inspectPlayer()
	{
		if (player)
		{
			player->inspect();
			if (player->weapon)
			{
				player->weapon->inspect();
			}
		}
	}

	void attack()
	{
	}

	void quitBattle()
	{
		go = true;
	}

public:
	Arena() : ClassController("Arena")
	{
		createClassAction("iw", bind(&Arena::inspectPlayer, this), "Inspect yourself");
		createClassAction("i", bind(&Arena::inspect, this), "Inspect arena");
		createClassAction("q", bind(&Arena::quitBattle, this), "Exit arena");
	}

	void mountPlayer(Character *pla)
	{
		player = pla;
	}

	void mountEnemy(Character *enm)
	{
		enemy = enm;
	}

	void startBattle()
	{
		while (!go)
		{
			string input = getInput("\nYou're inside a battle - q to exit", true);
			cout << rich("Battleground", Color::red, Decoration::bold) << endl;
			triggerAction(input);
		}
	}
};

#endif
