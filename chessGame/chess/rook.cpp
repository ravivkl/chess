#include "rook.h"

Rook::Rook(int y, int x, int color, Board* board) : Piece(y, x, color, ROOK, board)
{
}

bool Rook::checkMove(int y, int x)
{
	Board* onboard = _myboard;
	Piece* check = nullptr;
	int myx = this->get_x();
	int myy = this->get_y();
	int i = 0;

	if (myy < y && myx == x) { //go up
		for (i = myy + 1; i < y; i++) {
			check = onboard->board[i][x];
			if (check != nullptr) {
				return false;
			}
		}
		return true;
	}
	else if(myy > y && myx == x) { //go down
		for (i = myy - 1; i > y; i--) {
			check = onboard->board[i][x];
			if (check != nullptr) {
				return false;
			}
		}
		return true;
	}
	else if(myx < x && myy == y) { //go right
		for (i = myx + 1; i < x; i++) {
			check = onboard->board[y][i];
			if (check != nullptr) {
				return false;
			}
		}
		return true;
	}
	else if (myx > x && myy == y) { //go left
		for (i = myx - 1; i > x; i--) {
			check = onboard->board[y][i];
			if (check != nullptr) {
				return false;
			}
		}
		return true;
	}

	return false; //illegal move
}
