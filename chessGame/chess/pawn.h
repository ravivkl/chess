#pragma once
#include "piece.h"

class Pawn : public Piece
{
private:
	int _turnnum;
public:
	Pawn(int y, int x, int color, Board* board);
	bool checkMove(int y, int x);
};