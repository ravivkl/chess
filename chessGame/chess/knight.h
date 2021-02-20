#pragma once
#include "piece.h"

class Knight : public Piece
{
public:
	Knight(int y, int x, int color, Board* board);
	bool checkMove(int y, int x);
};