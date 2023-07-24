#include "controller.hpp"
#include "../model/model.hpp"

#include <string>

using namespace std;

Controller *Controller::instance_ = nullptr;

void createAction(string key, function<void()> action, string description)
{
	Controller &co = Controller::GetInstance();
	Action act(action, description);
	co.addAction(key, act);
}