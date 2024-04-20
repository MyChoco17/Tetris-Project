#include <iostream>
#include <SFML/Graphics.hpp>
#include "Movement.h"


// using namespace for simplicity sake, do not want to write std:: chrono:: or sf:: every single line :P
using namespace std;
using namespace sf;

// This is the main loop, where the game will run from
int main()
{	
	int MoveTimer = 0;
	RenderWindow window(VideoMode(GameWidth, GameHeight), "Tetris", Style::Close);
	
	auto icon = Image{};
	if (!icon.loadFromFile("Textures\\Tetris_Logo.png"))
	{
		return 0;
	};
	// This sets the game FPS to 60 and gives it an icon
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	window.setView(View(FloatRect(0, 0, CellSize * Columns, CellSize * Rows)));
	window.setFramerateLimit(60);

	// This is SFML's way of generating an event
	Movement GameInput;
	GameLogic Logic; 
	// While the game is open
	while (window.isOpen())
	{
		GameInput.EventManager(window, Logic.GetCurrentMino(), Logic);
		MoveTimer++;
		if (MoveTimer == 30)
		{
			Logic.MoveMinoDown(Logic.GetCurrentMino(), Logic, window);
			MoveTimer = 0;
		}
		window.clear();
		// This sets the grid for the background as a rectangle filling the screen without the lines
		Logic.Draw(window);
		window.display();
	}
	return 0;
}
