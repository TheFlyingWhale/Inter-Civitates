#include "character.hpp"
#include "../items/items.hpp"
#include "../items/weapon/weapon.hpp"

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
	ene->mountShield(createRandomShield());
	return ene;
}

Character *createCommonEnemy()
{
	Character *ene = new Character(generateRandomName());
	ene->mountWeapon(createCommonWeapon());
	ene->mountShield(createCommonShield());
	return ene;
}

Character *createUncommonEnemy()
{
	Character *ene = new Character(generateRandomName());
	ene->mountWeapon(createUncommonWeapon());
	ene->mountShield(createUncommonShield());
	return ene;
}

Character *createSpecialEnemy()
{
	Character *ene = new Character(generateRandomName());
	ene->mountWeapon(createSpecialWeapon());
	ene->mountShield(createSpecialShield());
	return ene;
}

Character *createRareEnemy()
{
	Character *ene = new Character(generateRandomName());
	ene->mountWeapon(createRareWeapon());
	ene->mountShield(createRareShield());
	return ene;
}

Character *createEpicEnemy()
{
	Character *ene = new Character(generateRandomName());
	ene->mountWeapon(createEpicWeapon());
	ene->mountShield(createEpicShield());
	return ene;
}

Character *createLegendaryEnemy()
{
	Character *ene = new Character(generateRandomName());
	ene->mountWeapon(createLegendaryWeapon());
	ene->mountShield(createLegendaryShield());
	return ene;
}

Character *createMythicEnemy()
{
	Character *ene = new Character(generateRandomName());
	ene->mountWeapon(createMythicWeapon());
	ene->mountShield(createMythicShield());
	return ene;
}