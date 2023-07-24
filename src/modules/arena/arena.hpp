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

	void inspectEnemy()
	{
		if (enemy)
		{
			enemy->inspect();
			if (enemy->weapon)
			{
				enemy->weapon->inspect();
			}
		}
	}

	void rest()
	{
		if (player)
		{
			player->incEnergy(10);
		}
	}

	void battle()
	{
		attack();
		enemyAttack();
	}

	void heal()
	{
		if (!player)
		{
			cout << "there is no player" << endl;
			return;
		}
		player->incHealth(10);
	}

	void attack()
	{
		if (!player)
		{
			cout << "there is no player" << endl;
			return;
		}
		if (!player->weapon)
		{
			cout << "player dont have a weapon" << endl;
			return;
		}
		if (!enemy)
		{
			cout << "there is no enemy";
			return;
		}
		enemy->decHealth(player->attack());
	}

	void enemyAttack()
	{
		if (!enemy)
		{
			cout << "there is no enemy";
			return;
		}
		if (!enemy->weapon)
		{
			cout << "enemy dont have a weapon" << endl;
			return;
		}
		if (!player)
		{
			cout << "there is no player" << endl;
			return;
		}
		player->decHealth(enemy->attack());
	}

	void quitBattle()
	{
		go = true;
	}

public:
	Arena() : ClassController("Arena")
	{
		createClassAction("q", bind(&Arena::quitBattle, this), "Exit arena");
		createClassAction("ie", bind(&Arena::inspectEnemy, this), "Inspect enemy");
		createClassAction("iw", bind(&Arena::inspectPlayer, this), "Inspect yourself");
		createClassAction("i", bind(&Arena::inspect, this), "Inspect arena");
		createClassAction("ea", bind(&Arena::enemyAttack, this), "Enemy attack");
		createClassAction("r", bind(&Arena::rest, this), "Rest");
		createClassAction("hp", bind(&Arena::heal, this), "Heal");
		createClassAction("a", bind(&Arena::attack, this), "Attack enemy");
		createClassAction("b", bind(&Arena::battle, this), "Battle");
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
			if (enemy->health.getValue() <= 0)
			{
				cout << "You won!" << endl;
				return;
			}
			string input = getInput("\nYou're inside a battle - q to exit", true);
			cout << rich("Battleground", Color::red, Decoration::bold) << endl;
			triggerAction(input);
			inspect();
		}
	}
};

#endif
