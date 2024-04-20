#include "Positioning.h"

// This keeps track of the positioning of the Tetromino in the matrix
Position::Position(int Column, int Row)
{
	this->MinoInColumn = Column;
	this->MinoInRow = Row;
};
