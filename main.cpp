#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include <ctime>

void moving(sf::RectangleShape &rectangle) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		sf::Vector2f position = rectangle.getPosition();
		rectangle.setPosition(position.x, position.y + 5);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		sf::Vector2f position = rectangle.getPosition();
		rectangle.setPosition(position.x, position.y - 5);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		sf::Vector2f position = rectangle.getPosition();
		rectangle.setPosition(position.x + 5, position.y);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		sf::Vector2f position = rectangle.getPosition();
		rectangle.setPosition(position.x - 5, position.y);
	}
}

int main()
{
	const int posA = 100; //Starting X rectangle
	const int posB = 100; //Starting Y rectangle
	sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!");
	window.setFramerateLimit(60);
	sf::RectangleShape rectangle(sf::Vector2f(120, 50));
	sf::CircleShape circle(25);
	rectangle.setFillColor(sf::Color::Red);
	rectangle.setPosition(posA, posB);
	circle.setPosition(400, 250);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (rectangle.getGlobalBounds().intersects(circle.getGlobalBounds())) {
			rectangle.setPosition(posA, posB);
		}
		moving(rectangle);
		window.clear();
		window.draw(rectangle);
		window.draw(circle);
		window.display();
	}

	return 0;
}
