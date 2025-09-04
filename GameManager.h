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
#include "SoundLoader.h"
#include "ItemManager.h"
#include "GameData.h"



class GameManager
{
public:
    void gameLoop();
    void stageMap(void);
	void scrollBG(int spd);
    void initVariable(void);
    void drawParameter(GameManager& game);
    void initGame(void);


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

	void setIsClear(bool v) { isClear = v; }
	bool getIsClear() const { return isClear; }

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
    SoundLoader soundLoader;
    SoundPlayer soundPlayer;
	ItemManager itemManager;
	GameData gameData;
	bool isClear = 0;
};
