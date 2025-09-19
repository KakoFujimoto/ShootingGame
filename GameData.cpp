#include "GameData.h"
#include "GameConfig.h"
#include "GameManager.h"

void GameData::stageIncrement(GameManager& game) {
	stage++;
	distance = GameConfig::STAGE_DISTANCE;
	timer = 0;
	game.setIsClear(false);
}

void GameData::distanceDecrement() {
	distance--;
}

void GameData::resetTimer() {
	timer = 0;
}

void GameData::noDamageCount() {
	noDamage--;
}