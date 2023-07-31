#ifndef SHIELD
#define SHIELD

#include "../usableItem.hpp"

class Shield;

Shield *createCommonShield();
Shield *createUncommonShield();
Shield *createSpecialShield();
Shield *createRareShield();
Shield *createEpicShield();
Shield *createLegendaryShield();
Shield *createMythicShield();
Shield *createRandomShield();

class Shield : public UsableItem
{
public:
	Shield() : UsableItem() {}
};

#endif