#include "stdafx.h"
#include <string>
#include <iostream>
#include "Game.h"
#include "GameSimulator.h"
	
#define BASESEMPTY 0
#define FIRSTONLY 1
#define SECONDONLY 2
#define THIRDONLY 3 
#define FIRSTANDSECOND 4
#define FIRSTANDTHIRD 5
#define SECONDANDTHIRD 6
#define BASESLOADED 7
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

void Game::setUpGame() {
		Game::currentInning = 1;
		curHomeBatter = 0;
		curAwayBatter = 0;
		halfInning = "Top";
		notOver = true;
		awayHits = 0;
		homeHits = 0;
		awayRuns = 0;
		homeRuns = 0;
		awayWalks = 0;
		homeWalks = 0;
		baseSituation = 0;
	}	
void Game::advanceHomeBatter() {
		curHomeBatter++;
		if(curHomeBatter == 9)
			curHomeBatter = 0;
		if(currentInning >= 9 && halfInning == "Bottom" && homeRuns > awayRuns)
			notOver = false;

		// don't enter next inning if (in extra innings) && (away winning in top half) or home is up on away
		if(currentInning > 9 && (((awayRuns > homeRuns) && halfInning == "Top"))) {
			notOver = false;
		}
	}
void Game::advanceAwayBatter() {
		curAwayBatter++;
		if(curAwayBatter == 9)
			curAwayBatter = 0;
		if(currentInning >= 9 && halfInning == "Bottom" && homeRuns > awayRuns)
			notOver = false;
	}
void Game::endGame() {
		notOver = false;
	}	
void Game::flipInning() { 
		if(halfInning == "Top")
		{
			halfInning = "Bottom";
		}
		else {
			halfInning = "Top";
			currentInning++;
		}

		// don't enter the bottom half of the ninth or later if home team is winning
		if(currentInning >= 9 && halfInning == "Bottom" && homeRuns > awayRuns)
			notOver = false;

		// don't enter next inning if (in extra innings) && (away winning in top half) or home is up on away
		if(currentInning > 9 && (((awayRuns > homeRuns) && halfInning == "Top"))) {
			notOver = false;
		}
	}
int Game::processBases(int result) {
		switch(baseSituation) {
		case BASESEMPTY:
			switch(result) {
				case GROUNDOUT:
					baseSituation = BASESEMPTY;
					return 0;
					break;
				case FLYOUT:
					baseSituation = BASESEMPTY;
					return 0;
					break;
				case SINGLE:
					baseSituation = FIRSTONLY;
					return 0;
					break;
				case DOUBLE:
					baseSituation = SECONDONLY;
					return 0;
					break;
				case TRIPLE:
					baseSituation = THIRDONLY;
					return 0;
					break;
				case HOMERUN:
					baseSituation = BASESEMPTY;
					return 1;
					break;
				case GROUNDRULEDOUBLE:
					baseSituation = SECONDONLY;
					return 0;
					break;
				case STRIKEOUT:
					baseSituation = BASESEMPTY;
					return 0;
					break;
				case WALK:
					baseSituation = FIRSTONLY;
					return 0;
					break;
				case HBP: 
					baseSituation = FIRSTONLY;
					return 0;
					break;
				default:
					return 0;
					break;
			}
		case FIRSTONLY:
			switch(result) {
				case GROUNDOUT:
					baseSituation = FIRSTONLY;
					return 0;
					break;
				case FLYOUT:
					baseSituation = FIRSTONLY;
					return 0;
					break;
				case SINGLE:
					baseSituation = FIRSTANDSECOND;
					return 0;
					break;
				case DOUBLE:
					baseSituation = SECONDANDTHIRD;
					return 0;
					break;
				case TRIPLE:
					baseSituation = THIRDONLY;
					return 1;
					break;
				case HOMERUN:
					baseSituation = BASESEMPTY;
					return 2;
					break;
				case GROUNDRULEDOUBLE:
					baseSituation = SECONDANDTHIRD;
					return 0;
					break;
				case STRIKEOUT:
					return 0;
					break;
				case WALK:
					baseSituation = FIRSTANDSECOND;
					return 0;
					break;
				case HBP:
					baseSituation = FIRSTANDSECOND;
					return 0;
					break;
				default:
					return 0;
					break;
			}
		case SECONDONLY:
			switch(result) {
				case GROUNDOUT:
					baseSituation = SECONDONLY;
					return 0;
					break;
				case FLYOUT:
					baseSituation = SECONDONLY;
					return 0;
					break;
				case SINGLE:
					baseSituation = FIRSTANDTHIRD;
					return 0;
					break;
				case DOUBLE:
					baseSituation = SECONDONLY;
					return 1;
					break;
				case TRIPLE:
					baseSituation = THIRDONLY;
					return 1;
					break;
				case HOMERUN:
					baseSituation = BASESEMPTY;
					return 2;
					break;
				case GROUNDRULEDOUBLE:
					baseSituation = SECONDONLY;
					return 1;
					break;
				case STRIKEOUT:
					baseSituation = SECONDONLY;
					return 0;
					break;
				case WALK:
					baseSituation = FIRSTANDSECOND;
					return 0;
					break;
				case HBP:
					baseSituation = FIRSTANDSECOND;
					return 0;
					break;
				default:
					return 0;
					break;
			}
		case THIRDONLY:
			switch(result) {
				case GROUNDOUT:
					baseSituation = THIRDONLY;
					return 0;
					break;
				case FLYOUT:
					baseSituation = BASESEMPTY;
					return 1;						
					break;
				case SINGLE:
					baseSituation = FIRSTONLY;
					return 1;
					break;
				case DOUBLE:
					baseSituation = SECONDONLY;
					return 1;
					break;
				case TRIPLE:
					baseSituation = THIRDONLY;
					return 1;
					break;
				case HOMERUN:
					baseSituation = BASESEMPTY;
					return 2;
					break;
				case GROUNDRULEDOUBLE:
					baseSituation = SECONDONLY;
					return 1;
					break;
				case STRIKEOUT:
					baseSituation = THIRDONLY;
					return 0;
					break;
				case WALK:
					baseSituation = FIRSTANDTHIRD;
					return 0;
					break;
				case HBP:
					baseSituation = FIRSTANDTHIRD;
					return 0;
					break;
				default:
					return 0;
					break;
			}
		case FIRSTANDSECOND:
			switch(result) {
				case GROUNDOUT:
					baseSituation = FIRSTANDSECOND;
					return 0;
					break;
				case FLYOUT:
					baseSituation = FIRSTANDSECOND;
					return 0;
					break;
				case SINGLE:
					baseSituation = BASESLOADED;
					return 0;
					break;
				case DOUBLE:
					baseSituation = SECONDANDTHIRD;
					return 1;
					break;
				case TRIPLE:
					baseSituation = THIRDONLY;
					return 2;
					break;
				case HOMERUN:
					baseSituation = BASESEMPTY;
					return 3;
					break;
				case GROUNDRULEDOUBLE:
					baseSituation = SECONDANDTHIRD;
					return 1;
					break;
				case STRIKEOUT:
					baseSituation = FIRSTANDSECOND;
					return 0;
					break;
				case WALK:
					baseSituation = BASESLOADED;
					return 0;
					break;
				case HBP:
					baseSituation = BASESLOADED;
					return 0;
					break;
				default:
					return 0;
					break;
			}
		case FIRSTANDTHIRD:
			switch(result) {
				case GROUNDOUT:
					baseSituation = FIRSTANDSECOND;
					return 1;
					break;
				case FLYOUT:
					baseSituation = FIRSTONLY;
					return 1;
					break;
				case SINGLE:
					baseSituation = FIRSTANDSECOND;
					return 1;
					break;
				case DOUBLE:
					baseSituation = SECONDANDTHIRD;
					return 1;
					break;
				case TRIPLE:
					baseSituation = THIRDONLY;
					return 2;
					break;
				case HOMERUN:
					baseSituation = BASESEMPTY;
					return 3;
					break;
				case GROUNDRULEDOUBLE:
					baseSituation = SECONDANDTHIRD;
					return 1;
					break;
				case STRIKEOUT:
					baseSituation = FIRSTANDTHIRD;
					return 0;
					break;
				case WALK:
					baseSituation = BASESLOADED;
					return 0;
					break;
				case HBP:
					baseSituation = BASESLOADED;
					return 0;
					break;
				default:
					return 0;
					break;
			}
		case SECONDANDTHIRD:
			switch(result) {
				case GROUNDOUT:
					baseSituation = FIRSTANDTHIRD;
					return 1;
					break;
				case FLYOUT:
					baseSituation = FIRSTANDTHIRD;
					return 1;
					break;
				case SINGLE:
					baseSituation = FIRSTANDTHIRD;
					return 1;
					break;
				case DOUBLE:
					baseSituation = SECONDONLY;
					return 2;
					break;
				case TRIPLE:
					baseSituation = THIRDONLY;
					return 2;
					break;
				case HOMERUN:
					baseSituation = BASESEMPTY;
					return 3;
					break;
				case GROUNDRULEDOUBLE:
					baseSituation = SECONDONLY;
					return 2;
					break;
				case STRIKEOUT:
					baseSituation = SECONDANDTHIRD;
					return 0;
					break;
				case WALK:
					baseSituation = BASESLOADED;
					return 0;
					break;
				case HBP:
					baseSituation = BASESLOADED;
					return 0;
					break;
				default:
					return 0;
					break;
			}
		case BASESLOADED:
			switch(result) {
				case GROUNDOUT:
					baseSituation = BASESLOADED;
					return 0;
					break;
				case FLYOUT:
					baseSituation = FIRSTANDSECOND;
					return 1;
					break;
				case SINGLE:
					baseSituation = BASESLOADED;
					return 1;
					break;
				case DOUBLE:
					baseSituation = SECONDANDTHIRD;
					return 2;
					break;
				case TRIPLE:
					baseSituation = THIRDONLY;
					return 3;
					break;
				case HOMERUN:
					baseSituation = BASESEMPTY;
					return 4;
					break;
				case GROUNDRULEDOUBLE:
					baseSituation = SECONDANDTHIRD;
					return 2;
					break;
				case STRIKEOUT:
					baseSituation = BASESLOADED;
					return 0;
					break;
				case WALK:
					baseSituation = BASESLOADED;
					return 1;
					break;
				case HBP:
					baseSituation = BASESLOADED;
					return 1;
					break;
				default:
					return 0;
					break;
			}
		default:
			return 0;
	}
}
void Game::printBasesStatus(int curOuts) {
	switch(baseSituation) {	
		case BASESEMPTY:
			break;
		case FIRSTONLY:
			std::cout << "** MAN ON FIRST, " << curOuts << " OUT **" << std::endl << std::endl;
			break;
		case SECONDONLY:
			std::cout << "** MAN ON SECOND, " << curOuts << " OUT **" << std::endl << std::endl;
			break;
		case THIRDONLY:
			std::cout << "** MAN ON THIRD, " << curOuts << " OUT **" << std::endl << std::endl;
			break;
		case FIRSTANDSECOND:
			std::cout << "** MEN ON FIRST AND SECOND, " << curOuts << " OUT **" << std::endl << std::endl;
			break;
		case FIRSTANDTHIRD:
			std::cout << "** MEN ON FIRST AND THIRD, " << curOuts << " OUT **" << std::endl << std::endl;
			break;
		case SECONDANDTHIRD:
			std::cout << "** MEN ON SECOND AND THIRD, " << curOuts << " OUT **" << std::endl << std::endl;
			break;
		case BASESLOADED:
			std::cout << "** BASES LOADED, " << curOuts << " OUT **" << std::endl << std::endl;
			break;
		default:
			std::cout << "Error, some weird base situation has arisen. :(" << std::endl << std::endl;
			break;
	}
}