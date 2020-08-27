#pragma once
#include "TicTacToe.h"
struct BoardCoordinate
{
	int r;
	int c;

};

class NineBoard
{

private:
	NineBoard();
	TicTacToe board[3][3];
	BoardCoordinate currentBoard;
};