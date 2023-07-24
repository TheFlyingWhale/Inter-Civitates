#ifndef WORLD
#define WORLD

#include "../tile/tile.hpp"

class World
{
private:
	Tile *start = nullptr;
	Tile *end = nullptr;
	Tile *stage = nullptr;
	Tile *iterator = nullptr;

	int maxWorldSize = 10;

public:
	void pushBack(Tile *til)
	{
		if (start == nullptr)
		{
			start = til;
			stage = til;
		}
		if (end == nullptr)
		{
			end = til;
			return;
		}
		til->setPrevTile(end);
		end->setNextTile(til);
		end = til;
	}

	Tile *forward()
	{
		if (stage->getNextTile() != nullptr)
		{
			stage = stage->getNextTile();
			return stage;
		}
		cout << "You've reached the end of the world" << endl;
		return stage;
	}

	Tile *backward()
	{
		if (stage->getPrevTile() != nullptr)
		{
			stage = stage->getPrevTile();
			return stage;
		}
		cout << "You've reached the start of the world" << endl;
		return stage;
	}

	void traverseForward()
	{
		iterator = start;
		while (iterator != nullptr)
		{
			cout << iterator->getBiome() << endl;
			iterator = iterator->getNextTile();
		}
	}

	void traverseBackwards()
	{
		iterator = end;
		while (iterator != nullptr)
		{
			cout << iterator->getBiome() << endl;
			iterator = iterator->getPrevTile();
		}
	}

	void printStage()
	{
		stage->inspect();
	}

	void generateDefaultWorld()
	{
		for (int i = 0; i < maxWorldSize; i++)
		{
			Tile *newTile = new Tile();
			newTile->setBiome("biome " + to_string(i));
			this->pushBack(newTile);
		}
	}

	void destroyWorld()
	{
		iterator = start;
		Tile *nextIterator = nullptr;
		while (iterator != nullptr)
		{
			nextIterator = iterator->getNextTile();
			cout << "Deleting " << iterator->getBiome() << endl;
			delete iterator;
			iterator = nextIterator;
		}
	}

	~World()
	{
		destroyWorld();
	}
};

#endif