#pragma once
#pragma once
#include "Player.h"

class GameManager
{
public:
    void gameLoop();

    Player& getPlayer() { return player; }

private:
    SceneManager sceneManager;
    Graphic graphic;
    Player player;
    EnemyManager enemies;
    BulletManager bullets;
};
