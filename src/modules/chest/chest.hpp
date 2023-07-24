#ifndef CHEST
#define CHEST

#include "../item/item.hpp"
#include "../usableItem/usableItem.hpp"

#include <vector>
#include <iostream>

using namespace std;

class Chest : public Item
{
private:
	vector<UsableItem *> items;

public:
	Chest(string name) : Item(name) {}

	void addItem(UsableItem *item)
	{
		items.push_back(item);
	}

	// UsableItem *removeItem(string uid)
	// {
	// }

	void inspect()
	{
		cout << name << ":" << endl;
		for (int i = 0; i < items.size(); i++)
		{
			items.at(i)->inspect("Item " + to_string(i));
		}
	}

	~Chest()
	{
		for (const auto &item : items)
		{
			delete item;
		}
	}
};

#endif
