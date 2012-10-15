#include "stdafx.h"
#include <string>
#include "Player.h"

double Player::getERA() {
	return (runsAllowed / inningsPitched * 9);
}