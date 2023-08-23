#pragma once
#include <iostream>
#include <vector>

typedef void(*Action)();

class Observable
{
	private:
		std::vector<Action> actions;
	public:
		Observable();
		~Observable();

		void Subscribe(Action action);
		void Unsubscribe(Action action);
		void Notify();
};