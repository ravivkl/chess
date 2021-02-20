#include "piece.h"
#include <iostream>

Piece::Piece(int y, int x, int color, int type, Board *board)
{
	this->_myboard = board;
	this->_type = type;
	this->_color = color;
	this->_x = x;
	this->_y = y;

	if (this->_myboard->board[this->_y][this->_x] == nullptr) {
		this->_myboard->board[this->_y][this->_x] = this;
	}
}

Piece::~Piece()
{
}

int Piece::get_type()
{
	return this->_type;
}

int Piece::get_color()
{
	return this->_color;
}

void Piece::set_x(int new_x)
{
	this->_x = new_x;
}

void Piece::set_y(int new_y)
{
	this->_y = new_y;
}

int Piece::get_x()
{
	return this->_x;
}

int Piece::get_y()
{
	return this->_y;
}
