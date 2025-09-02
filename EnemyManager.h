#pragma once
#include "Enemy.h"
#include "GameConfig.h"
#include "GameManager.h"

class EnemyManager {
public:
	void moveEnemy(GameManager& game);
	int setEnemy(int x, int y, int vx, int vy, EnemyType ptn, Image img, int sld, GameManager& game);
	void damageEnemy(int n, int dmg, GameManager& game);


private:
	Enemy enemies[GameConfig::ENEMY_MAX];
};