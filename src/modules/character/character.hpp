#ifndef CHARACTER
#define CHARACTER

#include "../resource/resource.hpp"
#include "../items/items.hpp"
#include "../../utilities/utilities.hpp"

#include <iostream>
#include <string>

using namespace std;
using namespace Print;

class Character;

Character *createRandomEnemy();
Character *createCommonEnemy();
Character *createUncommonEnemy();
Character *createSpecialEnemy();
Character *createRareEnemy();
Character *createEpicEnemy();
Character *createLegendaryEnemy();
Character *createMythicEnemy();

class Character
{
private:
	string name;
	Color color = Color::white;

public:
	Character() {}

	Character(string nam)
	{
		name = nam;
	}

	Resource health = Resource("Health");
	Resource energy = Resource("Energy");
	UsableItem *weapon = nullptr;
	UsableItem *shield = nullptr;

	void setName(string nam)
	{
		name = nam;
	}

	void setColor(Color col)
	{
		color = col;
	}

	int attack()
	{
		if (energy.getValue() < 10)
		{
			cout << "Not enough energy" << endl;
			return 0;
		}
		energy.decValue(10);
		return weapon->calculateHit();
	}

	void incHealth(int amo)
	{
		health.incValue(amo);
	}

	void decHealth(int amo)
	{
		if (health.decValue(amo))
		{
			cout << name << " died" << endl;
		}
	}

	void incEnergy(int amo)
	{
		energy.incValue(amo);
	}

	void decEnergy(int amo)
	{
		energy.decValue(amo);
	}

	void mountWeapon(UsableItem *wea)
	{
		if (weapon)
		{
			delete weapon;
		}

		weapon = wea;
	}

	void unmountWeapon()
	{
		delete weapon;
		weapon = nullptr;
	}

	void mountShield(UsableItem *shi)
	{
		if (shield)
		{
			delete shield;
		}

		shield = shi;
	}

	void unmountShield()
	{
		delete shield;
		shield = nullptr;
	}

	void createPlayer()
	{
		name = "Player";
		color = Color::green;
		weapon = createSpecialWeapon();
		// name = getInput("Provide character name", true);
	}

	void inspect()
	{
		cout << Print::rich(name, color, Decoration::bold) << endl;
		cout << "Health: " << health.getValue() << endl;
		cout << "Energy: " << energy.getValue() << endl;
		if (weapon)
			weapon->inspect();
		if (shield)
			shield->inspect();
	}

	~Character()
	{
		delete weapon;
		delete shield;
	}
};

#endif
