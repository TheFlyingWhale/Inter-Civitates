#include "modules/modules.hpp"
#include "utilities/utilities.hpp"
#include "errors/errors.hpp"
#include "initializer.hpp"

#include <iostream>
#include <string>

using namespace std;

int main()
{
	Model &mm = Model::GetInstance();
	Controller &co = Controller::GetInstance();

	init();

	try
	{
		while (!mm.isGameOver)
		{
			co.iterate();
		}
	}
	catch (const exception &ex)
	{
		handleEx(ex);
	}
}