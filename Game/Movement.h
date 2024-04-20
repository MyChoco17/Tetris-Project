#pragma once
#include "Tetromino.h"
#include "MinoPieces.h"
#include "GameLogic.h"

class Movement
{
public:
	void EventManager(sf::RenderWindow &window, Tetromino& CurrentMino, GameLogic& Logic);
};