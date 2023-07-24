#ifndef CONTROLLER
#define CONTROLLER

#include "../../utilities/utilities.hpp"
#include "../model/model.hpp"

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
using namespace Print;

void createAction(string key, function<void()> action, string description = "No description");

class Action
{
public:
	Action(function<void()> pAction = nullptr, string pDescription = "")
	{
		action = pAction;
		description = pDescription;
	}

	function<void()> action;
	string description;
};

class Controller
{
protected:
	Controller() {}
	~Controller() {}
	static Controller *instance_;

	unordered_map<string, Action> actions;

	int iterations = 0;

public:
	static Controller &GetInstance()
	{
		if (!instance_)
			instance_ = new Controller();

		return *instance_;
	}

	void iterate()
	{
		newLine();
		cout << "Iteration " << iterations << endl;
		string input = getInput("Please provide some input - h for help", true);
		triggerAction(input);
		iterations++;
	}

	void addAction(string signal, const Action &action)
	{
		actions[signal] = action;
	}

	void triggerAction(string signal)
	{
		if (signal == "h")
		{
			printActions();
			return;
		}

		if (const auto action = actions.find(signal); action != actions.end())
		{
			action->second.action();
			return;
		}

		cout << rich("Action with signal [" + signal + "] does not exist\n", Color::red);
		printActions();
	}

	void printActions()
	{
		cout << "Actions: " << endl;

		for (const auto &pair : actions)
		{
			cout << "[" << pair.first << "] - " << pair.second.description << endl;
		}

		cout << endl;
	}
};

#endif
