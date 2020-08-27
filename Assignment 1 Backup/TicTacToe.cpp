#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include<time.h>
#include "TicTacToe.h"

using namespace std;

TicTacToe::TicTacToe()
{
	noOfMoves = 0;
	
	for (int i = 0; i < 3; i++)
	{ 
		for (int j = 0; j < 3; j++)
		{ 
			board[i][j] = ' ';
		}
	}

}

//TicTacToe::fillBoard()
//{
//
//}


void TicTacToe::displayBoard()
{
	cout << "   1    2    3" << endl << endl; //column number display on sideboard 
	for (int r = 0; r < 3; r++)
	{
		cout << r + 1; // row number display on sideboard 
		for (int c = 0; c < 3; c++) 
		{
			cout << setw(3) << board[r][c]; //displays what is stored in char board array 
			if (c != 2)
				cout << " |"; // then displays column divider
		}
		cout << endl;
		if (r != 2)
			cout << " ____|____|____" << endl << "     |    |    " << endl; //displays row dividers 
	}
	cout << endl; // leaves gap between the board and the next line 
}

bool TicTacToe::isValidMove(int r, int c)
{
	if (((r >= 0 && r < 3) && (c >= 0 && c < 3)) && board[r][c] == ' ')
		return true;
	else
		return false;
}

bool TicTacToe::addMove(int r, int c, char player)
{
	status gStatus = gameStatus(player);

	if (gStatus == WIN)
	{
		displayBoard();
		cout << "Player " << player << " wins!" << endl;
		
		return true;
	}

	else if (gStatus == DRAW)
	{
		displayBoard();
		cout << "This game is a draw!" << endl;
		
		return true;
	}

	else
		return false;
}

status TicTacToe::gameStatus(char player)
{
	noOfMoves++;

	if (board[0][0] == player && board[0][1] == player && board[0][2] == player)
		return WIN;
	if (board[1][0] == player && board[1][1] == player && board[1][2] == player)
		return WIN;
	if (board[2][0] == player && board[2][1] == player && board[2][2] == player)
		return WIN;
	// win by cols
	if (board[0][0] == player && board[1][0] == player && board[2][0] == player)
		return WIN;
	if (board[0][1] == player && board[1][1] == player && board[2][1] == player)
		return WIN;
	if (board[0][2] == player && board[1][2] == player && board[2][2] == player)
		return WIN;
	// diagonals
	if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
		return WIN;
	if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
		return WIN;

	if (noOfMoves == 9)
		return DRAW;

	return CONTINUE;
}
