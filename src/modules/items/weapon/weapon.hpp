#ifndef WEAPON
#define WEAPON

#include "../usableItem.hpp"

class Weapon;

Weapon *createCommonWeapon();
Weapon *createUncommonWeapon();
Weapon *createSpecialWeapon();
Weapon *createRareWeapon();
Weapon *createEpicWeapon();
Weapon *createLegendaryWeapon();
Weapon *createMythicWeapon();
Weapon *createRandomWeapon();

class Weapon : public UsableItem
{
public:
	Weapon() : UsableItem() {}
};

#endif