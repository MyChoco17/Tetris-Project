#include "Movement.h"
#include "Tetromino.h"
#include "Positioning.h"
#include <iostream>

using namespace sf;
void Movement::EventManager(sf::RenderWindow& window, Tetromino& CurrentMino, GameLogic& Logic)
{
	// This loop is for event polling in SFML and is crucial for the game to function properly, as without it, the game will not operate
	// This loop also checks for any pending events, such as game closure and if any inputs are pressed
	Event event;
	while (window.pollEvent(event))
	{
		// This checks if the application has been closed, to ensure proper closure and not a freeze
		switch (event.type)
		{
		case Event::Closed:
			window.close();
			break;
		case Event::KeyPressed:
			switch (event.key.scancode)
			{
			case Keyboard::Scan::X:
				CurrentMino.UpdateRotationNegative();
				if (CurrentMino.IsMinoOutside())
				{
					CurrentMino.UpdateRotationPositive();
				}
				break;
			case Keyboard::Scan::C:
				CurrentMino.UpdateRotationPositive();
				if (CurrentMino.IsMinoOutside())
				{
					CurrentMino.UpdateRotationNegative();
				}
				break;
			case Keyboard::Scan::Left:
				Logic.MoveMinoLeft(CurrentMino, Logic);
				break;
			case Keyboard::Scan::Right:
				Logic.MoveMinoRight(CurrentMino, Logic);
				break;
			case Keyboard::Scan::Down:
				Logic.MoveMinoDown(CurrentMino, Logic, window);
				break;
			case Keyboard::Scan::Space:
				break;
			case Keyboard::Scan::Escape:
				window.close();
				break;
			}
		default:
			break;
		}
	}
}