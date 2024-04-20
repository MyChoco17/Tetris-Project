#include "MinoColours.h"

// This assigns a value to a colour in SFML
const sf::Color Red(255, 0, 0, 255);
const sf::Color Blue(13, 64, 216, 255);
const sf::Color Green(47, 230, 23, 255);
const sf::Color Cyan(21, 204, 209, 255);
const sf::Color Purple(166, 0, 247, 255);
const sf::Color Yellow(237, 234, 4, 255);
const sf::Color Orange(226, 116, 17, 255);
const sf::Color Background(26, 31, 40, 255);


// This is a vector of colours that I use to pick and choose between each colour for each piece
std::vector<sf::Color> GetSquareColours()
{
	return { Background, Orange, Blue, Cyan, Yellow, Green, Red, Purple };
}
