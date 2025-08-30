#pragma once
#pragma once
#include "Player.h"
#include "BulletManager.h"
#include "SceneManager.h"
#include "EnemyManager.h"
#include "EffectManager.h"
#include "ImageContainer.h"
#include "Drawer.h"
#include "SoundContainer.h"
#include "SoundPlayer.h"


class GameManager
{
public:
    void gameLoop();

    Player& getPlayer() { return player; }
    BulletManager& getBullet(){ return bullets; }
    EffectManager& getEffect() { return effects; }
    EnemyManager& getEnemy() { return enemies; }
    ImageContainer& getImage() { return images; }
    SoundContainer& getSoundContainer() { return soundContainer; }
    SoundPlayer& getSoundPlayer() { return soundPlayer; }
    Drawer& getDrawer() { return drawer; }


private:
    SceneManager sceneManager;
    Drawer drawer;
    Player player;
    EnemyManager enemies;
    BulletManager bullets;
	EffectManager effects;
    ImageContainer images;
    SoundContainer soundContainer;
    SoundPlayer soundPlayer;
};
