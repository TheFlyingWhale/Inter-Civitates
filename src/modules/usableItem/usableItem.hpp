#ifndef USABLE_ITEM
#define USABLE_ITEM

#include "../item/item.hpp"
#include "../../utilities/utilities.hpp"

#include <iostream>

using namespace std;
using namespace Print;

class UsableItem : public Item
{
private:
	int value;
	int chance;
	int durability;

public:
	UsableItem(string name, int val, int cha, int dur) : Item(name)
	{
		value = val;
		chance = cha;
		durability = dur;
	}

	int calculateHit()
	{
		if (durability == 0)
		{
			cout << name << " is broken" << endl;
			return 0;
		}
		int ran = rand() % 100;
		if (ran < chance)
		{
			return value;
		}
		cout << name << " missed" << endl;
		return 0;
	}

	void setDurability(int dur)
	{
		if (dur > 100)
		{
			durability = 100;
			return;
		}

		if (dur < 0)
		{
			durability = 0;
			return;
		}

		durability = dur;
	}

	void inspect(string prefix)
	{
		cout << endl;
		cout << prefix << endl;
		cout << name << endl;
		cout << "Value: " << value << endl;
		cout << "Chance: " << chance << endl;
		cout << "Durability: " << durability << endl;
	};

	void inspect()
	{
		cout << endl;
		cout << rich(name, Color::cyan) << endl;
		cout << "Value: " << value << endl;
		cout << "Chance: " << chance << endl;
		cout << "Durability: " << durability << endl;
	}
};

#endif
