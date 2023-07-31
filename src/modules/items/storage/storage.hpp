#ifndef STORAGE
#define STORAGE

#include "../../../utilities/utilities.hpp"
#include "../item.hpp"
#include "../usableItem.hpp"
#include "../weapon/weapon.hpp"
#include "../shield/shield.hpp"

#include <vector>
#include <iostream>

using namespace std;
using namespace Print;

class Potion;

class Storage : public Item
{
private:
	int maxSize = 10;
	int occupiedSlots = 0;
	vector<Item *> items;

public:
	Storage(string name) : Item(name) {}

	void add(Item *ite)
	{
		if (occupiedSlots + 1 > maxSize)
		{
			cout << rich(getName() + " is full", Color::red) << endl;
			return;
		}
		items.push_back(ite);
		occupiedSlots++;
	}

	void inspect()
	{
		if (items.size() == 0)
		{
			cout << "Storage is empty" << endl;
			return;
		}
		cout << getName() + ":" << endl;
		for (int i = 0; i < items.size(); i++)
		{
			cout << "Item " << i << ":" << endl;
			items.at(i)->inspect();
			cout << endl;
		}
	}

	template <typename T>
	T *getItem();

	template <>
	Shield *getItem<Shield>()
	{
		return new Shield();
	}

	// THIS NEEDS TO BE EXPLAINED
	template <>
	Weapon *getItem<Weapon>()
	{
		vector<Weapon *> avaItems;
		// Filter out weapons from the items vector into avaItems
		for (vector<Item *>::iterator it = items.begin(); it != items.end();)
		{
			if (dynamic_cast<Weapon *>(*it))
			{
				avaItems.push_back(dynamic_cast<Weapon *>(*it));
				it = items.erase(it);
				continue;
			}
			it++;
		}

		cout << "Selectable items:" << endl;
		for (int i = 0; i < avaItems.size(); i++)
		{
			cout << "Item " << i << ":" << endl;
			avaItems.at(i)->inspect();
			cout << endl;
		}

		int index = getPositiveInt("What item do you want?");
		Weapon *selected = avaItems.at(index);

		// Remove selected weapon from avaItems
		avaItems.erase(avaItems.begin() + index);

		// Add Weapons back to the items vector
		for (Item *item : avaItems)
		{
			items.push_back(item);
		}

		return selected;
	}

	// template <typename T>
	// void *getItem();

	// template <>
	// UsableItem *getItem<Weapon>()
	// {
	// 	// vector<Weapon *> availableItems;
	// 	Weapon *temp = createCommonWeapon();
	// 	return temp;
	// }

	template <typename T>
	void inspectOnlyCertainType(T *item)
	{
		if (dynamic_cast<Potion *>(item))
		{
			cout << "A potion was provided" << endl;
			return;
		}
		if (dynamic_cast<UsableItem *>(item))
		{
			cout << "A usable item was provided" << endl;
			return;
		}
		cout << "Unkown item was provided" << endl;
	}

	bool empty()
	{
		return occupiedSlots == 0;
	}

	void trashItem(int index)
	{
		cout << "Are you sure you want to delete:" << endl;
		items.at(index)->inspect();
	}

	void clearStorage()
	{
		for (Item *item : items)
		{
			delete item;
		}
		items.clear();
		occupiedSlots = 0;
	}

	~Storage()
	{
		clearStorage();
	}
};

#endif
