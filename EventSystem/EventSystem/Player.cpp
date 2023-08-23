#include "Player.h"
#include "Observable.h"

using sf::Keyboard;

extern Observable overlapEvent;
sf::RectangleShape Player::sprite;

Player::Player(sf::Vector2f size, sf::Vector2f pos)
{
	sprite.setSize(size);
	sprite.setPosition(pos);
	sprite.setOrigin(size.x / 2, size.y / 2);
	sprite.setFillColor(sf::Color::Cyan);

	overlapEvent.Subscribe(&overlapFix);
}

Player::~Player()
{
	overlapEvent.Unsubscribe(&overlapFix);
}

void Player::MovePlayer()
{
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		inputDir = -1;
	}
	else if (Keyboard::isKeyPressed(Keyboard::D))
	{
		inputDir = 1;
	}
	else
	{
		inputDir = 0;
	}

	sf::Vector2f moveDir(inputDir, 0);
	sprite.move(moveDir * 0.5f);
}

void Player::DrawPlayer(sf::RenderWindow* window)
{
	window->draw(sprite);
}

void overlapFix()
{
	Player::sprite.setFillColor(sf::Color::Magenta);
}