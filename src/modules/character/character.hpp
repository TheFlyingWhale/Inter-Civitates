#ifndef CHARACTER
#define CHARACTER

#include "../resource/resource.hpp"
#include "../usableItem/usableItem.hpp"
#include "../../utilities/utilities.hpp"

#include <iostream>
#include <string>

using namespace std;

class Character
{
private:
	string name;

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

	void addWeapon(UsableItem *wea)
	{
		if (weapon)
		{
			delete weapon;
		}

		weapon = wea;
	}

	void removeWeapon()
	{
		delete weapon;
		weapon = nullptr;
	}

	void addShield(UsableItem *shi)
	{
		if (shield)
		{
			delete shield;
		}

		shield = shi;
	}

	void removeShield()
	{
		delete shield;
		shield = nullptr;
	}

	void createPlayer()
	{
		name = "Player";
		weapon = createSpecialWeapon();
		// name = getInput("Provide character name", true);
	}

	void inspect()
	{
		cout << Print::rich(name, Print::Color::green) << endl;
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
