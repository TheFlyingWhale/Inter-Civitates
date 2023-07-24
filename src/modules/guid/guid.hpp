#ifndef GENERATE_UNIQUE_IDENTIFICATION
#define GENERATE_UNIQUE_IDENTIFICATION

#include <string>
#include <ctime>

using namespace std;

class GUID
{
private:
	GUID()
	{
		srand(time(nullptr));
	}
	~GUID() {}
	static GUID *instance_;

	int id = 0;

	string formStr(string str)
	{
		string form = str;
		for (char &c : form)
		{
			if (c == ' ')
			{
				c = '_';
			}
		}
		return form;
	}

public:
	string genUID(string prefix)
	{
		string uuid = formStr(prefix) + to_string(id) + to_string(rand() % 999);
		id++;
		return uuid;
	}

	string genUID()
	{
		string uuid = to_string(id);
		id++;
		return uuid;
	}

	static GUID &GetInstance()
	{
		if (!instance_)
		{
			instance_ = new GUID();
		}
		return *instance_;
	}
};

#endif
