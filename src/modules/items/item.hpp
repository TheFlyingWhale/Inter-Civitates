#ifndef ITEM
#define ITEM

#include "../guid/guid.hpp"
#include "../../utilities/utilities.hpp"

#include <iostream>
#include <string>

using namespace std;
using namespace Print;

class Item
{
private:
	string uuid;

protected:
	string name;

public:
	Item(string nam)
	{
		name = nam;
		GUID &guid = GUID::GetInstance();
		uuid = guid.genUID(nam);
	}

	void setName(string nam)
	{
		name = nam;
	}

	string getName()
	{
		return name;
	}

	string getUID()
	{
		return uuid;
	}

	virtual void inspect()
	{
		cout << rich("This is an unset item", Color::orange) << endl;
	}
};

#endif
