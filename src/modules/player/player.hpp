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

		inventory.addItem(createMythicWeapon());
		inventory.addItem(new HealthPotion());
		inventory.addItem(new EnergyPotion());

		createAction(
			"q", [this]()
			{ isEditing = false; },
			"");
	}
	~Player() {}

	static Player *instance;
	bool isEditing = false;

public:
	static Player &getInstance()
	{
		if (!instance)
		{
			instance = new Player();
		}
		return *instance;
	}

	void editPlayer()
	{
		isEditing = true;
	}

	void resetPlayer()
	{
		health.setValue(100);
		energy.setValue(100);
	}
};

#endif
