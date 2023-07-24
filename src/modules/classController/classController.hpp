#ifndef CLASS_CONTROLLER
#define CLASS_CONTROLLER

#include "../../utilities/utilities.hpp"

#include <unordered_map>
#include <iostream>
#include <functional>

using namespace Print;

class ClassAction
{
public:
	ClassAction(function<void()> act, string desc)
	{
		action = act;
		description = desc;
	}

	function<void()> action;
	string description;
};

class ClassController
{
private:
	unordered_map<string, ClassAction *> actions;
	string controllerName;

public:
	ClassController(string name)
	{
		controllerName = name;
	}

	void createClassAction(string signal, function<void()> action, string description)
	{
		ClassAction *act = new ClassAction(action, description);
		addClassAction(signal, act);
	}

	void addClassAction(string signal, ClassAction *action)
	{
		actions[signal] = action;
	}

	void triggerAction(string signal)
	{
		if (signal == "h")
			return printActions();

		if (const auto action = actions.find(signal); action != actions.end())
		{
			action->second->action();
			return;
		}

		cout << rich("Action with signal [" + signal + "] does not exit", Color::red) << endl;
		printActions();
	}

	void printActions()
	{
		cout << controllerName << " actions:" << endl;

		for (const auto &pair : actions)
		{
			cout << "[" << pair.first << "] - " << pair.second->description << endl;
		}
	}
	~ClassController()
	{
		for (const auto &pair : actions)
		{
			delete pair.second;
		}
	}
};

#endif
