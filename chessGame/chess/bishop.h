#pragma once
#include "piece.h"

class Bishop : public Piece
{
public:
	Bishop(int y, int x, int color, Board* board);
	virtual bool checkMove(int y, int x);
};