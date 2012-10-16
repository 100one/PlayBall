#include "stdafx.h"
#include <string>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include "Game.h"

#define LEFT 0
#define RIGHT 1

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
#define CON 240

using namespace std;

void Game::setUpGame(string awayTeam, string homeTeam) {
		awayTeamName = awayTeam;
		homeTeamName = homeTeam;
		currentInning = 1;
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
		startGame();
}	
void Game::setAwayTeam() {
	// batters
	awayTeam[0].name = "N. McClouth";
	awayTeam[0].battingAvg = .278;
	awayTeam[0].plateAwareness = 85;
	awayTeam[0].conR = .289*CON;
	awayTeam[0].conL = .217*CON;
	awayTeam[0].powL = 85;
	awayTeam[0].powR = 85;
	awayTeam[0].handedness = LEFT;
	awayTeam[1].name = "J. Hardy";
	awayTeam[1].battingAvg = .238;
	awayTeam[1].plateAwareness = 85;
	awayTeam[1].conR = .225*CON;
	awayTeam[1].conL = .277*CON;
	awayTeam[1].powL = 85;
	awayTeam[1].powR = 85;
	awayTeam[1].handedness = RIGHT;
	awayTeam[2].name = "C. Davis";
	awayTeam[2].battingAvg = .270;
	awayTeam[2].plateAwareness = 85;
	awayTeam[2].conR = .271*CON;
	awayTeam[2].conL = .265*CON;
	awayTeam[2].powL = 85;
	awayTeam[2].powR = 85;
	awayTeam[2].handedness = LEFT;
	awayTeam[3].name = "A. Jones";
	awayTeam[3].battingAvg = .287;
	awayTeam[3].plateAwareness = 85;
	awayTeam[3].conR = .285*CON;
	awayTeam[3].conL = .292*CON;
	awayTeam[3].powL = 85;
	awayTeam[3].powR = 85;
	awayTeam[3].handedness = RIGHT;
	awayTeam[4].name = "M. Wieters";
	awayTeam[4].battingAvg = .238;
	awayTeam[4].plateAwareness = 85;
	awayTeam[4].conR = .224*CON;
	awayTeam[4].conL = .323*CON;
	awayTeam[4].powL = 85;
	awayTeam[4].powR = 85;
	awayTeam[4].handedness = RIGHT;
	awayTeam[5].name = "J. Thome";
	awayTeam[5].battingAvg = .257;
	awayTeam[5].plateAwareness = 85;
	awayTeam[5].conR = .269*CON;
	awayTeam[5].conL = .125*CON;
	awayTeam[5].powL = 85;
	awayTeam[5].powR = 85;
	awayTeam[5].handedness = 85;
	awayTeam[6].name = "M. Reynolds";
	awayTeam[6].battingAvg = .221;
	awayTeam[6].plateAwareness = 85;
	awayTeam[6].conR = .219*CON;
	awayTeam[6].conL = .227*CON;
	awayTeam[6].powL = 85;
	awayTeam[6].powR = 85;
	awayTeam[6].handedness = RIGHT;
	awayTeam[7].name = "R. Flaherty";
	awayTeam[7].battingAvg = .216;
	awayTeam[7].plateAwareness = 85;
	awayTeam[7].conR = .213*CON;
	awayTeam[7].conL = .250*CON;
	awayTeam[7].powL = 85;
	awayTeam[7].powR = 85;
	awayTeam[7].handedness = LEFT;
	// actually M. Machado
	awayTeam[8].name = "N. Kane";
	awayTeam[8].battingAvg = .262;
	awayTeam[8].plateAwareness = 85;
	awayTeam[8].conR = .255*CON;
	awayTeam[8].conL = .280*CON;
	awayTeam[8].powL = 85;
	awayTeam[8].powR = 85;
	awayTeam[8].handedness = RIGHT;

	// pitchers
	awayPitchers[0].name = "J. Hammell";
	awayPitchers[0].allowedBattingAvg = .234;
	awayPitchers[0].handedness = RIGHT;
	awayPitchers[0].composure = 80;
	awayPitchers[0].stamina = 82;
	awayPitchers[0].control = 86;
	awayPitchers[0].pConL = 80;
	awayPitchers[0].pConR = 80;
	awayPitchers[0].kAbility = 80;
	awayPitchers[1].name = "W. Chen";
	awayPitchers[1].allowedBattingAvg = .234;
	awayPitchers[1].handedness = RIGHT;
	awayPitchers[1].composure = 80;
	awayPitchers[1].stamina = 82;
	awayPitchers[1].control = 86;
	awayPitchers[1].pConL = 80;
	awayPitchers[1].pConR = 80;
	awayPitchers[1].kAbility = 80;
	awayPitchers[2].name = "C. Tillman";
	awayPitchers[2].allowedBattingAvg = .234;
	awayPitchers[2].handedness = RIGHT;
	awayPitchers[2].composure = 80;
	awayPitchers[2].stamina = 82;
	awayPitchers[2].control = 86;
	awayPitchers[2].pConL = 80;
	awayPitchers[2].pConR = 80;
	awayPitchers[2].kAbility = 80;
	awayPitchers[3].name = "M. Gonzalez";
	awayPitchers[3].allowedBattingAvg = .234;
	awayPitchers[3].handedness = RIGHT;
	awayPitchers[3].composure = 80;
	awayPitchers[3].stamina = 82;
	awayPitchers[3].control = 86;
	awayPitchers[3].pConL = 80;
	awayPitchers[3].pConR = 80;
	awayPitchers[3].kAbility = 80;
	awayPitchers[4].name = "J. Saunders";
	awayPitchers[4].allowedBattingAvg = .234;
	awayPitchers[4].handedness = RIGHT;
	awayPitchers[4].composure = 80;
	awayPitchers[4].stamina = 82;
	awayPitchers[4].control = 86;
	awayPitchers[4].pConL = 80;
	awayPitchers[4].pConR = 80;
	awayPitchers[4].kAbility = 80;
	awayPitchers[5].name = "B. 'The Bad' Salmon";
	awayPitchers[5].allowedBattingAvg = .234;
	awayPitchers[5].handedness = RIGHT;
	awayPitchers[5].composure = 80;
	awayPitchers[5].stamina = 80;
	awayPitchers[5].control = 82;
	awayPitchers[5].pConL = 70;
	awayPitchers[5].pConR = 70;
	awayPitchers[5].kAbility = 75;
}
void Game::setHomeTeam() {
	// batters
	homeTeam[0].name = "D. Jeter";
	homeTeam[0].battingAvg = .364;
	homeTeam[0].plateAwareness = 85;
	homeTeam[0].conR = .294*CON;
	homeTeam[0].conL = .364*CON;
	homeTeam[0].powR = 85;
	homeTeam[0].powL = 85;
	homeTeam[0].handedness = LEFT;
	homeTeam[1].name = "I. Suzuki";
	homeTeam[1].battingAvg = .322;
	homeTeam[1].plateAwareness = 85;
	homeTeam[1].conR = .289*CON;
	homeTeam[1].conL = .397*CON;
	homeTeam[1].powR = 85;
	homeTeam[1].powL = 85;
	homeTeam[1].handedness = LEFT;
	homeTeam[2].name = "M. Teixeira";
	homeTeam[2].battingAvg = .251;
	homeTeam[2].plateAwareness = 85;
	homeTeam[2].conR = .239*CON;
	homeTeam[2].conL = .269*CON;
	homeTeam[2].powR = 85;
	homeTeam[2].powL = 85;
	homeTeam[2].handedness = RIGHT;
	homeTeam[3].name = "R. Cano";
	homeTeam[3].battingAvg = .313;
	homeTeam[3].plateAwareness = 85;
	homeTeam[3].conR = .359*CON;
	homeTeam[3].conL = .239*CON;
	homeTeam[3].powR = 85;
	homeTeam[3].powL = 85;
	homeTeam[3].handedness = LEFT;
	homeTeam[4].name = "A. Rodriguez";
	homeTeam[4].battingAvg = .272;
	homeTeam[4].plateAwareness = 85;
	homeTeam[4].conR = .256*CON;
	homeTeam[4].conL = .308*CON;
	homeTeam[4].powR = 85;
	homeTeam[4].powL = 85;
	homeTeam[4].handedness = RIGHT;
	homeTeam[5].name = "N. Swisher";
	homeTeam[5].battingAvg = .272;
	homeTeam[5].plateAwareness = 85;
	homeTeam[5].conR = .273*CON;
	homeTeam[5].conL = .270*CON;
	homeTeam[5].powR = 85;
	homeTeam[5].powL = 85;
	homeTeam[5].handedness = RIGHT;
	homeTeam[6].name = "R. Martin";
	homeTeam[6].battingAvg = .211;
	homeTeam[6].conR = .205*CON;
	homeTeam[6].conL = .226*CON;
	homeTeam[6].powR = 85;
	homeTeam[6].powL = 85;
	homeTeam[6].plateAwareness = 85;
	homeTeam[6].handedness = RIGHT;
	homeTeam[7].name = "C. Granderson";
	homeTeam[7].battingAvg = .232;
	homeTeam[7].plateAwareness = 85;
	homeTeam[7].conR = .239*CON;
	homeTeam[7].conL = .218*CON;
	homeTeam[7].powR = 85;
	homeTeam[7].powL = 85;
	homeTeam[7].handedness = LEFT;
	// homeTeam[8].name = "J. Nix";
	// homeTeam[8].battingAvg = .243;
	// homeTeam[8].conR = .228*CON;
	// homeTeam[8].conL = .255*CON;
	// homeTeam[8].powR = 85;
	// homeTeam[8].powL = 85;
	// homeTeam[0].handedness = 85;
	homeTeam[8].name = "K. Varga";
	homeTeam[8].plateAwareness = 90;
	homeTeam[8].conR = .785*CON;
	homeTeam[8].conL = .857*CON;
	homeTeam[8].powR = 85;
	homeTeam[8].powL = 85;
	homeTeam[8].handedness = RIGHT;

	// pitchers
	homePitchers[0].name = "C. Sabathia";
	homePitchers[0].kAbility = 92;
	homePitchers[0].allowedBattingAvg = .238;
	homePitchers[0].composure = 100;
	homePitchers[0].handedness = LEFT;
	homePitchers[0].stamina = 100;
	homePitchers[0].control = 92;
	homePitchers[0].pConL = 90;
	homePitchers[0].pConR = 95;
	homePitchers[1].name = "H. Kuroda";
	homePitchers[1].kAbility = 92;
	homePitchers[1].allowedBattingAvg = .238;
	homePitchers[1].composure = 100;
	homePitchers[1].handedness = LEFT;
	homePitchers[1].stamina = 100;
	homePitchers[1].control = 92;
	homePitchers[1].pConL = 90;
	homePitchers[1].pConR = 95;
	homePitchers[2].name = "A. Pettitte";
	homePitchers[2].kAbility = 92;
	homePitchers[2].allowedBattingAvg = .238;
	homePitchers[2].composure = 100;
	homePitchers[2].handedness = LEFT;
	homePitchers[2].stamina = 100;
	homePitchers[2].control = 92;
	homePitchers[2].pConL = 90;
	homePitchers[2].pConR = 95;
	homePitchers[3].name = "P. Hughes";
	homePitchers[3].kAbility = 92;
	homePitchers[3].allowedBattingAvg = .238;
	homePitchers[3].composure = 100;
	homePitchers[3].handedness = LEFT;
	homePitchers[3].stamina = 100;
	homePitchers[3].control = 92;
	homePitchers[3].pConL = 90;
	homePitchers[3].pConR = 95;
	homePitchers[4].name = "I. Nova";
	homePitchers[4].kAbility = 92;
	homePitchers[4].allowedBattingAvg = .238;
	homePitchers[4].composure = 100;
	homePitchers[4].handedness = LEFT;
	homePitchers[4].stamina = 100;
	homePitchers[4].control = 92;
	homePitchers[4].pConL = 90;
	homePitchers[4].pConR = 95;
	homePitchers[5].name = "G. Seppala";
	homePitchers[5].kAbility = 100;
	homePitchers[5].allowedBattingAvg = .238;
	homePitchers[5].composure = 100;
	homePitchers[5].handedness = LEFT;
	homePitchers[5].stamina = 100;
	homePitchers[5].control = 100;
	homePitchers[5].pConL = 100;
	homePitchers[5].pConR = 100;
}
void Game::playBall() {
	while(notOver) {
		std::cout << "**************** " << halfInning << " " << currentInning << ", AWAY: " << awayRuns << ", HOME: " << homeRuns << " ****************" << std::endl << std::endl;
		while(sim.curOuts < 3 && notOver) {
			if(halfInning == "Top") {
				std::cout << "Now batting: " << awayTeam[curAwayBatter].name << std::endl;
				int result = sim.simulateAtBat(homePitchers[homeStartPitcher], awayTeam[curAwayBatter]);
				int runsScoredOnPlay = processBases(result); 
				awayTeam[curAwayBatter].gRBI+=runsScoredOnPlay;
				if(sim.curOuts!=3) {
					awayRuns+=runsScoredOnPlay;
					if(runsScoredOnPlay != 0)
						std::cout << "** " << runsScoredOnPlay << " run(s) scored on play! **" << std::endl << std::endl;
					printBasesStatus(sim.curOuts);
				}
				if(result == GROUNDOUT) {
				}
				else if(result == STRIKEOUT) {
					homePitchers[homeStartPitcher].gPStrikeouts++;
					awayTeam[curAwayBatter].gStrikeouts++;
				}
				else if(result == FLYOUT) {
				}
				else if(result == WALK) {
					awayTeam[curAwayBatter].gWalks++;
					awayWalks++;
					homeTeam[homeStartPitcher].gPWalks++;
				}
				else if(result == SINGLE) {
					awayTeam[curAwayBatter].gHits++;
					awayHits++;
					homeTeam[homeStartPitcher].gPHits++;
				}
				else if(result == DOUBLE) {
					awayTeam[curAwayBatter].gHits++;
					awayHits++;
					homeTeam[homeStartPitcher].gPHits++;
				}
				else if(result == TRIPLE) {
					awayTeam[curAwayBatter].gHits++;
					awayHits++;
					homeTeam[homeStartPitcher].gPHits++;
				}
				else if(result == HOMERUN) {
					awayTeam[curAwayBatter].gHits++;
					awayHits++;
					homeTeam[homeStartPitcher].gPHits++;
				}
				else if(result == GROUNDRULEDOUBLE) {
					awayTeam[curAwayBatter].gHits++;
					awayHits++;
					homeTeam[homeStartPitcher].gPHits++;
				}
				if(result!=WALK)
					awayTeam[curAwayBatter].gAtBats++;
				advanceAwayBatter();
			}
			else {
				std::cout << "Current batter: " << homeTeam[curHomeBatter].name << std::endl;
				int result = sim.simulateAtBat(awayPitchers[awayStartPitcher], homeTeam[curHomeBatter]);
				int runsScoredOnPlay = processBases(result); 
				homeTeam[curHomeBatter].gRBI+=runsScoredOnPlay;
				if(sim.curOuts!=3) {
					homeRuns+=runsScoredOnPlay;
					if(runsScoredOnPlay != 0)
						std::cout << "** " << runsScoredOnPlay << " runs scored on play! **" << std::endl << std::endl;
					printBasesStatus(sim.curOuts);
				}
				if(result == GROUNDOUT) {
				}
				else if(result == STRIKEOUT) {
					awayPitchers[awayStartPitcher].gPStrikeouts++;
					homeTeam[curHomeBatter].gStrikeouts++;
				}
				else if(result == FLYOUT) {
				}
				else if(result == WALK) {
					homeTeam[curHomeBatter].gWalks++;
					homeWalks++;
					awayTeam[awayStartPitcher].gPWalks++;
				}
				else if(result == SINGLE) {
					homeTeam[curHomeBatter].gHits++;
					homeHits++;
					awayTeam[awayStartPitcher].gPHits++;
				}
				else if(result == DOUBLE) {
					homeTeam[curHomeBatter].gHits++;
					homeHits++;
					awayTeam[awayStartPitcher].gPHits++;
				}
				else if(result == TRIPLE) {
					homeTeam[curHomeBatter].gHits++;
					homeHits++;
					awayTeam[awayStartPitcher].gPHits++;
				}
				else if(result == HOMERUN) {
					homeTeam[curHomeBatter].gHits++;
					homeTeam[curHomeBatter].gHomeRuns++;
					homeHits++;
					awayTeam[awayStartPitcher].gPHits++;
				}
				else if(result == GROUNDRULEDOUBLE) {
					homeTeam[curHomeBatter].gHits++;
					homeHits++;
					awayTeam[awayStartPitcher].gPHits++;
				}
				homeTeam[curHomeBatter].gAtBats++;
				advanceHomeBatter();
			}
		}
		if(halfInning == "Top")
			homePitchers[homeStartPitcher].gInningsPitched++;
		else
			awayPitchers[awayStartPitcher].gInningsPitched++;
		if(currentInning >= 9 && halfInning == "Bottom" && homeRuns > awayRuns) {
				std::cout << "***************** WALK OFF WIN! THE HOME TEAM WINS! *****************" << std::endl << std::endl;
				notOver = false;
		}
		flipInning();
		baseSituation = 0;
		sim.curOuts = 0;
		}
	endGame();
}
void Game::startGame() {
	awayStartPitcher = 0;
	homeStartPitcher = 0;

	srand((unsigned)time(NULL));
	setAwayTeam();
	setHomeTeam();
	std::cout << "Please select one of the following pitchers for " << awayTeamName << ":" << std::endl << std::endl;
	
		for(int x = 0; x < 6; x++) {
		std::cout << x+1 << ". " << awayPitchers[x].name << std::endl;
	}
	std::cout << std::endl;
	std::cin >> awayStartPitcher;
	awayStartPitcher--;

	std::cout << std::endl << "******************************" << std::endl << std::endl << "You have chosen '" << awayPitchers[awayStartPitcher].name << "' as the starting pitcher for " << awayTeamName << "." << std::endl << std::endl;
	std::cout << "Please select one of the following pitchers for the home team, " << homeTeamName << ":" << std::endl << std::endl;
	
	for(int x = 0; x < 6; x++) {
		std::cout << x+1 << ". " << homePitchers[x].name << std::endl;
	}
	std::cout << std::endl;
	std::cin >> homeStartPitcher;
	homeStartPitcher--;
	std::cout << std::endl << "******************************" << std::endl << std::endl << "You have chosen '" << homePitchers[homeStartPitcher].name << "' as the starting pitcher for " << homeTeamName << "." << std::endl << std::endl;
	std::cout << "Get ready as " << awayPitchers[awayStartPitcher].name << " and the Orioles prepare to take on  " << homePitchers[homeStartPitcher].name << " and the Yankees!" << std::endl << std::endl;

	playBall();
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
	std::cout << "GAME OVER!" << std::endl;
	std::cout << "****** FINAL SCORE: AWAY " << awayRuns << " , HOME: " << homeRuns << " ******" << std::endl << std::endl;
	std::cout << "Total hits away: " << awayHits << std::endl;
	std::cout << "Total hits home: " << homeHits << std::endl;
	std::cout << awayPitchers[awayStartPitcher].name << ": " << homeHits << " hits, " << awayPitchers[awayStartPitcher].gPStrikeouts << " K, " << homeWalks << " BB" << std::endl;
	std::cout << homePitchers[homeStartPitcher].name << ": " << awayHits << " hits, " << homePitchers[homeStartPitcher].gPStrikeouts << " K, " << awayWalks << " BB" << std::endl;
	std::cout << homeTeam[8].name << ": " << homeTeam[8].gHits << "-" << homeTeam[8].gAtBats << ", " << homeTeam[8].gWalks << " walks, " << homeTeam[8].gHomeRuns << " HR, " << homeTeam[8].gRBI << " RBI" << std::endl;
	std::cout << awayTeam[8].name << ": " << awayTeam[8].gHits << "-" << awayTeam[8].gAtBats << ", " << awayTeam[8].gWalks << " walks, " << awayTeam[8].gHomeRuns << " HR, " << awayTeam[8].gRBI << " RBI" << std::endl << endl << endl;	
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