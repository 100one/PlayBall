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
	bool exitProgram = false;
	int choice = 0;
	cout << "                      ____  __               ____        ____" << endl;
	cout << "                     / __ \\/ /___ ___  __   / __ )____ _/ / /" << endl;
	cout << "                    / /_/ / / __ `/ / / /  / __  / __ `/ / / " << endl;
	cout << "                   / ____/ / /_/ / /_/ /  / /_/ / /_/ / / /  " << endl;
	cout << "                  /_/   /_/\\__,_/\\__, /  /_____/\\__,_/_/_/  " << endl; 
    cout << "                                /____/                       	" << endl;
	cout << "                  by Ryan Fox" << endl << endl;
	cout << "Welcome to Play Ball! Please select an option from the menu below." << endl << endl;
			cout << "===============================================================" << endl << endl;

	while(!exitProgram) {
		cout << "1. New Exhibition" << endl;
		cout << "2. Load Exhibition" << endl;
		cout << "3. New Series" << endl;
		cout << "4. Load Series" << endl;
		cout << "5. Settings" << endl;
		cout << "6. Exit Game" << endl << endl;
		cin >> choice;
		cout << endl;
		switch(choice) {
			case 1:
				cout << "===============================================================" << endl << endl;
				cout << "Starting exhibition game!" << endl << endl;
				curGame.setUpGame("BAL", "NYY");
				break;
			case 6:
				exitProgram = true;
				break;
			default:
				cout << "Not a valid selection! Please enter a number 1-5 to indicate your selection." << endl << endl;
				break;
		}
				cout << "===============================================================" << endl << endl;

	}
	return 0;
}