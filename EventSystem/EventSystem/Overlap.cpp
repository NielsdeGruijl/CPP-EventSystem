#include <iostream>

#include "Overlap.h"

Observable overlapEvent;

Overlap::Overlap()
{

}

Overlap::~Overlap()
{

}

void Overlap::CheckOverlap(Player* p, sf::RectangleShape* b)
{
	sf::RectangleShape a = p->sprite;
	sf::Vector2f aPos = a.getPosition();
	sf::Vector2f bPos = b->getPosition();
	float aBoundWidth = a.getGlobalBounds().width;
	float aBoundHeight = a.getGlobalBounds().height;
	float bBoundWidth = b->getGlobalBounds().width;
	float bBoundHeight = b->getGlobalBounds().height;
	if (abs(aPos.x - bPos.x) > (aBoundWidth / 2) + (bBoundWidth / 2)) return;
	if (abs(aPos.y - bPos.y) > (aBoundHeight / 2) + (bBoundHeight / 2)) return;

	overlapEvent.Notify();

	std::cout << "overlapping" << '\n';
}