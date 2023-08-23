#include "Observable.h"

Observable::Observable()
{

}

Observable::~Observable()
{

}

void Observable::Subscribe(Action action)
{
	actions.push_back(action);
}

void Observable::Unsubscribe(Action action)
{
	auto it = std::find(actions.begin(), actions.end(), action);
	
	if (it != actions.end())
	{
		actions.erase(it);
	}
	else
	{
		std::cout << "-1" << '\n';
	}
}

void Observable::Notify()
{
	for (int i = 0; i < actions.size(); i++)
	{
		Action action = actions.at(i);
		action();
	}
}