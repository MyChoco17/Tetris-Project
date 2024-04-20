#pragma once
#include "SFML/Graphics.hpp"
#include "MinoColours.h"
#include "Tetromino.h"

// This is my grid class, where everything will render to it
class Grid
{
public:
	Grid();
	void StartGrid();
	void DrawGrid(sf::RenderWindow& window);
	bool SpaceInGrid(int Column, int Row);
	int ClearRows();
	void Print();
	int grid[10][20];
private:
	bool IsRowFull(int Row);
	void ClearFullRow(int Row);
	void MoveRowsDown(int Row, int RowAmount);
	int RowAmount;
	int ColumnAmount;
	int SquareSize;
	std::vector<sf::Color> GridColour;


};