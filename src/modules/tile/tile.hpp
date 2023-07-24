#ifndef TILE
#define TILE

#include <iostream>
#include "../character/character.hpp"

using namespace std;

class Tile
{
private:
	string biome = "No biome set";
	Character *enemy = nullptr;
	Tile *next = nullptr;
	Tile *prev = nullptr;

public:
	void setBiome(string bio)
	{
		biome = bio;
	}

	string getBiome()
	{
		return biome;
	}

	void addEnemy(Character *ene)
	{
		enemy = ene;
	}

	void inspect()
	{
		cout << "Tile: " << biome << endl;
		if (enemy)
		{
			enemy->inspect();
		}
	}

	void setNextTile(Tile *nex)
	{
		next = nex;
	}

	Tile *getNextTile()
	{
		return next;
	}

	void setPrevTile(Tile *pre)
	{
		prev = pre;
	}

	Tile *getPrevTile()
	{
		return prev;
	}

	~Tile()
	{
		delete enemy;
	}
};

#endif
