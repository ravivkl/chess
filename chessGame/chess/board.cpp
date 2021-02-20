#include "board.h"
#include <iostream>

#define BOARDSIZE 8

Board::Board()
{
}

Board::~Board()
{
	Piece* check = nullptr;
	int i, ii = 0;

	for (i = 0; i < BOARDSIZE; i++) {
		for (ii = 0; ii < BOARDSIZE; ii++) {
			check = board[i][ii];
			if(check != nullptr){
				delete(check);
			}
		}
	}
}

bool Board::movePiece(int py, int px, int y, int x)
{
	int i, ii = 0;


	//check
	Piece* movPiece = board[py][px];

	if (movPiece == nullptr) {
		printf("not a piece!");
		return false;
	}
	if (movPiece->checkMove(y, x)) {
		if (board[y][x] == nullptr) {
			changePosition(py, px, y, x);
			return true;
		}
		else if (movPiece->get_color() != board[y][x]->get_color()) {
			printf("eaten piece!");
			changePosition(py, px, y, x);
			return true;
		}
		else if (movPiece->get_color() == board[y][x]->get_color()) {
			printf("same team!");
		}
	}
	else 
	{
		printf("illegal move!!!"); //debug
	}
	
	return false;

}

void Board::changePosition(int py, int px, int y, int x)
{
	board[y][x] = board[py][px]; //put at new position piece at x,y
    board[py][px] = nullptr; //remove piece from before

	board[y][x]->set_x(x);
	board[y][x]->set_y(y);
}

/*
checking chess
*/
bool Board::checkChess(PieceColor color) const
{
	int i = 0;
	int j = 0;

	for (i = 0; i < BOARDSIZE; i++)
	{
		for (j = 0; j < BOARDSIZE; j++)
		{
			if(this->board[i][j] != nullptr && this->board[i][j]->get_color() != color)
			{
				if (color == PieceColor::BLACK && this->board[i][j]->checkMove(this->_blackKing->get_y(), this->_blackKing->get_x()))
				{
					return true;
				}

				if (color == PieceColor::WHITE && this->board[i][j]->checkMove(this->_whiteKing->get_y(), this->_whiteKing->get_x()))
				{
					return true;
				}
			}
		}
	}
	return false;
}
