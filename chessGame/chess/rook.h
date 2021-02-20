#pragma 
#include "piece.h"

class Rook : public Piece
{
public:
	Rook(int y, int x, int color, Board* board);
	virtual bool checkMove(int y, int x);
};