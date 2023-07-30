#ifndef TEST_GROUND
#define TEST_GROUND

#include "../controller/controller.hpp"
#include "../items/storage/storage.hpp"
#include "../items/items.hpp"

#include <iostream>

using namespace std;

class TestGround : public Controller
{
private:
	bool inTestGround = false;
	Storage storage = Storage("test");

public:
	TestGround() : Controller("Test ground")
	{
		createAction("q", bind(&TestGround::exitTestGround, this), "Exit test ground");
		createAction("i", bind(&TestGround::inspect, this), "inspect storage");
		createAction("f", bind(&TestGround::fillStorage, this), "Fill storage");
		createAction(
			"c", [this]()
			{ storage.clearStorage(); },
			"Clear storage");
	}

	void fillStorage()
	{
		storage.addItem(createRandomWeapon());
		storage.addItem(createRandomShield());
		storage.addItem(createRandomWeapon());
		storage.addItem(createRandomShield());
		storage.addItem(new HealthPotion());
		storage.addItem(new EnergyPotion());
	}

	void exitTestGround()
	{
		inTestGround = false;
	}

	void inspect()
	{
		storage.inspect();
	}

	void enterTestGround()
	{
		inTestGround = true;
		while (inTestGround)
		{
			autoTrigger("Test ground");
		}
	}
};

#endif
