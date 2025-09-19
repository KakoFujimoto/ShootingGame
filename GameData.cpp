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

void GameData::resetScore() {
	score = 0;
}

void GameData::setStage(int s) {
	stage = s;
}

void GameData::setNoDamage(int n) {
	noDamage = n;
}

void GameData::setWeaponLv(int lv) {
	weaponLv = lv;
	}

void GameData::setDistance(int d) {
	distance = d;
}