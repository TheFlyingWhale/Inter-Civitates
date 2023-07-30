#include "shield.hpp"
#include "../../../utilities/utilities.hpp"

using namespace Print;

UsableItem *createCommonShield()
{
	UsableItem *ite = new UsableItem();
	ite->setName("Common shield");
	ite->setRarity("Common");
	ite->setValue(10);
	ite->setChance(65);
	ite->setColor(Color::white);

	return ite;
}

UsableItem *createUncommonShield()
{
	UsableItem *ite = new UsableItem();
	ite->setName("Uncommon shield");
	ite->setRarity("Uncommon");
	ite->setValue(20);
	ite->setChance(70);
	ite->setColor(Color::green);

	return ite;
}

UsableItem *createSpecialShield()
{
	UsableItem *ite = new UsableItem();
	ite->setName("Special shield");
	ite->setRarity("Special");
	ite->setValue(30);
	ite->setChance(75);
	ite->setColor(Color::cyan);

	return ite;
}

UsableItem *createRareShield()
{
	UsableItem *ite = new UsableItem();
	ite->setName("Rare shield");
	ite->setRarity("Rare");
	ite->setValue(40);
	ite->setChance(80);
	ite->setColor(Color::blue);

	return ite;
}

UsableItem *createEpicShield()
{
	UsableItem *ite = new UsableItem();
	ite->setName("Epic shield");
	ite->setRarity("Epic");
	ite->setValue(50);
	ite->setChance(85);
	ite->setColor(Color::magenta);

	return ite;
}

UsableItem *createLegendaryShield()
{
	UsableItem *ite = new UsableItem();
	ite->setName("Legendary shield");
	ite->setRarity("Legendary");
	ite->setValue(60);
	ite->setChance(90);
	ite->setColor(Color::yellow);

	return ite;
}

UsableItem *createMythicShield()
{
	UsableItem *ite = new UsableItem();
	ite->setName("Mythic shield");
	ite->setRarity("Mythic");
	ite->setValue(70);
	ite->setChance(95);
	ite->setColor(Color::orange);

	return ite;
}

UsableItem *createRandomShield()
{
	int randBase = randomInt(1000 + 1);
	if (randBase > 500)
	{
		return createCommonShield();
	}
	if (randBase > 250)
	{
		return createUncommonShield();
	}
	if (randBase > 125)
	{
		return createSpecialShield();
	}
	if (randBase > 50)
	{
		return createRareShield();
	}
	if (randBase > 25)
	{
		return createEpicShield();
	}
	if (randBase > 5)
	{
		return createLegendaryShield();
	}
	return createMythicShield();
}