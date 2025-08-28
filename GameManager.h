#pragma once
#pragma once
#include "Player.h"
#include "BulletManager.h"
#include "SceneManager.h"
#include "EnemyManager.h"

class GameManager
{
public:
    void gameLoop();

    Player& getPlayer() { return player; }
    BulletManager& getBullet()
    {
        return bullets;
    }

private:
    SceneManager sceneManager;
    Graphic graphic;
    Player player;
    EnemyManager enemies;
    BulletManager bullets;
};
