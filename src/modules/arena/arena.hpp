#ifndef ARENA
#define ARENA

#include "../../utilities/utilities.hpp"
#include "../character/character.hpp"
#include "../controller/controller.hpp"
#include "../player/player.hpp"
#include "../tile/tile.hpp"

#include <iostream>

using namespace std;
using namespace Print;

class Arena : public Controller
{
private:
	Player &player = Player::getInstance();
	Tile *stage = nullptr;
	Character *enemy;
	bool go = false;
	bool playerTurn = true;

	void inspect()
	{
		player.inspect();
		if (enemy)
		{
			cout << endl;
			enemy->inspect();
		}
	}

	void inspectPlayer()
	{
		player.inspect();
		if (player.weapon)
		{
			player.weapon->inspect();
		}
	}

	void inspectEnemy()
	{
		if (enemy)
		{
			enemy->inspect("Enemy");
			if (enemy->weapon)
			{
				enemy->weapon->inspect();
			}
		}
	}

	void rest()
	{
		player.incEnergy(25);
		evaluateEnemyAction();
		inspect();
	}

	void heal()
	{
		player.incHealth(10);
		evaluateEnemyAction();
		inspect();
	}

	void playerAttack()
	{
		if (!player.weapon)
		{
			cout << "player dont have a weapon" << endl;
			return;
		}

		if (!enemy)
		{
			cout << "there is no enemy" << endl;
			return;
		}

		int hitValue = player.attack();
		cout << "Player hit value: " << hitValue << endl;
		int blockValue = enemy->block();
		cout << "Enemy block value: " << blockValue << endl;
		double blockedValue = hitValue * (1 - blockValue / 100.0);
		cout << "Successful hit value: " << blockedValue << endl;
		enemy->decHealth(blockedValue);
		cout << endl;
	}

	void enemyAttack()
	{
		if (!enemy)
		{
			cout << "there is no enemy" << endl;
			return;
		}

		if (!enemy->weapon)
		{
			cout << "enemy dont have a weapon" << endl;
			return;
		}

		int hitValue = enemy->attack();
		cout << "Enemy hit value: " << hitValue << endl;
		int blockValue = player.block();
		cout << "Player block value: " << blockValue << endl;
		double blockedValue = hitValue * (1 - blockValue / 100.0);
		cout << "Successful hit value: " << blockedValue << endl;
		player.decHealth(blockedValue);
		cout << endl;
	}

	void evaluateEnemyAction()
	{
		if (enemy->health.getValue() <= 0)
		{
			cout << "Enemy is dead" << endl;
			return;
		}

		if (enemy->energy.getValue() < randomInt(25))
		{
			enemy->incEnergy(25);
			cout << "Enemy rested" << endl;
			return;
		}

		if (enemy->health.getValue() < randomInt(50))
		{
			enemy->incHealth(10);
			cout << "Enemy healed" << endl;
			return;
		}

		cout << "Enemy attacked" << endl;
		enemyAttack();
	}

	void battle()
	{
		playerAttack();
		evaluateEnemyAction();
		inspect();
	}

	void turnHandler()
	{
		if (playerTurn)
		{
			playerTurn = false;
			evaluateEnemyAction();
		}
		else
		{
			playerTurn = true;
		}
	}

	void killPlayer()
	{
		player.health.setValue(0);
	}

	void killEnemy()
	{
		enemy->health.setValue(0);
	}

	void quitBattle()
	{
		go = true;
	}

public:
	Arena(Tile *stage) : Controller("Arena")
	{
		this->stage = stage;
		// createAction("ie", bind(&Arena::inspectEnemy, this), "Inspect enemy");
		// createAction("iw", bind(&Arena::inspectPlayer, this), "Inspect yourself");
		// createAction("kp", bind(&Arena::killPlayer, this), "Kill player");
		// createAction("ke", bind(&Arena::killEnemy, this), "Kill enemy");
		// createAction("ea", bind(&Arena::enemyAttack, this), "Enemy attack");
		createAction("q", bind(&Arena::quitBattle, this), "Exit arena");
		createAction("i", bind(&Arena::inspect, this), "Inspect arena");
		createAction("a", bind(&Arena::battle, this), "Attack");
		createAction("r", bind(&Arena::rest, this), "Rest");
		createAction("h", bind(&Arena::heal, this), "Heal");
	}

	void mountEnemy(Character *enm)
	{
		enemy = enm;
	}

	void startBattle()
	{
		inspect();
		while (!go)
		{
			if (enemy->health.getValue() <= 0)
			{
				system("clear");
				cout << rich("You won!", Color::green, Decoration::bold) << endl;
				stage->removeEnemy();
				quitBattle();
				break;
			}
			if (player.health.getValue() <= 0)
			{
				manualTrigger("EXIT_WORLD");
				manualTrigger("GAME_OVER");
				break;
			}
			// cout << rich("Battleground", Color::red, Decoration::bold) << endl;
			string input = getInput("You're inside a battle", true);
			manualTrigger(input);
		}
		player.health.setValue(100);
		player.energy.setValue(100);
	}
};

#endif
