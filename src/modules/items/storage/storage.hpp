#ifndef STORAGE
#define STORAGE

#include "../../../utilities/utilities.hpp"
#include "../item.hpp"
#include "../usableItem.hpp"

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

	void addItem(Item *ite)
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
