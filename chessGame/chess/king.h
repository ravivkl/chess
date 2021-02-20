#pragma once
#include "piece.h"

class King : public Piece
{
public:
	King(int y, int x, int color, Board* board);
	bool checkMove(int y, int x);
};