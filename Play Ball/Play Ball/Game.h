#include <string>

class Game {
	
public:
	int currentInning;
	std::string halfInning;
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

	void setUpGame();
	void advanceHomeBatter();
	void advanceAwayBatter();
	void endGame();
	void flipInning();
	int processBases(int result);
	void printBasesStatus(int curOuts);
};