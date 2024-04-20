// This header file will create a class for each piece, using a map for positioning the Tetrominos in the grid
#pragma once
#include "Positioning.h"
#include <vector>
#include <map>
#include <SFML/Graphics.hpp>


class Tetromino
{
public:
	Tetromino();
	int id;
	void setOffsetColumn(int xPosNew) { OffsetColumn = xPosNew;}
	void setOffsetRow(int yPosNew) { OffsetRow = yPosNew;}
	void updateOffset(int newColumn, int newRow);
	void UpdateRotationPositive();
	void UpdateRotationNegative();
	void draw(sf::RenderWindow &window);
	void Move(int Column, int Row);
	bool SquareOutsideScreen(int Column, int Row);
	std::map<int, std::vector<Position>> Cells;
	std::vector<Position> SquarePosition();
	bool IsMinoOutside();
private:
	std::vector<sf::Color> MinoColour;
	int CellSize;
	int OffsetColumn;
	int OffsetRow;
	int RotationState;
};

