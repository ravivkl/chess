#include "knight.h"

Knight::Knight(int y, int x, int color, Board* board) : Piece(y, x, color, KNIGHT, board)
{
}

bool Knight::checkMove(int y, int x)
{
	Board* onboard = _myboard;
	Piece* check = nullptr;
	int myx = this->get_x();
	int myy = this->get_y();
	int i = 0;
	
	/*
	0	@	0	@	0
	@	0	0	0	@
	0	0	1	0	0
	@	0	0	0	@
	0	@	0	@	0
	*/
	
	//these "if's" check the places in rows because it dosent matter left or right, it checks the same path
	if ((y == myy + 2) && ((x == myx + 1) || (x == myx - 1))) { 
		return true;
	}

	else if ((y == myy - 1) || (y == myy + 1)) {
		if (x == myx + 2) {
			return true;
		}
		else if (x == myx - 2) {
			return true;
		}
	}

	else if ((y == myy - 2) && ((x == myx + 1) || (x == myx - 1))) {
		return true;
	}

	return false;
}
