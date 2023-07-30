#ifndef CLASS_CONTROLLER
#define CLASS_CONTROLLER

#include "../../utilities/utilities.hpp"

#include <unordered_map>
#include <iostream>
#include <functional>

using namespace Print;

class Action
{
public:
	Action(function<void()> act, string desc)
	{
		action = act;
		description = desc;
	}

	function<void()> action;
	string description;
};

class Controller
{
private:
	unordered_map<string, Action *> actions;
	static unordered_map<string, Action *> globalActions;
	static unordered_map<string, function<void()>> systemActions;
	string controllerName;

	void addAction(string signal, Action *action)
	{
		actions[signal] = action;
	}

	void addGlobalAction(string signal, Action *action)
	{
		globalActions[signal] = action;
	}

	void addSystemAction(string signal, function<void()> action)
	{
		systemActions[signal] = action;
	}

	void printActions()
	{
		cout << controllerName << " actions:" << endl;

		for (const auto &pair : actions)
		{
			cout << "[" << pair.first << "] - " << pair.second->description << endl;
		}

		cout << "Global actions" << endl;

		for (const auto &pair : globalActions)
		{
			cout << "[" << pair.first << "] - " << pair.second->description << endl;
		}
	}

public:
	Controller(string name)
	{
		controllerName = name;
	}

	// Creates a action which will only be available for the class inheriting Controller
	// The signal must be unique within the inherited class, meaning it can only trigger one action
	void createAction(string signal, function<void()> action, string description)
	{
		Action *act = new Action(action, description);
		addAction(signal, act);
	}

	// Creates a action which will be available for all classes inheriting Controller
	// The signal must be unique across the whole program, meaning it can only trigger one action
	void createGlobalAction(string signal, function<void()> action, string description)
	{
		Action *act = new Action(action, description);
		addGlobalAction(signal, act);
	}

	// Creates a action which will be available for all classes inheriting Controller
	// The signal does not have to be unique, meaning it can trigger multiple actions
	void createSystemAction(string signal, function<void()> action)
	{
		addSystemAction(signal, action);
	}

	// Handles input and triggers the corresponding action
	void autoTrigger(string message)
	{
		string input = getInput(message, true);
		manualTrigger(input);
	}

	// Triggers the corresponding action
	void manualTrigger(string signal)
	{
		bool foundSignal = false;

		if (signal == "H")
			return printActions();

		if (const auto action = actions.find(signal); action != actions.end())
		{
			action->second->action();
			return;
		}

		if (const auto action = globalActions.find(signal); action != actions.end())
		{
			action->second->action();
			return;
		}

		if (const auto action = systemActions.find(signal); action != systemActions.end())
		{
			action->second();
			foundSignal = true;
		}

		if (foundSignal)
			return;

		cout << rich("Action with signal [" + signal + "] does not exit", Color::red) << endl;
		printActions();
	}

	~Controller()
	{
		for (const auto &pair : actions)
		{
			delete pair.second;
		}
	}
};

#endif
