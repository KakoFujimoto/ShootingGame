#pragma once
#include "Enemy.h"
#include "GameConfig.h"

class GameManager;

class EnemyManager {
public:
	void moveEnemy(GameManager& game);
	int setEnemy(int x, int y, int vx, int vy, EnemyType ptn, const Image& img, int sld, GameManager& game);
	void damageEnemy(int n, int dmg, GameManager& game);
	void resetAllEnemies();
	const Enemy& getEnemy(int idx) const;

private:
	Enemy enemies[GameConfig::ENEMY_MAX];
};