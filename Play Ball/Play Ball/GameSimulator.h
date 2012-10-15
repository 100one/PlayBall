#include <stdio.h>
#include "Player.h"

class GameSimulator {
public:
	int curOuts;
private:
	Player curPitcher;
	Player curBatter;
	int curStrikes;
	int curBalls;
	int result;
	bool curBatterOut;

public:
int simulateAtBat(Player pitcher, Player batter);
void throwPitch();
void batterSwing();
void simulateContact();
};