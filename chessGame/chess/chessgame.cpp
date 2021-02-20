#include "chessgame.h"

#define ONE 1
#define TWO 2
#define THREE 3
#define FOUR 4
#define FIVE 5
#define SIX 6
#define SEVEN 7
#define EIGHT 8
#define NINE 9


ChessGame::ChessGame(bool initboard):
	_chessboard(new Board()), _playerColor(PieceColor::WHITE)
{
	int color, height;
	int i = 0;

	//init chess board
	//white and black pawn setup
	if (initboard) {
		for (i = 0; i < BOARDSIZE; i++) {
			_chessboard->board[1][i] = new Pawn(1, i, WHITE, _chessboard);
			_chessboard->board[SIX][i] = new Pawn(SIX, i, BLACK, _chessboard);
		}

		color = WHITE;
		height = 0;

		for (i = 0; i < 2; i++) {
			_chessboard->board[height][0] = new Rook(height, 0, color, _chessboard);
			_chessboard->board[height][ONE] = new Knight(height, ONE, color, _chessboard);
			_chessboard->board[height][TWO] = new Bishop(height, TWO, color, _chessboard);
			_chessboard->board[height][THREE] = new Queen(height, THREE, color, _chessboard);
			_chessboard->board[height][FIVE] = new Bishop(height, FIVE, color, _chessboard);
			_chessboard->board[height][SIX] = new Knight(height, SIX, color, _chessboard);
			_chessboard->board[height][SEVEN] = new Rook(height, SEVEN, color, _chessboard);
			color = BLACK;
			height = SEVEN;
		}
		_chessboard->_whiteKing = new King(height, FOUR, WHITE, _chessboard);
		_chessboard->board[0][FOUR] = _chessboard->_whiteKing;//new King(0, FOUR, color, _chessboard);
		_chessboard->_blackKing = new King(height, FOUR, BLACK, _chessboard);
		_chessboard->board[SEVEN][FOUR] = _chessboard->_blackKing;  //new King(SEVEN, FOUR, color, _chessboard);
	}
	
}

ChessGame::~ChessGame()
{
	delete _chessboard;
}

void ChessGame::printBoard()
{
	int i = 0;
	int ii = 0;

	int piecetype = 0;
	int piececolor = 0;

	printf("\n\nSTART OF PRINT BOARD\n");

	for (ii = BOARDSIZE - 1; ii >= 0; ii--) {
		printf("[%d]", ii + 1);
		for (i = 0; i < BOARDSIZE; i++) {
			printf("%3c", NULL);
			if (_chessboard->board[ii][i] == nullptr) {
				printf("#");
			}
			else { //if not empty print something
				piecetype = _chessboard->board[ii][i]->get_type();
				piececolor = _chessboard->board[ii][i]->get_color();

				printf("%c", getCharPiece(piececolor, piecetype));
			}
		}
		printf("\n");
	}
	printf("     [A] [B] [C] [D] [E] [F] [G] [H]\n");
	printf("END OF PRINT BOARD\n\n");
}


std::string ChessGame::getBoardString()
{
	std::string BoardStr = "";
	Piece* check = nullptr;
	int i, ii = 0;

	for (i = 0; i < BOARDSIZE; i++) {
		for (ii = 0; ii < BOARDSIZE; ii++) {
			check = _chessboard->board[i][ii];
			if (check == nullptr) {
				BoardStr += "#";
			}
			else {
				BoardStr += getCharPiece(check->get_color(), check->get_type());
			}
		}
	}

	return BoardStr;
}

char ChessGame::getCharPiece(int color, int type)
{
	switch (color)
	{
	case WHITE:
		switch (type)
		{
		case PieceType(KING):		return 'K'; 	break;
		case PieceType(QUEEN):		return 'Q'; 	break;
		case PieceType(ROOK):	    return 'R'; 	break;
		case PieceType(KNIGHT):		return 'N'; 	break;
		case PieceType(BISHOP):		return 'B'; 	break;
		case PieceType(PAWN):		return 'P'; 	break;
		}
		break;
	case BLACK:
		switch (type)
		{
		case PieceType(KING):		return 'k';		break;
		case PieceType(QUEEN):		return 'q';		break;
		case PieceType(ROOK):		return 'r';		break;
		case PieceType(KNIGHT):		return 'n';		break;
		case PieceType(BISHOP):		return 'b';		break;
		case PieceType(PAWN):		return 'p';		break;
		}
		break;
	}
}

returnCode ChessGame::movePiece(int py, int px, int y, int x)
{
	 std::stack<const Board> s = std::stack<const Board>();
	 if (x < 0 || y < 0 || px < 0 || py < 0 || x>= BOARDSIZE || y >= BOARDSIZE || px >= BOARDSIZE|| py >= BOARDSIZE)
	 {
		 return returnCode::INVALID_MOVE_WRONG_INDEXES;
	 }
	 if(this->_chessboard->board[py][px] == nullptr || this->_chessboard->board[py][px]->get_color() != this->_playerColor)
	 {
		 return returnCode::INVALID_MOVE_NONE_PICE;
	 }
	 if (px == x && py == y)
	 {
		 return returnCode::INVALID_MOVE_SAME_PLACE;
	 }
	 if (this->_chessboard->board[y][x] != nullptr || this->_chessboard->board[y][x]->get_color() != this->_playerColor)
	 {
		 return returnCode::INVALID_MOVE_PICE_IN_DESTANITION;
	 }
	 s.push(*this->_chessboard);
	 if (!(_chessboard->movePiece(py, px, y, x)))
	 {
		 return returnCode::INVALID_MOVE_WRONG_MOVE;
	 }
	 if (this->_chessboard->checkChess(_playerColor))
	 {
		 this->_chessboard = s.pop;
		 return returnCode::INVALID_MOVE_MADE_YOUROWN_CHESS;
	 }
	 if (this->_chessboard->checkChess(this->_playerColor == PieceColor::WHITE?PieceColor::BLACK:PieceColor::WHITE))
	 {
		 return returnCode::VALID_MOVE_MADE_CHESS;
	 }
	 return returnCode::VALID_MOVE;
}
