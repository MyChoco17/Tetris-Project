#pragma once
#include "Positioning.h"
#include "Tetromino.h"


class LMino :public Tetromino
{
public:
	LMino()
	{
		// L shaped Tetromino
		id = 1;
		Cells[0] = { Position(2,0), Position(0,1), Position(1,1), Position(2,1) };
		Cells[1] = { Position(1,0), Position(1,1), Position(1,2), Position(2,2) };
		Cells[2] = { Position(0,1), Position(0,2), Position(1,1), Position(2,1) };
		Cells[3] = { Position(0,0), Position(1,0), Position(1,1), Position(1,2) };
		Move(3, 0);
	}
};

class JMino :public Tetromino
{
public:
	JMino()
	{
		// J Shaped Tetromino
		id = 2;
		Cells[0] = { Position(0,0), Position(0,1), Position(1,1), Position(2,1) };
		Cells[1] = { Position(1,0), Position(2,0), Position(1,1), Position(1,2) };
		Cells[2] = { Position(0,1), Position(1,1), Position(2,1), Position(2,2) };
		Cells[3] = { Position(1,0), Position(1,1), Position(0,2), Position(1,2) };
		Move(3, 0);
	}
};

class IMino :public Tetromino
{
public:
	IMino()
	{
		// I Shaped Tetromino
		id = 3;
		Cells[0] = { Position(0,1), Position(1,1), Position(2,1), Position(3,1) };
		Cells[1] = { Position(2,0), Position(2,1), Position(2,2), Position(2,3) };
		Cells[2] = { Position(0,2), Position(1,2), Position(2,2), Position(3,2) };
		Cells[3] = { Position(1,0), Position(1,1), Position(1,2), Position(1,3) };
		Move(3, -1);
	}
};

class OMino :public Tetromino
{
public:
	OMino()
	{
		// O Shaped Tetromino
		id = 4;
		Cells[0] = { Position(0,0), Position(0,1), Position(1,0), Position(1,1) };
		Cells[1] = { Position(0,0), Position(0,1), Position(1,0), Position(1,1) };
		Cells[2] = { Position(0,0), Position(0,1), Position(1,0), Position(1,1) };
		Cells[3] = { Position(0,0), Position(0,1), Position(1,0), Position(1,1) };
		Move(4, 0);
	}
};
	
class SMino :public Tetromino
	
{
	
public:	
	SMino()
	{
		// S Shaped Tetromino
		id = 5;
		Cells[0] = { Position(1,0), Position(2,0), Position(0,1), Position(1,1) };
		Cells[1] = { Position(0,0), Position(0,1), Position(1,1), Position(1,2) };
		Cells[2] = { Position(1,0), Position(2,0), Position(0,1), Position(1,1) };
		Cells[3] = { Position(0,0), Position(0,1), Position(1,1), Position(1,2) };
		Move(3, 0);
	}
};

class ZMino :public Tetromino
{
public:
	ZMino()
	{
		// Z Shaped Tetromino
		id = 6;
		Cells[0] = { Position(0,0), Position(1,0), Position(1,1), Position(2,1) };
		Cells[1] = { Position(2,0), Position(1,1), Position(2,1), Position(1,2) };
		Cells[2] = { Position(0,0), Position(1,0), Position(1,1), Position(2,1) };
		Cells[3] = { Position(2,0), Position(1,1), Position(2,1), Position(1,2) };
		Move(3, 0);
	}
};

class TMino :public Tetromino
{
public:
	TMino()
	{
		// T Shaped Tetromino
		id = 7;
		Cells[0] = { Position(0,1), Position(1,0), Position(1,1), Position(1,2) };
		Cells[1] = { Position(0,1), Position(1,1), Position(1,2), Position(2,1) };
		Cells[2] = { Position(1,0), Position(1,1), Position(1,2), Position(2,1) };
		Cells[3] = { Position(0,1), Position(1,0), Position(1,1), Position(2,1) };
		Move(3, 0);
	}
};