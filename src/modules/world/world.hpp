#ifndef WORLD
#define WORLD

#include "../tile/tile.hpp"
#include "../controller/controller.hpp"
#include "../items/items.hpp"
#include "../player/player.hpp"
#include "../arena/arena.hpp"

class World;

void createFirstWorld(World *wor);

class World : public Controller
{
private:
	Tile *start = nullptr;
	Tile *end = nullptr;
	Tile *stage = nullptr;
	Tile *iterator = nullptr;

	int maxWorldSize = 10;
	bool inWorld = false;
	Player &pl = Player::getInstance();

public:
	World() : Controller("World")
	{
		createAction("q", bind(&World::exitWorld, this), "Exit world");
		createAction("i", bind(&World::printStage, this), "Inspect tile");
		createAction("b", bind(&World::startBattle, this), "Start battle");
		createAction("d", bind(&World::forward, this), "Go to next tile");
		createAction("a", bind(&World::backward, this), "Go to previous tile");

		createSystemAction("EXIT_WORLD", bind(&World::exitWorld, this));
	}

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

	void startBattle()
	{
		if (stage->getEnemy() == nullptr)
		{
			cout << rich("There is no enemy to fight", Color::red) << endl;
			return;
		}
		Arena *arena = new Arena(stage);
		arena->mountEnemy(stage->getEnemy());
		arena->startBattle();
		delete arena;
	}

	void printStage()
	{
		stage->inspect();
		cout << endl;
	}

	void exitWorld()
	{
		inWorld = false;
	}

	void enterWorld()
	{
		inWorld = true;
		while (inWorld)
		{
			stage->info();
			autoTrigger("World input");
		}
	}

	void generateWorld()
	{
		destroyWorld();
		createFirstWorld(this);
	}

	void destroyWorld()
	{
		iterator = start;
		Tile *nextIterator = nullptr;
		while (iterator != nullptr)
		{
			nextIterator = iterator->getNextTile();
			delete iterator;
			iterator = nextIterator;
		}
		start = nullptr;
		end = nullptr;
	}

	~World()
	{
		destroyWorld();
	}
};

#endif