#include <SFML/Graphics.hpp>
#include "Overlap.h"
#include "Player.h"
#include "Observable.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");

    Overlap overlap;

    Player player(sf::Vector2f(200, 200), sf::Vector2f(640, 360));

    sf::RectangleShape triggerBox;
    triggerBox.setFillColor(sf::Color::Red);
    triggerBox.setPosition(1080, 360);
    triggerBox.setSize(sf::Vector2f(400, 720));
    triggerBox.setOrigin(200, 360);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        player.MovePlayer();

        overlap.CheckOverlap(&player, &triggerBox);

        window.clear();
        //window.draw(shape);
        window.draw(triggerBox);
        player.DrawPlayer(&window);
        window.display();
    }

    return 0;
}