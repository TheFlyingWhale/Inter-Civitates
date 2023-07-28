#ifndef TILE
#define TILE

#include <iostream>
#include "../character/character.hpp"

using namespace std;

string getRandomBiome();

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

	Character *getEnemy()
	{
		return enemy;
	}

	void removeEnemy()
	{
		Character *ene = enemy;
		delete enemy;
		enemy = nullptr;
	}

	void addEnemy(Character *ene)
	{
		enemy = ene;
	}

	void inspect()
	{
		cout << "Biome: " << biome << endl;
		if (enemy)
		{
			enemy->inspect();
		}
	}

	void info()
	{
		cout << "Biome: " << biome << endl;
		if (enemy)
		{
			cout << "Enemies: [1]" << endl;
		}
		else
		{
			cout << "Enemies: [0]" << endl;
		}

		cout << "Chests: [0]" << endl;
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
