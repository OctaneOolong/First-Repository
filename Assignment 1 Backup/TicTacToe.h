#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include<time.h>

using namespace std;

enum status
{
	WIN, DRAW, CONTINUE
};

class TicTacToe
{
private:
	int noOfMoves;

public:
	char board[3][3];

	TicTacToe();
	bool addMove(int r, int c, char player);
	void displayBoard();
	bool isValidMove(int r, int c);
	status gameStatus(char player);
};