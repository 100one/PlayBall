#include "stdafx.h"
#include "Game.h"
#include <iostream>
#include <array>
#include <string>
#include <time.h>

#define LEFT 0
#define RIGHT 1
#define GROUNDOUT 0
#define FLYOUT 1
#define SINGLE 2
#define DOUBLE 3
#define TRIPLE 4
#define HOMERUN 5
#define GROUNDRULEDOUBLE 6
#define STRIKEOUT 7
#define WALK 8
#define HBP 9

#define CON 240

using namespace std;
	Game curGame;

int _tmain(int argc, _TCHAR* argv[])
{
	curGame.setUpGame("team1", "team2");
	curGame.startGame();
	system("pause");
	return 0;
}