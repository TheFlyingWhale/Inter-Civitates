#ifndef USABLE_ITEM
#define USABLE_ITEM

#include "item.hpp"
#include "../../utilities/utilities.hpp"

#include <iostream>

using namespace std;
using namespace Print;

class UsableItem;

class UsableItem : public Item
{
private:
	int value;
	int chance;
	Color color;
	string rarity;

public:
	UsableItem(string name, int val, int cha) : Item(name)
	{
		value = val;
		chance = cha;
	}

	UsableItem(string name) : Item(name) {}

	UsableItem() : Item("No name") {}

	int calculateValue()
	{
		int ran = randomInt();
		if (ran < chance)
		{
			// cout << name << " hit" << endl;
			// durability = durability - 10;
			return value;
		}
		// cout << name << " missed" << endl;
		return 0;
	}

	void setColor(Color col)
	{
		color = col;
	}

	void setValue(int val)
	{
		value = val;
	}

	void setChance(int cha)
	{
		chance = cha;
	}

	void setRarity(string rar)
	{
		rarity = rar;
	}

	void inspect(string prefix)
	{
		cout << prefix << endl;
		cout << rich(name, Decoration::bold) << " - " << rich(rarity, color) << endl;
		cout << "Value: " << value << endl;
		cout << "Chance: " << chance << endl;
	};

	void inspect()
	{
		cout << rich(name, Decoration::bold) << " - " << rich(rarity, color) << endl;
		cout << "Value: " << value << endl;
		cout << "Chance: " << chance << endl;
	}
};

#endif
