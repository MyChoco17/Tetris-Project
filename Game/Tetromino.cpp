#include <SFML/Graphics.hpp>
#include "Tetromino.h"
#include "MinoPieces.h"
#include "MinoColours.h"
#include "Movement.h"
#include "Positioning.h"

using namespace std;


Tetromino::Tetromino()
{
	id = 0;
	CellSize = 8;
	RotationState = 0;
	OffsetColumn = 0;
	OffsetRow = 0;
	MinoColour = GetSquareColours();
};


// This updates the offset position of the Tetromino to display on screen
void Tetromino::updateOffset(int newColumn, int newRow)
{
	OffsetColumn = newColumn;
	OffsetRow = newRow;
}


// This rotates the Tetromino anti-clockwise
void Tetromino::UpdateRotationNegative()
{
	RotationState--;
	if (RotationState < 0)
		RotationState = 3;
}


// This rotates the Tetromino clockwise
void Tetromino::UpdateRotationPositive()
{
	RotationState++;
	if (RotationState > 3)
		RotationState = 0;
}

// This is my main draw function that will draw each square of the Tetromino and colour it
void Tetromino::draw(sf::RenderWindow &window)
{
	vector<Position> Square = SquarePosition();
	sf::RectangleShape TetrominoPiece(sf::Vector2f(CellSize - 1, CellSize - 1));
	for (Position Pos : Square)
	{
		TetrominoPiece.setPosition(Pos.MinoInColumn * CellSize, Pos.MinoInRow * CellSize);
		// This is checking the ID of the piece, and assigning it the correct colour
		TetrominoPiece.setFillColor(MinoColour[id]);
		// This is drawing the piece onto the screen
		window.draw(TetrominoPiece);
	}
}


// This is the movement of the Tetromino
void Tetromino::Move(int Column, int Row)
{
	OffsetColumn += Column;
	OffsetRow += Row;
}


// This calculates the current position of the Tetromino
vector <Position> Tetromino::SquarePosition()
{
	vector<Position> Square = Cells[RotationState];
	vector<Position> SquaresMoved;
	for (Position Pos : Square)
	{
		Position NewPosition = Position(Pos.MinoInColumn + OffsetColumn, Pos.MinoInRow + OffsetRow);
		SquaresMoved.push_back(NewPosition);
	}
	return SquaresMoved;
}


// This function checks whether the tetromino is outside the grid, using the grid's number of columns and rows
bool Tetromino::SquareOutsideScreen(int Column, int Row)
{
	if (Column >= 0 && Column < 10 && Row >= 0 && Row < 20)
	{
		return false;
	}
	return true;
}


// this is a follow-up on the function above, and if the mino is outside the grid, it will return true, inversing the movement made by the player
bool Tetromino::IsMinoOutside()
{
	vector <Position> Square = SquarePosition();
	for (Position Mino : Square)
	{
		if (SquareOutsideScreen(Mino.MinoInColumn, Mino.MinoInRow))
		{
			return true;
		}
	}
	return false;
}


// This (when programmed) will lock the Tetromino in place once it has touched the ground
