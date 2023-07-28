#include "character.hpp"

#include <string>

using namespace std;
using namespace Print;

string enemyTypes[] = {
	"Bear",
	"Boar",
	"Skeleton",
	"Elf",
	"Ogre",
	"Vampire",
	"Angel",
	"Demon",
	"Ghost",
	"Spirit",
	"Harpy",
	"Gargoyle",
	"Goblin",
	"Djinni",
	"Dragonkin",
	"Troll",
	"Imp",
	"Wraith",
	"Minotaur",
	"Griffin",
	"Werewolf",
	"Banshee",
	"Cyclops",
	"Satyr",
	"Centaur",
	"Kraken",
	"Phoenix",
	"Gremlin",
	"Golem",
	"Siren",
	"Chimera",
	"Specter",
	"Nymph",
	"Harbinger",
	"Wendigo",
	"Poltergeist",
	"Hydra",
	"Incubus",
	"Succubus",
	"Cerberus",
	"Slime",
	"Wight",
	"Lich",
	"Kitsune",
	"Hellhound",
	"Revenant",
	"Bansidhe",
	"Dullahan",
	"Faun"};

string generateRandomName()
{
	int index = randomInt(sizeof(enemyTypes) / sizeof(string));
	return enemyTypes[index];
}

Character *createRandomEnemy()
{
	Character *ene = new Character(generateRandomName());
	ene->mountWeapon(createRandomWeapon());
	return ene;
}

Character *createCommonEnemy()
{
	Character *ene = new Character(generateRandomName());
	ene->setColor(Color::white);
	ene->mountWeapon(createCommonWeapon());
	return ene;
}

Character *createUncommonEnemy()
{
	Character *ene = new Character(generateRandomName());
	ene->setColor(Color::green);
	ene->mountWeapon(createUncommonWeapon());
	return ene;
}

Character *createSpecialEnemy()
{
	Character *ene = new Character(generateRandomName());
	ene->setColor(Color::cyan);
	ene->mountWeapon(createSpecialWeapon());
	return ene;
}

Character *createRareEnemy()
{
	Character *ene = new Character(generateRandomName());
	ene->setColor(Color::blue);
	ene->mountWeapon(createRareWeapon());
	return ene;
}

Character *createEpicEnemy()
{
	Character *ene = new Character(generateRandomName());
	ene->setColor(Color::magenta);
	ene->mountWeapon(createEpicWeapon());
	return ene;
}

Character *createLegendaryEnemy()
{
	Character *ene = new Character(generateRandomName());
	ene->setColor(Color::yellow);
	ene->mountWeapon(createLegendaryWeapon());
	return ene;
}

Character *createMythicEnemy()
{
	Character *ene = new Character(generateRandomName());
	ene->setColor(Color::orange);
	ene->mountWeapon(createMythicWeapon());
	return ene;
}