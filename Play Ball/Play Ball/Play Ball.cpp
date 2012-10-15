#include "stdafx.h"
#include "Game.h"
#include "GameSimulator.h"
#include <iostream>
#include <array>
#include <random>
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

using namespace std;
	Game curGame;
	GameSimulator sim;
	Player awayTeam[9];
	Player homeTeam[9];
	Player awayPitchers[6];
	Player homePitchers[5];
	double chanceOfHit;
	int awayStartPitcher;
	int homeStartPitcher;
void setAwayTeam() {
	awayTeam[0].name = "N. McClouth";
	awayTeam[0].battingAvg = .278;
	awayTeam[0].plateAwareness = 85;
	awayTeam[0].conL = 85;
	awayTeam[0].powL = 85;
	awayTeam[1].name = "J. Hardy";
	awayTeam[1].battingAvg = .238;
	awayTeam[1].plateAwareness = 85;
	awayTeam[1].conL = 85;
	awayTeam[1].powL = 85;
	awayTeam[2].name = "C. Davis";
	awayTeam[2].battingAvg = .270;
	awayTeam[2].plateAwareness = 85;
	awayTeam[2].conL = 85;
	awayTeam[2].powL = 85;
	awayTeam[3].name = "A. Jones";
	awayTeam[3].battingAvg = .287;
	awayTeam[3].plateAwareness = 85;
	awayTeam[3].conL = 85;
	awayTeam[3].powL = 85;
	awayTeam[4].name = "M. Wieters";
	awayTeam[4].battingAvg = .238;
	awayTeam[4].plateAwareness = 85;
	awayTeam[4].conL = 85;
	awayTeam[4].powL = 85;
	awayTeam[5].name = "J. Thome";
	awayTeam[5].battingAvg = .257;
	awayTeam[5].plateAwareness = 85;
	awayTeam[5].conL = 85;
	awayTeam[5].powL = 85;
	awayTeam[6].name = "M. Reynolds";
	awayTeam[6].battingAvg = .221;
	awayTeam[6].plateAwareness = 85;
	awayTeam[6].conL = 85;
	awayTeam[6].powL = 85;
	awayTeam[7].name = "R. Flaherty";
	awayTeam[7].battingAvg = .216;
	awayTeam[7].plateAwareness = 85;
	awayTeam[7].conL = 85;
	awayTeam[7].powL = 85;
	awayTeam[8].name = "M. Machado";
	awayTeam[8].battingAvg = .262;
	awayTeam[8].conL = 85;
	awayTeam[8].powL = 85;
	awayTeam[8].plateAwareness = 85;
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
	awayPitchers[1].allowedBattingAvg = .250;
	awayPitchers[2].name = "C. Tillman";
	awayPitchers[2].allowedBattingAvg = .207;
	awayPitchers[3].name = "M. Gonzalez";
	awayPitchers[3].allowedBattingAvg = .235;
	awayPitchers[4].name = "J. Saunders";
	awayPitchers[4].allowedBattingAvg = .283;
	awayPitchers[5].name = "B. 'The Bad' Salmon";
	awayPitchers[5].allowedBattingAvg = .400;
}
void setHomeTeam() {
	homeTeam[0].name = "D. Jeter";
	homeTeam[0].battingAvg = .316;
	homeTeam[0].plateAwareness = 85;
	homeTeam[0].conR = 85;
	homeTeam[0].powR = 85;
	homeTeam[1].name = "I. Suzuki";
	homeTeam[1].battingAvg = .322;
	homeTeam[1].plateAwareness = 85;
	homeTeam[1].conR = 85;
	homeTeam[1].powR = 85;
	homeTeam[2].name = "M. Teixeira";
	homeTeam[2].battingAvg = .251;
	homeTeam[2].plateAwareness = 85;
	homeTeam[2].conR = 85;
	homeTeam[2].powR = 85;
	homeTeam[3].name = "R. Cano";
	homeTeam[3].battingAvg = .313;
	homeTeam[3].plateAwareness = 85;
	homeTeam[3].conR = 85;
	homeTeam[3].powR = 85;
	homeTeam[4].name = "A. Rodriguez";
	homeTeam[4].battingAvg = .272;
	homeTeam[4].plateAwareness = 85;
	homeTeam[4].conR = 85;
	homeTeam[4].powR = 85;
	homeTeam[5].name = "N. Swisher";
	homeTeam[5].battingAvg = .272;
	homeTeam[5].plateAwareness = 85;
	homeTeam[5].conR = 85;
	homeTeam[5].powR = 85;
	homeTeam[6].name = "R. Martin";
	homeTeam[6].battingAvg = .211;
	homeTeam[6].conR = 85;
	homeTeam[6].powR = 85;
	homeTeam[6].plateAwareness = 85;
	homeTeam[7].name = "C. Granderson";
	homeTeam[7].battingAvg = .232;
	homeTeam[7].plateAwareness = 85;
	homeTeam[7].conR = 85;
	homeTeam[7].powR = 85;
	// homeTeam[8].name = "J. Nix";
	// homeTeam[8].battingAvg = .243;
	homeTeam[8].name = "K. Varga";
	homeTeam[8].plateAwareness = 90;
	homeTeam[8].conR = 99;
	homeTeam[8].powR = 99;
	homePitchers[0].name = "C. Sabathia";
	homePitchers[0].kAbility = 92;
	homePitchers[0].allowedBattingAvg = .238;
	homePitchers[0].composure = 100;
	homePitchers[0].handedness = LEFT;
	homePitchers[0].stamina = 100;
	homePitchers[0].control = 96;
	homePitchers[0].pConL = 90;
	homePitchers[0].pConR = 95;
	homePitchers[1].name = "H. Kuroda";
	homePitchers[1].allowedBattingAvg = .249;
	homePitchers[2].name = "A. Pettitte";
	homePitchers[2].allowedBattingAvg = .232;
	homePitchers[3].name = "P. Hughes";
	homePitchers[3].allowedBattingAvg = .259;
	homePitchers[4].name = "I. Nova";
	homePitchers[4].allowedBattingAvg = .288;
}
void playBall() {
	curGame.setUpGame();
	while(curGame.notOver) {
		std::cout << "**************** " << curGame.halfInning << " " << curGame.currentInning << ", AWAY: " << curGame.awayRuns << ", HOME: " << curGame.homeRuns << " ****************" << endl << endl;
		while(sim.curOuts < 3 && curGame.notOver) {
			if(curGame.halfInning == "Top") {
				std::cout << "Now batting: " << awayTeam[curGame.curAwayBatter].name << endl;
				int result = sim.simulateAtBat(homePitchers[homeStartPitcher], awayTeam[curGame.curAwayBatter]);
				int runsScoredOnPlay = curGame.processBases(result); 
				awayTeam[curGame.curAwayBatter].gRBI+=runsScoredOnPlay;
				if(sim.curOuts!=3) {
					curGame.awayRuns+=runsScoredOnPlay;
					if(runsScoredOnPlay != 0)
						std::cout << "** " << runsScoredOnPlay << " run(s) scored on play! **" << endl << endl;
					curGame.printBasesStatus(sim.curOuts);
				}
				if(result == GROUNDOUT) {
				}
				else if(result == STRIKEOUT) {
					homePitchers[homeStartPitcher].gPStrikeouts++;
					awayTeam[curGame.curAwayBatter].gStrikeouts++;
				}
				else if(result == FLYOUT) {
				}
				else if(result == WALK) {
					awayTeam[curGame.curAwayBatter].gWalks++;
					curGame.awayWalks++;
					homeTeam[homeStartPitcher].gPWalks++;
				}
				else if(result == SINGLE) {
					awayTeam[curGame.curAwayBatter].gHits++;
					curGame.awayHits++;
				}
				else if(result == DOUBLE) {
					awayTeam[curGame.curAwayBatter].gHits++;
					curGame.awayHits++;
				}
				else if(result == TRIPLE) {
					awayTeam[curGame.curAwayBatter].gHits++;
					curGame.awayHits++;
				}
				else if(result == HOMERUN) {
					awayTeam[curGame.curAwayBatter].gHits++;
					curGame.awayHits++;
				}
				else if(result == GROUNDRULEDOUBLE) {
					awayTeam[curGame.curAwayBatter].gHits++;
					curGame.awayHits++;
				}
				if(result!=WALK)
					awayTeam[curGame.curAwayBatter].gAtBats++;
				curGame.advanceAwayBatter();
			}
			else {
				std::cout << "Current batter: " << homeTeam[curGame.curHomeBatter].name << endl;
				int result = sim.simulateAtBat(awayPitchers[awayStartPitcher], homeTeam[curGame.curHomeBatter]);
				int runsScoredOnPlay = curGame.processBases(result); 
				homeTeam[curGame.curHomeBatter].gRBI+=runsScoredOnPlay;
				if(sim.curOuts!=3) {
					curGame.homeRuns+=runsScoredOnPlay;
					if(runsScoredOnPlay != 0)
						std::cout << "** " << runsScoredOnPlay << " runs scored on play! **" << endl << endl;
					curGame.printBasesStatus(sim.curOuts);
				}
				if(result == GROUNDOUT) {
				}
				else if(result == STRIKEOUT) {
					awayPitchers[awayStartPitcher].gPStrikeouts++;
					homeTeam[curGame.curHomeBatter].gStrikeouts++;
				}
				else if(result == FLYOUT) {
				}
				else if(result == WALK) {
					homeTeam[curGame.curHomeBatter].gWalks++;
					curGame.homeWalks++;
					awayTeam[awayStartPitcher].gPWalks++;
				}
				else if(result == SINGLE) {
					homeTeam[curGame.curHomeBatter].gHits++;
					curGame.homeHits++;
				}
				else if(result == DOUBLE) {
					homeTeam[curGame.curHomeBatter].gHits++;
					curGame.homeHits++;
				}
				else if(result == TRIPLE) {
					homeTeam[curGame.curHomeBatter].gHits++;
					curGame.homeHits++;
				}
				else if(result == HOMERUN) {
					homeTeam[curGame.curHomeBatter].gHits++;
					homeTeam[curGame.curHomeBatter].gHomeRuns++;
					curGame.homeHits++;
					curGame.homeRuns++;
				}
				else if(result == GROUNDRULEDOUBLE) {
					homeTeam[curGame.curHomeBatter].gHits++;
					curGame.homeHits++;
					curGame.homeHits++;
				}
				homeTeam[curGame.curHomeBatter].gAtBats++;
				curGame.advanceHomeBatter();
			}
		}
		if(curGame.halfInning == "Top")
			homePitchers[homeStartPitcher].gInningsPitched++;
		else
			awayPitchers[awayStartPitcher].gInningsPitched++;
		if(curGame.currentInning >= 9 && curGame.halfInning == "Bottom" && curGame.homeRuns > curGame.awayRuns) {
				cout << "***************** WALK OFF WIN! THE HOME TEAM WINS! *****************" << endl << endl;
				curGame.notOver = false;
		}
		curGame.flipInning();
		curGame.baseSituation = 0;
		sim.curOuts = 0;
	}
	std::cout << "GAME OVER!" << endl;
	std::cout << "****** FINAL SCORE: AWAY " << curGame.awayRuns << " , HOME: " << curGame.homeRuns << " ******" << endl << endl;
	std::cout << "Total hits away: " << curGame.awayHits << endl;
	std::cout << "Total hits home: " << curGame.homeHits << endl;
	std::cout << awayPitchers[awayStartPitcher].name << ": " << awayPitchers[awayStartPitcher].gPStrikeouts << " K, " << curGame.homeWalks << " BB" << endl;
	std::cout << homePitchers[homeStartPitcher].name << ": " << homePitchers[homeStartPitcher].gPStrikeouts << " K, " << curGame.awayWalks << " BB" << endl;
	std::cout << homeTeam[8].name << ": " << homeTeam[8].gHits << "-" << homeTeam[8].gAtBats << ", " << homeTeam[8].gWalks << " walks, " << homeTeam[8].gHomeRuns << " HR, " << homeTeam[8].gRBI << " RBI" << endl;
}
int _tmain(int argc, _TCHAR* argv[])
{
	string awayTeam;
	string homeTeam;
	awayStartPitcher = 0;
	homeStartPitcher = 0;

	srand((unsigned)time(NULL));

	// cout << "WELCOME TO 'PLAY BALL'! PLEASE SELECT THE AWAY TEAM USING THE TEAM'S THREE-CHARACTER ABBREVIATION." << endl << endl;
	// cin >> awayTeam;
	setAwayTeam();

	// cout << "******************************" << endl << endl << "YOU HAVE CHOSEN '" << awayTeam << "' AS THE AWAY TEAM." << endl << endl;
	// cout << "PLEASE SELECT THE HOME TEAM USING THE TEAM'S THREE-CHARACTER ABBREVIATION." << endl << endl;

	// cin >> homeTeam;
	setHomeTeam();

	// cout << "******************************" << endl << endl << "YOU HAVE CHOSEN '" << homeTeam << "' AS THE HOME TEAM." << endl << endl;
	cout << "PLEASE SELECT THE NUMBER OF ONE OF THE FOLLOWING STARTING PITCHERS FOR THE AWAY TEAM, BALTIMORE:" << endl << endl;
	
		for(int x = 0; x < 6; x++) {
		cout << x+1 << ". " << awayPitchers[x].name << endl;
	}
	cout << endl;
	cin >> awayStartPitcher;
	awayStartPitcher--;

	cout << endl << "******************************" << endl << endl << "YOU HAVE CHOSEN '" << awayPitchers[awayStartPitcher].name << "' AS THE STARTING PITCHER FOR BALTIMORE." << endl << endl;
	cout << "PLEASE SELECT THE NUMBER OF ONE OF THE FOLLOWING STARTING PITCHERS FOR THE HOME TEAM, NEW YORK:" << endl << endl;
	
	for(int x = 0; x < 5; x++) {
		cout << x+1 << ". " << homePitchers[x].name << endl;
	}
	cout << endl;
	cin >> homeStartPitcher;
	homeStartPitcher--;
	cout << endl << "******************************" << endl << endl << "YOU HAVE CHOSEN '" << homePitchers[homeStartPitcher].name << "' AS THE STARTING PITCHER FOR NEW YORK." << endl << endl;
	


	cout << "Get ready as " << awayPitchers[awayStartPitcher].name << " and the Orioles prepare to take on  " << homePitchers[homeStartPitcher].name << " and the Yankees!" << endl << endl;
	playBall();
	system("pause");
	return 0;
}