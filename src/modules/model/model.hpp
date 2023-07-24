#ifndef MODEL
#define MODEL

#include <iostream>
#include <string>
#include "../tile/tile.hpp"
#include "../world/world.hpp"

using namespace std;

class Model : public World
{
protected:
	Model() {}
	~Model() {}
	static Model *instance_;

public:
	bool isGameOver = false;

	static Model &GetInstance()
	{
		if (!instance_)
		{
			instance_ = new Model();
		}
		return *instance_;
	}
};

#endif
