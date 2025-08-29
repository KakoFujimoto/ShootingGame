#pragma once
#pragma once
#include "Player.h"
#include "BulletManager.h"
#include "SceneManager.h"
#include "EnemyManager.h"
#include "EffectManager.h"

class GameManager
{
public:
    void gameLoop();

    Player& getPlayer() { return player; }
    BulletManager& getBullet(){ return bullets; }
    EffectManager& getEffect() { return effects; }


private:
    SceneManager sceneManager;
    Graphic graphic;
    Player player;
    EnemyManager enemies;
    BulletManager bullets;
	EffectManager effects;
};
