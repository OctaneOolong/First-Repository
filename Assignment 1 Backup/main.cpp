#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include<time.h>
#include "TicTacToe.h"
#include "Game.h"

using namespace std;

int main()
{
	srand(time(NULL));
	Game b;
	b.play();
	return 0;
}