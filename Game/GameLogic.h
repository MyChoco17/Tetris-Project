#pragma once
#include <vector>
#include "Tetromino.h"
#include "MinoPieces.h"
#include "Display.h"
#include "MinoColours.h"
#include "GameGrid.h"

// This is my game logic class, where (so far) it will generate a bag of Tetrominos and pick one, and draw the current one on screen.
class GameLogic
{
public:
	GameLogic();
	void Draw(sf::RenderWindow& window);
	std::vector<Tetromino> GetAllMinos();
	Tetromino PickRandomMino();
	Tetromino& GetCurrentMino();
	void FreezeTetromino(sf::RenderWindow& window);
	bool MinoToMinoCollision();
	void MoveMinoDown(Tetromino& CurrentMino, GameLogic& logic, sf::RenderWindow& window);
	void MoveMinoLeft(Tetromino& CurrentMino, GameLogic& logic);
	void MoveMinoRight(Tetromino& CurrentMino, GameLogic& logic);
private:
	std::vector<Tetromino> Minos;
	std::vector<Tetromino> FrozenMinos;
	Tetromino CurrentMino;
	Tetromino NextMino;
	Grid grid;
	int CellSize;
};
