#pragma once
#include "piece.h"

class Queen : public Piece
{
public:
	Queen(int y, int x, int color, Board* board);
	virtual bool checkMove(int y, int x);
};