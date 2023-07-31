#ifndef PLAYER
#define PLAYER

#include "../../utilities/utilities.hpp"
#include "../items/items.hpp"
#include "../character/character.hpp"
#include "../controller/controller.hpp"

using namespace Print;

class Player : public Character, public Controller
{
private:
	Player() : Character(), Controller("Player")
	{
		setName("Player");
		setColor(Color::green);

		mountWeapon(createSpecialWeapon());
		mountShield(createSpecialShield());

		inventory.add(createUncommonWeapon());
		inventory.add(createMythicWeapon());
		inventory.add(createEpicWeapon());
		inventory.add(new HealthPotion());
		inventory.add(new EnergyPotion());

		createAction("cw", bind(&Player::changeWeapon, this), "Change weapon");

		createAction(
			"q", [this]()
			{ isManaging = false; },
			"Exit player management");
	}
	~Player() {}

	static Player *instance;
	bool isManaging = false;

	void changeWeapon()
	{
		Weapon *curWep = weapon;
		weapon = inventory.getItem<Weapon>();
		inventory.add(curWep);
		system("clear");
	}

	void changeShield() {}

public:
	static Player &getInstance()
	{
		if (!instance)
		{
			instance = new Player();
		}
		return *instance;
	}

	void manage()
	{
		isManaging = true;
		while (isManaging)
		{
			autoTrigger("Player");
		}
	}

	void resetPlayer()
	{
		health.setValue(100);
		energy.setValue(100);
	}
};

#endif
