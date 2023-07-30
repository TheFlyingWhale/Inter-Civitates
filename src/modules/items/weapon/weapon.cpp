#include "weapon.hpp"
#include "../../../utilities/utilities.hpp"

using namespace Print;

UsableItem *createCommonWeapon()
{
	UsableItem *ite = new UsableItem();
	ite->setName("Common weapon");
	ite->setRarity("Common");
	ite->setValue(10);
	ite->setChance(65);
	ite->setColor(Color::white);

	return ite;
}

UsableItem *createUncommonWeapon()
{
	UsableItem *ite = new UsableItem();
	ite->setName("Uncommon weapon");
	ite->setRarity("Uncommon");
	ite->setValue(20);
	ite->setChance(70);
	ite->setColor(Color::green);

	return ite;
}

UsableItem *createSpecialWeapon()
{
	UsableItem *ite = new UsableItem();
	ite->setName("Special weapon");
	ite->setRarity("Special");
	ite->setValue(30);
	ite->setChance(75);
	ite->setColor(Color::cyan);

	return ite;
}

UsableItem *createRareWeapon()
{
	UsableItem *ite = new UsableItem();
	ite->setName("Rare weapon");
	ite->setRarity("Rare");
	ite->setValue(40);
	ite->setChance(80);
	ite->setColor(Color::blue);

	return ite;
}

UsableItem *createEpicWeapon()
{
	UsableItem *ite = new UsableItem();
	ite->setName("Epic weapon");
	ite->setRarity("Epic");
	ite->setValue(50);
	ite->setChance(85);
	ite->setColor(Color::magenta);

	return ite;
}

UsableItem *createLegendaryWeapon()
{
	UsableItem *ite = new UsableItem();
	ite->setName("Legendary weapon");
	ite->setRarity("Legendary");
	ite->setValue(60);
	ite->setChance(90);
	ite->setColor(Color::yellow);

	return ite;
}

UsableItem *createMythicWeapon()
{
	UsableItem *ite = new UsableItem();
	ite->setName("Mythic weapon");
	ite->setRarity("Mythic");
	ite->setValue(70);
	ite->setChance(95);
	ite->setColor(Color::orange);

	return ite;
}

UsableItem *createRandomWeapon()
{
	int randBase = randomInt(1000 + 1);
	if (randBase > 500)
	{
		return createCommonWeapon();
	}
	if (randBase > 250)
	{
		return createUncommonWeapon();
	}
	if (randBase > 125)
	{
		return createSpecialWeapon();
	}
	if (randBase > 50)
	{
		return createRareWeapon();
	}
	if (randBase > 25)
	{
		return createEpicWeapon();
	}
	if (randBase > 5)
	{
		return createLegendaryWeapon();
	}
	return createMythicWeapon();
}