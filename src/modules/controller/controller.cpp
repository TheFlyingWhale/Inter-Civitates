#include "controller.hpp"

#include <unordered_map>
#include <string>

using namespace std;

unordered_map<string, Action *> Controller::globalActions;
unordered_map<string, function<void()>> Controller::systemActions;