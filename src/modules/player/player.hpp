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
		createPlayer();
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

	void createPlayer()
	{
		setName("Player");
		setColor(Color::green);
		mountWeapon(createSpecialWeapon());
		// name = getInput("Provide character name", true);
	}
};

#endif
