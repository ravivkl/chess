#include <iostream>
#include "chessgame.h"

int main()
{
	ChessGame *mychess = new ChessGame(true);
	std::string strboard =  mychess->getBoardString();
	int py = 0;
	int px = 0;
	int y = 0;
	int x = 0;
	std::cout << strboard << std::endl;

	while (1 == 1) {
		mychess->printBoard();

		printf("enter cords: ");
		std::cin >> py;
		std::cin >> px;
		std::cin >> y;
		std::cin >> x;
		if (py == 99) {
			goto end;
		}
		mychess->movePiece(py, px, y, x);
	}
	end:
	delete(mychess);

	getchar();
	return 0;
}