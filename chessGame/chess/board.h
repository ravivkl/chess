#pragma once
#include "piece.h"
#include <string>

#define BOARDSIZE 8

class Piece;

class Board
{
public:
	Piece* board[BOARDSIZE][BOARDSIZE] = { nullptr }; //board of pieces
	Piece* _blackKing;
	Piece* _whiteKing;

	Board();
	~Board();

	bool movePiece(int py, int px, int y, int x);
	void changePosition(int py, int px, int y, int x);
	bool checkChess(PieceColor color) const;
};