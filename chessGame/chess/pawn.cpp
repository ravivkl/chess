#include "pawn.h"

Pawn::Pawn(int y, int x, int color, Board* board) : Piece(y, x, color, PAWN, board)
{
	_turnnum = 0;
}

bool Pawn::checkMove(int y, int x)
{
	Board* onboard = _myboard;
	Piece* check = nullptr;
	int myx = this->get_x();
	int myy = this->get_y();
	int i = 0;
	int yoffset = 0;

	//if white then can only go up if black then down
	if (get_color() == WHITE) {
		yoffset = 1;
	}
	else {
		yoffset = -1;
	}

	if ((onboard->board[y][x] != nullptr)) {
		//check eating
		if ((y == myy + (1 * yoffset)) && (x == myx + 1)) {
			//if upper right corner of pawn is what the designated pos is and there is not an empty space, means he wants to eat!
			return true;
		}
		else if ((y == myy + (1 * yoffset)) && (x == myx - 1)) {
			//same but opposite corner
			return true;
		}
	}
	else {
		//check movement
		if ((y == myy + (2 * yoffset)) && (x == myx)) {
			return true;
		}
		else if ((y == myy + (1 * yoffset)) && (x == myx)) {
			return true;
		}
		else if ((y == myy) && (x == myx + 1)) {
			return true;
		}
		else if ((y == myy) && (x == myx - 1)) {
			return true;
		}
	}
	
	return false;
}
