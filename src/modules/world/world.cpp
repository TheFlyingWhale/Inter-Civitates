#include "world.hpp"
#include "../tile/tile.hpp"
#include "../character/character.hpp"
#include "../tile/tile.hpp"

void createFirstWorld(World *wor)
{
	Tile *tile1 = new Tile();
	tile1->setBiome(getRandomBiome());
	tile1->addEnemy(createCommonEnemy());
	wor->pushBack(tile1);

	Tile *tile2 = new Tile();
	tile2->setBiome(getRandomBiome());
	tile2->addEnemy(createUncommonEnemy());
	wor->pushBack(tile2);

	Tile *tile3 = new Tile();
	tile3->setBiome(getRandomBiome());
	tile3->addEnemy(createSpecialEnemy());
	wor->pushBack(tile3);

	Tile *tile4 = new Tile();
	tile4->setBiome(getRandomBiome());
	tile4->addEnemy(createRareEnemy());
	wor->pushBack(tile4);

	Tile *tile5 = new Tile();
	tile5->setBiome(getRandomBiome());
	tile5->addEnemy(createEpicEnemy());
	wor->pushBack(tile5);

	Tile *tile6 = new Tile();
	tile6->setBiome(getRandomBiome());
	tile6->addEnemy(createLegendaryEnemy());
	wor->pushBack(tile6);

	Tile *tile7 = new Tile();
	tile7->setBiome(getRandomBiome());
	tile7->addEnemy(createMythicEnemy());
	wor->pushBack(tile7);
}