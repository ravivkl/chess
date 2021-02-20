/*
This file servers as an example of how to use Pipe.h file.
It is recommended to use the following code in your project, 
in order to read and write information from and to the Backend
*/


#include "Pipe.h"
#include <iostream>
#include <thread>
#include "chessgame.h"

#define BOARDFIRSTSTATE "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR1"

using std::cout;
using std::endl;
using std::string;


int main()
{
	ChessGame game = game;
	Pipe p;
	bool isConnect = p.connect();
	
	string ans;
	string dst = "  ";
	string src = "  ";
	while (!isConnect)
	{
		cout << "cant connect to graphics" << endl;
		cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
		std::cin >> ans;

		if (ans == "0")
		{
			cout << "trying connect again.." << endl;
			Sleep(5000);
			isConnect = p.connect();
		}
		else 
		{
			p.close();
			return 0;
		}
	}
	
	char msgToGraphics[1024];
	// msgToGraphics should contain the board string accord the protocol
	// YOUR CODE

	strcpy_s(msgToGraphics, BOARDFIRSTSTATE); // just example...
	
	p.send_message_to_graphics(msgToGraphics);   // send the board string

	// get message from graphics
	string msgFromGraphics = p.get_message_from_graphics();


	while (msgFromGraphics != "quit")
	{
		dst = msgFromGraphics.substr(2, 2);
		src = msgFromGraphics.substr(0, 2);
		// according the protocol. Ex: e2e4           (move e2 to e4)
		ans = "" + game.movePiece('8' - src[1], src[0] - 'a', '8' - dst[1], dst[0] - 'a');
		
		strcpy_s(msgToGraphics, ans.c_str()); // msgToGraphics should contain the result of the operation

		// return result to graphics		
		p.send_message_to_graphics(msgToGraphics);

		// get message from graphics
		msgFromGraphics = p.get_message_from_graphics();
	}

	p.close();
	return 0;
}
