#ifndef POTION
#define POTION

#include "../../character/character.hpp"
#include "../../../utilities/utilities.hpp"
#include "../../resource/resource.hpp"

using namespace Print;

class Potion : public Item
{
protected:
	Resource amount = Resource("Amount");

	Character *test;

	void printEmptyWarning()
	{
		cout << rich(getName() + " is empty and cant be used", Color::red) << endl;
	}

public:
	Potion(string name) : Item(name) {}

	void use(Character *character) {}

	void replenish()
	{
		amount.setValue(100);
	}

	void inspect()
	{
		cout << getName() << ": " << amount.getValue() << endl;
	}
};

class HealthPotion : public Potion
{
public:
	HealthPotion() : Potion("Health Potion") {}

	void use(Character *character)
	{
		if (amount.getValue() == 0)
		{
			printEmptyWarning();
			return;
		}
		character->health.incValue(25);
		amount.decValue(25);
	}

	void inspect()
	{
		cout << getName() << ": " << amount.getValue() << endl;
	}
};

class EnergyPotion : public Potion
{
public:
	EnergyPotion() : Potion("Energy potion") {}

	void use(Character *character)
	{
		if (amount.getValue() == 0)
		{
			printEmptyWarning();
			return;
		}
		character->energy.incValue(25);
		amount.decValue(25);
	}
};

#endif
