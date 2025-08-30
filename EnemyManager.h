#pragma once
#include "Enemy.h"

class EnemyManager {
public:
	void moveEnemy(void);

	int setEnemy(int x, int y, int vx, int vy, EnemyType ptn, Image img, int sld);
};