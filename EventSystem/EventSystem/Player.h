#pragma once
#include <SFML/Graphics.hpp>

class Player
{
	private: 
		float inputDir = 0;
	public:
		Player(sf::Vector2f size, sf::Vector2f pos);
		~Player();

		void MovePlayer();
		void DrawPlayer(sf::RenderWindow* window);

		static sf::RectangleShape sprite;
};

void overlapFix();