#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include "GameSimulator.h"

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
#define FOUL 10
#define CONTACTCONSTANT 1200 // raise this to increase the chance of a batter making contact on a correctly identified pitch
#define STRIKECONSTANT .1 // raise to make pitchers throw more strikes
#define PITCHERDECAYCONSTANT .2 // raise to make pitchers tire more throughout game
#define PLATEAWARENESSCONSTANT 1 // raise to let batters identify pitchers more often
#define HOMERUNCONSTANT .2 // raise to increase chances of a batter hitting a home run
#define POWERCONSTANT .1 // raise to increase chances of a batter hitting an extra-base hit
#define HITCONSTANT .3 // raise to increase chances of a ball landing for a hit
#define FOULFLYBALLCONSTANT .4 // raise to increase the chances of a contacted non-hit flyball landing foul
#define FOULGROUNDBALLCONSTANT .2 // raise to increase the chances of a contacted non-hit groundball going foul
#define STRIKEOUTCONSTANT 8 // raise this to increase the chances of a batter hitting a strike

int GameSimulator::simulateAtBat(Player pitcher, Player batter) {
	// uncomment the following line to go through the game batter-by-batter
	// std::cin.get();
	curPitcher = pitcher;
	curBatter = batter;
	curBatterOut = 0;
	while(!curBatterOut)
	//	pitcher.pitchCount++;
		throwPitch();

	return result;
}
void GameSimulator::throwPitch() {
	// uncomment the following line to go through the game pitch-by-pitch
	// std::cin.get();
	bool strike = false;
	bool batterIdentifiedPitch = false;
	if(curBatter.plateAwareness * PLATEAWARENESSCONSTANT * (1000-curPitcher.kAbility)/1000 >= rand()%100) {
		batterIdentifiedPitch = true;
	}
	// pitcher.stamina, pitcher.control, pitcher.composure, batter.plateAwareness determine ball/strike
	double chanceOfStrike = 100 * curPitcher.control/100 * STRIKECONSTANT * curPitcher.composure/100 * curPitcher.stamina/(pow((curPitcher.gInningsPitched+1), .2));
	// std::cout << curPitcher.control/100 << " * " << curPitcher.composure/100 <<  " * .75 *  " << curPitcher.stamina/(pow((curPitcher.gInningsPitched+1), .1)) << " = " << chanceOfStrike << std::endl;
	if(chanceOfStrike >= rand()%1000) {
		strike = true;
	} else { 
		strike = false;
	}
	if(strike && batterIdentifiedPitch) {
		// swung at strike
		batterSwing();
	}
	else if(strike && !batterIdentifiedPitch) {
		// took strike
		curStrikes++;
		if(curStrikes!=3)
			std::cout << curBatter.name << " took a strike! Count: " << curBalls << "-" << curStrikes << "." << std::endl;
		else
			std::cout << curBatter.name << " took strike three!" << std::endl << std::endl ;
	}
	else if(!strike && batterIdentifiedPitch) {
		// took ball
		curBalls++;
		if(curBalls!=4)
			std::cout << curBatter.name << " took a ball! Count: " << curBalls << "-" << curStrikes << "." << std::endl;
		else
			std::cout << curBatter.name << " took ball four!" << std::endl << std::endl;
	}	
	else if (!strike && !batterIdentifiedPitch) {
		// swung at ball
		curStrikes++;
		if(curStrikes!=3)
			std::cout << curBatter.name << " swung at a ball! Count: " << curBalls << "-" << curStrikes << "." << std::endl;
		else
			std::cout << curBatter.name << " swung at strike three!" << std::endl;
		}
	if(curBalls == 4) {
		std::cout << "** " << curBatter.name << " walked! **" << std::endl << std::endl;
		curBatterOut = 1;
		curStrikes = 0;
		curBalls = 0;
		result = WALK;
	}
	if(curStrikes == 3) {
		curOuts++;
		std::cout << "** " << curBatter.name << " struck out! **" << std::endl << std::endl;
		curBatterOut = 1;
		curStrikes = 0;
		curBalls = 0;
		result = STRIKEOUT;
	}
}
void GameSimulator::batterSwing() {
	double chanceOfContact = 1000;
	if(curPitcher.handedness == LEFT) {
		if(curBatter.handedness == LEFT) {
			// left-handed batter, left-handed pitcher
			chanceOfContact = curBatter.conL / curPitcher.pConL * CONTACTCONSTANT;
		}
		else {
			// right-handed batter, left-handed pitcher
			chanceOfContact = curBatter.conL / curPitcher.pConR * CONTACTCONSTANT;
		}
	}
	else {
		// right-handed pitcher
		if(curBatter.handedness == RIGHT) {
			// left-handed batter, right-handed pitcher
			chanceOfContact = curBatter.conR / curPitcher.pConL * CONTACTCONSTANT;
		}
		else {
			// right-handed batter, right-handed pitcher
			chanceOfContact = curBatter.conR / curPitcher.pConR * CONTACTCONSTANT	;
		}
	
	}
	// std::cout << "chanceOfContact: " << chanceOfContact << std::endl;
	if(chanceOfContact >= rand()%1400) {
		// std::cout << "Contact made!" << std::endl;
		 simulateContact();
	} else {
		curStrikes++;
		if(curStrikes == 3) {
			std::cout << curBatter.name << " swung and missed!" << std::endl << std::endl;
			result = STRIKEOUT;
			curOuts++;
			std::cout << "** " << curBatter.name << " struck out! **" << std::endl << std::endl;
			curBatterOut = true;
			curStrikes = 0;
			curBalls = 0;
		}
		else {
				std::cout << curBatter.name << " swung and missed! Count: " << curBalls << "-" << curStrikes << std::endl;
		}
	}
}
void GameSimulator::simulateContact() {
	double powerRating = 0;
	double contactVar = rand()%100;

	if(curPitcher.handedness = 0) {
		powerRating = 10000*POWERCONSTANT*pow(curBatter.powL / 130, 3);
	} else {
		powerRating = 10000*POWERCONSTANT*pow(curBatter.powR / 130, 3);
	}
	// powerRating = chance of double
	// powerRating / 4 = chance of home run
	if(powerRating / (1/HOMERUNCONSTANT) >= rand()%1000) {
		std::cout << "** HOME RUN, " << curBatter.name << "! **" << std::endl << std::endl;
		result = HOMERUN;
	}
	else {
		// not home run
		if(HITCONSTANT*100 >= contactVar) {
			if(powerRating >= rand()%1000) {
				std::cout << "** " << curBatter.name << " doubled! **" << std::endl << std::endl;
				result = DOUBLE;
			}
			else {
				// hit, but not a double
				std::cout << "** " << curBatter.name << " singled! **" << std::endl << std::endl;
				result = SINGLE;
			}
		}
		else {
			// not a hit
			if(powerRating * 1.5 <= rand()%1000) {
				// fly ball
				if(FOULFLYBALLCONSTANT*1000 >= rand()%1000) {
					// foul flyball
					result = FOUL;
					if(curStrikes!=2)
						curStrikes++;
					std::cout << curBatter.name << " fouled one away!" << std::endl;
				}
				else {
					// flyball out
					std::cout << "** " << curBatter.name << " flew out! **" << std::endl << std::endl;
					result = FLYOUT;
					curOuts++;
				}
			}
			else {
				// ground ball 
				if(FOULGROUNDBALLCONSTANT*1000 >= rand()%1000) {
					// foul groundball
					std::cout << curBatter.name << " grounded one foul!" << std::endl;
					result = FOUL;
					if(curStrikes!=2)
						curStrikes++;
					}
				else {
					// groundball out
					std::cout << "** " << curBatter.name << " singled! **" << std::endl << std::endl;
					result = GROUNDOUT;
					curOuts++;
				}
			}
		}
	}

	if(result != FOUL) {
			curBatterOut = true;
			curBalls = 0;
			curStrikes = 0;
	}
}