#ifndef STORAGE
#define STORAGE

#include "../../../utilities/utilities.hpp"
#include "../item.hpp"

#include <vector>

using namespace std;
using namespace Print;

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
		for (Item *item : items)
		{
			item->inspect();
			cout << endl;
		}
	}

	bool empty()
	{
		return occupiedSlots == 0;
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
