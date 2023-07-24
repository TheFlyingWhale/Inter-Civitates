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
	int durability = 100;
	Color color;
	string rarity;

	void generateRandomItem()
	{
		int randBase = randomInt(1000 + 1);
		// Common
		if (randBase > 500)
		{
			color = Color::white;
			rarity = "Common";
			value = 10;
			chance = 25;
			return;
		}

		// Uncommon
		if (randBase > 250)
		{
			color = Color::green;
			rarity = "Uncommon";
			value = 20;
			chance = 20;
			return;
		}

		// Special
		if (randBase > 125)
		{
			color = Color::cyan;
			rarity = "Special";
			value = 30;
			chance = 30;
			return;
		}

		// Rare
		if (randBase > 50)
		{
			color = Color::blue;
			rarity = "Rare";
			value = 40;
			chance = 40;
		}

		// Epic
		if (randBase > 25)
		{
			color = Color::magenta;
			rarity = "Epic";
			value = 50;
			chance = 50;
			return;
		}

		// Legendary
		if (randBase > 5)
		{
			color = Color::yellow;
			rarity = "Legendary";
			value = 60;
			chance = 60;
			return;
		}

		// Mythical
		color = Color::orange;
		rarity = "Mythical";
		value = 70;
		chance = 70;
	}

public:
	UsableItem(string name, int val, int cha) : Item(name)
	{
		value = val;
		chance = cha;
	}

	UsableItem(string name) : Item(name)
	{
		generateRandomItem();
		inspect();
	}

	int calculateHit()
	{
		if (durability == 0)
		{
			cout << name << " is broken" << endl;
			return 0;
		}
		int ran = randomInt();
		if (ran < chance)
		{
			cout << name << " hit" << endl;
			durability = durability - 10;
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
		cout << rich(name, Decoration::bold) << " - " << rich(rarity, color) << endl;
		cout << "Value: " << value << endl;
		cout << "Chance: " << chance << endl;
		cout << "Durability: " << durability << endl;
	};

	void inspect()
	{
		cout << endl;
		cout << rich(name, Decoration::bold) << " - " << rich(rarity, color) << endl;
		cout << "Value: " << value << endl;
		cout << "Chance: " << chance << endl;
		cout << "Durability: " << durability << endl;
	}
};

#endif
