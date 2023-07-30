#ifndef USABLE_ITEM
#define USABLE_ITEM

#include "item.hpp"
#include "../../utilities/utilities.hpp"

#include <iostream>

using namespace std;
using namespace Print;

class UsableItem;

UsableItem *createCommonWeapon();
UsableItem *createUncommonWeapon();
UsableItem *createSpecialWeapon();
UsableItem *createRareWeapon();
UsableItem *createEpicWeapon();
UsableItem *createLegendaryWeapon();
UsableItem *createMythicWeapon();
UsableItem *createRandomWeapon();

UsableItem *createCommonShield();
UsableItem *createUncommonShield();
UsableItem *createSpecialShield();
UsableItem *createRareShield();
UsableItem *createEpicShield();
UsableItem *createLegendaryShield();
UsableItem *createMythicShield();
UsableItem *createRandomShield();

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

	UsableItem(string name) : Item(name)
	{
		inspect();
	}

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

	void setName(string nam)
	{
		Item::setName(nam);
	}

	void inspect(string prefix)
	{
		cout << endl;
		cout << prefix << endl;
		cout << rich(name, Decoration::bold) << " - " << rich(rarity, color) << endl;
		cout << "Value: " << value << endl;
		cout << "Chance: " << chance << endl;
	};

	void inspect()
	{
		cout << endl;
		cout << rich(name, Decoration::bold) << " - " << rich(rarity, color) << endl;
		cout << "Value: " << value << endl;
		cout << "Chance: " << chance << endl;
	}
};

#endif
