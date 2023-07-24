#include "random.hpp"

#include <ctime>
#include <cstdlib>

using namespace std;

int randomInt(int range)
{
	static bool seeded = false;
	if (!seeded)
	{
		srand(time(nullptr));
		seeded = true;
	}
	return rand() % range;
}

int randomInt()
{
	return rand() % 100;
}
