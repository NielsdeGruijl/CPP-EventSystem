#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Observable.h"

class Overlap
{
	public:
		Overlap();
		~Overlap();

		void CheckOverlap(Player* p, sf::RectangleShape* b);
};