#include "GameGrid.h"
#include <iostream>

Grid::Grid()
{
	ColumnAmount = 10;
	RowAmount = 20;
	SquareSize = 8;
	StartGrid();
	GridColour = GetSquareColours();
}

// This function initialises the grid
void Grid::StartGrid()
{
	for (int Column = 0; Column < ColumnAmount; Column++)
	{
		for (int Row = 0; Row< RowAmount; Row++)
		{
			grid[Column][Row] = 0;
		}
	}
}

// This function draws the grid, and each cell (the squares) in their respective positions
void Grid::DrawGrid(sf::RenderWindow &window)
{
	sf::RectangleShape Square(sf::Vector2f(SquareSize - 1, SquareSize - 1));
	Square.setFillColor(Background);
	for (int Column = 0; Column < ColumnAmount; Column++)
	{
		for (int Row = 0; Row < RowAmount; Row++)
		{
			// This creates a shape called Square, with an offset of -1 so that it leaves lines on the grid to look like classic tetris, with it being coloured "background"
			int SquareValue = grid[Column][Row];
			Square.setPosition(SquareSize * Column, SquareSize * Row);
			window.draw(Square);
		}
	}
}

// This function checks if there are any free spaces in the grid to be occupied by the current Tetromino being moved
bool Grid::SpaceInGrid(int Column, int Row)
{
	if (grid[Column][Row] == 0)
	{
		return true;
	}
	return false;
}

// This is my main function for clearing a full row, replacing it with an empty space and pushing all the squares down however many rows were cleared
int Grid::ClearRows()
{
	int FullRows = 0;
	for (int Row = RowAmount - 1; Row >= 0; Row --)
	{
		if (IsRowFull(Row))
		{
			ClearFullRow(Row);
			FullRows++;
		}
		else if (FullRows > 0)
		{
			MoveRowsDown(Row, FullRows);
		}
	}
	return FullRows;
}

// This function checks to see whether the row is full or not
bool Grid::IsRowFull(int Row)
{
	for (int Column = 0; Column < ColumnAmount; Column++)
	{
		if (grid[Column][Row] == 0)
		{
			return false;
		}
	}
	return true;
}
// This function is designed to be used in the main "ClearRows" function, this replaces the entire row with an index id of 0
void Grid::ClearFullRow(int Row)
{
	for (int Column = 0; Column< ColumnAmount; Column++)
	{
		grid[Column][Row] = 0;
	}
}

// This function moves down the Tetromino pieces by however many rows are above it (RowAmount) E.G a middle row gets cleared, that row is cleared and the rows above it move down
void Grid::MoveRowsDown(int Row, int RowAmount)
{
	for (int Column = 0; Column < ColumnAmount; Column++)
	{
		grid[Column][Row + RowAmount] = grid[Column][Row];
		grid[Column][Row] = 0;
	}
}

// This function is for testing purposes, it prints the grid as a matrix in text to see the values in the background
void Grid::Print()
{
	for (int Row = 0; Row < RowAmount; Row++)
	{
		for (int Column = 0; Column < ColumnAmount; Column++)
		{
			std::cout << grid[Column][Row] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
