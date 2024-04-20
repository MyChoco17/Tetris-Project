#include "GameLogic.h"
#include "MinoColours.h"
#include <random>

using namespace sf;
//This is the main game logic function
GameLogic::GameLogic()
{
	Grid grid;
	std::vector<Tetromino> FrozenMinos;
	Minos = GetAllMinos();
	CurrentMino = PickRandomMino();
	NextMino = PickRandomMino();
	int CellSize = 8;
}

// This picks a random Tetromino by checking how many Minos are in an index, and for each shape that is picked, it will erase it from the bag, until it is empty and fills again with more Minos.
Tetromino GameLogic::PickRandomMino()
{
	if (Minos.empty())
	{
		Minos = GetAllMinos();
	};
	int randomIndex = rand() % Minos.size();
	Tetromino Mino = Minos[randomIndex];
	Minos.erase(Minos.begin() + randomIndex);
	return Mino;
}

// This just gets the information of each Tetromino piece
std::vector<Tetromino> GameLogic::GetAllMinos()
{
	LMino LMino; JMino JMino; IMino IMino; OMino OMino; SMino SMino; ZMino ZMino; TMino TMino;
	return { LMino, JMino, IMino, OMino, SMino, ZMino, TMino };
}


// This Renders the grid and draws all tetrominos on screen
void GameLogic::Draw(RenderWindow &window)
{
	grid.DrawGrid(window);
	CurrentMino.draw(window);
	for (Tetromino& FrozenMino : FrozenMinos)
	{
		FrozenMino.draw(window);
	}
}

// This function returns the current Tetromino being used
Tetromino& GameLogic::GetCurrentMino()
{
	return CurrentMino;
}


// This function is SUPPOSED to freeze the tetromino in place once it reaches the bottom, and picks another Tetromino to display
void GameLogic::FreezeTetromino(sf::RenderWindow& window)
{
	std::vector<Position> Square = CurrentMino.SquarePosition();
	for (Position Pos : Square)
	{
		grid.grid[Pos.MinoInColumn][Pos.MinoInRow] = CurrentMino.id;
	}
	FrozenMinos.push_back(CurrentMino);
	CurrentMino = NextMino;
	NextMino = PickRandomMino();
	grid.ClearRows();
	grid.Print();
}


// This function checks for Tetromino collisions with Frozen Tetrominos
bool GameLogic::MinoToMinoCollision()
{

	std::vector<Position> Square = CurrentMino.SquarePosition();
	for (Position Pos : Square)
	{
		if (grid.SpaceInGrid(Pos.MinoInColumn, Pos.MinoInRow) == false)
		{
			return true;
		}
	}
	return false;
}

// This moves the Tetromino down and freezes it in place once the bottom has reached a surface
void GameLogic::MoveMinoDown(Tetromino& CurrentMino, GameLogic& logic, sf::RenderWindow& window)
{
	CurrentMino.Move(0, 1);
	if (CurrentMino.IsMinoOutside() || logic.MinoToMinoCollision() == true)
	{
		CurrentMino.Move(0, -1);
		logic.FreezeTetromino(window);
	}
}

// This accepts left inputs to move the Tetromino left
void GameLogic::MoveMinoLeft(Tetromino& CurrentMino, GameLogic& logic)
{
	CurrentMino.Move(-1, 0);
	if (CurrentMino.IsMinoOutside() || logic.MinoToMinoCollision() == true)
	{
		CurrentMino.Move(1, 0);
	}
}

// This accepts right inputs to move the Tetromino right
void GameLogic::MoveMinoRight(Tetromino& CurrentMino, GameLogic& logic)
{
	CurrentMino.Move(1, 0);
	if (CurrentMino.IsMinoOutside() || logic.MinoToMinoCollision() == true)
	{
		CurrentMino.Move(-1, 0);
	}
}

