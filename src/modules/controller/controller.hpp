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
	string controllerName;

	void addAction(string signal, Action *action)
	{
		actions[signal] = action;
	}

	void addGlobalAction(string signal, Action *action)
	{
		globalActions[signal] = action;
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

	void createAction(string signal, function<void()> action, string description)
	{
		Action *act = new Action(action, description);
		addAction(signal, act);
	}

	void createGlobalAction(string signal, function<void()> action, string description)
	{
		Action *act = new Action(action, description);
		addGlobalAction(signal, act);
	}

	// For when you dont want to deal with the input yourself
	void simpleTrigger(string message)
	{
		string input = getInput(message, true);
		triggerAction(input);
	}

	// For when you want to deal with the input yourself
	void triggerAction(string signal)
	{
		if (signal == "h")
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
