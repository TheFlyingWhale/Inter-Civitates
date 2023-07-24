#ifndef RESOURCE
#define RESOURCE

#include <string>

using namespace std;

class Resource
{
private:
	string name;
	int value = 100;

public:
	Resource(string nam)
	{
		name = nam;
	}

	void incValue(int val)
	{
		if (value + val > 100)
		{
			value = 100;
			return;
		}
		value = value + val;
	}

	bool decValue(int val)
	{
		if (value - val <= 0)
		{
			value = 0;
			return 1;
		}
		value = value - val;
		return 0;
	}

	int getValue()
	{
		return value;
	}
};

#endif
