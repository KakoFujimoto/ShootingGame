#pragma once
#include "Enemy.h"

class EnemyManager {
public:
	void moveEnemy(void);

	int setEnemy(int x, int y, int vx, int vy, int ptn, int img, int sld);
};