#pragma once

//This header file will be used to keep track of positioning the Tetrominos in a grid to enable rotations and allow them to stay in the game window without leaving it by rotating the piece
class Position
{
public:
	Position(int Column, int Row);
	int MinoInColumn;
	int MinoInRow;
};
