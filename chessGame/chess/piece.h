#pragma once
#include "board.h"

class Board;

enum PieceColor
{
	WHITE = 0,
	BLACK = 1
};

enum PieceType
{
	KING = 0,
	QUEEN = 1,
	ROOK = 2,
	BISHOP = 3,
	KNIGHT = 4,
	PAWN = 5
};

class Piece
{
protected:
	Board *_myboard;
	int _type;
	int _color;
	int _x;
	int _y;

public:
	Piece(int y, int x, int color, int type, Board *board);
	~Piece();
	virtual bool checkMove(int y, int x) = 0;

	int get_type();
	int get_color();
	void set_x(int new_x);
	void set_y(int new_y);
	int get_x();
	int get_y();
};