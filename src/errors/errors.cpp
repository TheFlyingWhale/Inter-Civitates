#include "errors.hpp"
#include "../utilities/utilities.hpp"

#include <iostream>
using namespace std;
using namespace Print;

void handleEx(const exception &ex)
{
	cout << rich("Unkown error occurred, generic error shall be proved\n", Color::red, Decoration::bold);
	cout << "Error: " << ex.what();
}
