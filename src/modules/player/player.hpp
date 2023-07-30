#ifndef PLAYER
#define PLAYER

#include "../../utilities/utilities.hpp"
#include "../items/items.hpp"
#include "../character/character.hpp"

using namespace Print;

class Player : public Character
{
private:
	Player() : Character()
	{
		setName("Player");
		setColor(Color::green);
		// mountWeapon(createSpecialWeapon());
		mountShield(createSpecialShield());
	}
	~Player() {}

	static Player *instance;

public:
	static Player &getInstance()
	{
		if (!instance)
		{
			instance = new Player();
		}
		return *instance;
	}

	void resetPlayer()
	{
		health.setValue(100);
		energy.setValue(100);
	}
};

#endif
