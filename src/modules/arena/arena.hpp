#ifndef ARENA
#define ARENA

#include "../../utilities/utilities.hpp"
#include "../character/character.hpp"
#include "../controller/controller.hpp"

#include <iostream>

using namespace std;
using namespace Print;

class Arena : public Controller
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
	Arena() : Controller("Arena")
	{
		createAction("q", bind(&Arena::quitBattle, this), "Exit arena");
		createAction("ie", bind(&Arena::inspectEnemy, this), "Inspect enemy");
		createAction("iw", bind(&Arena::inspectPlayer, this), "Inspect yourself");
		createAction("i", bind(&Arena::inspect, this), "Inspect arena");
		createAction("ea", bind(&Arena::enemyAttack, this), "Enemy attack");
		createAction("r", bind(&Arena::rest, this), "Rest");
		createAction("hp", bind(&Arena::heal, this), "Heal");
		createAction("a", bind(&Arena::attack, this), "Attack enemy");
		createAction("b", bind(&Arena::battle, this), "Battle");
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
