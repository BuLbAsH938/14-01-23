#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"




void initText(sf::Text& scoreText, int score, sf::Font& font,
	const int charSize, const sf::Vector2f textStartPos) {
	scoreText.setString(std::to_string(score));
	scoreText.setFont(font);
	scoreText.setCharacterSize(charSize);
	scoreText.setPosition(textStartPos);
}

bool pointInRect(sf::RectangleShape bat, sf::Vector2f point) {
	float batX = bat.getPosition().x;
	float batY = bat.getPosition().y;
	return (point.x >= batX && point.x <= batX + BAT_WIDTH)
		&& (point.y >= batY && point.y <= batY + BAT_HEIGHT);
}