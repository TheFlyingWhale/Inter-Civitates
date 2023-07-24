#ifndef TYPE_CHECKERS
#define TYPE_CHECKERS

#include <string>
#include <type_traits>

using namespace std;

template <typename T>
bool isString(T variable)
{
	if (is_same<T, const char *>::value)
		return true;
	return is_same<T, string>::value;
}

template <typename T>
bool isInt(T variable)
{
	return is_same<T, int>::value;
}

#endif
