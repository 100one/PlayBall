#include <string>
#include <array>
#include <random>

#include "GameSimulator.h"

using namespace std;

class Game {
	
public:
	int currentInning;
	bool notOver;
	int homeHits;
	int awayHits;
	int homeRuns;
	int awayRuns;
	int homeWalks;
	int awayWalks;
	int curHomeBatter;
	int curAwayBatter;
	int baseSituation;
	double chanceOfHit;
	int awayStartPitcher;
	int homeStartPitcher;

	std::string awayTeamName;
	std::string homeTeamName;
	std::string halfInning;
	Player awayTeam[9];
	Player homeTeam[9];
	Player awayPitchers[6];
	Player homePitchers[6];
	GameSimulator sim;

	void setUpGame(string awayTeam, string homeTeam);
	void advanceHomeBatter();
	void advanceAwayBatter();
	void endGame();
	void flipInning();
	int processBases(int result);
	void printBasesStatus(int curOuts);
	void Game::setAwayTeam();
	void Game::setHomeTeam();
	void Game::playBall();
	void Game::startGame();
};