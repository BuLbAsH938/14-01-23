#pragma once
#include "settings.h"
#include "SFML/Graphics.hpp"


struct Bat {
	sf::RectangleShape shape;
	float speedx, speedy;
};

void batDown(Bat& bat) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		bat.speedy = bat.speedy;
	}
}

void batUp(Bat& bat) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		bat.speedy = -batSpeed;
	}
}

void BatInit(Bat& bat)
{
	bat.shape.setSize(batSize);
	bat.shape.setFillColor(BAT_COLOR);
	bat.shape.setPosition(batPosition);
}

void batUpdate(Bat& bat) {
	batUp(bat);
	batDown(bat);
}

void batDraw(sf::RenderWindow& window, Bat bat) {
	window.draw(bat.shape);
}
