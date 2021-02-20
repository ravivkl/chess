#include "bishop.h"

Bishop::Bishop(int y, int x, int color, Board* board) : Piece(y, x, color, BISHOP, board)
{
}

bool Bishop::checkMove(int y, int x)
{
	Board* onboard = _myboard;
	Piece* check = nullptr;
	int myx = this->get_x();
	int myy = this->get_y();
	int i = 0;
	int yoffset = 0;

	if (abs(myy - y) == abs(myx - x)) { //if move is an X
		if (y > myy) yoffset = 1; else yoffset = -1; //if going up, change rate to 1, if going down change rate to -1

		if (x > myx) {
			for (i = 1; i <= (x - myx) - 1; i++) {
				check = onboard->board[myy + (i * yoffset)][myx + i];
				if (check != nullptr) {
					return false;
				}
			}
			return true;
		}
		else if (x < myx) {
			for (i = 1; i <= (myx - x) - 1; i++) {
				check = onboard->board[myy + (i * yoffset)][myx - i];
				printf("[%d, %d]", myy + (i * yoffset), myx - i);
				if (check != nullptr) {
					return false;
				}
			}
			return true;
		}
	}

	return false; //illegal move
}
