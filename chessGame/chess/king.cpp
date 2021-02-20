#include "king.h"

King::King(int y, int x, int color, Board* board) : Piece(y, x, color, KING, board)
{
}

bool King::checkMove(int y, int x)
{
	Board* onboard = _myboard;
	Piece* check = nullptr;
	int myx = this->get_x();
	int myy = this->get_y();
	int i = 0;

	check = onboard->board[y][x];
	if (x == myx + 1 && y == myy) {
			return true;
	}
	else if (x == myx + 1 && y == myy + 1) {
		return true;
	}
	else if (x == myx + 1 && y == myy - 1) {
		return true;
	}
	else if (x == myx - 1 && y == myy) {
		return true;
	}
	else if (x == myx - 1 && y == myy + 1) {
		return true;
	}
	else if (x == myx - 1 && y == myy - 1) {
		return true;
	}
	else if (x == myx && y == myy + 1) {
		return true;
	}
	else if (x == myx && y == myy - 1) {
		return true;
	}

	return false;
}
