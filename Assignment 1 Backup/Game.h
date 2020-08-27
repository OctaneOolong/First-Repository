#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include<time.h>
#include"TicTacToe.h"
#include"NineBoard.h"

using namespace std;

class Game {

public:
	Game();
	void play();
	void getXMove(char player, int&, int&);
	void getOMove(char player, int&, int&);
private:
	TicTacToe board;
	char player;
	
};