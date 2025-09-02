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
#include "ItemManager.h"
#include "GameData.h"


class GameManager
{
public:
    void gameLoop();
    void stageMap(void);
	void scrollBG(int spd);
    void initVariable(void);


    Player& getPlayer() { return player; }
    BulletManager& getBulletManager(){ return bullets; }
    Bullet& getBullet() { return bullet; }
    EffectManager& getEffect() { return effects; }
    EnemyManager& getEnemy() { return enemies; }
    ImageContainer& getImage() { return images; }
    SoundContainer& getSoundContainer() { return soundContainer; }
    SoundPlayer& getSoundPlayer() { return soundPlayer; }
    Drawer& getDrawer() { return drawer; }
	ItemManager& getItem() { return itemManager; }
    GameData& getGameData() { return gameData; }


private:
    SceneManager sceneManager;
    Drawer drawer;
    Player player;
    EnemyManager enemies;
    BulletManager bullets;
	Bullet bullet;
	EffectManager effects;
    ImageContainer images;
    SoundContainer soundContainer;
    SoundPlayer soundPlayer;
	ItemManager itemManager;
	GameData gameData;
};
