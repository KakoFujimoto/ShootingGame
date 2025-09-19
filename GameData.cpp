#include "GameData.h"
#include "GameConfig.h"
#include "GameManager.h"

void GameData::stageIncrement(GameManager& game) {
	stage++;
	distance = GameConfig::STAGE_DISTANCE;
	timer = 0;
	game.setIsClear(false);
}