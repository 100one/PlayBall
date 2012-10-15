#include <string>

class Player {
public:
		// player info
		std::string name;
		int height;
		int weight;
		int age;
		int overall;
		int position;
		int handedness;

		// batting ratins
		double conR;
		double conL;
		double powR;
		double powL;
		double plateAwareness;

		// pitching ratings
		double kAbility;
		double pConR;
		double pConL;
		double control;
		double stamina;
		double composure;

		// fielding ratings
		int posField;

		// speed ratings
		int speed;

		// batting stats
		double battingAvg;

		// pitching stats
		double allowedBattingAvg;
		double ERA;
		double runsAllowed;
		double inningsPitched;

		// game stats
		int gInningsPitched;
		int pitchCount;
		int gPStrikeouts;
		int gPWalks;
		int gPHits;
		int gPHomeRuns;
		int gHits;
		int gRBI;
		int gHomeRuns;
		int gAtBats;
		int gStrikeouts;
		int gWalks;

		double getERA();
};