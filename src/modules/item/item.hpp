#ifndef ITEM
#define ITEM

#include "../guid/guid.hpp"

#include <string>

using namespace std;

class Item
{
protected:
	string name;
	string uuid;

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
};

#endif
