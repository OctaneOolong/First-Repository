#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include<time.h>
#include "Game.h"

using namespace std;

Game::Game()
{
	int a = rand() % 1;
		switch (a)
		{ 
		case 0:
			player = 'X';
		case 1:
			player = 'O';
		}
};

void Game::play()
{
	int r, c;

	bool done = false;
	while (done == false)
	{
		board.displayBoard();//void

		if (player == 'X')
		{
		
			getXMove(player, r, c);//void
			done = board.addMove(r, c, player);
		
			player = 'O';
		}
		else
		{
			
			getOMove(player, r, c);
			done = board.addMove(r, c, player);
			
			player = 'X';
		}

	}
}

void Game::getXMove(char player, int& r, int& c)
{
	
	do {
		r = rand() % 3;
		c = rand() % 3;

	} while (board.isValidMove(r, c) == false);

	int rMove = r + 1;
	int cMove = c + 1;

	cout << "Player " << player << " enter move: \n" << rMove << endl << cMove << endl;
	board.board[r][c] = player;
}

void Game::getOMove(char player, int& r, int& c)
{
	do {
		cout << "Player " << player << " enter move: " << endl;
		cin >> r >> c;
		r--;
		c--;
		cout << endl;
	} while (board.isValidMove(r, c) == false);

	board.board[r][c] = player;
}