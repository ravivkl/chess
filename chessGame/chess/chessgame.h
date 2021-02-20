#pragma once
#include "board.h"
#include "piece.h"

#include "bishop.h"
#include "queen.h"
#include "pawn.h"
#include "king.h"
#include "knight.h"
#include "rook.h"
#include <stack>

enum returnCode 
{
	VALID_MOVE, VALID_MOVE_MADE_CHESS, INVALID_MOVE_NONE_PICE, INVALID_MOVE_PICE_IN_DESTANITION, 
	INVALID_MOVE_MADE_YOUROWN_CHESS, INVALID_MOVE_WRONG_INDEXES, INVALID_MOVE_WRONG_MOVE, INVALID_MOVE_SAME_PLACE, VALID_MOVE_CHECK_MATE
};

class ChessGame
{
private:
	Board* _chessboard;
	PieceColor _playerColor;

public:
	ChessGame(bool initboard);
	~ChessGame();

	void printBoard();
	std::string getBoardString();

	char getCharPiece(int color, int type);
	returnCode movePiece(int py, int px, int y, int x);
};